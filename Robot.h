#ifndef __home_Robot_h__
#define __home_Robot_h__
#include <iostream>
#include <string>
using namespace std;
class Robot
{
private:
    int rnum;
    int rplate;
    int rhold;
    int rloc;
public:
	string expectMove;		//针对goto
	int expectPickup;	//针对pickup
	int expectGive;		//针对give

    Robot();
    void setNum(int _num);
    void setLoc(int _loc);
    void setHold(int _hold);
    void setPlate(int _plate);
    int getNum();
    int getLoc();
    int getHold();
    int getPlate();
};
#endif
