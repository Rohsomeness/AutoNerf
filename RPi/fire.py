import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

PIN1 = 20
PIN2 = 21
TRIGGER = 2

GPIO.setup(PIN1, GPIO.OUT)
GPIO.setup(PIN2, GPIO.OUT)
GPIO.setup(TRIGGER, GPIO.OUT)

def aim(cmd:str):
    """
    Takes in a string enum command and performs the corresponding action
    @param cmd (Enum)(str): Either "FIRE", "CCW", "CW"
    """
    if (cmd is "FIRE"):
        fire()
    else:
        move(cmd)

def move(cmd:str, positive_pin:int=21, negative_pin:int=20):
    """
    Helper method that outputs signals to pins to move the motor the proper direction. Also prints status message 
    @param cmd (Enum)(str): Either "CCW" or "CW"
    @param positive_pin: positive charged pin connected to motor, usually red in color
    @param negative_pin: negative charged pin connected to motor, usually black in color
    """
    if (cmd is "CCW"):
        print("Moving counter clockwise")
        PIN1 = pin1
        PIN2 = pin2
    else:
        PIN1 = pin2
        PIN2 = pin1
        print("Moving clockwise")
    GPIO.output(PIN1, 0)
    GPIO.output(PIN2, 1)
    
def fire():
    """
    Helper method that outputs signals to pins to fire the gun. Also prints status message 
    @param cmd (Enum)(str): Either "CCW" or "CW"
    @param positive_pin: positive charged pin connected to motor, usually red in color
    @param negative_pin: negative charged pin connected to motor, usually black in color
    """
    print("FIRING")
    GPIO.output(PIN1, 0)
    GPIO.output(PIN2, 0)
    GPIO.output(TRIGGER, 1)
    
        
    