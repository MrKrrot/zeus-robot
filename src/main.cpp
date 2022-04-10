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
  Drivetrain.drive(forward);                       // Va hacia el plato amarillo infinitamente
  checkStop();                                     // Comprobación para detenerse una vez detenga el plato amarillo o cruce el límite
  RightPincer.setTimeout(500, msec);
  RightPincer.spinFor(reverse, 380, degrees);      // Agarra el plato amarillo
  //Drivetrain.setDriveVelocity(50, percent);
  //Drivetrain.setTurnVelocity(50, percent);
  //Drivetrain.setTimeout(3, sec);
  driveTo(reverse, 35);                            // Se regresa con el plato amarillo
  RightArm.spinFor(reverse, 10, degrees);          // Levanta 10 grados el brazo derecho
  turnTo(55);                                      // Gira hacia el plato del centro
  driveTo(forward, 30);                            // Se dirige hacia el plato del centro
  LeftPincer.setTimeout(500, msec); 
  LeftPincer.spinFor(reverse, 300, degrees);       // Agarra el plato del centro
  driveTo(reverse, 20);                            // Se regresa con ambos platos amarillos
  turnTo(90);                                      // Se gira para quedar viendo hacia la derecha
  driveTo(reverse, 20);                            // Se va en reversa
  turnTo(0);                                       // Se queda viendo hacia la base aliada en reversa
  RightPincer.spinFor(forward, 300, degrees); 
  LeftPincer.spinFor(forward, 300, degrees);       // Suelta ambos platos
  Drivetrain.setTimeout(4, sec);
  driveTo(reverse, 30);                            // Se pega contra la pared hacia atrás
  //driveTo(forward, 5);                             // Se va 5 pulgadas hacia enfrente
  turnTo(270);                                     // Se queda viendo de reversa al plato de la plataforma de la base
  BackValve.set(true);                             // Abre la valvula de atrás para que entre el plato
  driveTo(reverse, 20);                            // Se va hacia el plato de la base
  Band.spin(forward);                              // Activar banda para tippings
  driveTo(forward, 10);                            // Alejarse un poco de la plataforma para el bucle
  
  for(int i = 0; i < 3; i++) {                     // Bucle para colocar los tippings
    driveTo(forward, 10);
    driveTo(reverse, 10);
  }
}

void usercontrol(void) {
  
  // Init configs
  changeVelocity(100, 100);
  changeTorque();
  // Control configs
  Control.ButtonRight.pressed(manageBackValve);
  Control.ButtonA.pressed(moveReverseBand);
  Control.ButtonY.pressed(stopBand);

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
