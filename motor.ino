#include<Servo.h>

int flag=1;
int button=8;
int buttonState=1;
Servo servo;
void setup(){
    pinMode(button,INPUT_PULLUP);
    servo.attach(9);
    servo.write(90);
    Serial.begin(9600);
}

void loop(){
    while(Serial.available()==0){}
    flag=Serial.read()-48;
    Serial.println(flag);
    buttonState=digitalRead(button);
    if(flag==1){
        if(buttonState==HIGH){
            while(buttonState==HIGH){
                servo.write(82);
                buttonState=digitalRead(button);
            }
            delay(500);
            servo.write(90);
        }
        else{
            servo.write(1);
        }
        delay(3000);
        servo.write(90);
    }
}