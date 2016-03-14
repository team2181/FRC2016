// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/DistanceOverTimeCG.h"
#include <Commands/Scheduler.h>
#include "Robot.h"
#include <RobotBase.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <memory>
//See issue Autonomous
#include "Commands/AutoDriveCommand.h"
#include "Commands/AutoAim.h"
#include "Commands/AutoLowBar.h"
#include "Commands/AutoRoughTerrain.h"
#include "Commands/AutoMoat.h"
#include "Commands/AutoRamparts.h"
#include "Commands/AutoRockWall.h"
#include "Commands/AutoPortipulis.h"
#include "Commands/AutoChivel.h"
#include "Commands/AutoOne.h"
#include "Commands/AutoShoot.h"
#include "Commands/AutoAssembler.h"
#include "Commands/AutonomousPlaceholder.h"
#include <string>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<Launcher> Robot::launcher;
std::shared_ptr<Ramp> Robot::ramp;
std::shared_ptr<VISION> Robot::vISION;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveTrain.reset(new DriveTrain());
    launcher.reset(new Launcher());
    ramp.reset(new Ramp());
    vISION.reset(new VISION());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// START DO NOT TOUCH THIS
	oi.reset(new OI());
	// END DO NOT TOUCH THIS

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	//autonomousCommand.reset(new AutonomousPlaceholder());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS

	//CameraServer::GetInstance()->SetQuality(50);
	//CameraServer::GetInstance()->StartAutomaticCapture("cam0");

	// START FRESHMAN DO NOT TOUCH THIS
	DoTCommand = new DistanceOverTimeCG();
	driveTrain->CalibrateGyro();
	chooserChooser = new SendableChooser();
	defenseChooser = new SendableChooser();
	shooterChooser = new SendableChooser();

	chooserChooser->AddDefault("Position One", new AutoOne(90, 2));
	chooserChooser->AddObject("Position Two", new AutoOne(90, 1.5));
	chooserChooser->AddObject("Position Three", new AutoOne(90, 1));
	chooserChooser->AddObject("Position Four", new AutoOne(-90, 1));
	chooserChooser->AddObject("Position Five", new AutoOne(-90, 1.5));
	chooserChooser->AddObject("No Movement", new AutonomousPlaceholder());

	defenseChooser->AddDefault("LowBar", new AutoLowBar());
	defenseChooser->AddObject("Rock Wall", new AutoRockWall());
	defenseChooser->AddObject("Rough Terrain", new AutoRoughTerrain());
	defenseChooser->AddObject("Moat", new AutoMoat());
	defenseChooser->AddObject("Porticulis", new AutoPortipulis());
	defenseChooser->AddObject("Chivel De Frise", new AutoChivel());
	defenseChooser->AddObject("Ramparts", new AutoRamparts());
	defenseChooser->AddObject("No Movement", new AutonomousPlaceholder());

	shooterChooser->AddDefault("Shoot Ball", new AutoShoot());
	shooterChooser->AddObject("No Shoot Ball", new AutonomousPlaceholder());



	SmartDashboard::PutData("Field Location", chooserChooser);
	SmartDashboard::PutData("Defense on Field", defenseChooser);
	SmartDashboard::PutData("Shoot the Ball", shooterChooser);
	//END FRESHMAN DO NOT TOUCH THIS
  }
/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {

	/*	autonomousCommand.reset((Command*)((SendableChooser*)
				chooserChooser->GetSelected())->GetSelected());
		if (autonomousCommand.get() != nullptr)
			autonomousCommand->Start();
	*/
//	autoDefense = (Command *) defenseChooser->GetSelected();
//	if(autoDefense != NULL) autoDefense->Start();
//	autoPosition = (Command *) chooserChooser->GetSelected();
//	if(autoPosition != NULL) autoPosition->Start();
//	autoShoot = (Command *) shooterChooser->GetSelected();
//	if(autoShoot != NULL) autoShoot->Start();

	autonomousCommand.reset(new AutoAssembler(
			 (Command *) chooserChooser->GetSelected(),
			 (Command *) defenseChooser->GetSelected(),
			 (Command *) shooterChooser->GetSelected()));
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

