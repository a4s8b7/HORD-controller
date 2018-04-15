int RedLightControl = 5; 
int YellowLightControl = 6;
int GreenLightControl = 7;
void setup() {
     //configure pin44 as an input and enable the internal pull-up resistor
  pinMode(46, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(50, INPUT_PULLUP);
  digitalWrite(46,HIGH);
  digitalWrite(48,HIGH);
  digitalWrite(50,HIGH);
  
  pinMode(RedLightControl, OUTPUT);
  pinMode(YellowLightControl, OUTPUT);
  pinMode(GreenLightControl, OUTPUT);
}

void loop() {
  //read the Red button value into a variable
  int sensorValRed = digitalRead(46);
  if (sensorValRed == HIGH) {
      digitalWrite(RedLightControl,LOW);
  } else {
      digitalWrite(RedLightControl,HIGH);
  }

    //read the Yellow button value into a variable
  int sensorValYel = digitalRead(48);
  if (sensorValYel == HIGH) {
      digitalWrite(YellowLightControl,LOW);
  } else {
      digitalWrite(YellowLightControl,HIGH);
  }
  //read the Green button value into a variable
  int sensorValGre = digitalRead(50);
  if (sensorValGre == HIGH) {
      digitalWrite(GreenLightControl,LOW);
  } else {
      digitalWrite(GreenLightControl,HIGH);
  }

}
