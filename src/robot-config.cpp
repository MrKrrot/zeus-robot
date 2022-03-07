#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Control;
motor LeftFrontWheel1 = motor(PORT11, ratio18_1, false);
motor LeftFrontWheel2 = motor(PORT12, ratio18_1, true);
motor LeftMiddleWheel = motor(PORT15, ratio18_1, false);
motor LeftBackWheel2 = motor(PORT13, ratio18_1, true);
motor LeftBackWheel1 = motor(PORT14, ratio18_1, false);

motor RightFrontWheel1 = motor(PORT10, ratio18_1, true);
motor RightFrontWheel2 = motor(PORT9, ratio18_1, false);
motor RightMiddleWheel = motor(PORT6, ratio18_1, true);
motor RightBackWheel2 = motor(PORT3, ratio18_1, false);
motor RightBackWheel1 = motor(PORT2, ratio18_1, true);

motor LeftArm = motor(PORT1, ratio36_1, true);
motor RightArm = motor(PORT18, ratio36_1, false);

motor Band = motor(PORT5, ratio18_1, false);

motor_group LeftWheels = motor_group(LeftFrontWheel1, LeftFrontWheel2, LeftBackWheel2, LeftBackWheel1);
motor_group RightWheels = motor_group(RightFrontWheel1, RightFrontWheel2, RightBackWheel2, RightBackWheel1);
motor_group Arms = motor_group(LeftArm, RightArm);

digital_out FrontValve = digital_out(Brain.ThreeWirePort.A);
digital_out BackValve = digital_out(Brain.ThreeWirePort.D);

inertial Inertial = inertial(PORT4);
smartdrive Drivetrain = smartdrive(LeftWheels, RightWheels, Inertial);

bool isBandReverse = false, enableBanda = false;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  Inertial.calibrate();
}

void moveLeft(void) {
  if(Control.Axis3.value() < -15 || Control.Axis3.value() > 15) {
    LeftWheels.spin(forward, Control.Axis3.value(), percent);
  } else {
    LeftWheels.stop(hold);
  }
}

void moveRight(void) {
  if(Control.Axis2.value() < -15 || Control.Axis2.value() > 15) {
    RightWheels.spin(forward, Control.Axis2.value(), percent);
  } else {
    RightWheels.stop(hold);
  }
}

void moveArms(void) {
  if(Control.ButtonR1.pressing()) {
    Arms.spin(forward, 100, percent);
  }
  else if(Control.ButtonR2.pressing()) {
    Arms.spin(reverse, 100, percent);
  } else {
    Arms.stop(hold);
  }
}

void turnBandForward() {
  enableBanda = true;
  isBandReverse = true;
}

void turnBandReverse() {
  enableBanda = true;
  isBandReverse = false;
}

void manageBandStop() {
  enableBanda = false;
}

void frontValveEnabled() {
  FrontValve.set(true);
}

void frontValveDisabled() {
  FrontValve.set(false);
}

void backValveEnabled() {
  BackValve.set(true);
}

void backValveDisabled() {
  BackValve.set(false);
}

void moveBand() {

  Control.ButtonB.pressed(turnBandForward);
  Control.ButtonX.pressed(turnBandReverse);
  Control.ButtonA.pressed(manageBandStop);

  if(enableBanda) {
    if(!isBandReverse) {
      Band.spin(forward, 100, percent);
    } else {
      Band.spin(reverse, 100, percent);
    }
  } else {
    Band.stop(hold);
  }
}

void moveValves() {
  Control.ButtonL2.pressed(frontValveDisabled);
  Control.ButtonL1.pressed(frontValveEnabled);
  Control.ButtonDown.pressed(backValveEnabled);
  Control.ButtonUp.pressed(backValveDisabled);
}