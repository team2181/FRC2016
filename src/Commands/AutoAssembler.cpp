/*
 * AutoAssembler.cpp
 *
 *  Created on: Mar 8, 2016
 *      Author: Stevan
 */

#include <Commands/AutoAssembler.h>
#include "Commands/Command.h"

AutoAssembler::AutoAssembler(Command* position,
		Command* obstacle,
		Command* shoot)
{
	AddSequential(position);
	AddSequential(obstacle);
	AddSequential(shoot);
}

