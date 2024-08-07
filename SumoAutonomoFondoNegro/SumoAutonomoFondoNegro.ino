//Sumo Autonomo Fondo Negro
int motA0=10; // Pines para control de motores
int motA1=11;
int motB0=9;
int motB1=8;

int sensorleft = 5; //Sensores de linea
int sensorcenter = 6;
int sensorright = 7;

int echo=2; //Sensor de obstaculos 
int triger=3;

int vel = 175  ;

void setup() 
{
  pinMode(sensorleft,INPUT);
  pinMode(sensorcenter,INPUT);
  pinMode(sensorright,INPUT);
  
  pinMode(motA0,OUTPUT);
  pinMode(motA1,OUTPUT);
  pinMode(motB0,OUTPUT);
  pinMode(motB1,OUTPUT);
  
  pinMode(echo,INPUT);
  pinMode(triger,OUTPUT);
  digitalWrite(triger,LOW);
  
  digitalWrite(motA0,LOW);
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,LOW);
  digitalWrite(motB1,LOW);
}

void loop() 
{
  if(distancia()<=20)
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
  digitalWrite(motA0,HIGH); 
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,LOW);
  digitalWrite(motB1,HIGH);
}

void derecha()  //Giro a la derecha
{
  digitalWrite(motA0,LOW); 
  digitalWrite(motA1,HIGH);
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
