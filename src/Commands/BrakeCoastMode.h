#ifndef BrakeCoastMode_H
#define BrakeCoastMode_H

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"

class BrakeCoastMode: public Command
{
public:
	BrakeCoastMode(bool brakeMode);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	bool m_brakeMode;
};

#endif
