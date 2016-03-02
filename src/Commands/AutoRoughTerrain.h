/*
 * AutoRoughTerrain.h
 *
 *  Created on: Mar 1, 2016
 *      Author: maxar
 */

#ifndef SRC_COMMANDS_AUTOROUGHTERRAIN_H_
#define SRC_COMMANDS_AUTOROUGHTERRAIN_H_

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoRoughTerrain: public Command {
public:

	AutoRoughTerrain();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	double done;

private:
};






#endif /* SRC_COMMANDS_AUTOROUGHTERRAIN_H_ */
