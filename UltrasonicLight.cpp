#include "mbed.h"
#include "ultrasonic.h"


DigitalOut led(LED1);

void dist(int distance)
{
    //printf("Distance changed to %dmm\r\n", distance);
    if(distance > 800)
    {
         led =1; 
    }
    else if(distance > 200 && distance < 800)
    {
        led = 1;
        wait(0.5);
        led=0;
        wait(0.5);
    }
    else
    {
       led = 1;
        wait(0.1);
        led=0;
        wait(0.1);
    }
    
 
}
ultrasonic sensor(p25,p7,.1,1, &dist);


int main(){
    sensor.startUpdates();
    while(1)
    {
        sensor.checkDistance();     
    }
}

