/*
 * AutoAssembler.h
 *
 *  Created on: Mar 8, 2016
 *      Author: Stevan
 */

#ifndef SRC_COMMANDS_AUTOASSEMBLER_H_
#define SRC_COMMANDS_AUTOASSEMBLER_H_

#include "Commands/CommandGroup.h"
#include "Commands/Command.h"

class AutoAssembler: public CommandGroup {
public:
	AutoAssembler(Command* position,
			Command* obstacle,
			Command* shoot);
};

#endif /* SRC_COMMANDS_AUTOASSEMBLER_H_ */
