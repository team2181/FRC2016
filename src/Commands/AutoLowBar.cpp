// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoLowBar.h"
#include "Commands/AutoDriveCommand.h"
#include "Commands/CommandGroup.h"
#include "Commands/TurnToGyroCommand.h"
#include "Commands/ActuateDartCommand.h"
#include "Commands/GetDown.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
AutoLowBar::AutoLowBar() {
	pos = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
	AddParallel(new GetDown());
	AddParallel(new TurnToGyroCommand(180, 2, 3));
	AddSequential(new AutoDriveCommand(-0.5, 4, 0));
	//Drives forward 50%, for 1 second, no turn
	AddSequential(new AutoDriveCommand(0, 0, 0));
	//Drives forward 0% (stops), instantly times out, no turn
	AddSequential(new TurnToGyroCommand(0, 2, 3));
	//Turns 180 based of Gyro values
	AddSequential(new AutoDriveCommand(0, 0, 0));

 }

