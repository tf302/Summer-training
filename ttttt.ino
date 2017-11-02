#include <Servo.h> 
Servo myservo;
#define EN1 2
#define rpwn1 3//电机正传
#define lpwn1 4//电机反转
#define EN2 5
#define rpwn2 6               
#define lpwn2 7
#define EN3 8
#define rpwn3 9
#define lpwn3 10
#define EN4 11
#define rpwn4 12
#define lpwn4 13
#define TPIN1 22//超声波输出
#define EPIN1 23//输入
#define TPIN2 24
#define EPIN2 25
#define TPIN3 26 
#define EPIN3 27
#define TPIN4 28
#define EPIN4 29   
#define TPIN6 30
#define EPIN6 31                                                                                   
int RED1 = 40;//红外引脚定义
int value1 = 0;
int RED2 = 41;
int value2 = 0;
int RED3 =42;
int value3 =0;
int RED4 =43;
int value4 =0; 
long endcount=0;
int myrand;//随机数
long starttime;//计时器
void setup()
{
  randomSeed(0);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);
  pinMode(RED1, INPUT);
  pinMode(RED2, INPUT);
  pinMode(RED3, INPUT);
  pinMode(RED4, INPUT);
  pinMode(TPIN1,OUTPUT);
  pinMode(EPIN1,INPUT); 
  pinMode(TPIN2,OUTPUT);
  pinMode(EPIN2,INPUT);
  pinMode(TPIN3,OUTPUT);
  pinMode(EPIN3,INPUT);
  pinMode(TPIN4,OUTPUT);
  pinMode(EPIN4,INPUT);
  pinMode(TPIN6,OUTPUT);
  pinMode(EPIN6,INPUT);
  myservo.attach(34);// 舵机引脚定义
  Serial.begin(9600);
  delay(2000);
  while(distance3()>10&&distance4()>10)
  {
      Serial.println("tttttttttttttttttt");
  }
    wheel1(50);
    wheel2(50);
    wheel3(50);
    wheel4(50);
    delay(1000);
    wheel1(170);
    wheel2(170);
    wheel3(170);
    wheel4(170);
    delay(1600); 
    myservo.write(0); //放下铲子  
    wheel1(200);
    wheel2(-200);
    wheel3(-200);
    wheel4(200);
    delay(500);
}

void wheel1(int t1) {

  if ( t1 > 0) {
    digitalWrite(EN1, HIGH);


    analogWrite(rpwn1, 0) ;
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
    analogWrite(rpwn3, t3);
    analogWrite(lpwn3, 0  );

  } else {
    if (t3 < 0) {
      t3 = -t3;
      digitalWrite(EN3, HIGH);
      analogWrite(rpwn3, 0);
      analogWrite(lpwn3, t3 );
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
    analogWrite(rpwn4, 0);
    analogWrite(lpwn4, t4);

  } else {
    if (t4 < 0) {
      t4 = -t4;
      digitalWrite(EN4, HIGH);
      analogWrite(rpwn4,t4 );
      analogWrite(lpwn4, 0);
    } else {
       if (t4 = 0) {
        digitalWrite(EN4, HIGH);
        analogWrite(rpwn4, 0);
        analogWrite(lpwn4, 0);

      }
    }
  }
}

void stp(){
  wheel1(0);
  wheel2(0);
  wheel3(0);
  wheel4(0);
}


float distance1(){//超声波测距
  float L1;
  digitalWrite(TPIN1,LOW); 
  delayMicroseconds(2);
  digitalWrite(TPIN1,HIGH);
  delayMicroseconds(10);
  digitalWrite(TPIN1,LOW);
  L1 = pulseIn(EPIN1,HIGH);
  L1 = L1/58.0;
  Serial.println(L1);
  return L1;
 }
float distance2(){//超声波测距
  float L2;
  digitalWrite(TPIN2,LOW); 
  delayMicroseconds(2);
  digitalWrite(TPIN2,HIGH);
  delayMicroseconds(10);
  digitalWrite(TPIN2,LOW);
  L2 = pulseIn(EPIN2,HIGH);
  L2 = L2/58.0;
  Serial.println(L2);
  return L2;
}

float distance3(){//超声波测距
  float L3;
  digitalWrite(TPIN3,LOW); 
  delayMicroseconds(2);
  digitalWrite(TPIN3,HIGH);
  delayMicroseconds(10);
  digitalWrite(TPIN3,LOW);
  L3 = pulseIn(EPIN3,HIGH);
  L3 = L3/58.0;
  Serial.println(L3);
  return L3;
}
float distance4(){//超声波测距
  float L4;
  digitalWrite(TPIN4,LOW); 
  delayMicroseconds(2);
  digitalWrite(TPIN4,HIGH);
  delayMicroseconds(10);
  digitalWrite(TPIN4,LOW);
  L4 = pulseIn(EPIN4,HIGH);
  L4 = L4/58.0;
  Serial.println(L4);
  return L4;
}
float distance6(){//超声波测距
  float L6;
  digitalWrite(TPIN6,LOW); 
  delayMicroseconds(2);
  digitalWrite(TPIN6,HIGH);
  delayMicroseconds(10);
  digitalWrite(TPIN6,LOW);
  L6 = pulseIn(EPIN6,HIGH);
  L6 = L6/58.0;
  Serial.println(L6);
  return L6;
}

void attack(int x){// 进攻
      wheel1(x);
      wheel2(x);
      wheel3(x);
      wheel4(x);
      Serial.println("攻击1");
}
void loop()
{   
    
    value1 = digitalRead(RED1);
    value2 = digitalRead(RED2);
    value3 = digitalRead(RED3);
    value4 = digitalRead(RED4);
    if((value1==1||value2==1)&&(value3==0)&&(value4==0)){
             attack(-120);
    }//防掉
    if((value3==1||value4==1)&&(value1==0)&&(value2==0)){
              attack(120);
            
    }
    float d1,d2,d3,d4,d6;
    d1=distance1();
    d2=distance2();
    d3=distance3();
    d4=distance4();
    d6=distance6();
    
    if(d1>60&&d2>60&&value1==0&&value2==0&&value3==0&&value4==0)
    {
         if(endcount==0)
         {
             myrand=random(0,5);
             starttime=millis();
         }
         if(millis()-starttime<myrand*300)
         {
     
              wheel1(150);
              wheel2(-150);
              wheel3(-150);
              wheel4(150);
              Serial.println("转圈");
         }
         else if((millis()-starttime)<myrand*1000)
              {
     
                    wheel1(-120);
                    wheel2(-120);
                    wheel3(-120);
                    wheel4(-120);
                    
               }
               else
               {
                    endcount=0;
               }
      
         endcount++;
     }
     else{
      endcount=0;
     }
     
    
     if(d3<60){//攻击 侧面
             wheel1(-150);
             wheel2(150);
             wheel3(150);
             wheel4(-150);
          
     }
     if(d4<60){
             wheel1(150);
             wheel2(-150);
             wheel3(-150);
             wheel4(150);
           
     }
     
     if(d1>0&&d1<60&&d2>60&&value1==0&&value2==0)
          attack(180);//攻击 前  
     if(d2>0&&d2<60&&d1>60&&value3==0&&value4==0)
          attack(180); //攻击 后
    
     if((d1+d2)<70&&d1>30&&d2>30&&d6<50) {
        Serial.println("台下");
        myservo.write(180);//提起铲子
        wheel1(0);
        wheel2(0);
        wheel3(0);
        wheel4(0);
        delay(200);
        wheel1(-180);
        wheel2(-180);
        wheel3(-180);
        wheel4(-180);
        Serial.println("上台1");
        delay(2000);
        myservo.write(0);//放下铲子
        wheel1(150);
        wheel2(-150);
        wheel3(-150);
        wheel4(150);
        delay(500);
      }
      
     if((d1+d2)<70&&d1>30&&d2>30&&d6>50){
        Serial.println("台下");
        myservo.write(180);
        wheel1(0);
        wheel2(0);
        wheel3(0);
        wheel4(0);
        delay(200);
        wheel1(180);
        wheel2(180);
        wheel3(180);
        wheel4(180);
        Serial.println("上台2");
        delay(2000);
        myservo.write(0);
        wheel1(150);
        wheel2(-150);
        wheel3(-150);
        wheel4(150);
        delay(500);
      }
      /*if((d1+d2)<60&&(d5+d6)<60){
             wheel1(-150);
             wheel2(150);
             wheel3(150);
             wheel4(-150);
             delay(500);
             if(d1>d2){
                wheel1(80);
                wheel2(80);
                wheel3(80);
                wheel4(80);
                delay(1500);
             }
             if(d2>d1){
                wheel1(-80);
                wheel2(-80);
                wheel3(-80);
                wheel4(-80);
                delay(1500);
             }
       }
      /*if(d1<60&&d5<60&&d3<60){
        wheel1(-50);
        wheel2(-50);
        wheel3(-50);
        wheel4(-50);
        delay(3000);
      }
      if(d1<60&&d5<60&&d4<60){
        wheel1(-50);
        wheel2(-50);
        wheel3(-50);
        wheel4(-50);
        delay(3000);
      }
      if(d2<60&&d6<60&&d3<60){
        wheel1(50);
        wheel2(50);
        wheel3(50);
        wheel4(50);
        delay(3000);
      }
       if(d2<60&&d6<60&&d4<60){
        wheel1(50);
        wheel2(50);
        wheel3(50);
        wheel4(50);        
        delay(3000);
      }
       */   
}
