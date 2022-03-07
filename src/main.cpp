/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
int timesPressed = 0;

void pre_auton(void) {
  vexcodeInit();

}

void autonomous(void) {

}

void addCounter() {
  timesPressed++;
}

void usercontrol(void) {
  Control.ButtonLeft.pressed(addCounter);
  while (1) {
    moveLeft();
    moveRight();
    moveArms();
    moveBand();
    Control.Screen.print(timesPressed);
    Control.Screen.newLine();
    //thread frontThread = thread(moveFrontValve);
    //thread backThread = thread(moveBackValve);
    moveValves();
    wait(20, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
