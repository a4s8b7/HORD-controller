int RedLightControl = 5;    // Digital Arduino Pin used to control the lights
int YellowLightControl = 6;
int GreenLightControl = 7;
 
// the setup routine runs once when you press reset:
void setup()  {
    // declare pin 5 to be an output:
    pinMode(RedLightControl, OUTPUT);
    pinMode(YellowLightControl, OUTPUT);
    pinMode(GreenLightControl, OUTPUT);
}
 
// the loop routine runs over and over again forever:
void loop()  {
    digitalWrite(RedLightControl,HIGH);// NO5 and COM3 Connected (red light is on)
    digitalWrite(YellowLightControl,HIGH);
    digitalWrite(GreenLightControl,HIGH);
    
    delay(1000); // wait 1000 milliseconds (1 second)
    digitalWrite(RedLightControl,LOW);// NO3 and COM3 Disconnected (the motor is not running)
    digitalWrite(YellowLightControl,LOW);
    digitalWrite(GreenLightControl,LOW);
    delay(1000); // wait 1000 milliseconds (1 second)
}
