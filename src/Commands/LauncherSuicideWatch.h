#ifndef LAUNCHERSUICIDEWATCH_H
#define LAUNCHERSUICIDEWATCH_H

#include "Commands/Command.h"

class LauncherSuicideWatch: public Command {
public:
	LauncherSuicideWatch();

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual bool IsOut();
private:
	int limit_low;
	int limit_high;
	int m_pos;
};
#endif
