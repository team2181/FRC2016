// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoOne.h"
#include "AutoDriveCommand.h"
#include "Commands/CommandGroup.h"
#include "TurnToGyroCommand.h"
#include "ActuateDartCommand.h"
#include "GetDown.h"

AutoOne::AutoOne(double angle, double time) {
	mAngle = angle;
	mTime = time;
	AddSequential(new TurnToGyroCommand(mAngle, 2, 2));
	//Spins robot around backwards based off gyro values
	AddSequential(new AutoDriveCommand(0, 0, 0));
	//Drives forward 50%, for 4 second, no turn
	AddSequential(new AutoDriveCommand(1, mTime, 0));
	//Drives forward 0% (stops), instantly times out, no turn
	AddSequential(new AutoDriveCommand(0, 0, 0));
	//stops robot
	AddSequential(new TurnToGyroCommand(0, 2, 2));
	//turns robots to 0 degrees
	AddSequential(new AutoDriveCommand(0, 0, 0));
	//stops the robot
 }

