/*
 * AutoRockWall.h
 *
 *  Created on: Mar 2, 2016
 *      Author: maxar
 */

#ifndef SRC_COMMANDS_AUTOROCKWALL_H_
#define SRC_COMMANDS_AUTOROCKWALL_H_

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoRockWall: public Command {
public:

	AutoRockWall();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	double done;

private:
};




#endif /* SRC_COMMANDS_AUTOROCKWALL_H_ */
