//On Request of Jason
//Robotbuilder was over rated, I made my own files XD
#include "LauncherSuicideWatch.h"

//Robot, Please don't kill yourself, we still need you.
//This will probably be over used.
void LauncherSuicideWatch::LauncherSuicideWatch(int pos)
{
	limit_high = 800;
	limit_low = 300;
	m_pos = pos;
}
//The following is a waste of space. BUUUTTTT WPILIB Tells me I have to keep these things in order to KEEP IT WORKING...
void LauncherSuicideWatch::Initialize(){}
void LauncherSuicideWatch::Execute(){}
bool LauncherSuicideWatch::IsFinished() {return true;}
void LauncherSuicideWatch::End() {}
void LauncherSuicideWatch::Interrupted() {}
//End Wasting Space

bool LauncherSuicideWatch::IsOut(int pos){
	return pos <= 300 && pos >= 500;
}
