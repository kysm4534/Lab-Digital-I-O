//Kyle Smith 
//Digital I/O Part 2
//A lot of this code was created by utilizing the NEO-PIXEL example code and repurposing certain functions and syntax

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

//pulled from example code, a clever way to keep the code efficient
#define BUTTON_PIN1   7

#define BUTTON_PIN2   14

#define PIXEL_PIN    15  // Digital IO pin connected to the NEO-PIXEL

#define PIXEL_COUNT 5  // Number of NEO-PIXELS

// declaring a NEO-PIXEL strip object:
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

//setting the boolean state and reset our LED color
boolean oldState1 = HIGH;
boolean oldState2 = HIGH;



void setup() {
  pinMode(BUTTON_PIN1, INPUT_PULLUP);
  pinMode(BUTTON_PIN2, INPUT_PULLUP);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'

}

void loop() {
  // get current button states
  boolean newState1 = digitalRead(BUTTON_PIN1);
  boolean newState2 = digitalRead(BUTTON_PIN2);

  // Check if button1 state changed from high to low (button1 press).
  if((newState1 == LOW) && (oldState1 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState1 = digitalRead(BUTTON_PIN1);
    if(newState1 == LOW) {     // Yes, still low
      colorWipe(strip.Color(255,   0,   0), 50);    // Red
    }  
  }
  
  // Check if button2 state changed from high to low (button2 press).
  if((newState2 == LOW) && (oldState2 == HIGH)) {
    // Short delay to debounce button.
    delay(20);
    // Check if button is still low after debounce.
    newState2 = digitalRead(BUTTON_PIN2);
    if(newState2 == LOW) {      // Yes, still low
        colorWipe(strip.Color(  0,   0, 255), 50);    // Blue
    }
  }

  //reseting button and therefor NEO-PIXEL states
  oldState1 = newState1;
  oldState2 = newState2;
}

 //simple colorWipe animation pulled from example code
 void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait); 
  }
}
