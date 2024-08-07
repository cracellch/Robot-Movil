//Evasor de Obstaculos sencillo
int motA0=10; // Pines para control de motores
int motA1=11;
int motB0=9;
int motB1=8;

int echo=2;//Sensor de obstaculos 
int triger=3;

void setup() {
 pinMode(motA0, OUTPUT);
 pinMode(motA1, OUTPUT);
 pinMode(motB0, OUTPUT);
 pinMode(motB1, OUTPUT);
 
 pinMode(echo,INPUT);
 pinMode(triger,OUTPUT);

 digitalWrite(motA0, LOW);
 digitalWrite(motA1, LOW);
 digitalWrite(motB0, LOW);
 digitalWrite(motB1, LOW);

}

void loop() {
  if(distancia() >= 20){
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

long distancia()  //Medicion de distancia
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