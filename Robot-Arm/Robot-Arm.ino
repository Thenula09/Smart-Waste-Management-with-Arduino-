#include <Servo.h>

// Declare servo objects for Base, Shoulder, Elbow, and Gripper
Servo Base;
Servo Shoulder;
Servo Elbow;
Servo Gripper;

void setup() {
  // Attach servos to the respective pins
  Base.attach(17);      // Connect the Base servo motor to pin 9
  Shoulder.attach(16); // Connect the Shoulder servo motor to pin 10
  Elbow.attach(15);    // Connect the Elbow servo motor to pin 11
  Gripper.attach(14);  // Connect the Gripper servo motor to pin 12
}

void loop() {
   for (int i = 130; i <= 130; i++) { 
    Elbow.write(i); // Move Elbow servo back to the previous position
    delay(100);      // Smooth movement with 50ms delay
  }
  delay(5000); 
   // --- Step 2: Shoulder Movement ---
  for (int i = 90; i <= 90; i++) { 
    Shoulder.write(i); // Move Shoulder servo to the next position
    delay(100);         // Smooth movement with 50ms delay
  }
   delay(5000);


 for (int i = 0; i <= 0; i++) { 
    Gripper.write(i); // open Gripper
    delay(100);        // Smooth movement with 50ms delay
  }
  delay(5000);

  // --- Step 1: Base Movement ---
  for (int i = 10; i <= 120; i++) { 
    Base.write(i);  // Move Base servo to the next position
    delay(100);      // Smooth movement with 50ms delay
  }
  delay(5000); // Pause for 3 seconds at 120 degrees

   for (int i = 130; i >= 50; i--) { 
    Elbow.write(i); // Move Elbow servo back to the previous position
    delay(100);      // Smooth movement with 50ms delay
  }
  delay(5000); 

for (int i = 0; i <= 180; i++) { 
    Gripper.write(i); // open Gripper
    delay(100);        // Smooth movement with 50ms delay
  }
  delay(5000);

   // --- Step 2: Shoulder Movement ---
  for (int i = 90; i <= 160; i++) { 
    Shoulder.write(i); // Move Shoulder servo to the next position
    delay(100);         // Smooth movement with 50ms delay
  }
   delay(5000);

   for (int i = 180; i >= 0; i--) { 
    Gripper.write(i); // Close Gripper
    delay(100);        // Smooth movement with 50ms delay
  }
  delay(3000);


 // Move Shoulder
   for (int i = 160; i >= 90; i--) { 
    Shoulder.write(i); // Move Shoulder servo to the next position
    delay(100);         // Smooth movement with 50ms delay
  }
   delay(5000); 

 for (int i = 50; i <= 130; i++) { 
    Elbow.write(i); // Move Elbow servo back to the previous position
    delay(100);      // Smooth movement with 50ms delay
  }
  delay(5000); 


  for (int i = 120; i >= 10; i--) { 
    Base.write(i);  // Move Base servo back to the previous position
    delay(100);      // Smooth movement with 50ms delay
  }
  delay(5000);




  
}