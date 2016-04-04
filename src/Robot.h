// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousPlaceholder.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Launcher.h"
#include "Subsystems/Ramp.h"
#include "Subsystems/VISION.h"
#include <string>

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "OI.h"

class Robot : public IterativeRobot {
	private:
	std::shared_ptr<CANTalon> motorRB;
	std::shared_ptr<CANTalon> motorRF;
	std::shared_ptr<CANTalon> motorLB;
	std::shared_ptr<CANTalon> motorLF;
	std::shared_ptr<RobotDrive> robotdrive;
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    static std::shared_ptr<DriveTrain> driveTrain;
    static std::shared_ptr<Launcher> launcher;
    static std::shared_ptr<Ramp> ramp;
    static std::shared_ptr<VISION> vISION;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

private:
	SendableChooser *chooserChooser;
	SendableChooser *defenseChooser;
	SendableChooser *shooterChooser;
	SendableChooser *nomoveChooser;

	Command *DoTCommand;
	Command* autoDefense;
	Command* autoPosition;
	Command* autoShoot;

};
#endif
