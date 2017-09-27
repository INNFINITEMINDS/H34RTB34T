/*
  This is H34RTB34T.
  D.I.Y. Electrocardiogram.
 
  Biomedical Instrumentation BI and Introduction to Electrical Engineering EE,
  Master's program in Biomedical Engineering BME, University of Bern.
  Roland Bruggmann, 2017.
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up a constant for the tilt switchPin
const int switchPin = 6;
// variable to hold the value of the switchPin
int switchState = 0;
// variable to hold previous value of the switchpin
int prevSwitchState = 0;

// a beats counter
int beatsCounter = 0;
// the beats per minute rate
int bpm = 0;


void setup() {
  // set up the number of columns and rows on the LCD 
  lcd.begin(16, 2);
  
  // set up the switch pin as an input
  pinMode(switchPin,INPUT);
  
  // Print a message to the LCD.
  lcd.print("This is H34RTB34T !");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("D.I.Y. Electrocardiogram.");
}

void loop() {
  // check the status of the switch
  switchState = digitalRead(switchPin);

  // compare the switchState to its previous state
  if (switchState == prevSwitchState) {
      // clean up the screen before printing a new reply
      lcd.clear();
      // Print the bpm to the LCD.
      lcd.print(bpm + " bpm");
      // set the cursor to column 0, line 1
      // line 1 is the second row, since counting begins with 0
      lcd.setCursor(0, 1);
      // print counted beats to the second line
      lcd.print("# beats: " + beatsCounter);
    } else {
      beatsCounter = 0;
      switchState = 0;
      prevSwitchState = 0;
    }
  }

}

