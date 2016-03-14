/*
 * AutoAssembler.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: Stevan
 */

#include "AutoAssembler.h"

AutoAssembler::AutoAssembler(Command* position,
		Command* obstacle,
		Command* shoot)
{
	AddSequential(obstacle);
	AddSequential(position);
	AddSequential(shoot);
}

