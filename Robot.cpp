#include "Robot.h"
Robot::Robot()
{
    rnum=0;
    rloc=0;
    rhold=0;
    rplate=0;
    useHold = 1;
    usePlate = 1;
    rcons_not = 0;
    rcons_notnot = 0;
	expectMove = "";
	expectPickup = 0;
	expectGive = 0;
}

void Robot::setNum(int _num)
{
    rnum=_num;
}
void Robot::setLoc(int _loc)
{
    rloc=_loc;
}
void Robot::setHold(int _hold)
{
    rhold=_hold;
}
void Robot::setPlate(int _plate)
{
    rplate=_plate;
}
void Robot::setUsehold(int signal)
{
    useHold = signal;
}
void Robot::setUseplate(int signal)
{
    usePlate = signal;
}
int Robot::getNum()
{
    return rnum;
}
int Robot::getLoc()
{
    return rloc;
}
int Robot::getHold()
{
    return rhold;
}
int Robot::getPlate()
{
    return rplate;
}
void Robot::setRobotConsnot(int num)
{
    rcons_not = num;
}
int Robot::getUsehold()
{
    return useHold;
}
int Robot::getUseplate()
{
    return useHold;
}
