#include "Robot.h"
Robot::Robot()
{
    rnum=0;
    rloc=0;
    rhold=0;
    rplate=0;
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
