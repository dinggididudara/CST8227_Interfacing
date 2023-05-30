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
}


void loop() {
  // put your main code here, to run repeatedly:

  // TODO: see below for each of the demos
  //DEMO #1 - CYCLE RGB (Digital)
  digitalWrite(redLED, HIGH);
  delay(MY_DELAY);
  digitalWrite(redLED, LOW);

  digitalWrite(greenLED, true);
  delay(MY_DELAY);
  digitalWrite(greenLED, false);

  digitalWrite(blueLED, 1);
  delay(MY_DELAY);
  digitalWrite(blueLED, 0);
  
} //end loop()
