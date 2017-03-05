#include "devil.hpp"
using namespace _home;
class taskSort{
	public:
		int used;			//判断当前物体是否需要
		int expectMoveLoc;   //期望移动到哪个位置
		int realMoveLoc;	//实际的位置，此条针对goto

		int expectInsiding;  //期望在哪个物体内部
		int realInsiding;	//实际处于哪个物体内部,此条针对takeout,putin

		int expectOn;		//期望在哪个物体上,此条针对puton,putdown
		int realOn;			//实际位于哪个物体上

		//以下是大物体属性
		int expectInsided; //期望哪个处于本物体内
		int realInsided;  //实际处于内部的物体
		
		bool expectClosed; //期望门关闭
		bool realClosed;	//门实际的状态,此条针对open,close
	/////////////////////
	taskSort()
	{
		used = 0;
		expectMoveLoc = -2;
		realMoveLoc = -2;
	
		expectInsiding = -2;
		realInsiding = -2;

	    expectOn = -2;
	    realOn = -2;

		//大物体
		expectInsided = -2;
		realInsided = -2;

		expectClosed = false;
		realClosed = false;
	}
	void setSortAttribute(Task task[],int num,taskSort tsort[],int stnum)
	{
		if(task[num].getTaskAction() == "open")
		{
			tsort[task[num].getTaskAct1()].expectClosed = false;
			tsort[task[num].getTaskAct1()].used = 1;
		}

		if(task[num].getTaskAction() == "close")
		{
			tsort[task[num].getTaskAct1()].expectClosed = true;
			tsort[task[num].getTaskAct1()].used = 1;
		}

		if(task[num].getTaskAction() == "takeout")
		{
			//小物体
			tsort[task[num].getTaskAct1()].realInsiding = task[num].getTaskAct2();
			tsort[task[num].getTaskAct1()].used = 1;
			//大物体
			tsort[task[num].getTaskAct2()].expectInsided = 0;
			tsort[task[num].getTaskAct2()].realInsided = task[num].getTaskAct1();
			tsort[task[num].getTaskAct2()].used = 1;
		}
		if(task[num].getTaskAction() == "putin")
		{
			//小物体
			tsort[task[num].getTaskAct1()].expectInsiding = task[num].getTaskAct2();
			tsort[task[num].getTaskAct1()].used = 1;
			//大物体
			tsort[task[num].getTaskAct2()].expectInsided = task[num].getTaskAct1();
			tsort[task[num].getTaskAct2()].used = 1;
		}
		if(task[num].getTaskAction() == "putdown")
		{
			tsort[task[num].getTaskAct1()].expectOn = -3; //-3代表此物体想放在地上
			tsort[task[num].getTaskAct2()].used = 1;
		}
		if(task[num].getTaskAction() == "goto")
		{
			tsort[0].expectMoveLoc = task[num].getTaskAct1();
			tsort[0].used = 1;
		}
		if(task[num].getTaskAction() == "puton")
		{
			tsort[task[num].getTaskAct1()].expectOn = task[num].getTaskAct2();
			tsort[task[num].getTaskAct1()].used = 1;
		}
		if(task[num].getTaskAction() == "pickup")
		{	tsort[task[num].getTaskAct1()].expectOn = 0; //代表希望在机器人上
			tsort[task[num].getTaskAct1()].used = 1;	
		}
		if(task[num].getTaskAction() == "give")
		{
			//暂时不处理
		}
	}
};


void Devil::planWithtask(Task task[],Sort sort[],int taskNum,int sortNum,Robot &robot)
{
    cout<<"hello"<<endl;
}
