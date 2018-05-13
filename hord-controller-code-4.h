#include "TM1637.h"
  
    int RedLightControl = 5;    // Digital Arduino Pin used to control the lights
    int YellowLightControl = 6;
    int GreenLightControl = 7;
    int modymode = 1;
    int toggle = 0;
    int keypressed = 0;
  
    int profile_BIT1_1  = 26;
    int profile_BIT1_2  = 25;
    int profile_BIT1_4  = 24;   //Profile variables are for the SCSI ID's
    int profile_BIT1_8  = 23;
    
    int profile_BIT2_1  = 31;
    int profile_BIT2_2  = 30;
    int profile_BIT2_4  = 29;
    int profile_BIT2_8  = 28;
    
    int profile_BIT3_1  = 36;
    int profile_BIT3_2  = 35;
    int profile_BIT3_4  = 34;
    int profile_BIT3_8  = 33;
  
  const int Player1ready = A0;  // Analog input pin that the Button is attached to
  const int PlayerOneQuit = A1;   // Analog input pin that the Button is attached to
  const int Player2ready = A2;  // Analog input pin that the Button is attached to
  const int PlayerTwoQuit = A3;   // Analog input pin that the Button is attached to
    
  int Player1readyValue = 0;
  int PlayerOneQuitValue = 0;
  int Player2readyValue = 0;
  int PlayerTwoQuitValue = 0;
      
// Define profile variable, set to 0

    int minutes = 3;
    int secoundstwo = 0;
    int secoundsone = 0;

  #define CLK 2//pins definitions for TM1637 and can be changed to other ports       
  #define DIO 3
  TM1637 tm1637(CLK,DIO);
  #define ON 1
  #define OFF 0
  unsigned char ClockPoint = 1;

 
void setup()  {

// for debugging:
  Serial.begin(9600);
  
  // make the profile switch's pins inputs, with internal pullups on:
  pinMode(profile_BIT1_1, INPUT_PULLUP);
  pinMode(profile_BIT1_2, INPUT_PULLUP);
  pinMode(profile_BIT1_4, INPUT_PULLUP);
  pinMode(profile_BIT1_8, INPUT_PULLUP);

  pinMode(profile_BIT2_1, INPUT_PULLUP);
  pinMode(profile_BIT2_2, INPUT_PULLUP);
  pinMode(profile_BIT2_4, INPUT_PULLUP);
  pinMode(profile_BIT2_8, INPUT_PULLUP);

  pinMode(profile_BIT3_1, INPUT_PULLUP);
  pinMode(profile_BIT3_2, INPUT_PULLUP);
  pinMode(profile_BIT3_4, INPUT_PULLUP);
  pinMode(profile_BIT3_8, INPUT_PULLUP);
  
  pinMode(46, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(50, INPUT_PULLUP);
  digitalWrite(46,HIGH);
  digitalWrite(48,HIGH);
  digitalWrite(50,HIGH);
  
    // declare pin 5 to be an output:
    pinMode(RedLightControl, OUTPUT);
    pinMode(YellowLightControl, OUTPUT);
    pinMode(GreenLightControl, OUTPUT);
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop()  {

		  //read the Red button value into a variable
          int sensorValRed = digitalRead(46);
          if (sensorValRed == LOW) {
            modymode = 4;     // all stop
            //keypressed = 1;
          } 
          //read the Yellow button value into a variable
          int sensorValYel = digitalRead(48);
          if (sensorValYel == LOW) {
            modymode = 3;     // pause
            //keypressed = 1;
          } 
          //read the Green button value into a variable
          int sensorValGre = digitalRead(50);
          if (sensorValGre == LOW) {
            modymode = 2;     //start the match
            //keypressed = 1;
          }
      //Player One Ready button 
        Player1readyValue = analogRead(Player1ready);
        if (Player1readyValue > 100) {
        modymode = 1;       //ready to start the match
        }
      //Player One Quit button 
        PlayerOneQuitValue = analogRead(PlayerOneQuit);
        if (PlayerOneQuitValue > 100) {
        modymode = 1;       //ready to start the match
        }
      //Player Two Ready button 
        Player2readyValue = analogRead(Player2ready);
        if (Player2readyValue > 100) {
        modymode = 1;       //ready to start the match
        }
      //Player Two Quit button 
        PlayerTwoQuitValue = analogRead(PlayerTwoQuit);
        if (PlayerTwoQuitValue > 100) {
        modymode = 1;       //ready to start the match
        }


    Serial.print("Mode  ");
    Serial.println(modymode);
    Serial.print(" Toggle ");
    Serial.print(toggle);
    //Serial.print("[pro-1: ");
    //Serial.print(profile);
    //Serial.print("  ");
    //Serial.print("pro-2: ");
    //Serial.print(profile2);
    //Serial.print("  ");
    //Serial.print("pro-3: ");
    //Serial.println(profile3);
  
switch (modymode) {
    case 1: // reset & set timer to set time
      {
        // read the input pins: NOTE - CLOSED switch (binary 1) returns "0"
        //profile = 3;
        //profile2 = 0;
        //profile3 = 0;
          
        int val_profile_BIT1_1 = digitalRead(profile_BIT1_1);
        int val_profile_BIT1_2 = digitalRead(profile_BIT1_2);
        int val_profile_BIT1_4 = digitalRead(profile_BIT1_4);
        int val_profile_BIT1_8 = digitalRead(profile_BIT1_8);
        
        int val_profile_BIT2_1 = digitalRead(profile_BIT2_1);
        int val_profile_BIT2_2 = digitalRead(profile_BIT2_2);
        int val_profile_BIT2_4 = digitalRead(profile_BIT2_4);
        int val_profile_BIT2_8 = digitalRead(profile_BIT2_8);
        
        int val_profile_BIT3_1 = digitalRead(profile_BIT3_1);
        int val_profile_BIT3_2 = digitalRead(profile_BIT3_2);
        int val_profile_BIT3_4 = digitalRead(profile_BIT3_4);
        int val_profile_BIT3_8 = digitalRead(profile_BIT3_8);

        //int     profile =  0; needed in loop to reset to 0 for each pass
        // turn bit values into single profile value by adding decimal value 
        // of each bit to profile variable
        
        if (  val_profile_BIT1_1 ==  0)    { minutes = minutes + 1; }
        if (  val_profile_BIT1_2 ==  0)    { minutes = minutes + 2; }
        if (  val_profile_BIT1_4 ==  0)    { minutes = minutes + 4; }
        if (  val_profile_BIT1_8 ==  0)    { minutes = minutes + 8; }
        
        if (  val_profile_BIT2_1 ==  0)    { secoundstwo = secoundstwo + 1; }
        if (  val_profile_BIT2_2 ==  0)    { secoundstwo = secoundstwo + 2; }
        if (  val_profile_BIT2_4 ==  0)    { secoundstwo = secoundstwo + 4; }
        if (  val_profile_BIT2_8 ==  0)    { secoundstwo = secoundstwo + 8; }
        
        if (  val_profile_BIT3_1 ==  0)    { secoundsone = secoundsone + 1; }
        if (  val_profile_BIT3_2 ==  0)    { secoundsone = secoundsone + 2; }
        if (  val_profile_BIT3_4 ==  0)    { secoundsone = secoundsone + 4; }
        if (  val_profile_BIT3_8 ==  0)    { secoundsone = secoundsone + 8; }

        //set timmer to the set time
        int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//0~9,A,b,C,d,E,F
        int8_t ListDisp[0];
        tm1637.display(0,0);
        tm1637.display(1,minutes); 
        tm1637.display(2,secoundstwo);
        tm1637.display(3,secoundsone);
        tm1637.point(POINT_ON);
        //delay(1000);
        modymode = 5;
      }
      break;
    case 2: //run match, decrease timer
      {
        secoundsone --;		//decres timmer by one
		if (secoundsone < 1) {secoundsone = 9; secoundstwo --;} // ones
		if (secoundstwo < 1) {secoundstwo = 5; minutes --;}  // tens
		if (minutes < 1) {modymode = 4; keypressed = 0;}               //stop the match
      
        int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//0~9,A,b,C,d,E,F
        int8_t ListDisp[0];
        tm1637.display(0,minutes);  //hundreds
        tm1637.display(1,secoundstwo);  //tens
        tm1637.display(2,secoundsone);  //ones
        tm1637.display(3,0);  //not used
        tm1637.point(POINT_ON);
        delay(2000);
        keypressed = 1;
      }
      break;
    case 3:   // Pause, stop timer, and blink time 
      {
      //pause the timmer and blink yellow button
            if (toggle = 1) {
              // insert some kind of delay
              //delayCTR = delayCTR + 1
              //delayCTR > 1000 then toggle = 0; delayCTR = 0
              //digitalWrite(RedLightControl,LOW);
              digitalWrite(YellowLightControl,LOW);
              delay(2000);
              toggle = 0;
            } else {
              // insert some kind of delay
              //delayCTR = delayCTR + 1
              //delayCTR > 1000 then toggle = 1; delayCTR = 0
              //digitalWrite(RedLightControl,HIGH);
              digitalWrite(YellowLightControl,HIGH);
              delay(2000);
              toggle = 1;
            }
      }
      break;
    case 4:   // Stop the match, clear the timer
      {
      //stop go back to demo mode
        //reset the time to the value set on the SCSI switches 
      modymode = 5;
      }
      break;
    case 5:   //Demo mode
      {
      // demo mode blink start stop lights and set time
       if (toggle = 1) {
              Serial.println("toggle 1");
			  //digitalWrite(RedLightControl,LOW);
              //digitalWrite(YellowLightControl,LOW);
              //digitalWrite(GreenLightControl,LOW);
              //minutes = 1;
              //secoundstwo = 1;
              //secoundsone = 1;
              toggle = 0;
			  delay(1200);
            } else {
			  //Serial.println("toggle 0");
              //digitalWrite(RedLightControl,HIGH);
              //digitalWrite(YellowLightControl,HIGH);
              //digitalWrite(GreenLightControl,HIGH);
              //minutes = 8;
              //secoundstwo = 8;
              //secoundsone = 8;
              toggle = 1;
            }
            //int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//0~9,A,b,C,d,E,F
            //int8_t ListDisp[0];
            //tm1637.display(0,4);
            //tm1637.display(1,minutes); 
            //tm1637.display(2,secoundstwo);
            //tm1637.display(3,secoundsone);
            //tm1637.point(POINT_ON);
            delay(1200);
      }
      break;
    default: 
      // if nothing else matches, do the default
      // default is optional
    break;
  }
 
}
      