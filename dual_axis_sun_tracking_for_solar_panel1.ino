#include <Servo.h>
///ground motor
int pos = 90;Servo servo_9;
///solar motor
int pos2 = 90;Servo servo_8;
///sensors for ground motor
int sensorValue_1 = 0; int sensorValue_2 = 0;
int sensorPin_1 = A0; int sensorPin_2 = A1;
///sensors for solar motor
int sensorValue_3 = 0; int sensorValue_4 = 0;
int sensorPin_3 = A2; int sensorPin_4 = A3;
void setup()
{
  servo_9.attach(9);
  servo_8.attach(8);
  Serial.begin(9600); Serial.println("STARTING!......");
  Serial.println("ldr_1 reading : "); Serial.println(sensorValue_1);
  Serial.println("ldr_2 reading : "); Serial.println(sensorValue_2);
  Serial.println("ldr_3 reading : "); Serial.println(sensorValue_3);
  Serial.println("ldr_4 reading : "); Serial.println(sensorValue_4);
  Serial.println("Both Motors at ");
  servo_9.write(pos);
  servo_8.write(pos);
  Serial.println(pos);
  delay(3000);
}
void loop()
{
  //////get l1 & l2
  sensorValue_1=analogRead(sensorPin_1);
  sensorValue_2=analogRead(sensorPin_2);
  ///get l3 & l4
  sensorValue_3=analogRead(sensorPin_3);
  sensorValue_4=analogRead(sensorPin_4);
  //ground servo motor
  while(sensorValue_1<sensorValue_2)
  {
    Serial.println("Adjusting Motor towards 180...");
    servo_9.write(pos=pos+1);
    Serial.println(pos);
    sensorValue_1=analogRead(sensorPin_1);
    sensorValue_2=analogRead(sensorPin_2);
  }
  while(sensorValue_1>sensorValue_2)
  {
    Serial.println("Adjusting Motor towards 0...");
    servo_9.write(pos=pos-1);
    Serial.println(pos);
    sensorValue_1=analogRead(sensorPin_1);
    sensorValue_2=analogRead(sensorPin_2);
  }
  //solar servo motor
  while(sensorValue_3<sensorValue_4)
  {
    Serial.println("Adjusting Motor towards 180...");
    servo_8.write(pos=pos+1);
    Serial.println(pos);
    sensorValue_3=analogRead(sensorPin_3);
    sensorValue_4=analogRead(sensorPin_4);
  }
  while(sensorValue_3>sensorValue_4)
  {
    Serial.println("Adjusting Motor towards 0...");
    servo_8.write(pos=pos-1);
    Serial.println(pos);
    sensorValue_3=analogRead(sensorPin_3);
    sensorValue_4=analogRead(sensorPin_4);
  }
  
  Serial.println("ldr_2 reading : "); Serial.println(sensorValue_1);
  Serial.println("ldr_2 reading : "); Serial.println(sensorValue_2);
  delay(1000);
}