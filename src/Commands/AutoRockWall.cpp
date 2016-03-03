/*
 * AutoRockWall.cpp
 *
 *  Created on: Mar 2, 2016
 *      Author: maxar
 */
/*
 * AutoRoughTerrain.cpp
 *
 *  Created on: Mar 1, 2016
 *      Author: maxar
 */


#include "AutoRockWall.h"
#include "Commands/AutoDriveCommand.h"

AutoRockWall::AutoRockWall(): Command() {

	done = 0;
}

void AutoRockWall::Initialize() {
	SetInterruptible(false);
}

void AutoRockWall::Execute() {
		Command* Drive = new AutoDriveCommand(1, 1.5, 0);
		if (Drive != NULL) Drive->Start();
		Drive = new AutoDriveCommand(0, 0, 0);
		if (Drive != NULL) Drive->Start();
		done = 1;
}

bool AutoRockWall::IsFinished() {
	return (done == 1);
}

void AutoRockWall::End() {
	Command* Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();

}
void AutoRockWall::Interrupted() {
	Command* Drive = new AutoDriveCommand(0, 0, 0);
	if (Drive != NULL) Drive->Start();
}







