/*
 * AutoMoat.h
 *
 *  Created on: Mar 1, 2016
 *      Author: maxar
 */

#ifndef SRC_COMMANDS_AUTOMOAT_H_
#define SRC_COMMANDS_AUTOMOAT_H_

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoMoat: public Command {
public:

	AutoMoat();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	double done;

private:
};


#endif /* SRC_COMMANDS_AUTOMOAT_H_ */
