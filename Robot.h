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
    int useHold;
    int usePlate;
    int rcons_not; //存放物体编号
    int rcons_notnot;
public:
	string expectMove;		//针对goto
	int expectPickup;	//针对pickup
	int expectGive;		//针对give

    Robot();
    void setNum(int _num);
    void setLoc(int _loc);
    void setHold(int _hold);
    void setPlate(int _plate);
    void setRobotConsnot(int num);
    void setRobotConsnotnot();
    void setUsehold(int signal);
    void setUseplate(int signal);
    int getNum();
    int getLoc();
    int getHold();
    int getPlate();
    int getUsehold();
    int getUseplate();
    int getRobotConsnot();
    int getRobotConsnotnot();
};
#endif
