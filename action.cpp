#include "devil.hpp"
using namespace _home;
int Devil::move(int sot,Sort sort[],Robot &robot)
{
	bool flag=0;
	if(robot.getLoc()!= sort[sot-1].getsLoc())
	{
		 flag=Move(sort[sot-1].getsLoc());
		robot.setLoc(sort[sot-1].getsLoc());
	}
	return flag;
}

int checkOpen(int sot,Sort sort[])
{
	int flag = 0;
	if(sort[sot-1].getsClosed()== false)
	{
		flag = 1;
	}
	return flag;
}

int Devil::open(int sot,Sort sort[],Robot &robot,Graph G)
{
	int flag = 0;
	if(G.getStatus(sot,0)==0)
	  return 1;
	if(checkOpen(sot,sort)==0)
	{
		flag = Open(sot);
		sort[sot-1].setsClosed(0);
		cout<<"Sir,I'm open "<<sot<<endl;
	}
	return flag;
}

int Devil::takeout(int sot,Sort sort[],Robot &robot,Graph G)
{
	int flag = 0;
	int act2 = sort[sot-1].getsInside();
	if(G.getStatus(sot,act2)==0)
	  return 0;
	open(act2,sort,robot,G);
	flag = TakeOut(sot,act2);
	robot.setHold(sot);
	sort[sot-1].setsInside(-1);
	cout<<"Sir, I'm takeout: "<<sot<<" from "<<act2<<endl;
	return flag;
}

int Devil::close(int sot,Sort sort[],Robot &robot,Graph G)
{
	int flag = 0;
	if(G.getStatus(sot,0)==0)
	{
		return 0;
	}
	if(sort[sot-1].getsClosed()==0)
	{
		//此处可以检查一下手上的东西有没有用
		//如果没有用可以扔掉
		if(robot.getHold()!=0&&robot.getPlate()==0)
		{
			ToPlate(robot.getHold());
			
			robot.setPlate(robot.getHold());
			robot.setHold(0);
			
			flag=Close(sot);
			sort[sot-1].setsClosed(1);
			cout<<"Sir, I'm closed the: "<<sot<<endl;
			return 1;
		}
		if(robot.getHold()==0)
		{
			flag = Close(sot);
			sort[sot-1].setsClosed(1);
			cout<<"Sir, I'm closed the: "<<sot<<endl;
		}
	}
	return flag;
}
int Devil::getSort(int sot,Sort sort[],Robot &robot,Graph G)
{
	int flag = 0;
	cout<<"I want get "<<sot<<endl;
	if(sort[sot-1].getsLoc()==robot.getLoc())
	{
		if(robot.getHold()==sot||robot.getPlate()==sot)	//on hold
		{
			flag = 1;
		}
		else if(sort[sot-1].getsInside()!=-1)	//inside
		{ 
			takeout(sot,sort,robot,G);
			flag = 1;
		}
		else
		{
			PickUp(sot);	//on the ground
			robot.setHold(sot);
			flag = 1;
		}
	}
	else
	{
		move(sot,sort,robot);
		if(sort[sot-1].getsInside()!=-1)
		{
			takeout(sot,sort,robot,G);
			flag =  1;
		}
		else
		{
			PickUp(sot);
			robot.setHold(sot);
			flag = 1;
		}

	}
	if(flag == 1)
	{
		cout<<"Sir, I get it "<<sot<<endl;
	}
	else
	{
		cout<<"Sorry Sir,I failed "<<sot<<endl;
	}
	return flag;
}
int Devil::putin(int sot,Sort sort[],Robot &robot,Graph G)
{
	int flag = 0;
	int act1;
	if(robot.getHold()==0&&robot.getPlate()!=0)
	{
		FromPlate(robot.getPlate());
		robot.setHold(robot.getPlate());
		robot.setPlate(0);
	}
	act1 = robot.getHold();
	cout<<act1<<" "<<sot<<" "<<G.getStatus(act1,sot)<<endl;
	if(G.getStatus(act1,sot)==0)
	  return 0;
	open(sot,sort,robot,G);
	flag = PutIn(act1,sot);
	robot.setHold(0);
	sort[act1-1].setsInside(sot);
	cout<<"Sir, I'm put "<<act1 <<" in "<<sot<<endl;
	return flag;
}
