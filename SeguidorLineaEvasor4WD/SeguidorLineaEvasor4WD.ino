//Evasor de Obstaculos sencillo
int motA0=10; // Pines para control de motores
int motA1=11;
int motB0=9;
int motB1=8;

int sensorleft = 5;
int sensorcenter = 6;
int sensorright = 7;

int echo=2;//Sensor de obstaculos 
int triger=3;

int l1 = 1;
int l2 = 1;
int l3 = 1;

int f1 = 0;
int f2 = 0;
int f3 = 0;
int vel = 100;

void setup() {
 pinMode(motA0, OUTPUT);
 pinMode(motA1, OUTPUT);
 pinMode(motB0, OUTPUT);
 pinMode(motB1, OUTPUT);

 digitalWrite(motA0, LOW);
 digitalWrite(motA1, LOW);
 digitalWrite(motB0, LOW);
 digitalWrite(motB1, LOW);
 
 pinMode(sensorleft, INPUT);
 pinMode(sensorcenter, INPUT);
 pinMode(sensorright, INPUT);

 pinMode(echo,INPUT);
 pinMode(triger,OUTPUT);
}

void loop(){
  //Linea Blanca
    
  l1 = digitalRead(sensorleft);     
  l2 = digitalRead(sensorcenter);
  l3 = digitalRead(sensorright);

  /////////////////
  if (l1 == 1 && l2 == 1 && l3 == 1) //Feedback cuando todos los sensores estan en negro
  {
    l1 = f1;
    l2 = f2;
    l3 = f3;
  }
  /////////////////
  else if(l1==1 && l2==1 && l3==0)
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
      if(l1==0 && l2==0 && l3==0){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  else if(l1==1 && l2==0 && l3==0)
  {
    derecha();
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
      if(l1==0 && l2==0 && l3==0){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  else if(l1==0 && l2==1 && l3==1)
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
      if(l1==0 && l2==0 && l3==0){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  else if(l1==0 && l2==0 && l3==1)
  {
    izquierda();
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
      if(l1==0 && l2==0 && l3==0){
        adelante();
        delay(200);
        izquierdacerrada();
      }
    }
  }
  else if(l1==1 && l2==0 && l3==1)
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
      if(l1==0 && l2==0 && l3==0){
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
  digitalWrite(motB1,LOW);
}

void izquierdacerrada()
{
  digitalWrite(motA0,HIGH); 
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,LOW);
  digitalWrite(motB1,HIGH);
}

void derecha()  //Giro a la derecha
{
  digitalWrite(motA0,LOW); 
  digitalWrite(motA1,LOW);
  digitalWrite(motB0,HIGH);
  digitalWrite(motB1,LOW);
}

void derechacerrada()//Giro a la derecha cerrada
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
