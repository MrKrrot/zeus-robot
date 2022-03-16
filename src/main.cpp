/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "functions.h"
#include "autonomous_functions.h"
void pre_auton(void) {

  vexcodeInit();
}

void autonomous(void) {

  initConfig();

  BackValve.set(true);
  driveTo(reverse, 20);
  BackValve.set(false);
  Band.spin(forward);
  Drivetrain.setDriveVelocity(25, pct);
  driveTo(forward, 20);
  
  for(int i = 0; i < 5; i++) {
    
    driveTo(reverse, 15);
    driveTo(forward, 15);
    
    wait(20, msec);
  }
  Band.stop();
  BackValve.set(true);
}

void usercontrol(void) {
  
  // Init configs
  changeVelocity(100, 100);
  changeTorque();
  // Control configs
  Control.ButtonLeft.pressed(manageFrontValve);
  Control.ButtonRight.pressed(manageBackValve);
  Control.ButtonA.pressed(moveReverseBand);
  Control.ButtonY.pressed(stopBand);

  Control.ButtonX.pressed(manageRightValve);

  while (1) {
    // Control functions
    moveLeft();
    moveRight();
    moveBand();
    moveLeftArm();
    moveRightArm();
    moveLeftPincer();
    moveRightPincer();
    
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
