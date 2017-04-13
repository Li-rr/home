/*
 * Simulation@Home Competition
 * File: devil.cpp
 * Author: Jiongkun Xie
 * Affiliation: Multi-Agent Systems Lab.
 *              University of Science and Technology of China
 */

#include "devil.hpp"
#include <iostream>

using namespace _home;
using namespace std;

//////////////////////////////////////////////////////////////////////////
Devil::Devil() :
    Plug("Devil")
{
}

//////////////////////////////////////////////////////////////////////////
void Devil::Plan()
{
    //cout << "#(Devil): Init" << endl;
   // cout << "# EnvDes:\n" << GetEnvDes() << endl;
    //cout << "# TaskDes:\n" << GetTaskDes() << endl;
    Sort sort[30];
    Robot robot;
    Task task[30];
    InfoCons info[30];
    InfoCons cons_not[30];
    InfoCons cons_notnot[30];
    string STR=GetEnvDes();
    string TASK=GetTaskDes();
    int senceMax= 0,taskMax=0,infoMax=0,cons_not_Max=0,cons_notnotMax=0;
    //////////////////////////////////////////////////
    dealwithsence(STR,sort,robot,senceMax);
   dealwithtask(TASK,task,taskMax);

    dealwithInfoCons(TASK,info,infoMax,"info");

    dealwithInfoCons(TASK,cons_not,cons_not_Max,"cons_not");
    dealwithInfoCons(TASK,cons_notnot,cons_notnotMax,"cons_notnot");
    //////////////////////////////////////////////////////////////////
    updateSenceByInfo(sort,info,robot,senceMax,infoMax);
    judgewithCons(cons_not,cons_not_Max,task,taskMax,sort,senceMax);
    judgewithCons(cons_notnot,cons_notnotMax,task,taskMax,sort,senceMax);
    updateTaskCons_not_notnot(sort,task,cons_notnot,cons_not,robot,senceMax,taskMax,cons_not_Max,cons_notnotMax);
    //////////////////////////////////////////////////////////////////
    cout<<endl<<endl;
    printScence(robot,sort,senceMax);
	for(int i=0; i<senceMax;i++)
	{
		if(sort[i].getsType()=="container")
		{
			cout<<sort[i].getsNum()<<" have "<<sort[i].sinsideD<<endl;
		}
	}
   	   printTask(task,taskMax);
  //  printInfoCons(info,infoMax,"info");
   // printInfoCons(cons_not,cons_not_Max,"cons_not");
   // printInfoCons(cons_notnot,cons_notnotMax,"cons_notnot");
    planWithtask(task,sort,taskMax,senceMax,robot);
 //  vector <unsigned int> test;
  // Sense(test);
  // for(vector<unsigned int>::iterator it=test.begin();it!=test.end();it++)
  // {
	//	cout<<*it<<endl;
  // }
    cout<<"\n|-------ok--------|\n";
}

void Devil::Fini()
{
    cout << "#(Devil): Fini" << endl;
}
