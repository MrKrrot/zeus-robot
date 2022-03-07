#pragma once
using namespace vex;

extern brain Brain;
extern controller Control;
// Left Wheels Motors
extern motor LeftFrontWheel1;
extern motor LeftFrontWheel2;
extern motor LeftBackWheel1;
extern motor LeftBackWheel2;

// Right Wheels Motors
extern motor RightFrontWheel1;
extern motor RightFrontWheel2;
extern motor RightBackWheel1;
extern motor RightBackWheel2;

// Arms
extern motor LeftArm;
extern motor RightArm;

// Band
extern motor Band;

// Motor groups
extern motor_group LeftWheels;
extern motor_group RightWheels;
extern motor_group Arms;

// Sensors and other devices
extern digital_out FrontValve;
extern digital_out BackValve;

extern inertial Inertial;
extern smartdrive Drivetrain;

extern bool isBandReverse;
extern bool enableBanda;
extern bool enableFrontValve;
extern bool enableBackValve;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);

void moveLeft(void);
void moveRight(void);
void moveArms(void);
void moveBand(void);
void moveValves(void);