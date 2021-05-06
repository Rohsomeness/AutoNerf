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
int motorpin = 30;

int trigger_servo_delay = 1000;
int turn_duration = 1500;
int motor_duration = 100;

Servo trigger;

const int offsetA = 1;

Motor m = Motor(AIN1, AIN2, PWMA, offsetA, STBY);

void setup() {
  
  delay(1000);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(motorpin, OUTPUT);
  digitalWrite(motorpin, LOW);
  trigger.attach(SERVO_PWM);
  int a = 0;
  int b = 0;
  if (a+b==0) {
    m.brake();
    digitalWrite(motorpin, 1);
    delay(1000);
    trigger.write(90);
    delay(trigger_servo_delay);
    trigger.write(180);
    delay(trigger_servo_delay);
    trigger.write(90);
    delay(trigger_servo_delay);
    trigger.write(180);
    delay(trigger_servo_delay);
    digitalWrite(motorpin, 0);
  }
  m.drive(255, motor_duration);
  m.brake();
  delay(turn_duration - motor_duration);
  m.drive(-255, motor_duration);
  m.brake();
  delay(turn_duration - motor_duration);
}

void loop() {
  
}
