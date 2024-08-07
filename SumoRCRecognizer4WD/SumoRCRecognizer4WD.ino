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
    Serial.print("Bluetooth Conectado"); 
    valorBoton = Serial.read();
    if(valorBoton == '8'){
      Serial.print("Adelante"); 
      adelante();
      delay(3000);
    }
    else if(valorBoton == '6'){
      Serial.print("izquierda"); 
      izquierda();
      delay(3000);
    }
    else if(valorBoton == '4'){
      derecha();
      delay(3000);
    }
    else if(valorBoton == '5'){
      atras();
      delay(3000);
    }
    else{
      alto();
    }
    Serial.println(valorBoton);
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
