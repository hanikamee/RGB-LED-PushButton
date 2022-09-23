// This project will change which LED is illuminated every time the button is toggled

// Constant Values
const int buttonPin = 2;
const int redLed = 9;
const int greenLed = 10;
const int blueLed = 11;


// Changeable variables
int colorState = 0;
int buttonState;
int lastButtonState = LOW;


// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50; // the debounce time; increase if the output flickers


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);
  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
  
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
      
        if (colorState == 0){
          colorState = 1;
        } else if (colorState == 1){
          colorState = 2;
        } else{
          colorState = 0;
        }
      }
         
    }  
  }

    // Determining which LED will be eluminated based on its colorstate
    if (colorState == 0){
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(greenLed, LOW);
    }
    else if (colorState == 1){
     digitalWrite(redLed, LOW);
     digitalWrite(blueLed, LOW);
     digitalWrite(greenLed, HIGH);
  }else{
     digitalWrite(redLed, LOW);
     digitalWrite(blueLed, HIGH);
     digitalWrite(greenLed, LOW);
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

}
