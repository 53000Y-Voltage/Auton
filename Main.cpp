//*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    8, 12, 9, 10    
// intake               motor_group   11, 18          
// flywheel             motor         17              
// roller               motor         13              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  intake.stop(brake);
  Drivetrain.setDriveVelocity(80,rpm);
  intake.setVelocity(600,rpm);
  flywheel.spin(reverse,10.3, voltageUnits::volt);
  Drivetrain.setTurnVelocity(5, rpm);
  Drivetrain.driveFor(6.5,inches);
  Drivetrain.turnFor(left,18.5,degrees);
  wait(1.5,seconds);
  intake.setVelocity(600,rpm);
  intake.spinFor(forward,200,degrees);
  wait(1.2,sec);
  intake.spinFor(forward,205,degrees);
  intake.stop();
  Drivetrain.driveFor(reverse,12,inches);
  roller.spin(reverse);
  wait(1,seconds);
  roller.stop();
  Drivetrain.setTurnVelocity(35, percent);
  intake.setVelocity(600,rpm);
  Drivetrain.driveFor(7,inches);
  Drivetrain.turnFor(right,55,degrees);
  Drivetrain.setDriveVelocity(120,rpm);
  Drivetrain.setDriveVelocity(200,rpm);
  Drivetrain.driveFor(forward,115,inches);
  Drivetrain.setDriveVelocity(80,rpm);
  Drivetrain.turnFor(left,135,degrees);
  Drivetrain.turnFor(left,90,degrees);
  Drivetrain.driveFor(-10,inches);
  Drivetrain.turnFor(right,90,degrees);
  intake.setVelocity(600,rpm);
  Drivetrain.driveFor(-15,inches);
  roller.spin(reverse);
  wait(1,seconds);
  roller.stop();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
flywheel.spin(reverse,9, voltageUnits::volt);
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
