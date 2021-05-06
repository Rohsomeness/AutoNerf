//https://learn.sparkfun.com/tutorials/tb6612fng-hookup-guide?_ga=2.73065424.2123903471.1619898097-1924508164.1618963764
//https://microcontrollerslab.com/mg995-servo-motor-pinout-interfacing-with-arduino-features-examples/

#include <SparkFun_TB6612.h>
#include <Servo.h>

#define SERVO_PWM 3 //needs to be PWM
#define AIN1 24
#define AIN2 22
#define PWMA 2 //needs to be PWM
#define STBY 26

int in1 = 50;
int in2 = 52;
int motorpin = 28;

int trigger_servo_delay = 240;
int turn_duration = 1500;
int motor_duration = 175;

Servo trigger;

const int offsetA = 1;

Motor m = Motor(AIN1, AIN2, PWMA, offsetA, STBY);

void setup() {
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(motorpin, OUTPUT);
  trigger.attach(SERVO_PWM);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(motorpin, 1);
  int a = digitalRead(in1);
  int b = digitalRead(in2);
  if (a+b==0) {
    m.brake();
    trigger.write(90);
    delay(trigger_servo_delay);
    trigger.write(180);
    delay(trigger_servo_delay);
    trigger.write(90);
    delay(trigger_servo_delay);
    trigger.write(180);
    delay(trigger_servo_delay);
    trigger.write(90);
    //digitalWrite(motorpin, 0);
    delay(turn_duration - (4*trigger_servo_delay));
  } else if ((a == 1)and (b==0)) {
    m.drive(255, motor_duration);
    m.brake();
    delay(turn_duration - motor_duration);
  } else if (a+b == 1){
    m.drive(-255, motor_duration);
    m.brake();
    delay(turn_duration - motor_duration);
  } else {
    m.brake();
    //digitalWrite(motorpin, 0);
    delay(turn_duration);
  }
}
