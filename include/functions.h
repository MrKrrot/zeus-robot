#pragma once
#include "devices.h"
/* ================= Initial Configuration Functions ================= */
void vexcodeInit(void) {

  Inertial.calibrate();
}

void changeVelocity(int v, int t) {

  Drivetrain.setDriveVelocity(v, percent);
  Drivetrain.setTurnVelocity(t, percent);
  LeftArm.setVelocity(100, percent);
  RightArm.setVelocity(100, percent);
  Band.setVelocity(100, percent);
}

void changeTorque() {

  LeftWheels.setMaxTorque(100, percent);
  RightWheels.setMaxTorque(100, percent);
  Band.setMaxTorque(100, percent);
  LeftArm.setMaxTorque(100, pct);
  RightArm.setMaxTorque(100, pct);
}

/* ================= Band Functions ================= */
void moveReverseBand() {

  enableBand = true;
  isBandReverse = !isBandReverse;
}

void stopBand() {

  enableBand = !enableBand;
}

void moveBand() {
  if(enableBand) {

    if(!isBandReverse) {

      Band.spin(forward, 100, percent);
    } else {

      Band.spin(reverse, 100, percent);
    }
  } else {

    Band.stop(hold);
  }
}

/* ================= Valve Functions ================= */
void manageBackValve() {

  enableBackValve = !enableBackValve;
  BackValve.set(enableBackValve);
}

/* ================= Base Functions ================= */

void moveLeft(void) {
  if(Control.Axis3.value() < -20 || Control.Axis3.value() > 20) {

    LeftWheels.spin(forward, Control.Axis3.value(), percent);
  } else {

    LeftWheels.stop(hold);
  }
}

void moveRight(void) {
  if(Control.Axis2.value() < -20 || Control.Axis2.value() > 20) {

    RightWheels.spin(forward, Control.Axis2.value(), percent);
  } else {

    RightWheels.stop(hold);
  }
}

/* ================= Arms Functions ================= */
void moveLeftArm(void) {
  if(Control.ButtonL2.pressing()) {

    LeftArm.spin(forward);
  }
  else if(Control.ButtonL1.pressing()) {

    LeftArm.spin(reverse);
  } else {

    LeftArm.stop(hold);
  }
}

void moveRightArm(void) {
  if(Control.ButtonR2.pressing()) {

    RightArm.spin(forward, 100, percent);
  }
  else if(Control.ButtonR1.pressing()) {

    RightArm.spin(reverse, 100, percent);
  } else {

    RightArm.stop(hold);
  }
}

/* ================= Pincers Functions ================= */
void moveLeftPincer() {
  if(Control.ButtonUp.pressing()){

    LeftPincer.spin(forward, 100, percent);
  } else if(Control.ButtonDown.pressing()) {

    LeftPincer.spin(reverse, 100, percent);
  } else {

    LeftPincer.stop(hold);
  }
}

void moveRightPincer() {
  if(Control.ButtonX.pressing()){

    RightPincer.spin(forward, 100, percent);
  } else if(Control.ButtonB.pressing()) {

    RightPincer.spin(reverse, 100, percent);
  } else {
    
    RightPincer.stop(hold);
  }
}