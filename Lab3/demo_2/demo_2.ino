// Lab03 - PWM and ISRs
// Gerald.Hurdle@AlgonquinCollege.com

#define MY_DELAY 800

//These Teensy pins are PWM
int greenLED = 18;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 19;//2.3V, ~111ohm
int redLED = 23;//1.6V, ~189ohm

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(blueLED,  OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED,   OUTPUT);
    //use this open circuited pin for a seed to the random number generator
  pinMode(A0, INPUT);
  randomSeed(analogRead(A0));
}


void loop() {
  // put your main code here, to run repeatedly:

  //DEMO #2 - RANDOMLY SET EACH OF: R,G,B (PWM)
  analogWrite(redLED, random(256));
  analogWrite(greenLED, random(256));
  analogWrite(blueLED, random(256));
//  analogWrite(redLED, 0);
//  analogWrite(greenLED, 200);
//  analogWrite(blueLED, 0);
  delay(MY_DELAY);
  
} //end loop()
