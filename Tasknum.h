#ifndef __home_Tasknum_h__
#define __home_Tasknum_h__
#include <iostream>
#include <string.h>
using namespace std;
class Tasknum
{
public:
    int taskNum;
	bool fUsed;
	string taskname;
	bool fmanyobj1;
	bool fmanyobj2;
	int howmanyobj1;
	int howmanyobj2;
	int obj1num;
	int obj2num;
	int arrayobj1num[5];
	int arrayobj2num[5];
    Tasknum();
};
#endif // __home_Tasknum_h__
