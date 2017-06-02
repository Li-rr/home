#include "Tasknum.h"
Tasknum::Tasknum()
{
    taskNum = -1;
    fUsed = false;
    taskname = "";
    fmanyobj1 = false;
    fmanyobj2 = false;

    howmanyobj1 = -1;
    howmanyobj2 = -1;

    obj1num = -1;
    obj2num = -1;
    for(int i=0; i<5;i++)
    {
        arrayobj1num[i] = -1;
        arrayobj2num[i] = -1;
    }
}
