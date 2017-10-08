#define EN1 2
#define rpwn1 3//正传
#define lpwn1 4//反转
#define EN2 5
#define rpwn2 6
#define lpwn2 7
#define EN3 8
#define rpwn3 9
#define lpwn3 10 
#define EN4 11
#define rpwn4 12
#define lpwn4 13
int RED=30;
int value=0;
void setup()
{
  Serial.begin(9600);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);
  pinMode(RED, INPUT);
}
int stop(){
  wheel1(0);
  wheel2(0);
  wheel3(0);
  wheel4(0);
  }
void wheel1(int t1) {

  if ( t1 > 0) {
    digitalWrite(EN1, HIGH);

 
    analogWrite(rpwn1,0) ;
    analogWrite(lpwn1, t1);
  } else {
    if (t1 < 0) {
      t1 = -t1;
      digitalWrite(EN1, HIGH);
      analogWrite(rpwn1, t1);
      analogWrite(lpwn1, 0);
    } else {
      if (t1 = 0) {
        digitalWrite(EN1, HIGH);
        analogWrite(rpwn1, 0);
        analogWrite(lpwn1, 0);
      }
    }
  }
}

void wheel2(int t2) {

  if ( t2 > 0) {
    digitalWrite(EN2, HIGH);
    analogWrite(rpwn2, t2);
    analogWrite(lpwn2, 0);

  } else {
    if (t2 < 0) {
      t2 = -t2;
      digitalWrite(EN2, HIGH);
      analogWrite(rpwn2, 0);
      analogWrite(lpwn2, t2);
    } else {
      if (t2 = 0) {
        digitalWrite(EN2, HIGH);
        analogWrite(rpwn2, 0);
        analogWrite(lpwn2, 0);
     
      }
    }
  }
}

void wheel3(int t3) {

  if ( t3 > 0) {
    digitalWrite(EN3, HIGH);
    analogWrite(rpwn3,t3);
    analogWrite(lpwn3,0  );

  } else {
    if (t3 < 0) {
      t3 = -t3;
      digitalWrite(EN3, HIGH);
      analogWrite(rpwn3, 0);
      analogWrite(lpwn3,t3 );
    } else {
      if (t3 = 0) {
        digitalWrite(EN3, HIGH);
        analogWrite(rpwn3, 0);
        analogWrite(lpwn3, 0);
       
      }
    }
  }
}

void wheel4(int t4) {

  if ( t4 > 0) {
    digitalWrite(EN4, HIGH);
    analogWrite(rpwn4, t4);
    analogWrite(lpwn4, 0);

  } else {
    if (t4 < 0) {
      t4= -t4;
      digitalWrite(EN4, HIGH);
      analogWrite(rpwn4, 0);
      analogWrite(lpwn4, t4);
    } else {
      if (t4 = 0) {
        digitalWrite(EN4, HIGH);
        analogWrite(rpwn4, 0);
        analogWrite(lpwn4, 0);
      
      }
    }
  }
}

void loop()
{
 

 value=digitalRead(RED);
 {
  if(value==0)
  //stop();
  //delay(100);
  wheel1(-150);
  wheel2(-150);
  wheel3(-150);
  wheel4(-150);
 }
 Serial.println(value);
}
