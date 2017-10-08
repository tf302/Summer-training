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
#define TPIN1 34//超声波输出
#define EPIN1 35 
#define TPIN2 36
#define EPIN2 38                                                                                  
int RED1 = 30;//红外引脚定义
int value1 = 0;
int RED2 = 31;
int value2 = 0;
int RED3 =32;
int value3 =0;
int RED4 =33;
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
  Serial.begin(9600);
  Serial.begin(9600);
 
 //attachInterrupt(1, attack, HIGH);//外部中断
    wheel1(50);
    wheel2(50);
    wheel3(50);
    wheel4(50);
    delay(1000);
    wheel1(120);
    wheel2(120);
    wheel3(120);
    wheel4(120);delay(1000);   
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
void go() {
  wheel1(80);
  wheel2(80);
  wheel3(80);
  wheel4(80);
  //delay(1000);
}
void back(){
  wheel1(-80);
  wheel2(-80);
  wheel3(-80);
  wheel4(-80);
  //delay(1000);
  Serial.println("b");
}

void defense(){//红外防掉
    value1 = digitalRead(RED1);
    value2 = digitalRead(RED2);
  if (value1 == 1 && value2 == 1) {
   
    wheel1(-100);
    wheel2(-100);  
    wheel3(-100);
    wheel4(-100);
     
    delay(1000);
  }  else if(value1==1&&value2==0)//右转 
  {  
   
    back(); 
    wheel1(100);
    wheel2(-100);
    wheel3(-100);
    wheel4(100);
    delay(1000);
    Serial.println("右转");
    
  }
  else if(value2==1&&value1==0)//左转 
  { 
 
    back();
    wheel1(-100);
    wheel2(100);
    wheel3(100);
    wheel4(-100);
    delay(1000);
    Serial.println("左转");
    
  }
   else if(value2==0&&value1==0)
  {
    
    wheel1(100);
    wheel2(100);
    wheel3(100);
    wheel4(100);
  }
  

  //Serial.print(value1);
 // Serial.println(value2);
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
  Serial.print(L1);
  //Serial.println(");
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
  Serial.print(L2);
  //Serial.println("超声波2");
  return L2;
}

void attack1(){// 进攻
      wheel1(100);
      wheel2(100);
      wheel3(100);
      wheel4(100);
      Serial.println("攻击1");
}
void attack2(){// 进攻
      wheel1(-100);
      wheel2(-100);
      wheel3(-100);
      wheel4(-100);
      Serial.println("攻击2");
}
void loop()
{   
    
    value1 = digitalRead(RED1);
    value2 = digitalRead(RED2);
    value3 = digitalRead(RED3);
    value4 = digitalRead(RED4);float d1,d2;
    d1=distance1();
    d2=distance2();
    if(d1>70&&value1==0&&value2==0)
    {
         if(endcount==0)
         {
             myrand=random(0,5);
           //endcoun=myrand+10000;
           starttime=millis();
         }
         if(millis()-starttime<myrand*300)
         {
     
              wheel1(80);
              wheel2(-80);
              wheel3(-80);
              wheel4(80);
              Serial.println("转圈");
         }
         else if((millis()-starttime)<myrand*3000)
              {
     
                    wheel1(80);
                    wheel2(80);
                    wheel3(80);
                    wheel4(80);
                    Serial.println("转圈");
               }
               else
               {
                    endcount=0;
               }
      
         endcount++;
     }
     else
     {
         endcount=0;
     }
     if((value1==1||value2==1)&&value3==0&&value4==0){
              attack2();
              endcount=0;
     }
      if((value1==3||value4==1)&&value1==0&&value2==0){
              attack1();
              endcount=0;
     }
     if(d1<60&&d2>60&&value1==0&&value2==0)
          attack1();
     if(d2<60&&d1>60&&value3==0&&value4==0)
          attack2(); 

     
}
