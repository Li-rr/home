#ifndef __home_readyadvence_h__
#define __home_redayadvence_h__
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include "Sort.h"
#include "Robot.h"
#include "Task.h"
#include "InfoCons.h"
using namespace std;
void dealwithtask(string TASK,Task task[], int &taskMaxnum);
void dealwithsence(string STR,Sort sort[],Robot &robot, int &senceMax);
void dealwithInfoCons(string TASK,InfoCons info_cons[],int &numMax,string SIGN);
int findSortByName(int sNum,string name,Sort sort[]);
void judgewithCons(InfoCons cons_nn[],int consNn,Task task[],int taskNum,Sort sort[],int sortNum);
void updateTaskCons_not_notnot(Sort sort[],Task task[],InfoCons consNn[],InfoCons consn[],Robot robot,int sNum,int tNum,int cNum,int cnNum);
void aboutTaskLackMatch(Task task[],Sort sort[],int sNum,int tNum,Robot &robot);

void updateSenceByInfo(Sort sort[],InfoCons info[],Robot robot,int SNum,int infoNum);

void printTask(Task task[],int count);
void printScence(Robot  robot,Sort sort[],int count);
void printInfoCons(InfoCons info[],int count,string SIGN);

#endif
