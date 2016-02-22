// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ActuateDartCommand.h"
#include "Commands/ActuateLauncherWheelCommand.h"
#include "Commands/ActuateRampCommand.h"
#include "Commands/AutoDriveCommand.h"
#include "Commands/AutoLaunchCommand.h"
#include "Commands/AutonomousPlaceholder.h"
#include "Commands/DistanceOverTimeCG.h"
#include "Commands/DriveTrainCommand.h"
#include "Commands/LaunchCommand.h"
#include "Commands/LauncherDefaultCommand.h"
#include "Commands/RampDefaultCommand.h"
#include "Commands/TurnToGyroCommand.h"
#include "Commands/VisionDefaultCommand.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutoAim.h"

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    opJoystick.reset(new Joystick(1));
    
    lowerRamp.reset(new JoystickButton(opJoystick.get(), 7));
    lowerRamp->WhileHeld(new ActuateRampCommand(false));
    launch.reset(new JoystickButton(opJoystick.get(), 1));
    launch->WhenPressed(new LaunchCommand());
    launcherWheelBackward.reset(new JoystickButton(opJoystick.get(), 3));
    launcherWheelBackward->WhenPressed(new ActuateLauncherWheelCommand(false));
    launcherWheelForward.reset(new JoystickButton(opJoystick.get(), 4));
    launcherWheelForward->WhenPressed(new ActuateLauncherWheelCommand(true));
    dartBackward.reset(new JoystickButton(opJoystick.get(), 6));
    dartBackward->WhenPressed(new ActuateDartCommand(false));
    dartForward.reset(new JoystickButton(opJoystick.get(), 8));
    dartForward->WhenPressed(new ActuateDartCommand(true));
    raiseRamp.reset(new JoystickButton(opJoystick.get(), 5));
    raiseRamp->WhileHeld(new ActuateRampCommand(true));
    driverjoystick.reset(new Joystick(0));
    

    // SmartDashboard Buttons
    SmartDashboard::PutData("TurnToGyroCommand: default", new TurnToGyroCommand(0, 0, 0));
    SmartDashboard::PutData("AutoLaunchCommand", new AutoLaunchCommand());
    SmartDashboard::PutData("VisionDefaultCommand", new VisionDefaultCommand());
    SmartDashboard::PutData("AutonomousPlaceholder", new AutonomousPlaceholder());
    SmartDashboard::PutData("DistanceOverTimeCG", new DistanceOverTimeCG());
    SmartDashboard::PutData("AutoDriveCommand: default", new AutoDriveCommand(0, 0, 0));
    SmartDashboard::PutData("ActuateRampCommand: default", new ActuateRampCommand(false));
    SmartDashboard::PutData("RampDefaultCommand", new RampDefaultCommand());
    SmartDashboard::PutData("LaunchCommand", new LaunchCommand());
    SmartDashboard::PutData("ActuateDartCommand: default", new ActuateDartCommand(false));
    SmartDashboard::PutData("ActuateLauncherWheelCommand: default", new ActuateLauncherWheelCommand(true));
    SmartDashboard::PutData("LauncherDefaultCommand", new LauncherDefaultCommand());
    SmartDashboard::PutData("DriveTrainCommand", new DriveTrainCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    SmartDashboard::PutData("AutoAim", new AutoAim());
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getdriverjoystick() {
   return driverjoystick;
}

std::shared_ptr<Joystick> OI::getopJoystick() {
   return opJoystick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
bool OI::getButtonLWForward() {return launcherWheelForward.get()->Get();}
bool OI::getButtonLWBackward() {return launcherWheelBackward.get()->Get();}
bool OI::getButtonDartForward() {return dartForward.get()->Get();}
bool OI::getButtonDartBackward() {return dartBackward.get()->Get();}
