/*
 * AutoAssembler.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: Stevan
 */

#include "AutoAssembler.h"
#include "BrakeCoastMode.h"

AutoAssembler::AutoAssembler(Command* position,
		Command* obstacle,
		Command* shoot)
{
	AddSequential(new BrakeCoastMode(true));
	AddSequential(obstacle);
	AddSequential(position);
	AddSequential(shoot);
	AddSequential(new BrakeCoastMode(false));
}

