/*A2  A1  A0
  0   0    0   programa básico (adelante)
  0   0    1   evasor de obstáculos
  0   1    0   seguidor de línea negra
  0   1    1   seguidor de línea blanca
  1   0    0   evasor seguidor
  1   0    1   sumo fondo negro
  1   1    0   sumo fondo blanco
  1   1    1   sumo RC
*/

int lec0=A0;
int lec1= A1;
int lec2= A2;

int motA0=10; // Pines para control de motores
int motA1=11;
int motB0=9;
int motB1=8;

int sensorleft = 5; //Sensores de linea
int sensorcenter = 6;
int sensorright = 7;

int echo=2; //Sensor de obstaculos 
int triger=3;

int vel=175;

char valorBoton;
char penultimo = 'n';
char antepenultimo = 'm';
char vali = 'b';

int l1 = 1;
int l2 = 1;
int l3 = 1;

int f1 = 0;
int f2 = 0;
int f3 = 0;

int datos [20];
int datos2 [20];
int i = 0;
int z = 0;

void setup() 
{
  Serial.begin(9600);     
  pinMode(lec0,INPUT);
  pinMode(lec1,INPUT);
  pinMode(lec2,INPUT);
  
  pinMode(motA0,OUTPUT);
  pinMode(motA1,OUTPUT);
  pinMode(motB0,OUTPUT);
  pinMode(motB1,OUTPUT);
  
  digitalWrite(motA0,LOW);
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,LOW);
  digitalWrite(motB1,LOW); 

  pinMode(sensorleft,INPUT);
  pinMode(sensorcenter,INPUT);
  pinMode(sensorright,INPUT);
  
  pinMode(echo,INPUT);
  pinMode(triger,OUTPUT);
  digitalWrite(triger,LOW);
  
}

void loop(){

if (digitalRead(lec2)==1){
// A2 == 1

    if( digitalRead(lec1)==1){
// A2==1 A1 == 1 

        if( digitalRead(lec0)==1){
// A2==1 A1==1 A0 ==1 
// 111 SUMO RC 
       vel=200;         
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
        
        else{
// A2==1 A1 == 1 A0==0
//110 SUMO FONDO BLANCO
   vel=150;
    if(distancia()<=20)
  {
    if(digitalRead(sensorleft)==1 || digitalRead(sensorcenter)==1 || digitalRead(sensorright)==1)
    {
      alto();
      delay(100);
      atras();
      delay(400);
      alto();
      delay(500);
      derecha();
      delay(700);
      alto();
      delay(500);
      adelante();
    }
    else 
    {
      adelante();
    }
  }
  
 else
  {    
    if(digitalRead(sensorleft)==1 || digitalRead(sensorcenter)==1 || digitalRead(sensorright)==1)
    {
      alto();
      delay(100);
      atras();
      delay(400);
      alto();
      delay(500);
      derecha();
      delay(700);
      alto();
      delay(500);
      adelanteLento();
    }
   else
    {
      adelanteLento();
    }
  }
          }
    }
    
    else {
// A2== 1, A1==0

        if( digitalRead(lec0)==1){
// A2==1 A1== 0 A0 ==1 
// 101 SUMO FONO NEGRO 
        vel=150;         
            if(distancia()<=20)
  {
    if(digitalRead(sensorleft)==0 || digitalRead(sensorcenter)==0 || digitalRead(sensorright)==0)
    {
      alto();
      delay(100);
      atras();
      delay(400);
      alto();
      delay(500);
      derecha();
      delay(700);
      alto();
      delay(500);
      adelante();
    }
    else 
    {
      adelante();
    }
  }
  
 else
  {    
    if(digitalRead(sensorleft)==0 || digitalRead(sensorcenter)==0 || digitalRead(sensorright)==0)//Cambiar los "0" por "1" para fondo blanco
    {
      alto();
      delay(100);
      atras();
      delay(400);
      alto();
      delay(500);
      derecha();
      delay(700);
      alto();
      delay(500);
      adelanteLento();
    }
   else
    {
      adelanteLento();
    }
  }
        }
        
        else{
// A2==1 A1== 0 A0 ==0 
//100 EVASOR SEGUIDOR
vel=100;
         l1 = digitalRead(sensorleft);     
  l2 = digitalRead(sensorcenter);
  l3 = digitalRead(sensorright);

  /////////////////
  if (l1 == 0 && l2 == 0 && l3 == 0)
  {
    l1 = f1;
    l2 = f2;
    l3 = f3;
  }
  /////////////////
  else if(l1==0 && l2==0 && l3==1)
  {
    derechacerrada();
    if(distancia() <= 15){
      izquierdacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(300);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(600);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(300);
      adelante();
      if(l1==1 && l2==1 && l3==1){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  else if(l1==0 && l2==1 && l3==1)
  {
    derechal();
    if(distancia() <= 15){
      izquierdacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(300);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(600);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(300);
      adelante();
      if(l1==1 && l2==1 && l3==1){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  else if(l1==1 && l2==0 && l3==0)
  {
    izquierdacerrada();
    if(distancia() <= 15){
      izquierdacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(300);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(600);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(300);
      adelante();
      if(l1==1 && l2==1 && l3==1){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  else if(l1==1 && l2==1 && l3==0)
  {
    izquierdal();
    if(distancia() <= 15){
      izquierdacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(300);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(600);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(300);
      adelante();
      if(l1==1 && l2==1 && l3==1){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  else if(l1==0 && l2==1 && l3==0)
  {
    adelante();
    if(distancia() <= 15){
      izquierdacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(300);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(200);
      adelante();
      delay(600);
      alto();
      delay(200);
      derechacerrada();
      delay(500);
      alto();
      delay(300);
      adelante();
      if(l1==1 && l2==1 && l3==1){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  ///////////////////////////////////////////////////////////////////
  f1 = l1;
  f2 = l2;
  f3 = l3;      //memory variables
  ////////////////////////////////////////////////////////////////////
  
            }      
      }  
            
      }
       
 else{
 //A2==0
 if( digitalRead(lec1)==1){
// A2==0 A1 == 1 

        if( digitalRead(lec0)==1){
// A2==0 A1==1 A0 ==1 
// 011 SEGUIDOR DE LINEA BLANCA          
 vel=100; 
          l1 = digitalRead(sensorleft);     
  l2 = digitalRead(sensorcenter);
  l3 = digitalRead(sensorright);

  /////////////////
  if (l1 == 1 && l2 == 1 && l3 == 1) 
  {
    l1 = f1;
    l2 = f2;
    l3 = f3;
  }
  /////////////////
  else if(l1==1 && l2==1 && l3==0)
  {
    derechacerrada();
  }
  else if(l1==1 && l2==0 && l3==0)
  {
    derechal();
  }
  else if(l1==0 && l2==1 && l3==1)
  {
    izquierdacerrada();
  }
  else if(l1==0 && l2==0 && l3==1)
  {
    izquierdal();
  }
  else if(l1==1 && l2==0 && l3==1)
  {
    adelante();
  }
  ///////////////////////////////////////////////////////////////////
  f1 = l1;
  f2 = l2;
  f3 = l3;      //memory variables
  ////////////////////////////////////////////////////////////////////
  
         
        }
        
        else{
// A2==0 A1 == 1 A0==0
//010 SEGUIDOR DE LINEA NEGRA
vel=100;
  l1 = digitalRead(sensorleft);     
  l2 = digitalRead(sensorcenter);
  l3 = digitalRead(sensorright);

  /////////////////
  if (l1 == 0 && l2 == 0 && l3 == 0) 
  {
    l1 = f1;
    l2 = f2;
    l3 = f3;
  }
  /////////////////
  else if(l1==0 && l2==0 && l3==1)
  {
    derechacerrada();
  }
  else if(l1==0 && l2==1 && l3==1)
  {
    derechal();
  }
  else if(l1==1 && l2==0 && l3==0)
  {
    izquierdacerrada();
  }
  else if(l1==1 && l2==1 && l3==0)
  {
    izquierdal();
  }
  else if(l1==0 && l2==1 && l3==0)
  {
    adelante();
  }
  ///////////////////////////////////////////////////////////////////
  f1 = l1;
  f2 = l2;
  f3 = l3;      //memory variables
  ////////////////////////////////////////////////////////////////////
   
          }
    }
    
    else {
// A2== 0, A1==0

        if( digitalRead(lec0)==1){
// A2==0 A1== 0 A0 ==1 
// 001 Evasor de obstaculos          
         if(distancia() >= 30){
    adelante();
  }else{
    alto();
    delay(1000);
    atras();
    delay(500);
    izquierda();
    delay(500);
  }  
        }
        
        else{          
// A2==0 A1== 0 A0 ==0 
//Dacta 4WD
   if (Serial.available()){
    datos[i] = Serial.read();
    
    if(datos[i] == 7){
      z = i;
      for(i = 0; i < z; i++){
        datos2[i] = datos[i];
      }
    }
    if(datos[i] == 1){
    for(i = 0; i < z; i++){
    Serial.print(datos2[i]);
    if(datos2[i] == 8){
      adelante();
      delay(500);
    }
    if(datos2[i] == 2){
      atras();
      delay(500);
    }
    if(datos2[i] == 4){
      izquierda();
      delay(525);
    }
    if(datos2[i] == 6){
      derecha();
      delay(525);
    }
  }
 }
  alto();
  if(datos[i] == 3){
    for(i = 0; i < z; i++){
      datos2[i] = 0;
      datos[i] = 0;
    }
    i = 0;
    z = 0;
  }
  i++;
   }
          }      
      }  

 
  }
  
  }

long distancia()
{
  
  long t; 
  long d; 

  digitalWrite(triger, HIGH);
  delayMicroseconds(10);  
  digitalWrite(triger, LOW);
  
  t = pulseIn(echo, HIGH);
  d = t/59;            
  
  delay(10);      
  return d;
}

void adelante()
{
  digitalWrite(motA0, HIGH);
  digitalWrite(motA1, LOW);
  digitalWrite(motB0, HIGH);
  digitalWrite(motB1, LOW);
}

void adelanteLento()
{
  analogWrite(motA0, vel);
  digitalWrite(motA1, LOW);
  analogWrite(motB0, vel);
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

void izquierdal()  //Giro a la izquierda
{
  digitalWrite(motA0,HIGH); 
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,LOW);
  digitalWrite(motB1,LOW);
}

void derechal()  //Giro a la derecha
{
  digitalWrite(motA0,LOW); 
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,HIGH);
  digitalWrite(motB1,LOW);
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

  void derechacerrada(){
  digitalWrite(motA0,LOW); 
  digitalWrite(motA1,vel);
  digitalWrite(motB0,HIGH);
  digitalWrite(motB1,LOW);
}
  
  void izquierdacerrada(){
  digitalWrite(motA0,HIGH); 
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,LOW);
  digitalWrite(motB1,vel);
}