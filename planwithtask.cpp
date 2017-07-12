#include "devil.hpp"
using namespace _home;
//void setSortAttribute(Task task[],int num,Sort sort[],int senceMax,Robot &robot);
int checkPutdown(int sort, int present,Graph G )
{
	int i;
	for(i=0;i<maxNode;i++)
	{
		if(G.getDirection(sort,i)==present)
			continue;
		if(G.getDirection(sort,i) == 4 && G.getStatus(sort,i)==1)
			return 4;
	}
}
int checkPuton(int sort,int present,Graph G)
{
	int i;
	for(i=0;i<maxNode;i++)
	{
		if(G.getDirection(sort,i)==present)
			continue;
		if(G.getDirection(sort,i) == 5 && G.getStatus(sort,i)==5)
			return 5;
	}

}
int checkGive(int sort,int present,Graph G)
{
	int i;
	cout<<"Now have not checkGive"<<endl;
     /*	for(i<maxNode;i++)
	{
		if(G.getDirection(sort,i)==present)
			continue;
		if(G.getDirection(sort,i) == 5 && G.getStatus(sort,i)==5)
			return 5;

	}*/
	return 0;
}
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
	int i;
	for(i=0;i<maxNode;i++)
	{
		if(G.getDirection(sort,i)==present)
		  continue;
		if(G.getDirection(sort,i)==-1 && G.getStatus(sort,i)==1)
		  return -1;
	}
	return 0;
}
int getPutinSort(int sort,Graph G)
{
	int i;
	for(i=0;i < maxNode;i++)
	{
		if(G.getDirection(sort,i)==-1 && G.getStatus(sort,i)==1)
			return i;
	}
	return 0;
}
void Devil::planWithtask(Task task[],Sort sort[],int taskNum,int sortNum,Robot &robot,Graph &G)
{
	cout<<"-----------------------------------------------------------"<<endl;
	int i=0,j=0;
	G.printMatrix();
	checkHold(robot,G);
	for(i=0;i<maxNode;i++)
	{
		for(j=0;j<maxNode;j++)
		{
			if(G.getStatus(i,j)==0)
			  continue;
			if(G.getDirection(i,j)==4)	//putdown
			{
				G.setStatus(i,j,putdown(i,sort,robot,G));
			}
			if(G.getDirection(i,j)==-4&&G.getStatus(i,j)==1) //puton
			{
				cout<<"This is run puton action\n";
				G.setStatus(i,j,puton(i,j,sort,robot,G));
				cout<<"This is run puton over\n";
			}

			if(G.getDirection(i,j)==6&&G.getStatus(i,j)==1) //give
			{
				cout<<"This is run give\n";
				G.setStatus(i,j,puton(i,j,sort,robot,G));
				cout<<"This is run give over\n";
			}
			if(G.getDirection(i,j)==-1)	//takeout
			{
				cout<<"This is run takeout\n";
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
				cout<<"run takout over\n";
			}
			if(G.getDirection(i,j)==1)	//putin
			{
				cout<<"\n\nthis is putin action  "<<i<<" "<<j<<endl;
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
					cout<<"this putin I'm move"<<endl;
					open(j,sort,robot,G);
					G.setStatus(i,j,putin(i,j,sort,robot,G));
				}
				cout<<"This is putin action run over\n";
			}
			if(G.getDirection(i,j)==2)	//close.低级处理
			{
				cout<<"This is run close\n";
				move(i,sort,robot);
				G.setStatus(i,j,close(i,sort,robot,G));
				cout<<"run close over\n";
			}
			if(G.getDirection(i,j)==-2) //open
			{
				cout<<"This is run open\n";
				move(i,sort,robot);
				G.setStatus(i,j,open(i,sort,robot,G));
			}
			if(G.getDirection(i,j)==5)	//pickup
			{
			/*	cout<<G.getStatus(i,j)<<" pickup "<<endl;
				if(checkPutdown(robot.getHold(),i,G) == 4)
				{

					//先执行putdown
						int hold = robot.getHold();
						G.setStatus(hold,0,putdown(hold,sort,robot,G));
				}
				if(checkPutdown(robot.getPlate(),i,G)==4)
				{
					int plate = robot.getPlate();
					G.setStatus(plate,0,putdown(plate,sort,robot,G));
				}
				if(checkPuton(robot.getHold(),i,G) == 5)
				{
					//puton
					//暂不处理
				}
				if(checkPutinFirst(robot.getHold(),i,G)==-1)
				{
					int act2 = getPutinSort(robot.getHold(),G);
					move(act2,sort,robot);
					open(act2,sort,robot,G);
					G.setStatus(robot.getHold(),act2,putin(robot.getHold(),act2,sort,robot,G));
				}
				if(checkPutinFirst(robot.getPlate(),i,G)==-1)
				{
					int act2 = getPutinSort(robot.getPlate(),G);
					move(act2,sort,robot);
					open(act2,sort,robot,G);
					G.setStatus(robot.getHold(),act2,putin(robot.getHold(),act2,sort,robot,G));
				}
				move(i,sort,robot);
				G.setStatus(i,j,pickup(i,sort,robot,G));
		*/
			}
		   
		}
 	}
    for(int q=0; q<=taskNum;q++)
    {
        if(task[i].getTaskAction()=="goto")
        {
            move(task[i].getTaskAct1(),sort,robot);
        }
    }
}

