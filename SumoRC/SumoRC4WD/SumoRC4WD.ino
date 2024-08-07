//Sumo RC
int motA0=10; // Pines para control de motores
int motA1=11;
int motB0=9;
int motB1=8;

char valorBoton;
char penultimo = 'n';
char antepenultimo = 'm';
char vali = 'b';
                
void setup() 
{
  Serial.begin(9600);     
  
  pinMode(motA0,OUTPUT);
  pinMode(motA1,OUTPUT);
  pinMode(motB0,OUTPUT);
  pinMode(motB1,OUTPUT);
  
  digitalWrite(motA0,LOW);
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,LOW);
  digitalWrite(motB1,LOW);    
}

void loop()
{
  if(Serial.available() > 0)
      { 
        valorBoton = Serial.read();
        //Penultimo = n neutral antepenultimo = m neutral
        //Donde se quiera una izquierda se debe poner derecha y al reves
        //3 señales o 3 botones al mismo tiempo
        if((antepenultimo == 'w' && penultimo == 'd' && valorBoton == 'h') 
                  || (antepenultimo == 'w' && penultimo == 'a' && valorBoton == 'f'))//wdh o waf 
        { 
          vali = 'i';
          adelante();
          penultimo = 'n';
          antepenultimo = 'm';
        } 
        else if((antepenultimo == 's' && penultimo == 'd' && valorBoton == 'h') 
                  || (antepenultimo == 's' && penultimo == 'a' && valorBoton == 'f'))//sdh o saf 
        {
          vali = 'k';
          atras();
          penultimo = 'n';
          antepenultimo = 'm';
        } 
        else if((antepenultimo == 'a' && penultimo == 'w' && valorBoton == 't') 
                  || (antepenultimo == 'a' && penultimo == 's' && valorBoton == 'g'))//awt o asg
        {
          vali = 'j';
          derecha();
          penultimo = 'n';
          antepenultimo = 'm';
        } 
        else if((antepenultimo == 'd' && penultimo == 'w' && valorBoton == 't') 
                  || (antepenultimo == 'd' && penultimo == 's' && valorBoton == 'g'))//dwt o dsg
        {
          vali = 'l';
          izquierda();
          penultimo = 'n';
          antepenultimo = 'm';
        } 
        else if(vali == 'i')//Validacion no se suelta adelante
        {
          adelante();
          if(valorBoton == 't')
          {
            vali = 'b';
            alto();
          }
          else if(valorBoton == 'd') { //d
            izquierda();
          }
          else if(valorBoton == 'a') { //a
            derecha();
          }
        }
        else if(vali == 'k')//Validacion no se suelta atras
        {
          atras();
          if(valorBoton == 'g')
          {
            vali = 'b';
            alto();
          }
          else if(valorBoton == 'd') { //d
            atrasderecha();
          }
          else if(valorBoton == 'a') { //a
            atrasizquierda();
          }
        }
        else if(vali == 'j')//Validacion no se suelta izquierda
        {
          derecha();
          if(valorBoton == 'f')
          {
            vali = 'b';
            alto();
          }
          else if(valorBoton == 'w') { //w
            derecha();
          }
          else if(valorBoton == 'a') { //s
            atrasderecha();
          }
        }
        else if(vali == 'l')//Validacion no se suelta derecha
        {
          izquierda();
          if(valorBoton == 'h')
          {
            vali = 'b';
            alto();
          }
          else if(valorBoton == 'w') { //w
            izquierda();
          }
          else if(valorBoton == 'a') { //s
            atrasizquierda();
          }
        }
        
        //Combinaciones de dos botones:
        else if(valorBoton == 'w') { //w
          adelante();
        }
        else if(valorBoton == 's') { //s
          atras();
        }
        else if(penultimo != 's' && valorBoton == 'a') { //a
          derecha();
        }
        else if(penultimo != 's' && valorBoton == 'd') { //d
          izquierda();
        }
        else if(penultimo == 'w' && valorBoton == 'a') { //wa
          derecha();
        }
        else if(penultimo == 'w' && valorBoton == 'd') { //wd
          izquierda();
        }
        else if(penultimo == 'w' && valorBoton == 'f') { //wf
          adelante();
        }
        else if(penultimo == 'w' && valorBoton == 'h') { //wh
          adelante();
        }
        else if(penultimo == 't' && valorBoton == 'a') { //ta
          derecha();
        }
        else if(penultimo == 't' && valorBoton == 'd') { //td
          izquierda();
        }
        else if(penultimo == 's' && valorBoton == 'a') { //sa
          atrasizquierda();
        }
        else if(penultimo == 's' && valorBoton == 'd') { //sd
          atrasderecha();
        }
        else if(penultimo == 's' && valorBoton == 'f') { //sf
          atras();
        }
        else if(penultimo == 's' && valorBoton == 'h') { //sh
          atras();
        }
        else if(penultimo == 'g' && valorBoton == 'a') { //ga
          atrasderecha();
        }
        else if(penultimo == 'g' && valorBoton == 'd') { //gd
          atrasizquierda();
        }
        //Espejo
        else if(penultimo == 'a' && valorBoton == 'w') { //aw
          derecha();
        }
        else if(penultimo == 'd' && valorBoton == 'w') { //dw
          izquierda();
        }
        else if(penultimo == 'f' && valorBoton == 'w') { //fw
          adelante();
        }
        else if(penultimo == 'h' && valorBoton == 'w') { //hw
          adelante();
        }
        else if(penultimo == 'a' && valorBoton == 't') { //at
          derecha();
        }
        else if(penultimo == 'd' && valorBoton == 't') { //dt
          izquierda();
        }
        else if(penultimo == 'a' && valorBoton == 's') { //as
          atrasderecha();
        }
        else if(penultimo == 'd' && valorBoton == 's') { //ds
          atrasizquierda();
        }
        else if(penultimo == 'f' && valorBoton == 's') { //fs
          atras();
        }
        else if(penultimo == 'h' && valorBoton == 's') { //hs
          atras();
        }
        else if(penultimo == 'a' && valorBoton == 'g') { //ag
          atrasderecha();
        }
        else if(penultimo == 'd' && valorBoton == 'g') { //dg
          atrasizquierda();
        }
        
        else {
          //Si se presionan más de dos botones o no se presionan los adecuados
          alto();
          penultimo = 'n';
          antepenultimo = 'm';
          
        }
        //Actualizar la penultimo

        Serial.print(antepenultimo);
        Serial.print("  ");
        Serial.print(penultimo);
        Serial.print("  ");
        Serial.print(valorBoton);
        Serial.print("  ");
        Serial.print(vali);
        Serial.println("  ");
        
        
        antepenultimo = penultimo;
        penultimo = valorBoton;
      }                
} 


void adelante()
{
  digitalWrite(motA0, HIGH);
  digitalWrite(motA1, LOW);
  digitalWrite(motB0, HIGH);
  digitalWrite(motB1, LOW);
}

void atras()
{
  digitalWrite(motA0, LOW);
  digitalWrite(motA1, HIGH);
  digitalWrite(motB0, LOW);
  digitalWrite(motB1, HIGH);
}

void izquierda()  //Giro a la izquierda
{
  digitalWrite(motA0,LOW); 
  digitalWrite(motA1,HIGH);
  digitalWrite(motB0,HIGH);
  digitalWrite(motB1,LOW);
}

void derecha()  //Giro a la derecha
{
  digitalWrite(motA0,HIGH); 
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,LOW);
  digitalWrite(motB1,HIGH);
}

void alto() //Paro total
{
  digitalWrite(motA0,HIGH);
  digitalWrite(motA1,HIGH);
  digitalWrite(motB0,HIGH);
  digitalWrite(motB1,HIGH);
}

void atrasizquierda(){
  digitalWrite(motA0, LOW);
  digitalWrite(motA1, LOW); //PWM
  digitalWrite(motB0, LOW); //PWM
  digitalWrite(motB1, HIGH);
}

void atrasderecha(){
  digitalWrite(motA0, LOW);
  digitalWrite(motA1, HIGH); //PWM
  digitalWrite(motB0, LOW); //PWM
  digitalWrite(motB1, LOW);
}
