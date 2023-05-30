/* LED Blink, Teensyduino Tutorial #1
   http://www.pjrc.com/teensy/tutorial.html
 
   This example code is in the public domain.
*/

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
const int ledPin = 19;
const int switchPin = 15;
bool state = LOW;

// the setup() method runs once, when the sketch starts

void setup() {
  // initialize the digital pin as an output.
  pinMode(switchPin,INPUT);
  pinMode(ledPin, OUTPUT);
}

// the loop() methor runs over and over again,
// as long as the board has power

void loop() {
  state = digitalRead(switchPin);  //read the state of button
  digitalWrite(ledPin, state);   // set the LED on

  for(int i=0;i<1000;i++){
    delay(500);
  }
}

