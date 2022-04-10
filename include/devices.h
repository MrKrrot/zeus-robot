#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;

/* =================== Global Instance =================== */
brain Brain;
controller Control;
competition Competition;

/* ================== Left Base Motors ================== */
motor LeftFrontWheel1 = motor(PORT11, ratio18_1, false);
motor LeftFrontWheel2 = motor(PORT12, ratio18_1, true);
motor LeftMiddleWheel = motor(PORT15, ratio18_1, false);
motor LeftBackWheel2 = motor(PORT13, ratio18_1, true);
motor LeftBackWheel1 = motor(PORT14, ratio18_1, false);

/* ================= Right Base Motors ================= */
motor RightFrontWheel1 = motor(PORT10, ratio18_1, true);
motor RightFrontWheel2 = motor(PORT9, ratio18_1, false);
motor RightMiddleWheel = motor(PORT6, ratio18_1, true);
motor RightBackWheel2 = motor(PORT3, ratio18_1, false);
motor RightBackWheel1 = motor(PORT2, ratio18_1, true);

/* ===================== Left Arms ===================== */
motor LeftUpArm = motor(PORT17, ratio36_1, true);
motor LeftDownArm = motor(PORT16, ratio36_1, true);
motor LeftPincer = motor(PORT7, ratio36_1, false);

/* =================== Right Motors =================== */
motor RightUpArm = motor(PORT20, ratio36_1, false);
motor RightDownArm = motor(PORT1, ratio36_1, false);
motor RightPincer = motor(PORT19, ratio36_1, true);

/* ======================= Band ======================= */
motor Band = motor(PORT5, ratio18_1, false);

/* =================== Motor Groups =================== */
motor_group LeftWheels = motor_group(LeftFrontWheel1, LeftFrontWheel2, LeftMiddleWheel, LeftBackWheel2, LeftBackWheel1);
motor_group RightWheels = motor_group(RightFrontWheel1, RightFrontWheel2, RightMiddleWheel, RightBackWheel2, RightBackWheel1);
motor_group LeftArm = motor_group(LeftUpArm, LeftDownArm);
motor_group RightArm = motor_group(RightUpArm, RightDownArm);

/* ====================== Valves ====================== */
digital_out BackValve = digital_out(Brain.ThreeWirePort.D);

/* ====================== Sensors ====================== */
bumper RightBumper = bumper(Brain.ThreeWirePort.A);
inertial Inertial = inertial(PORT4);
distance Distance = distance(PORT8);
smartdrive Drivetrain = smartdrive(LeftWheels, RightWheels, Inertial, 259.33, 393.7, 355.6, inches, 0.666666);

/* ================= Variables ================= */
bool isBandReverse = false, enableBand = false;
bool enableBackValve = false;