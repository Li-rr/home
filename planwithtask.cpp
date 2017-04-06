#include "devil.hpp"
using namespace _home;
void setSortAttribute(Task task[],int num,Sort sort[],int senceMax,Robot &robot);
void Devil::planWithtask(Task task[],Sort sort[],int taskNum,int sortNum,Robot &robot)
{
	int i=0;
	//将任务目标写入sort中
	for(i = 0; i <= taskNum; i++)
	{
	  setSortAttribute(task,i,sort,sortNum,robot);	
	}
	//验证写入是否成功
	/*
	for(i=0;i<sortNum;i++)
	{
		if(sort[i].used==1)
		{
			cout<<i<<" "<<sort[i].getsName()<<" "<<sort[i].getsNum()<<" "<<sort[i].appareCount<<endl;
		}
	}
	*/
	//start plan task
	for(i = 0;i <= taskNum; i++)
	{
		if(task[i].getTaskPriority()== 1 && !task[i].getTaskSuccess())
		{
			task[i].setTaskSuccess(PutDown(task[i].getTaskAct1()));
			cout<<"PutDown success: "<<task[i].getTaskSuccess()<<endl;
		}

	}
	
	Graph G;
    cout<<"hello"<<endl;
} 
///////////////////////////
void setSortAttribute(Task task[],int num,Sort sort[],int senceMax,Robot &robot)
{
	if(task[num].getTaskAction()=="open")
	{
		sort[task[num].getTaskAct1()-1].expectClosed = 0;
		sort[task[num].getTaskAct1()-1].used=1;
		sort[task[num].getTaskAct1()-1].appareCount++;
	}
	if(task[num].getTaskAction()=="close")
	{
		sort[task[num].getTaskAct1()-1].expectClosed = 1;
		sort[task[num].getTaskAct1()-1].used=1;
		sort[task[num].getTaskAct1()-1].appareCount++;
	}
	if(task[num].getTaskAction()=="takeout")
	{
		sort[task[num].getTaskAct1()-1].used=1;
		sort[task[num].getTaskAct2()-1].sinsideD = 0;
		sort[task[num].getTaskAct2()-1].used=1;
		sort[task[num].getTaskAct1()-1].appareCount++;
		sort[task[num].getTaskAct2()-1].appareCount++;
	}
	if(task[num].getTaskAction()=="putin")
	{
		//小物体
		sort[task[num].getTaskAct1()-1].expectInsiding = task[num].getTaskAct2();
		sort[task[num].getTaskAct1()-1].used=1;
		sort[task[num].getTaskAct1()-1].appareCount++;
		//大物体
		sort[task[num].getTaskAct2()-1].expectInsided = task[num].getTaskAct1();
		sort[task[num].getTaskAct2()-1].used = 1;
		sort[task[num].getTaskAct2()-1].appareCount++;
	}
	if(task[num].getTaskAction()=="putdown")
	{
		sort[task[num].getTaskAct1()-1].expectOn = -3; //-3代表putdown
		sort[task[num].getTaskAct1()-1].used = 1;
		sort[task[num].getTaskAct1()-1].appareCount++;	
	}
	if(task[num].getTaskAction()=="goto")
	{
		//此条针对机器人
		robot.expectMove = task[num].getTaskAct1();
	}
	if(task[num].getTaskAction()=="puton")
	{
		sort[task[num].getTaskAct1()-1].expectOn = task[num].getTaskAct2();
		sort[task[num].getTaskAct1()-1].used=1;
		sort[task[num].getTaskAct1()-1].appareCount++;
	}
	if(task[num].getTaskAction()=="pickup")
	{
		//此条针对机器人
		robot.expectPickup = task[num].getTaskAct1();
	}
	if(task[num].getTaskAction()=="give")
	{
		//此条针对机器人
		robot.expectGive = task[num].getTaskAct1();
	}
}

