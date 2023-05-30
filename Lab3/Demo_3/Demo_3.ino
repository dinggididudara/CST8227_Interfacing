// Lab03 - PWM and ISRs
// Gerald.Hurdle@AlgonquinCollege.com

#define MY_DELAY 800

//These Teensy pins are PWM
int greenLED = 18;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 19;//2.3V, ~111ohm
int redLED = 23;//1.6V, ~189ohm

// Demo #3 and Demo #4
int pushButton = 10;
// Demo #3
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(blueLED,  OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED,   OUTPUT);


  // Demo #3 and Demo #4
  pinMode(pushButton, INPUT);
  pinMode(A0, INPUT);
  randomSeed(analogRead(A0));
  }

//DEMO #3 - COLOUR CYCLING WITH A PUSH-BUTTON SWITCH (PBS)
void loop() {
  randomLights();

  // first press of pushbutton
  if ( digitalRead(pushButton) == LOW ) {
    counter++;
    if ( counter > 10 ) counter = 1;  // reset counter after 10 presses
    Serial.print("Press (freeze).... counter is: ");
    Serial.println( counter );
    delay(1000);  // freeze lights of LED
  }

  while ( counter > 0 && counter < 10 ) {
    if( digitalRead(pushButton) == LOW ) {
      counter++;
      Serial.print("Another Press (random)... counter is: ");
      Serial.println( counter );
      randomLights();
    }   
  }
} //end loop() - Demo #3

void randomLights() {
  analogWrite(redLED, random(256));
  analogWrite(greenLED, random(256));
  analogWrite(blueLED, random(256));
  delay(MY_DELAY);
}
