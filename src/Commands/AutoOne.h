/*
 * AutoOne.h
 *
 *  Created on: Mar 1, 2016
 *      Author: maxar
 */

#ifndef SRC_COMMANDS_AUTOOne_H_
#define SRC_COMMANDS_AUTOOne_H_

#include "Commands/CommandGroup.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutoOne: public CommandGroup {
public:

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	AutoOne(double time, double angle);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

private:
	double mTime;
	double mAngle;
};

#endif
