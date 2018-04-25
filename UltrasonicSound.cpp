#include "mbed.h"
#include "ultrasonic.h"
#include "pwm_tone.h"

PwmOut Buzzer(p26);
DigitalOut led(LED1);

float C_3 = 1000000/Do3, C_4 = 1000000/Do4, C_5 = 1000000/Do5;



void dist(int distance)
{
        if (distance > 800)
        {
            Tune(Buzzer, C_3, 4);
               
        }
        else if(distance > 200 &&  distance < 800)
        {
            Tune(Buzzer, C_4, 4);
        }
        else 
        {
            Tune(Buzzer, C_5, 4);
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

