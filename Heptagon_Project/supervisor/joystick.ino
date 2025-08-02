#include <ezButton.h>
#include <SoftwareSerial.h>

// XBEE...........
#define rxPin 2
#define txPin 3



#define VRX_PIN  A4 // Arduino pin connected to VRX pin
#define VRY_PIN  A3 // Arduino pin connected to VRY pin
#define SW_PIN   A2  // Arduino pin connected to SW  pin

ezButton button(SW_PIN);
ezButton leverSwitch(10);//left switch
ezButton leverSwitch2(12);//right switch
//ezButton leverSwitch2(10);//right switch

// XBEE...................
SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);

enum Mode {
  MODE_0,
  MODE_1,
  MODE_2,
  MODE_3
};

Mode currentMode = MODE_0;
int switch1PressCount = 0;
int switch2PressCount = 0;
bool switch1PressedLast = false;
bool switch2PressedLast = false;
int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
int bValue = 0; // To store value of the button

void setup() {
  Serial.begin(9600) ;
  button.setDebounceTime(10); // set debounce time to 50 milliseconds
  leverSwitch.setDebounceTime(10);
  leverSwitch2.setDebounceTime(10);

  // XBEE +........
//  Serial.begin(19200);
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 xbee.begin(9600);
}

void loop() {
  button.loop(); // MUST call the loop() function first

  // read analog X and Y analog values
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  // Read the button value
  bValue = button.getState();

  if (button.isPressed()) {
        xbee.print('S');

    Serial.println("The button is pressed");
    // TODO do something here
  }

  if (button.isReleased()) {
    Serial.println("The button is released");
    // TODO do something here
  }

  // print data to Serial Monitor on Arduino IDE
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.print(yValue);
  Serial.print(" : button = ");
  Serial.println(bValue);
  delay(200);


  leverSwitch.loop(); // MUST call the loop() function first
  leverSwitch2.loop();

   // Check if lever switch 1 is pressed
  if (leverSwitch.isPressed() && !switch1PressedLast) {
    switch1PressCount++;
    switch1PressedLast = true;
    if (switch1PressCount == 1) {
      currentMode = MODE_0;
    } else if (switch1PressCount == 2) {
      currentMode = MODE_1;
    }
  } else if (!leverSwitch.isPressed()) {
    switch1PressedLast = false;
  }

  // Check if lever switch 2 is pressed
  if (leverSwitch2.isPressed() && !switch2PressedLast) {
    switch2PressCount++;
    switch2PressedLast = true;
    if (switch2PressCount == 1) {
      currentMode = MODE_2;
    } else if (switch2PressCount == 2) {
      currentMode = MODE_3;
    }
  } else if (!leverSwitch2.isPressed()) {
    switch2PressedLast = false;
  }

  switch (currentMode) {
    case MODE_0:
      // Mode 1 behavior
      // Implement behavior specific to Mode 1
      xbee.print('0');
      Serial.println('0');
      break;
    case MODE_1:
      // Mode 2 behavior
      // Implement behavior specific to Mode 2
      xbee.print('1');
      Serial.println('1');
      break;
    case MODE_2:
      // Mode 3 behavior
      // Implement behavior specific to Mode 3
      xbee.print('2');;
      Serial.println('2');
      break;
    case MODE_3:
      // Mode 4 behavior
      // Implement behavior specific to Mode 4
      xbee.print('3');
      Serial.println('3');
      break;
      
    default:
      break;
  }

    
    if(leverSwitch.isPressed()){
    Serial.println("The lever switch: UNTOUCHED left*** -> TOUCHED");
    }

  if(leverSwitch.isReleased())
    Serial.println("The lever switch: TOUCHED left*** -> UNTOUCHED");

  int state = leverSwitch.getState();
  if(state == HIGH)
    Serial.println("The lever switch left***: UNTOUCHED");
  else
    Serial.println("The lever switch left***: TOUCHED");


  if(leverSwitch2.isPressed())
    Serial.println("The lever switch2 right***: UNTOUCHED -> TOUCHED");

  if(leverSwitch2.isReleased())
    Serial.println("The lever switch2 right***: TOUCHED -> UNTOUCHED");

  int state1 = leverSwitch2.getState();
  if(state1 == HIGH)
    Serial.println("The lever switch2 right***: UNTOUCHED");
  else
    Serial.println("The lever switch2 right***: TOUCHED");
    delay(500);

  if(xValue>1000){
    xbee.print('L');
    Serial.println('L');}
  else if(yValue>1000){
    xbee.print('U');
    Serial.println('U');}
  else if(xValue<6){
    xbee.print('R');
    Serial.println('R');}
  else if(yValue<6){
    xbee.print('D');
 Serial.println('D');}
// Serial.println('B'); //
}
