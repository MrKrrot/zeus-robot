#include "devices.h"

/* ================= Distance Sensor ================= */
/**
 * Set up the robot configuration. Velocity, Drivetrain, torque, arms and pincers
 */
void initConfig(){ 
  Drivetrain.setRotation(0, degrees);
  Drivetrain.setDriveVelocity(100, percent);
  Drivetrain.setTurnVelocity(80, percent);
  RightArm.setVelocity(100, percent);
  LeftArm.setVelocity(100, percent);
  RightPincer.setVelocity(100, percent);
  LeftPincer.setVelocity(100, percent);
  Band.setVelocity(100, percent);
  RightPincer.setStopping(hold);
  RightWheels.resetRotation();
  LeftWheels.resetRotation();
}

void driveTo(directionType direccion, double distancia) {
  Drivetrain.driveFor(direccion, distancia, inches);
}

void driveTo(directionType direccion, double distancia, double velocidad) {
  Drivetrain.driveFor(direccion, distancia, inches, velocidad, rpm);
}

void turnTo(double grados) {
  Drivetrain.turnToHeading(grados, degrees);
}

void checkStop() {
  while(true) {
    if(RightBumper.pressing() || RightWheels.rotation(degrees) > 900 || Distance.objectDistance(mm) > 1160) {
      Drivetrain.stop();
      break;
    }
  }
}