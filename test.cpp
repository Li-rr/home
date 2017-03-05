#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include "Sort.cpp"
#include "Robot.cpp"
#include "problem.h"
#include "Task.cpp"
#include "InfoCons.cpp"
#include "dealwithsence.hpp"
#include "dealwithtask.hpp"
#include "dealwithinfoCons.hpp"
using namespace std;
int main()
{
    Sort sort[20];
    Robot robot;
    Task task[10];
    InfoCons info[10];
    InfoCons cons_not[10];
    InfoCons cons_notnot[10];
    int senceMax= 0,taskMax=0,infoMax=0,cons_not_Max=0,cons_notnotMax=0;
//    dealwithsence(STR,sort,robot,senceMax);
//        dealwithtask(TASK,task,taskMax);
//       printTask(task,taskMax);
//     printScence(robot,sort,senceMax);
    dealwithInfoCons(TASK,info,infoMax,"info");
   dealwithInfoCons(TASK,cons_not,infoMax,"cons_not");
    dealwithInfoCons(TASK,cons_notnot,cons_notnotMax,"cons_notnot");
    printInfo(info,infoMax);
    cout<<endl;
    printInfo(cons_not,cons_not_Max);
    cout<<endl;
    printInfo(cons_notnot,cons_notnotMax);
    cout<<"|-------ok--------|\n";
    return 0;
}

