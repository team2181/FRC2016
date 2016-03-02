/*
 * AutoRoughTerrain.cpp
 *
 *  Created on: Mar 1, 2016
 *      Author: maxar
 */


#include "AutoRoughTerrain.h"
#include "Commands/AutoDriveCommand.h"

AutoRoughTerrain::AutoRoughTerrain(): Command() {

	done = 0;
}

void AutoRoughTerrain::Initialize() {
	SetInterruptible(false);
}

void AutoRoughTerrain::Execute() {
		Command* Drive = new AutoDriveCommand(1, 1.5, 0);
		if (Drive != NULL) Drive->Start();
		Drive = new AutoDriveCommand(0, 0, 0);
		if (Drive != NULL) Drive->Start();
		done = 1;
}

bool AutoRoughTerrain::IsFinished() {
	return (done == 1);
}

void AutoRoughTerrain::End() {
	Command* Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();

}
void AutoRoughTerrain::Interrupted() {
	Command* Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();
}



