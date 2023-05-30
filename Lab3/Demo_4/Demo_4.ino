// Lab03 - PWM and ISRs
// Gerald.Hurdle@AlgonquinCollege.com

#define MY_DELAY 800

//These Teensy pins are PWM
int greenLED = 18;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 19;//2.3V, ~111ohm
int redLED = 23;//1.6V, ~189ohm

// Demo #3 and Demo #4
int pushButton = 10;

// Demo #4
volatile int counter = 0;

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
  // Demo #4
//  README: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  attachInterrupt( pushButton, cycleRGB, FALLING );
}




void randomLights() {
  analogWrite(redLED, random(256));
  analogWrite(greenLED, random(256));
  analogWrite(blueLED, random(256));
  delay(MY_DELAY);
}


//DEMO #4 - COLOUR CYCLING WITH AN INTERRUPT SERVICE ROUTINE (ISR)
void loop() {
  randomLights();
} //end loop() - Demo #4

void cycleRGB() {
  int onPin, offPin_1, offPin_2;

  counter++;
  //FIXME: no I/O in ISR; only here for teaching purposes
  Serial.print( "cycleRBG() ISR\tcounter: ");
  Serial.println( counter );

  int beacon = counter % 3;
  
  if ( beacon == 0 ) {
    onPin = redLED;
    offPin_1 = greenLED;
    offPin_2 = blueLED;
  } else if ( beacon == 1 ) {
    onPin = greenLED;
    offPin_1 = redLED;
    offPin_2 = blueLED;
  } else { // must be Blue
    onPin = blueLED;
    offPin_1 = redLED;
    offPin_2 = greenLED;
  }
  
  analogWrite(onPin, HIGH);
  analogWrite(offPin_1, LOW);
  analogWrite(offPin_2, LOW);
  delay(200);
}
