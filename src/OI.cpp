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
#include "Commands/ActuateLoaderCommand.h"
#include "Commands/ActuateRampCommand.h"
#include "Commands/AutoDriveCommand.h"
#include "Commands/AutonomousPlaceholder.h"
#include "Commands/DistanceOverTimeCG.h"
#include "Commands/DriveTrainCommand.h"
#include "Commands/LaunchCommand.h"
#include "Commands/LauncherDefaultCommand.h"
#include "Commands/RampDefaultCommand.h"
#include "Commands/VisionDefaultCommand.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driverjoystick.reset(new Joystick(0));
    
    lowerRamp.reset(new JoystickButton(driverjoystick.get(), 7));
    lowerRamp->WhileHeld(new ActuateRampCommand(false));
    raiseRamp.reset(new JoystickButton(driverjoystick.get(), 5));
    raiseRamp->WhileHeld(new ActuateRampCommand(true));
    launch.reset(new JoystickButton(driverjoystick.get(), 1));
    launch->WhenPressed(new LaunchCommand());
    launcherWheelBackward.reset(new JoystickButton(driverjoystick.get(), 3));
    launcherWheelBackward->WhileHeld(new ActuateLauncherWheelCommand(true));
    launcherWheelForward.reset(new JoystickButton(driverjoystick.get(), 4));
    launcherWheelForward->WhileHeld(new ActuateLauncherWheelCommand(false));
    dartBackward.reset(new JoystickButton(driverjoystick.get(), 6));
    dartBackward->WhileHeld(new ActuateDartCommand(false));
    dartForward.reset(new JoystickButton(driverjoystick.get(), 8));
    dartForward->WhileHeld(new ActuateDartCommand(true));

    // SmartDashboard Buttons
    SmartDashboard::PutData("VisionDefaultCommand", new VisionDefaultCommand());
    SmartDashboard::PutData("AutonomousPlaceholder", new AutonomousPlaceholder());
    SmartDashboard::PutData("DistanceOverTimeCG", new DistanceOverTimeCG());
    SmartDashboard::PutData("AutoDriveCommand: default", new AutoDriveCommand(0, 0, 0));
    SmartDashboard::PutData("ActuateRampCommand: default", new ActuateRampCommand(false));
    SmartDashboard::PutData("RampDefaultCommand", new RampDefaultCommand());
    SmartDashboard::PutData("LaunchCommand", new LaunchCommand());
    SmartDashboard::PutData("ActuateDartCommand: default", new ActuateDartCommand(false));
    SmartDashboard::PutData("ActuateLoaderCommand: default", new ActuateLoaderCommand(false));
    SmartDashboard::PutData("ActuateLauncherWheelCommand: default", new ActuateLauncherWheelCommand(true));
    SmartDashboard::PutData("LauncherDefaultCommand", new LauncherDefaultCommand());
    SmartDashboard::PutData("DriveTrainCommand", new DriveTrainCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getdriverjoystick() {
   return driverjoystick;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
