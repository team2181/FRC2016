#ifndef GetDown_H
#define GetDown_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class GetDown: public Command
{
public:
	GetDown();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	double pos;
};

#endif
