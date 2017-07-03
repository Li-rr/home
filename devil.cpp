#include "devil.hpp"
#include <iostream>
#include <fstream>
using namespace _home;
using namespace std;

//////////////////////////////////////////////////////////////////////////
Devil::Devil() :
 Plug("Miracle-1")
{
}

//////////////////////////////////////////////////////////////////////////
void Devil::Plan()
{
	
    //cout << "#(Devil): Init" << endl;
//    cout << "# EnvDes:\n" << GetEnvDes() << endl;
  //  cout << "# TaskDes:\n" << GetTaskDes() << endl;
    Sort sort[30];
    Robot robot;
    Task task[30];
    InfoCons info[30];
    InfoCons cons_not[30];
    InfoCons cons_notnot[30];
    Graph G;
    Tasknum tasknum[15];
    string STR=GetEnvDes();
    string TASK=GetTaskDes();
  //  freopen("/tmp/Debug.txt","w",stdout);
    if(TASK.find("(:")==-1)
    {
		cout<<TASK<<endl;
       TASK = Translate(TASK);
	   cout<<TASK<<endl;
    }
    int senceMax= 0,taskMax=0,infoMax=0,cons_not_Max=0,cons_notnotMax=0;
    int i=0;
//    freopen("/tmp/Debug.txt","w",stdout);
    //////////////////////////////////////////////////
    dealwithsence(STR,sort,robot,senceMax);
   dealwithtask(TASK,task,taskMax);
	printScence(robot,sort,senceMax);
    dealwithInfoCons(TASK,info,infoMax,"info");

    dealwithInfoCons(TASK,cons_not,cons_not_Max,"cons_not");
    dealwithInfoCons(TASK,cons_notnot,cons_notnotMax,"cons_notnot");
    ////////////////////////////////////////////////////////////////
    updateSenceByInfo(sort,info,robot,senceMax,infoMax);
    judgewithCons(cons_not,cons_not_Max,task,taskMax,sort,senceMax);
    judgewithCons(cons_notnot,cons_notnotMax,task,taskMax,sort,senceMax);
    updateTaskCons_not_notnot(sort,task,cons_notnot,cons_not,robot,senceMax,taskMax,cons_not_Max,cons_notnotMax);
    updateSenceByCons(sort,cons_not,robot,senceMax,cons_not_Max);
   updateTask(sort,task,senceMax,taskMax,robot);
    ////////////////////////////////////////////////////////////////
    cout<<endl<<endl;
//    printScence(robot,sort,senceMax);
//    for(int i=0; i<senceMax; i++)
//    {
//        if(sort[i].getsType()=="container")
//        {
//            cout<<sort[i].getsNum()<<" ";
//            printVector(sort[i].sinsideD);
//            cout<<endl;
//        }
//		if(sort[i].getsSize()=="small")
//			cout<<" book "<<sort[i].getsStatic("book")
//				<<" cup "<<sort[i].getsStatic("cup")
//				<<" can "<<sort[i].getsStatic("can")
//				<<" remotecontrol "<<sort[i].getsStatic("remotecontrol")
//				<<" bottle "<<sort[i].getsStatic("bottle")<<endl;
//		if(sort[i].getsSize()=="small")
//		{
//			cout<<sort[i].getsName()<<" "<<sort[i].getsLocked()<<endl;
//		}
//    }
	getLostLocFromTask(task,taskMax,sort);
	printScence(robot,sort,senceMax);
    printTask(task,taskMax);
    printInfoCons(info,infoMax,"info");
   // printInfoCons(cons_not,cons_not_Max,"cons_not");
   // printInfoCons(cons_notnot,cons_notnotMax,"cons_notnot");

	for(i = 0; i <= taskMax; i++)
 	{
		if(task[i].getTaskAction() != "give")	
  		{
			G.setStatus(task[i].getTaskAct1(),task[i].getTaskAct2(),task[i].getTaskAction());
		}
		else
		{
			int human = findSortByName(senceMax,"human",sort);
			G.setStatus(task[i].getTaskAct1(),human,task[i].getTaskAction());
		}
	}
    planwithcons_not_info(cons_not,task,sort,robot,cons_not_Max,taskMax,G);
    planWithtask(task,sort,taskMax,senceMax,robot,G);
	dealwithgoto(task,taskMax,sort,robot);
// //  vector <unsigned int> test;
  // Sense(test);
  // for(vector<unsigned int>::iterator it=test.begin();it!=test.end();it++)
  // {
	//	cout<<*it<<endl;


	// }
 //system("pkill -9 kill");
    cout<<"\n|-------ok--------|\n";
}

void Devil::Fini()
{
    cout << "#(Maricle-2): Fini" << endl;
}
