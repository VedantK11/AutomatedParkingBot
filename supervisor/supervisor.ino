#include "alphabot_drivers.h"
#include "line_follower.h"

// XBEE................
#include <SoftwareSerial.h>
#define rxPin 8
#define txPin 9


#define NUM_SENSORS 5
int sensorValues[NUM_SENSORS];
Line_follower__main_out _res;
Line_follower__main_mem _test;
int nodeValue = 1;
int parkLeftFlag = 0;
int parkRightFlag = 0;
unsigned long startTime;
int parkedFlag = 0;
int parkingDetectedFlag = 0;
int nodecounterFlag = 0;
int counterFlag = 0;
int firstNodeflag = 0;
int SecondNodeflag = 0;
int testNodeCount = 0;
int ThirdNodeflag = 0;
int blackEntry = 0;
int dontDo = 0;
int count = 0;
int arenaNumber = 0;

// unsigned long currentTime;

int IRSensor1 = 4;  // connect ir sensor module to Arduino pin 9
int IRSensor2 = 7;
int timer = 0;
bool extremeLeft = true;
bool extremeRight = true;
int zFlag = 0;

//XBEE...............
SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);


void setup() {
  // chmod 777 /dev/ttyUSB0
  init_devices();
  forward();
  // Serial.begin(115200);
  Serial.println("Serial Working");  // Test to check if serial is working or not
  // startTime = millis();


  pinMode(IRSensor1, INPUT);  // IR Sensor pin INPUT
  pinMode(IRSensor2, INPUT);  // IR Sensor pin INPUT

// XBEE..........
 pinMode(rxPin, INPUT);
 pinMode(txPin, OUTPUT);
 
 xbee.begin(9600);
 Serial.begin(9600);
 Serial.println("Starting XBee Comunication");

  // pinMode(LED, OUTPUT); // LED Pin Output
}

void parkingLeft() {
  backward();
  delay(500);
  back_right();
  delay(1900);
  backward();
  delay(80);
}

void parkingRight() {

  backward();
  delay(500);
  back_left();
  delay(1800);
  backward();
  delay(1000);
}


void loop() {

  int sensorStatus1 = digitalRead(IRSensor1);  // Set the GPIO as Input
  int sensorStatus2 = digitalRead(IRSensor2);  // Set the GPIO as Input
  unsigned long currentTime = millis();

  //XBEE....

 char someChar = xbee.read();
 Serial.println(someChar);
delay(500);

 if(someChar=='L'){

  SetSpeed(20,50);
  forward_left();
    delay(100);

 }
 else if(someChar=='R'){
  SetSpeed(50,20);
  forward_right();
    delay(100);

 }
 else if(someChar=='U'){
  SetSpeed(50,50);
  forward();
  delay(100);
 }
 else if(someChar=='D'){
  SetSpeed(50,50);
  backward();
  delay(100);

 }
 else if(someChar=='S'){
  SetSpeed(0,0);
    delay(100);

 }
 //Serial.println(rec);




//   AnalogRead(sensorValues);

//   Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], &_res, &_test);


//   long leftS = _res.v_l;
//   long rightS = _res.v_r;
//   //------------------------------------------Z code for arena 0==================================================================================================================================
//   if (_res.dir != 7 and sensorValues[0] < 400 and sensorValues[1] < 400 and sensorValues[2] < 400 and sensorValues[3] < 400 and sensorValues[4] < 400 and sensorValues[0] > 100 and sensorValues[1] > 100 and arenaNumber == 0) {
//     if (zFlag == 0) {
//       beep_on();
//       SetSpeed(70, 120);
//       left();
//       delay(100);
//       // delay(10000);
//       beep_off();
//       SetSpeed(50, 50);
//       forward();
//       delay(280);
//       right();
//       SetSpeed(50, 70);
//       delay(200);
//       forward();
//       zFlag = 1;
//     }
//   }

//   //------------------------------------------Z code for arena 2==================================================================================================================================
//   if (_res.dir != 7 and sensorValues[0] < 400 and sensorValues[1] < 400 and sensorValues[2] < 400 and sensorValues[3] < 400 and sensorValues[4] < 400 and sensorValues[0] > 100 and sensorValues[1] > 100 and arenaNumber == 2) {
//     if (zFlag == 0) {
//       beep_on();
//       SetSpeed(70, 120);
//       left();
//       delay(100);
//       // delay(10000);
//       beep_off();
//       SetSpeed(50, 50);
//       forward();
//       delay(280);
//       right();
//       SetSpeed(50, 70);
//       delay(200);
//       forward();
//       zFlag = 1;
//     }
//   }
//   //=====================================================================================================================================================================
//   //----------------------z code for arena  3
//   if (_res.dir != 7 and sensorValues[0] < 400 and sensorValues[1] < 400 and sensorValues[2] < 400 and sensorValues[3] < 400 and sensorValues[4] < 400 and sensorValues[0] > 100 and sensorValues[1] > 100 and arenaNumber == 3) {
//     if (zFlag == 0) {
//       beep_on();
//       SetSpeed(70, 120);
//       beep_off();
//       right();
//       delay(200);
//       SetSpeed(50, 50);
//       forward();
//       delay(280);
//       left();
//       SetSpeed(50, 70);
//       delay(200);
//       //   SetSpeed(0,0);
//       // delay(10000);
//       forward();
//       zFlag = 1;
//     }
//   }

//   //=====================================================================================================================================================================
//   //----------------------z code for arena  1
//   if (_res.dir != 7 and sensorValues[0] < 400 and sensorValues[1] < 400 and sensorValues[2] < 400 and sensorValues[3] < 400 and sensorValues[4] < 400 and sensorValues[0] > 100 and sensorValues[1] > 100 and arenaNumber == 1) {
//     if (zFlag == 0) {
//       beep_on();
//       SetSpeed(70, 120);
//       right();
//       delay(100);
//       SetSpeed(50, 50);
//       beep_off();
//       forward();
//       delay(280);
//       left();
//       SetSpeed(50, 70);
//       delay(200);
//       //   SetSpeed(0,0);
//       // delay(10000);
//       forward();
//       zFlag = 1;
//     }
//   }


//   for (int i = 0; i < NUM_SENSORS; i++) {
//     Serial.print(sensorValues[i]);

//     Serial.print(" ");
//   }
//   Serial.println();
//   //--------------------------------------------------------------------------------------------------------------------------------------------
//   if (_res.dir == 7) {

//     //------------------------------------------------------arena Number :0.........................................................................
//     if (arenaNumber == 0) {
//       if (blackEntry == 0) {
//         SetSpeed(70, 100);
//         right();
//         delay(200);
//         forward();
//         delay(10);
//         // delay(10000);
//         blackEntry = 1;
//       }

//       //-------------node 1---------------------
//       if (_res.nc == 1) {
//         if (firstNodeflag == 0) {

//           beep_on();
//           SetSpeed(83, 57);
//           right();
//           delay(50);
//           beep_off();
//           forward();
//           delay(20);
//           forward();
//           SetSpeed(20, 20);
//           delay(10);
//           firstNodeflag = 1;
//         }
//       }
//       //------------node 2-------------------------
//       if (_res.nc == 2) {
//         if (firstNodeflag == 1) {
//           beep_on();
//           forward();
//           delay(40);
//           right();
//           delay(140);
//           beep_off();
//           forward();
//           firstNodeflag = 0;
//         }
//       }

//       //--------node 3.............................
//       if (_res.nc == 3) {
//         if (SecondNodeflag == 0) {

//           SetSpeed(57, 83);
//           // SetSpeed(leftS+20,rightS+20);
//           beep_on();
//           left();
//           delay(200);
//           beep_off();
//           forward();
//           SecondNodeflag = 1;
//         }
//       }
//       //------------node 4-------------------------------
//       if (_res.nc == 4) {
//         if (ThirdNodeflag == 0) {
//           // SetSpeed(leftS+50,rightS+50);
//           SetSpeed(57, 83);
//           beep_on();
//           left();
//           delay(200);
//           beep_off();
//           forward();
//           ThirdNodeflag = 1;
//         }
//       }
//     }


//     //------------------------------------------------------arena nuber 2---------------------------------------------------------------------------------------
//     if (arenaNumber == 2) {
//       if (blackEntry == 0) {
//         SetSpeed(150, 70);
//         right();
//         delay(150);
//         forward();
//         // SetSpeed(0,0);
//         // delay(10000);
//         // delay(50);
//         blackEntry = 1;
//       }

//       //-------------node 1---------------------
//       if (_res.nc == 1) {
//         if (firstNodeflag == 0) {
//           SetSpeed(83, 57);
//           forward();
//           delay(50);
//           beep_on();
//           right();
//           delay(100);
//           beep_off();
//           forward();
//           // SetSpeed(0,0);
//           // delay(10000);
//           firstNodeflag = 1;
//         }
//       }
//       //------------node 2-------------------------
//       if (_res.nc == 2) {
//         if (firstNodeflag == 1) {

//           beep_on();
//           SetSpeed(57, 83);
//           left();
//           delay(150);
//           beep_off();
//           forward();
//           firstNodeflag = 0;
//         }
//       }

//       //--------node 3.............................
//       if (_res.nc == 3) {
//         if (SecondNodeflag == 0) {

//           SetSpeed(83, 57);
//           // SetSpeed(leftS+20,rightS+20);
//           beep_on();
//           right();
//           delay(200);
//           beep_off();
//           forward();
//           SecondNodeflag = 1;
//         }
//       }
//       //------------node 4-------------------------------
//       if (_res.nc == 4) {
//         if (ThirdNodeflag == 0) {
//           // SetSpeed(leftS+50,rightS+50);
//           SetSpeed(83, 57);
//           beep_on();
//           right();
//           delay(200);
//           beep_off();
//           forward();
//           ThirdNodeflag = 1;
//         }
//       }
//     }
//     //-----------------------------------------------------arena 1------------------------------------------------------------------------------------------

//     if (arenaNumber == 1) {

//       if (blackEntry == 0) {
//         SetSpeed(220, 80);
//         right();
//         delay(150);
//         forward();
//         // SetSpeed(0,0);
//         // delay(10000);
//         // delay(50);
//         blackEntry = 1;
//       }

//       //-------------node 1---------------------
//       if (_res.nc == 1) {
//         if (firstNodeflag == 0) {
//           SetSpeed(83, 57);
//           // forward();
//           // delay(50);
//           beep_on();
//           left();
//           delay(200);
//           beep_off();
//           // SetSpeed(0,0);
//           //   delay(2000);
//           forward();
//           // SetSpeed(0,0);
//           // delay(10000);
//           firstNodeflag = 1;
//         }
//       }
//       //------------node 2-------------------------
//       if (_res.nc == 2) {
//         // if(firstNodeflag==1)
//         // {

//         // beep_on();
//         // SetSpeed(57,83);
//         // left();
//         // delay(150);
//         // beep_off();
//         // forward();
//         // firstNodeflag=0;
//         // }
//         if (firstNodeflag == 1) {
//           beep_on();
//           forward();
//           delay(40);
//           right();
//           delay(140);
//           beep_off();
//           forward();
//           firstNodeflag = 0;
//         }
//       }

//       //--------node 3.............................
//       if (_res.nc == 3) {
//         //  if(SecondNodeflag==0)
//         // {

//         //   SetSpeed(83,57);
//         // // SetSpeed(leftS+20,rightS+20);
//         // beep_on();
//         // right();
//         // delay(200);
//         // beep_off();
//         // forward();
//         // SecondNodeflag=1;
//         // }

//         if (SecondNodeflag == 0) {

//           SetSpeed(57, 83);
//           // SetSpeed(leftS+20,rightS+20);
//           beep_on();
//           left();
//           delay(200);
//           beep_off();
//           forward();
//           SecondNodeflag = 1;
//         }
//       }
//       //------------node 4-------------------------------
//       if (_res.nc == 4) {
//         //    if(ThirdNodeflag==0)
//         //   {
//         //   // SetSpeed(leftS+50,rightS+50);
//         //   SetSpeed(83,57);
//         //   beep_on();
//         //   right();
//         //   delay(150);
//         //   beep_off();
//         //   forward();
//         //  ThirdNodeflag=1;
//         //   }

//         if (ThirdNodeflag == 0) {
//           // SetSpeed(leftS+50,rightS+50);
//           SetSpeed(57, 83);
//           beep_on();
//           left();
//           delay(200);
//           beep_off();
//           forward();
//           ThirdNodeflag = 1;
//         }
//       }
//     }
//   }









//   //------------------------------------------------------arena 3-------------------------------------------------------------------------------------------
//   if (arenaNumber == 3) {

//     if (blackEntry == 0) {
//       SetSpeed(220, 80);
//       right();
//       delay(150);
//       forward();
//       // SetSpeed(0,0);
//       // delay(10000);
//       // delay(50);
//       blackEntry = 1;
//     }

//     //-------------node 1---------------------
//     if (_res.nc == 1) {
//       if (firstNodeflag == 0) {
//         SetSpeed(83, 57);
//         // forward();
//         // delay(50);
//         beep_on();
//         left();
//         delay(200);
//         beep_off();
//         // SetSpeed(0,0);
//         //   delay(2000);
//         forward();
//         // SetSpeed(0,0);
//         // delay(10000);
//         firstNodeflag = 1;
//       }
//     }
//     //------------node 2-------------------------
//     if (_res.nc == 2) {
//       if (firstNodeflag == 1) {

//         beep_on();
//         SetSpeed(57, 83);
//         left();
//         delay(150);
//         beep_off();
//         forward();
//         firstNodeflag = 0;
//       }
//     }

//     //--------node 3.............................
//     if (_res.nc == 3) {
//       if (SecondNodeflag == 0) {

//         SetSpeed(83, 57);
//         // SetSpeed(leftS+20,rightS+20);
//         beep_on();
//         right();
//         delay(200);
//         beep_off();
//         forward();
//         SecondNodeflag = 1;
//       }
//     }
//     //------------node 4-------------------------------
//     if (_res.nc == 4) {
//       if (ThirdNodeflag == 0) {
//         // SetSpeed(leftS+50,rightS+50);
//         SetSpeed(83, 57);
//         beep_on();
//         right();
//         delay(150);
//         beep_off();
//         forward();
//         ThirdNodeflag = 1;
//       }
//     }
//   }
//   //----------------------------------------------------------------------------------------------------------------------------------------------------
//   if (_res.dir == 7) {
//     if (blackEntry == 0) {
//       SetSpeed(70, 100);
//       right();
//       delay(200);
//       forward();
//       delay(50);
//       blackEntry = 1;
//     }
//   }
//   // if (_res.nc == 1) {

//   //   if (firstNodeflag == 0) {

//   //     beep_on();
//   //     right();
//   //     delay(50);
//   //     beep_off();
//   //     forward();
//   //     firstNodeflag = 1;
      
//   //   }

//   // }
//   // if (_res.nc == 2) {

//   //   if (firstNodeflag == 1) {

//   //     beep_on();
//   //     right();
//   //     delay(140);
//   //     beep_off();
//   //     forward();
//   //     firstNodeflag = 0;
//   //   }
//   // }
//   // //-----------------------------------------------------------------------------------------------------------
//   // if (_res.nc == 3) {
//   //   if (SecondNodeflag == 0) {

//   //     SetSpeed(57, 83);
//   //     // SetSpeed(leftS+20,rightS+20);
//   //     beep_on();
//   //     left();
//   //     delay(200);
//   //     beep_off();
//   //     forward();
//   //     SecondNodeflag = 1;
//   //   }
//   // }
//   // if (_res.nc == 4) {
//   //   if (ThirdNodeflag == 0) {
//   //     // SetSpeed(leftS+50,rightS+50);
//   //     SetSpeed(57, 83);
//   //     beep_on();
//   //     left();
//   //     delay(200);
//   //     beep_off();
//   //     forward();
//   //     ThirdNodeflag = 1;
//   //   }
//   // }

//   Serial.print(_res.nc);
//   Serial.println();





//   //-------------------------------------------------------------------------------------------------------




//   SetSpeed(leftS, rightS);


//   //----------------------------------------parking Logic--------------------------------------------------------------------------------------------------------------------------------------
//   if (_res.nc == 5) {
//     if (parkingDetectedFlag == 0) {
//       startTime = millis();
//       beep_on();
//       delay(100);
//       beep_off();
//       parkingDetectedFlag = 1;
//     }
//     if (sensorStatus1 == 0)  // Check if the pin high or not
//     {
//       parkLeftFlag = 1;
//       Serial.println("Sensor 1 Motion detected");
//     }

//     if (sensorStatus2 == 0) {
//       //else turn on the onboard LED
//       Serial.println("Sensor 2 Motion Detected");  // print Motion Ended! on the serial monitor window
//       parkRightFlag = 1;
//     }

//     if (currentTime > startTime + 4275) {
//       if (parkLeftFlag != 1) {
//         Serial.println("Parking Left");
//         parkingLeft();
//         parkedFlag = 1;
//       } else if (parkRightFlag != 1) {
//         Serial.println("Parking Right");
//         parkingRight();
//         parkedFlag = 1;
//       }
//       //  beep_on();
//       //   delay(100);
//       //   beep_off();
//       startTime = millis();
//       parkLeftFlag = 0;
//       parkRightFlag = 0;
//     } else {
//       Serial.println("Parking full");
//     }
//   }
//   //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// }





// // #include "alphabot_drivers.h"
// // #include "line_follower.h"

// // // XBEE................
// // #include <SoftwareSerial.h>
// // #define rxPin 8
// // #define txPin 9

// // #define NUM_SENSORS 5
// // int sensorValues[NUM_SENSORS];
// // Line_follower__main_out _res;
// // Line_follower__main_mem _test;
// // int nodeValue = 1;
// // int parkLeftFlag = 0;
// // int parkRightFlag = 0;
// // unsigned long startTime;
// // int parkedFlag = 0;
// // int parkingDetectedFlag = 0;
// // int nodecounterFlag = 0;
// // int counterFlag = 0;
// // int firstNodeflag = 0;
// // int SecondNodeflag = 0;
// // int testNodeCount = 0;
// // int ThirdNodeflag = 0;
// // int blackEntry = 0;
// // int dontDo = 0;
// // int count = 0;
// // int arenaNumber = 8;

// // // unsigned long currentTime;

// // int IRSensor1 = 9;  // connect ir sensor module to Arduino pin 9
// // int IRSensor2 = 7;
// // int timer = 0;
// // bool extremeLeft = true;
// // bool extremeRight = true;
// // int zFlag = 0;


// // //XBEE...............
// // SoftwareSerial xbee =  SoftwareSerial(rxPin, txPin);


// // void setup() {
// //   // chmod 777 /dev/ttyUSB0
// //   init_devices();
// //   forward();
// //   Serial.begin(115200);
// //   Serial.println("Serial Working");  // Test to check if serial is working or not
// //   // startTime = millis();


// //   pinMode(IRSensor1, INPUT);  // IR Sensor pin INPUT
// //   pinMode(IRSensor2, INPUT);  // IR Sensor pin INPUT

// //   // XBEE..........
// //  pinMode(rxPin, INPUT);
// //  pinMode(txPin, OUTPUT);
 
// //  xbee.begin(9600);
// //  Serial.begin(19200);
// //  Serial.println("Starting XBee Comunication");




// //   // pinMode(LED, OUTPUT); // LED Pin Output
// // }

// // void parkingLeft() {
// //   backward();
// //   delay(500);
// //   back_right();
// //   delay(1900);
// //   backward();
// //   delay(80);
// // }

// // void parkingRight() {

// //   backward();
// //   delay(500);
// //   back_left();
// //   delay(1800);
// //   backward();
// //   delay(1000);
// // }


// // void loop() {

// //   int sensorStatus1 = digitalRead(IRSensor1);  // Set the GPIO as Input
// //   int sensorStatus2 = digitalRead(IRSensor2);  // Set the GPIO as Input
// //   unsigned long currentTime = millis();

// //     //XBEE....

// //  char someChar = xbee.read();
// //  Serial.println(someChar);
// // //  delay(1000);
// //  if(someChar=='L'){
// //   SetSpeed(20,50);
// //   left();
// //  }
// //  else if(someChar=='R'){
// //   SetSpeed(50,20);
// //   right();
// //  }
// //  else if(someChar=='U'){
// //   SetSpeed(20,20);
// //   forward();
// //  }
// //  else if(someChar=='D'){
// //   SetSpeed(20,20);
// //   backward();
// //  }
// //  else if(someChar=='S'){
// //   SetSpeed(0,0);
// //  }




// //   AnalogRead(sensorValues);

// //   Line_follower__main_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4], &_res, &_test);


// //   long leftS = _res.v_l;
// //   long rightS = _res.v_r;
// //   //------------------------------------------Z code for arena 0==================================================================================================================================
// //   if (_res.dir != 7 and sensorValues[0] < 400 and sensorValues[1] < 400 and sensorValues[2] < 400 and sensorValues[3] < 400 and sensorValues[4] < 400 and sensorValues[0] > 100 and sensorValues[1] > 100 and arenaNumber == 0) {
// //     if (zFlag == 0) {
// //       beep_on();
// //       SetSpeed(70, 120);
// //       left();
// //       delay(100);
// //       // delay(10000);
// //       beep_off();
// //       SetSpeed(50, 50);
// //       forward();
// //       delay(280);
// //       right();
// //       SetSpeed(50, 70);
// //       delay(200);
// //       forward();
// //       zFlag = 1;
// //     }
// //   }

// //   //------------------------------------------Z code for arena 2==================================================================================================================================
// //   if (_res.dir != 7 and sensorValues[0] < 400 and sensorValues[1] < 400 and sensorValues[2] < 400 and sensorValues[3] < 400 and sensorValues[4] < 400 and sensorValues[0] > 100 and sensorValues[1] > 100 and arenaNumber == 2) {
// //     if (zFlag == 0) {
// //       beep_on();
// //       SetSpeed(70, 120);
// //       left();
// //       delay(100);
// //       // delay(10000);
// //       beep_off();
// //       SetSpeed(50, 50);
// //       forward();
// //       delay(280);
// //       right();
// //       SetSpeed(50, 70);
// //       delay(200);
// //       forward();
// //       zFlag = 1;
// //     }
// //   }
// //   //=====================================================================================================================================================================
// //   //----------------------z code for arena  3
// //   if (_res.dir != 7 and sensorValues[0] < 400 and sensorValues[1] < 400 and sensorValues[2] < 400 and sensorValues[3] < 400 and sensorValues[4] < 400 and sensorValues[0] > 100 and sensorValues[1] > 100 and arenaNumber == 3) {
// //     if (zFlag == 0) {
// //       beep_on();
// //       SetSpeed(70, 120);
// //       beep_off();
// //       right();
// //       delay(200);
// //       SetSpeed(50, 50);
// //       forward();
// //       delay(280);
// //       left();
// //       SetSpeed(50, 70);
// //       delay(200);
// //       //   SetSpeed(0,0);
// //       // delay(10000);
// //       forward();
// //       zFlag = 1;
// //     }
// //   }

// //   //=====================================================================================================================================================================
// //   //----------------------z code for arena  1
// //   if (_res.dir != 7 and sensorValues[0] < 400 and sensorValues[1] < 400 and sensorValues[2] < 400 and sensorValues[3] < 400 and sensorValues[4] < 400 and sensorValues[0] > 100 and sensorValues[1] > 100 and arenaNumber == 1) {
// //     if (zFlag == 0) {
// //       beep_on();
// //       SetSpeed(70, 120);
// //       right();
// //       delay(100);
// //       SetSpeed(50, 50);
// //       beep_off();
// //       forward();
// //       delay(280);
// //       left();
// //       SetSpeed(50, 70);
// //       delay(200);
// //       //   SetSpeed(0,0);
// //       // delay(10000);
// //       forward();
// //       zFlag = 1;
// //     }
// //   }


// //   for (int i = 0; i < NUM_SENSORS; i++) {
// //     Serial.print(sensorValues[i]);

// //     Serial.print(" ");
// //   }
// //   Serial.println();
// //   //--------------------------------------------------------------------------------------------------------------------------------------------
// //   if (_res.dir == 7) {

// //     //------------------------------------------------------arena Number :0.........................................................................
// //     if (arenaNumber == 0) {
// //       if (blackEntry == 0) {
// //         SetSpeed(70, 100);
// //         right();
// //         delay(200);
// //         forward();
// //         delay(10);
// //         // delay(10000);
// //         blackEntry = 1;
// //       }

// //       //-------------node 1---------------------
// //       if (_res.nc == 1) {
// //         if (firstNodeflag == 0) {

// //           beep_on();
// //           SetSpeed(83, 57);
// //           right();
// //           delay(50);
// //           beep_off();
// //           forward();
// //           delay(20);
// //           forward();
// //           SetSpeed(20, 20);
// //           delay(10);
// //           firstNodeflag = 1;
// //         }
// //       }
// //       //------------node 2-------------------------
// //       if (_res.nc == 2) {
// //         if (firstNodeflag == 1) {
// //           beep_on();
// //           forward();
// //           delay(40);
// //           right();
// //           delay(140);
// //           beep_off();
// //           forward();
// //           firstNodeflag = 0;
// //         }
// //       }

// //       //--------node 3.............................
// //       if (_res.nc == 3) {
// //         if (SecondNodeflag == 0) {

// //           SetSpeed(57, 83);
// //           // SetSpeed(leftS+20,rightS+20);
// //           beep_on();
// //           left();
// //           delay(200);
// //           beep_off();
// //           forward();
// //           SecondNodeflag = 1;
// //         }
// //       }
// //       //------------node 4-------------------------------
// //       if (_res.nc == 4) {
// //         if (ThirdNodeflag == 0) {
// //           // SetSpeed(leftS+50,rightS+50);
// //           SetSpeed(57, 83);
// //           beep_on();
// //           left();
// //           delay(200);
// //           beep_off();
// //           forward();
// //           ThirdNodeflag = 1;
// //         }
// //       }
// //     }


// //     //------------------------------------------------------arena nuber 2---------------------------------------------------------------------------------------
// //     if (arenaNumber == 2) {
// //       if (blackEntry == 0) {
// //         SetSpeed(150, 70);
// //         right();
// //         delay(150);
// //         forward();
// //         // SetSpeed(0,0);
// //         // delay(10000);
// //         // delay(50);
// //         blackEntry = 1;
// //       }

// //       //-------------node 1---------------------
// //       if (_res.nc == 1) {
// //         if (firstNodeflag == 0) {
// //           SetSpeed(83, 57);
// //           forward();
// //           delay(50);
// //           beep_on();
// //           right();
// //           delay(100);
// //           beep_off();
// //           forward();
// //           // SetSpeed(0,0);
// //           // delay(10000);
// //           firstNodeflag = 1;
// //         }
// //       }
// //       //------------node 2-------------------------
// //       if (_res.nc == 2) {
// //         if (firstNodeflag == 1) {

// //           beep_on();
// //           SetSpeed(57, 83);
// //           left();
// //           delay(150);
// //           beep_off();
// //           forward();
// //           firstNodeflag = 0;
// //         }
// //       }

// //       //--------node 3.............................
// //       if (_res.nc == 3) {
// //         if (SecondNodeflag == 0) {

// //           SetSpeed(83, 57);
// //           // SetSpeed(leftS+20,rightS+20);
// //           beep_on();
// //           right();
// //           delay(200);
// //           beep_off();
// //           forward();
// //           SecondNodeflag = 1;
// //         }
// //       }
// //       //------------node 4-------------------------------
// //       if (_res.nc == 4) {
// //         if (ThirdNodeflag == 0) {
// //           // SetSpeed(leftS+50,rightS+50);
// //           SetSpeed(83, 57);
// //           beep_on();
// //           right();
// //           delay(200);
// //           beep_off();
// //           forward();
// //           ThirdNodeflag = 1;
// //         }
// //       }
// //     }
// //     //-----------------------------------------------------arena 1------------------------------------------------------------------------------------------

// //     if (arenaNumber == 1) {

// //       if (blackEntry == 0) {
// //         SetSpeed(220, 80);
// //         right();
// //         delay(150);
// //         forward();
// //         // SetSpeed(0,0);
// //         // delay(10000);
// //         // delay(50);
// //         blackEntry = 1;
// //       }

// //       //-------------node 1---------------------
// //       if (_res.nc == 1) {
// //         if (firstNodeflag == 0) {
// //           SetSpeed(83, 57);
// //           // forward();
// //           // delay(50);
// //           beep_on();
// //           left();
// //           delay(200);
// //           beep_off();
// //           // SetSpeed(0,0);
// //           //   delay(2000);
// //           forward();
// //           // SetSpeed(0,0);
// //           // delay(10000);
// //           firstNodeflag = 1;
// //         }
// //       }
// //       //------------node 2-------------------------
// //       if (_res.nc == 2) {
// //         // if(firstNodeflag==1)
// //         // {

// //         // beep_on();
// //         // SetSpeed(57,83);
// //         // left();
// //         // delay(150);
// //         // beep_off();
// //         // forward();
// //         // firstNodeflag=0;
// //         // }
// //         if (firstNodeflag == 1) {
// //           beep_on();
// //           forward();
// //           delay(40);
// //           right();
// //           delay(140);
// //           beep_off();
// //           forward();
// //           firstNodeflag = 0;
// //         }
// //       }

// //       //--------node 3.............................
// //       if (_res.nc == 3) {
// //         //  if(SecondNodeflag==0)
// //         // {

// //         //   SetSpeed(83,57);
// //         // // SetSpeed(leftS+20,rightS+20);
// //         // beep_on();
// //         // right();
// //         // delay(200);
// //         // beep_off();
// //         // forward();
// //         // SecondNodeflag=1;
// //         // }

// //         if (SecondNodeflag == 0) {

// //           SetSpeed(57, 83);
// //           // SetSpeed(leftS+20,rightS+20);
// //           beep_on();
// //           left();
// //           delay(200);
// //           beep_off();
// //           forward();
// //           SecondNodeflag = 1;
// //         }
// //       }
// //       //------------node 4-------------------------------
// //       if (_res.nc == 4) {
// //         //    if(ThirdNodeflag==0)
// //         //   {
// //         //   // SetSpeed(leftS+50,rightS+50);
// //         //   SetSpeed(83,57);
// //         //   beep_on();
// //         //   right();
// //         //   delay(150);
// //         //   beep_off();
// //         //   forward();
// //         //  ThirdNodeflag=1;
// //         //   }

// //         if (ThirdNodeflag == 0) {
// //           // SetSpeed(leftS+50,rightS+50);
// //           SetSpeed(57, 83);
// //           beep_on();
// //           left();
// //           delay(200);
// //           beep_off();
// //           forward();
// //           ThirdNodeflag = 1;
// //         }
// //       }
// //     }
// //   }









// //   //------------------------------------------------------arena 3-------------------------------------------------------------------------------------------
// //   if (arenaNumber == 3) {

// //     if (blackEntry == 0) {
// //       SetSpeed(220, 80);
// //       right();
// //       delay(150);
// //       forward();
// //       // SetSpeed(0,0);
// //       // delay(10000);
// //       // delay(50);
// //       blackEntry = 1;
// //     }

// //     //-------------node 1---------------------
// //     if (_res.nc == 1) {
// //       if (firstNodeflag == 0) {
// //         SetSpeed(83, 57);
// //         // forward();
// //         // delay(50);
// //         beep_on();
// //         left();
// //         delay(200);
// //         beep_off();
// //         // SetSpeed(0,0);
// //         //   delay(2000);
// //         forward();
// //         // SetSpeed(0,0);
// //         // delay(10000);
// //         firstNodeflag = 1;
// //       }
// //     }
// //     //------------node 2-------------------------
// //     if (_res.nc == 2) {
// //       if (firstNodeflag == 1) {

// //         beep_on();
// //         SetSpeed(57, 83);
// //         left();
// //         delay(150);
// //         beep_off();
// //         forward();
// //         firstNodeflag = 0;
// //       }
// //     }

// //     //--------node 3.............................
// //     if (_res.nc == 3) {
// //       if (SecondNodeflag == 0) {

// //         SetSpeed(83, 57);
// //         // SetSpeed(leftS+20,rightS+20);
// //         beep_on();
// //         right();
// //         delay(200);
// //         beep_off();
// //         forward();
// //         SecondNodeflag = 1;
// //       }
// //     }
// //     //------------node 4-------------------------------
// //     if (_res.nc == 4) {
// //       if (ThirdNodeflag == 0) {
// //         // SetSpeed(leftS+50,rightS+50);
// //         SetSpeed(83, 57);
// //         beep_on();
// //         right();
// //         delay(150);
// //         beep_off();
// //         forward();
// //         ThirdNodeflag = 1;
// //       }
// //     }
// //   }
// //   //----------------------------------------------------------------------------------------------------------------------------------------------------
// //   // if (_res.dir == 7) {
// //   //   if (blackEntry == 0) {
// //   //     SetSpeed(70, 100);
// //   //     right();
// //   //     delay(200);
// //   //     forward();
// //   //     delay(50);
// //   //     blackEntry = 1;
// //   //   }
// //   // }
// //   // if (_res.nc == 1) {

// //   //   if (firstNodeflag == 0) {

// //   //     beep_on();
// //   //     right();
// //   //     delay(50);
// //   //     beep_off();
// //   //     forward();
// //   //     firstNodeflag = 1;
      
// //   //   }

// //   // }
// //   // if (_res.nc == 2) {

// //   //   if (firstNodeflag == 1) {

// //   //     beep_on();
// //   //     right();
// //   //     delay(140);
// //   //     beep_off();
// //   //     forward();
// //   //     firstNodeflag = 0;
// //   //   }
// //   // }
// //   // //-----------------------------------------------------------------------------------------------------------
// //   // if (_res.nc == 3) {
// //   //   if (SecondNodeflag == 0) {

// //   //     SetSpeed(57, 83);
// //   //     // SetSpeed(leftS+20,rightS+20);
// //   //     beep_on();
// //   //     left();
// //   //     delay(200);
// //   //     beep_off();
// //   //     forward();
// //   //     SecondNodeflag = 1;
// //   //   }
// //   // }
// //   // if (_res.nc == 4) {
// //   //   if (ThirdNodeflag == 0) {
// //   //     // SetSpeed(leftS+50,rightS+50);
// //   //     SetSpeed(57, 83);
// //   //     beep_on();
// //   //     left();
// //   //     delay(200);
// //   //     beep_off();
// //   //     forward();
// //   //     ThirdNodeflag = 1;
// //   //   }
// //   // }

// //   Serial.print(_res.nc);
// //   Serial.println();





// //   //-------------------------------------------------------------------------------------------------------



// // if(parkingDetectedFlag==0)
// //   SetSpeed(leftS, rightS);
// //   else
// //     SetSpeed(50,50);


// //   //----------------------------------------parking Logic--------------------------------------------------------------------------------------------------------------------------------------
  
// //   if (_res.nc == 1 and _res.dir==7)
// //    {
// //     if (parkingDetectedFlag == 0) 
// //     {
// //       SetSpeed(20,20);
// //       forward();
// //       startTime = millis();
// //       beep_on();
// //       delay(50);
// //       beep_off();
// //       parkingDetectedFlag = 1;
// //     }

// //     if (sensorStatus1 == 0)  // Check if the pin high or not
// //     {
// //       parkLeftFlag = 1;
// //       Serial.println("Sensor 1 Motion detected");
// //     }

// //     if (sensorStatus2 == 0) {
// //       //else turn on the onboard LED
// //       Serial.println("Sensor 2 Motion Detected");  // print Motion Ended! on the serial monitor window
// //       parkRightFlag = 1;
// //     }

// //     if (currentTime > startTime + 4275) {
// //       if (parkLeftFlag != 1) {
// //         Serial.println("Parking Left");
// //         parkingLeft();
// //         parkedFlag = 1;
// //       } else if (parkRightFlag != 1) {
// //         Serial.println("Parking Right");
// //         parkingRight();
// //         parkedFlag = 1;
// //       }
// //       //  beep_on();
// //       //   delay(100);
// //       //   beep_off();
// //       startTime = millis();
// //       parkLeftFlag = 0;
// //       parkRightFlag = 0;
// //     } else {
// //       Serial.println("Parking full");
// //     }
// //   }
// //   //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
}
