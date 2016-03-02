/*
 * AutoRoughTerrain.cpp
 *
 *  Created on: Mar 1, 2016
 *      Author: maxar
 */


#include "AutoMoat.h"
#include "Commands/AutoDriveCommand.h"

AutoMoat::AutoMoat(): Command() {

	done = 0;
}

void AutoMoat::Initialize() {
	SetInterruptible(false);
}

void AutoMoat::Execute() {
		Command* Drive = new AutoDriveCommand(1, 1.5, 0);
		if (Drive != NULL) Drive->Start();
		Drive = new AutoDriveCommand(0, 0, 0);
		if (Drive != NULL) Drive->Start();
		done = 1;
}

bool AutoMoat::IsFinished() {
	return (done == 1);
}

void AutoMoat::End() {
	Command* Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();

}
void AutoMoat::Interrupted() {
	Command* Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();
}



