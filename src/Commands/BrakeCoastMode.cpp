#include "BrakeCoastMode.h"
#include <CANTalon.h>
#include "../RobotMap.h"
#include <CANSpeedController.h>

BrakeCoastMode::BrakeCoastMode(bool brakeMode)
{
	m_brakeMode = brakeMode;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void BrakeCoastMode::Initialize()
{
	if(m_brakeMode)
	{
		RobotMap::driveTrainmotorRB->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
		RobotMap::driveTrainmotorRF->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
		RobotMap::driveTrainmotorLB->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
		RobotMap::driveTrainmotorLF->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
	}
	else
	{
		RobotMap::driveTrainmotorRB->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
		RobotMap::driveTrainmotorRF->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
		RobotMap::driveTrainmotorLB->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
		RobotMap::driveTrainmotorLF->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
	}
}

// Called repeatedly when this Command is scheduled to run
void BrakeCoastMode::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool BrakeCoastMode::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void BrakeCoastMode::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BrakeCoastMode::Interrupted()
{

}
