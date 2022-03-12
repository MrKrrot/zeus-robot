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
  driveTo(forward, 10, 40); // Ir plato base
  RightPincer.spinFor(reverse, 200, degrees); // Agarrar plato
  RightArm.spinFor(reverse, 150, degrees); // Levantar brazo
  driveTo(forward, 5, 40);
  turnTo(270); 
  driveTo(forward, 18, 40);
  turnTo(0); // Acomodarse para ver el plato amarillo
  driveTo(forward, 25, 50); // Ir hacia plato amarillo
  LeftPincer.setTimeout(2, sec);
  LeftPincer.spinFor(reverse, 200, degrees); // Agarrar plato amarillo
  LeftArm.spinFor(reverse, 150, degrees);
  driveTo(forward, 45, 80); // Ir con ambos platos a la otra base
  
  RightPincer.setTimeout(2, sec);
  RightPincer.spinFor(forward, 150, degrees);
  LeftPincer.setTimeout(2, sec);
  LeftPincer.spinFor(forward, 150, degrees); // Soltar brazos
  driveTo(reverse, 15, 70);
  turnTo(270); // Girar a la derecha para pegarse a la pared
  Drivetrain.setTimeout(5, sec);
  driveTo(reverse, 90, 100);
  driveTo(forward, 55, 70);
  turnTo(0);
  Drivetrain.setTimeout(10, sec);
  driveTo(reverse, 80);
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

    //moveRightPincer();
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
