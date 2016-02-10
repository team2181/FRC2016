// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::driveTrainmotorRB;
std::shared_ptr<CANTalon> RobotMap::driveTrainmotorRF;
std::shared_ptr<CANTalon> RobotMap::driveTrainmotorLB;
std::shared_ptr<CANTalon> RobotMap::driveTrainmotorLF;
std::shared_ptr<RobotDrive> RobotMap::driveTrainrobotdrive;
std::shared_ptr<CANTalon> RobotMap::launcherdart;
std::shared_ptr<SpeedController> RobotMap::launcherlauncherWheelMotor;
std::shared_ptr<SpeedController> RobotMap::launcherloaderMotor;
std::shared_ptr<DigitalInput> RobotMap::launcherloaderSensor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    driveTrainmotorRB.reset(new CANTalon(4));
    lw->AddActuator("DriveTrain", "motorRB", driveTrainmotorRB);
    
    driveTrainmotorRF.reset(new CANTalon(3));
    lw->AddActuator("DriveTrain", "motorRF", driveTrainmotorRF);
    
    driveTrainmotorLB.reset(new CANTalon(2));
    lw->AddActuator("DriveTrain", "motorLB", driveTrainmotorLB);
    
    driveTrainmotorLF.reset(new CANTalon(1));
    lw->AddActuator("DriveTrain", "motorLF", driveTrainmotorLF);
    
    driveTrainrobotdrive.reset(new RobotDrive(driveTrainmotorLF, driveTrainmotorLB,
              driveTrainmotorRF, driveTrainmotorRB));
    
    driveTrainrobotdrive->SetSafetyEnabled(false);
        driveTrainrobotdrive->SetExpiration(0.1);
        driveTrainrobotdrive->SetSensitivity(0.5);
        driveTrainrobotdrive->SetMaxOutput(1.0);

        driveTrainrobotdrive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
    launcherdart.reset(new CANTalon(5));
    lw->AddActuator("Launcher", "dart", launcherdart);
    
    launcherlauncherWheelMotor.reset(new Talon(0));
    lw->AddActuator("Launcher", "launcherWheelMotor", std::static_pointer_cast<Talon>(launcherlauncherWheelMotor));
    
    launcherloaderMotor.reset(new Talon(1));
    lw->AddActuator("Launcher", "loaderMotor", std::static_pointer_cast<Talon>(launcherloaderMotor));
    
    launcherloaderSensor.reset(new DigitalInput(0));
    lw->AddSensor("Launcher", "loaderSensor", launcherloaderSensor);
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}