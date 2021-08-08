# AutoNerf
AutoNerf - Automatically targeting nerf gun that is able to hunt down targets.
Video (in dev): https://youtu.be/9rLi6Xelfl4

## Code Structure

Code structure is modeled after the hardware architecture, divided into arduino and raspberry pi code. This division was done as the arduino is good at handling sending signals to motor controllers and rapidly changing signals with pwm, but the raspberry pi has the computing power (and OS) to handle running the two models needed. 

For the raspberry pi code, RPi/detect.py contains the main OpenCV model that performs detections. RPi/fire.py contains the code that controls the data encoding between the Raspberry Pi and arduino to perform commands like shooting and rotating. Finally, RPi/controller.py contains code that uses the OpenCV model output and decides what signals to send. Importantly, it also contains code for buffers needed to account for the processing power of the raspberry pi. This buffer is also reflected in the arduino code. 

## Limitations

The raspberry pi has enough processing power for around 2 frames per second; however, ideally, we would need around 10 fps for "instantaneous" performance. Otherwise, the buffers added in both the raspberry pi and arduino code are needed. Making the gun turn slower, as opposed to making it "stutter" by adding buffers, was not an option as the minimum speed was needed to overcome the static friction needed to make the gun rotate was too fast for the processing power of the raspberry pi.
