#include "devil.hpp"
using namespace _home;
int checkConnectionSmall(int sot,Graph G)
{
	int i=0;
	for(i=0;i<maxNode;i++)
	{
		if(G.getStatus(sot,i)==1)
			return 1;
	}
	return 0;
}
int checkConnectionSmall(int sot[],Graph G,int count)
{
	int i = 0,j=0;
	for(i=0; i<count;i++)
 	{
		if(sot[i]==0)
			return 0;
		for(j=0;j<maxNode;j++)
 		{
			//若有需要可以增加对任务的判断
			if(G.getStatus(sot[i],j)==1)
				return sot[i];
		}
	}
	return 0;
}
//第一个参数为大物体编号
int checkContainer(int sot,Sort sort[],Graph G)
{
	int smallSort[5] = {0};
	int flag = 0;
	getVector(smallSort,sort[sot-1].sinsideD);
//	smallSort = sort[sot-1].sinsideD;
	cout<<"This is checkContainer ,check: "<<sot<<" get -> ";
	printVector(sort[sot-1].sinsideD);
	//<<smallSort<<endl;
	if(smallSort[0] == 0)
	{
		return 0;
	}
	flag = checkConnectionSmall(smallSort,G,5);
	return flag;
}
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
//	if(G.getStatus(sot,0)==0)
//	  return 1;
	if(checkConnectionSmall(robot.getHold(),G)!= 0 && robot.getHold()!=0)
	{
		cout<<"Befor open big sort,my hand have other sort, i need it -> "<<robot.getHold()<<" i will put it in my plate"<<endl;
		ToPlate(robot.getHold());
		robot.setPlate(robot.getHold());
		robot.setHold(0);
	}
	else if(checkConnectionSmall(robot.getHold(),G)==0&&robot.getHold()!=0)
	{
		cout<<"Before open big sort,my hand have other sort, i need pudown it -> "<<robot.getHold()<<endl;
		PutDown(robot.getHold());
		robot.setHold(0);
	}
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
	int flag = 0,checkOpen = 0;
	int act2 = sort[sot-1].getsInside();
//	if(G.getStatus(sot,act2)==0)
//	  return 0;
	cout<<"This is take -> "<<sot<<" from -> "<<act2<<endl;
	checkOpen = open(act2,sort,robot,G);
	if(checkOpen==1)
	{
		cout<<"I open this sort ->"<<act2<<endl;
	}
	else
	{
		cout<<"Sorry, I can't open this sort -> "<<act2<<endl;
	}
	flag = TakeOut(sot,act2);
	robot.setHold(sot);
	sort[sot-1].setsInside(-1);
	cout<<"Sir, I'm takeout: "<<sot<<" from "<<act2<<endl;
	return flag;
}

int Devil::close(int sot,Sort sort[],Robot &robot,Graph G)
{
	int flag = 0;
	int check_container = 0;
	//在关闭前应当检查该物体内部有没有
	//其他任务所需要的物品
	check_container = checkContainer(sot,sort,G);
	if(check_container != 0)
	{
		cout<<"In this container,have a sort -> ";
		printVector(sort[sot-1].sinsideD);
		cout<<" i need it"<<endl;
		takeout(check_container,sort,robot,G);
	}
//	if(G.getStatus(sot,0)==0)
//	{
//		return 0;
//	}

	if(robot.getHold()&&checkConnectionSmall(robot.getHold(),G)==0)
	{
		cout<<"My hand has sort,but I don't need it"<<endl;
		PutDown(robot.getHold());
		robot.setHold(0);
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
		cout<<"This sort location same with  me"<<endl;
		if(robot.getHold()==sot||robot.getPlate()==sot)	//on hold
		{
			flag = 1;
			cout<<"This sort "<<sot<<" on my hand"<<endl;
		}
		else if(sort[sot-1].getsInside()!=-1)	//inside
		{
			flag=takeout(sot,sort,robot,G);
			cout<<"This sort "<<sot<<" in other sort"<<endl;
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
		//此处有bug
		move(sot,sort,robot);
		if(sort[sot-1].getsInside()!=-1)
		{
			cout<<"This sort in other sort"<<sort[sot-1].getsInside()<<endl;
			flag = takeout(sot,sort,robot,G);

		}
		else
		{
			flag = PickUp(sot);
			robot.setHold(sot);

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
	open(sot,sort,robot,G);
	if(robot.getHold()==0&&robot.getPlate()!=0)
	{
		FromPlate(robot.getPlate());
		robot.setHold(robot.getPlate());
		robot.setPlate(0);
	}
	act1 = robot.getHold();
	cout<<"i will putin"<<act1<<" "<<sot<<" "<<G.getStatus(act1,sot)<<endl;
	if(G.getStatus(act1,sot)==0)
	  return 0;
//	open(sot,sort,robot,G);
	flag = PutIn(act1,sot);
	robot.setHold(0);
	sort[act1-1].setsInside(sot);
	cout<<"Sir, I'm put "<<act1 <<" in "<<sot<<endl;
	return flag;
}
int Devil::putdown(int sort,Robot &robot,Graph G)
{

	int act1;
	if(robot.getHold() == sort && robot.getPlate()==0)
	{
		PutDown(robot.getHold());
		robot.setHold(0);
		return 1;
	}else if(robot.getHold() == 0 && robot.getPlate()==sort)
	{
		FromPlate(robot.getPlate());
		robot.setHold(robot.getPlate());
		robot.setPlate(0);

		PutDown(robot.getHold());
		robot.setHold(0);
		return 1;
	}else if(robot.getHold() !=0 && robot.getPlate()==sort)
	{
		int flag = 0;
		for(int i=0;i<maxNode;i++)
		{
			if(G.getStatus(sort,i)==1)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			PutDown(robot.getHold());

			FromPlate(robot.getPlate());
			robot.setHold(robot.getPlate());
			robot.setPlate(0);
			PutDown(robot.getHold());
			robot.setHold(0);
			return 1;
		}
	}
	return 0;
}
int Devil::pickup(int sot,Sort sort[],Robot &robot,Graph G)
{
	int flag = 0;
	if(robot.getHold()!=0)
	{
		PutDown(robot.getHold());
		cout<<"I'm running Pickup ,i need putdown "<<robot.getHold()<<endl;
		robot.setHold(0);
	}
	flag = PickUp(sot);
	if(flag==1)
	{
		robot.setHold(sot);
		if(robot.getPlate()==0)
			{
				ToPlate(robot.getHold());
				robot.setPlate(robot.getHold());
				robot.setHold(0);
			}
	}
	if(flag == 0)
	{
		vector <unsigned int> obj;
		Sense(obj);
		for(vector<unsigned int>::iterator it =obj.begin();it!=obj.end();it++)
			cout<<"I can see"<<*it<<" My location is "<<robot.getLoc()<<endl;
	}

	return flag;
}
