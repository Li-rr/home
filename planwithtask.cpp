#include "devil.hpp"
using namespace _home;
void setSortAttribute(Task task[],int num,Sort sort[],int senceMax,Robot &robot);
int checkConnection(int sort2,Graph G)
{
	cout<<"check connection: "<<G.getDirection(sort2,0)<<endl;
	return G.getDirection(sort2,0); //返回大物体
}
int checkInside(int smallSort,Sort sort[])
{
	return sort[smallSort-1].getsInside();
}
int checkPutinFirst(int sort,int present,Graph G)
{
	int i,flag=0;
	for(i=0;i<maxNode;i++)
	{
		if(G.getDirection(sort,i)==present)
		  continue;
		if(G.getDirection(sort,i)==-1 && G.getStatus(sort,i)==1)
		  flag = -1;
	}
	return 0;
}
void Devil::planWithtask(Task task[],Sort sort[],int taskNum,int sortNum,Robot &robot)
{
	cout<<"-----------------------------------------------------------"<<endl;
	int i=0,j=0;
	Graph G;
	//将任务目标写入sort中
	for(i = 0; i <= taskNum; i++)
	{
	//  setSortAttribute(task,i,sort,sortNum,robot);	
	  G.setStatus(task[i].getTaskAct1(),task[i].getTaskAct2(),task[i].getTaskAction());
	}
	G.printMatrix();
	for(i=0;i<maxNode;i++)
	{
		for(j=0;j<maxNode;j++)
		{
			if(G.getStatus(i,j)==0)
			  continue;
			if(G.getDirection(i,j)==4)	//putdown
			{
				G.setStatus(i,j,PutDown(i));
			}
			if(G.getDirection(i,j)==-1)	//takeout
			{
				cout<<j<<" "<<checkConnection(j,G)<<endl;
				cout<<i<<" inside: "<<checkInside(i,sort)<<endl;
				if(checkInside(i,sort)!=-1)	//确定为takeout
				{
					Devil::move(i,sort,robot);
					G.setStatus(i,j,Devil::takeout(i,sort,robot,G));
				}
				if(checkConnection(j,G)==2)	//close
				{
					cout<<"j->: "<<j<<endl;
					G.setStatus(j,0,close(j,sort,robot,G));
				}
			}
			if(G.getDirection(i,j)==1)	//putin
			{
				cout<<"This task putin\n";
				cout<<G.getStatus(i,j)<<endl;
				int signedTask = checkPutinFirst(i,G.getDirection(i,j),G);
				cout<<"I have other task "<<signedTask<<endl;
				if(signedTask == -1) //takeout_fisrt
				{
					cout<<"asd"<<endl;
					move(i,sort,robot);
					G.setStatus(i,sort[i-1].getsInside(),Devil::takeout(i,sort,robot,G));
				}
				if(checkPutinFirst(i,G.getDirection(i,j),G) == 0) //only_putin
				{
					getSort(i,sort,robot,G);
					move(j,sort,robot);
					open(j,sort,robot,G);
					G.setStatus(i,j,putin(j,sort,robot,G));
				}
				cout<<"Task putin is over\n";
			}
			if(G.getDirection(i,j)==3)	//goto,低级处理
			{
				G.setStatus(i,j,move(i,sort,robot));
			}
			if(G.getDirection(i,j)==2)	//close.低级处理
			{
				move(i,sort,robot);
				G.setStatus(i,j,close(i,sort,robot,G));
			}
			if(G.getDirection(i,j)==4)	//pickup
			{
			
			}
		}
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
/*	for(i = 0;i <= taskNum; i++)
	{
		if(task[i].getTaskPriority()== 1 && !task[i].getTaskSuccess())
		{
			task[i].setTaskSuccess(PutDown(task[i].getTaskAct1()));
			cout<<"PutDown success: "<<task[i].getTaskSuccess()<<endl;
		}

	}
*/

	
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

