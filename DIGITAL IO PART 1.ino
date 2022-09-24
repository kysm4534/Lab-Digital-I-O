//Kyle Smith 
//Digital I/O Part 1

//a lot of this code is directly taken from the "button example" and altered to be for 2 buttons rather than just one input output

const int buttonPin1 = 7;     // the number of the pushbutton pin
const int ledPin1 =  4;      // the number of the LED pin
const int buttonPin2 = 14 ;     // the number of the pushbutton pin
const int ledPin2 =  19;      // the number of the LED pin

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);

  // initialize the LED pin as an output:
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin2, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin1, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin1, LOW);
  }

  if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin2, LOW);
  }

  if (buttonState2 == HIGH && buttonState1 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);
    delay(500); 
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, HIGH);
    delay(500);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);
    delay(500); 
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, HIGH);
    delay(500);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);
  } else {
    // turn LED off:
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, LOW);
  }
}
