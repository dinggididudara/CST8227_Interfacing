/*
 * Hold: ON / Release: OFF (No Interrupt)
 * 
 * Discrete LED controlled by push button switch (PBS)
 * in pull-down configuration.
 * 
 * @author Gerald.Hurdle@AlgonquinCollege.com
 */

int pbIn = 15;
int ledOut = 20; //LED_BUILTIN;    // The output LED pin
boolean state = HIGH;

void setup() {
  // put your setup code here, to run once:
  // Set up the digital Pin 15 to an Input and Pin 20 to an Output
  Serial.begin(38400);
  pinMode(pbIn, INPUT_PULLUP);
  pinMode(ledOut, OUTPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  
  state = digitalRead(pbIn);  //Read the state of the button
  Serial.println(state);
  if(state == HIGH){
    digitalWrite(ledOut,LOW);
  }
  else {
    digitalWrite(ledOut, HIGH);
  }
  
}
