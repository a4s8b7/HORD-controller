// TEST For "Profile switch" currently set to read BCD switch 
// once during setup; move code as noted below for repeated reads

// BCD Switch inputs attached to pins D2-5, common to Ground 
// (use internal pullups)

// Define data bit pins
    int      profile_BIT1_1  = 26;
    int      profile_BIT1_2  = 25;
    int      profile_BIT1_4  = 24;
    int      profile_BIT1_8  = 23;
    
    int      profile_BIT2_1  = 31;
    int      profile_BIT2_2  = 30;
    int      profile_BIT2_4  = 29;
    int      profile_BIT2_8  = 28;
    
    int      profile_BIT3_1  = 36;
    int      profile_BIT3_2  = 35;
    int      profile_BIT3_4  = 34;
    int      profile_BIT3_8  = 33;

// Define profile variable, set to 0

    int      profile = 0;
    int      profile2 = 0;
    int      profile3 = 0;

void setup() {
// initialize serial communication at 9600 bits per second (only needed
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
// to make read on each pass move all below this to "loop",  
// uncomment profile reset
}

  void loop() {
    // read the input pins: NOTE - CLOSED switch (binary 1) returns "0"
  profile = 0;
  profile2 = 0;
  profile3 = 0;
  
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

if (  val_profile_BIT1_1 ==  0)    { profile = profile + 1; }
if (  val_profile_BIT1_2 ==  0)    { profile = profile + 2; }
if (  val_profile_BIT1_4 ==  0)    { profile = profile + 4; }
if (  val_profile_BIT1_8 ==  0)    { profile = profile + 8; }

if (  val_profile_BIT2_1 ==  0)    { profile2 = profile2 + 1; }
if (  val_profile_BIT2_2 ==  0)    { profile2 = profile2 + 2; }
if (  val_profile_BIT2_4 ==  0)    { profile2 = profile2 + 4; }
if (  val_profile_BIT2_8 ==  0)    { profile2 = profile2 + 8; }

if (  val_profile_BIT3_1 ==  0)    { profile3 = profile3 + 1; }
if (  val_profile_BIT3_2 ==  0)    { profile3 = profile3 + 2; }
if (  val_profile_BIT3_4 ==  0)    { profile3 = profile3 + 4; }
if (  val_profile_BIT3_8 ==  0)    { profile3 = profile3 + 8; }

// DEBUG - prints out the state of the switch bits and profile value

    //Serial.print("[profile_BIT1: ");
    //Serial.print(val_profile_BIT1_1);
    //Serial.print("] ");
    //Serial.print("[profile_BIT2: ");
    //Serial.print(val_profile_BIT1_2);
    //Serial.print("] ");
    //Serial.print("[profile_BIT4: ");
    //Serial.print(val_profile_BIT1_4);
    //Serial.print("] ");
    //Serial.print("[profile_BIT8: ");
    //Serial.print(val_profile_BIT1_8);
    //Serial.print("] ");
    Serial.print("[profile1: ");
    Serial.print(profile);
    Serial.print("] ");
    Serial.print("[profile2: ");
    Serial.print(profile2);
    Serial.print("] ");
    Serial.print("[profile3: ");
    Serial.println(profile3); 

// delay in between reads for stability, uncomment if in loop
//  delay(1000); 
}
