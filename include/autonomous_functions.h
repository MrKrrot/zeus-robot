#include "devices.h"

/* ================= Distance Sensor ================= */

void initConfig(){ 
  //Drivetrain.setRotation(0, degrees);
  Drivetrain.setRotation(0, degrees);
  Drivetrain.setHeading(0, degrees);
  Drivetrain.setDriveVelocity(60, percent);
  Drivetrain.setTurnVelocity(20, percent);
  RightArm.setVelocity(100, percent);
  LeftArm.setVelocity(100, percent);
  RightPincer.setVelocity(100, percent);
  LeftPincer.setVelocity(100, percent);
  Band.setVelocity(100, percent);
  RightPincer.setStopping(hold);
}

void driveTo(directionType direccion, double distancia) {
  Drivetrain.driveFor(direccion, distancia, inches);
}

void driveTo(directionType direccion, double distancia, double velocidad) {
  Drivetrain.driveFor(direccion, distancia, inches, velocidad, rpm);
}

void turnTo(double cantidad) {
  Drivetrain.turnToHeading(cantidad, degrees);
}


void driveDistance(directionType direction, double Inches) {
  bool enableDrive = true;

  while(enableDrive){
    Control.Screen.print(Distance.objectDistance(inches));
    if(direction == forward) {
      Control.Screen.print("Forward");
      if(Distance.objectDistance(inches) < Inches || !Distance.isObjectDetected() || Distance.objectDistance(inches) != 0) {
        
        Drivetrain.drive(forward);
      } else {

        enableDrive = false;
        Drivetrain.stop();
      }
    }

    if(direction == reverse) {
      Control.Screen.print("Reverse");
      if(Distance.objectDistance(inches) > Inches || !Distance.isObjectDetected() || Distance.objectDistance(inches) != 0) {
        Drivetrain.drive(reverse);
      } else {
        enableDrive = false;
        Drivetrain.stop();
      }
    }
  }
}
