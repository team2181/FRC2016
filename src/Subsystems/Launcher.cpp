// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Launcher.h"
#include "../Commands/AutoAim.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/LauncherDefaultCommand.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Launcher::Launcher() : Subsystem("Launcher") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    dart = RobotMap::launcherdart;
    launcherWheelMotor = RobotMap::launcherlauncherWheelMotor;
    loaderMotor = RobotMap::launcherloaderMotor;
    loaderSensor = RobotMap::launcherloaderSensor;
    ultrasonic = RobotMap::launcherUltrasonic;
	

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Launcher::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new LauncherDefaultCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Launcher::setLauncherMotor(double s)
{
	launcherWheelMotor->Set(s);
}

void Launcher::setLoaderMotor(double s)
{
	loaderMotor->Set(s);
}

bool Launcher::readArmSensor()
{
	SmartDashboard::PutBoolean("Arm Sensor Triggered:", loaderSensor->Get());
	return loaderMotor->Get();
}


void Launcher::setDart(double v)
{
	SmartDashboard::PutNumber("Dart Position", dart->GetAnalogIn());
	int p = dart->GetAnalogIn();
	if(v > 0 && p >= 316)
	{
		dart->Set(v);
	}
	else
	{
		if(v < 0 && p <= 966)
		{
			dart->Set(v);
		}
		else
		{
			dart->Set(0);
		}
	}
}

void Launcher::printUltrasonic()
{
	double u = ultrasonic->GetVoltage();
	double target = AutoAim::GetTargetValue;
	double pos = dart->GetAnalogIn();
	SmartDashboard::PutNumber("Ultrasonic Voltage", u);
	SmartDashboard::PutNumber("Dart Position Target Value", target);
	SmartDashboard::PutNumber("Correction to Target", target - pos);
	SmartDashboard::PutBoolean("On Target", abs(target - pos) <= 15);
	delete u, target, pos;
}
