#include "devil.hpp"
using namespace _home;
int getAskLoc(string str,Sort sort[])
{
	int loc = -1;
	int left = 0,right = 0, mid = 0;
	int obj1,obj2;
	string str1,str2,str3;
	left = str.find("(");
	mid = str.find(",");
	right = str.find(")");
	str1 = str.substr(0,left);
	str2 = str.substr(left+1,mid-left-1);
	str3 = str.substr(mid+1,right-mid-1);
	if(str1 == "inside")
	{
		obj2 = atoi(str3.c_str());
		obj1 = atoi(str2.c_str());
		sort[obj1-1].setsInside(obj2);
		cout<<"getinside "<<obj1<<" "<<sort[obj1-1].getsInside()<<endl;
		sort[obj2-1].sinsideD.push_back(obj1);
		loc = sort[obj2-1].getsLoc();
	//	sort[obj1-1].setsLoc(loc); //此行有bug不知道为什么
	//	cout<<"This is askloc i get location :) \n";
	//	cout<<obj1<<" location is "<<sort[obj1-1].getsLoc()<<endl;

	}
	if(str1 == "at")
	{
		loc = atoi(str3.c_str());
	//	sort[obj1-1].setsLoc(loc);//同上面一行一样
	//	cout<<"This is askloc i get location :) \n";
	//	cout<<obj1<<" location is "<<sort[obj1-1].getsLoc()<<endl;
	}
	return loc;
}
int checkTakeout(int sotx,int soty,Graph G)
{
	return G.getDirection(sotx,soty);
}
int checkConnectionBig(int sot,Graph G,int taskCode,int present)
{
	int i = 0;
	cout<<"This is checkConnectionBig()\n";
	for( i=0; i < maxNode; i++)
	{
        if( i == present)
            continue;
		if(G.getDirection(i,sot) == taskCode && G.getStatus(i,sot)==1)
		{
			return i;
 		}
 	}
	cout<<"checkConnectionBig() is over!()\n";
	return 0;
} 
int checkConnectionLoc(int sot,Graph G)
{
	for(int i=0; i<maxNode;i++)
	{
		if(G.getStatus(sot,i)==1)
			return i;
	}
}
int checkConnectionSmall(int sot,Graph G)
{
    int i=0;
    for(i=0; i<maxNode; i++)
     {
        if(G.getStatus(sot,i)==1)
         {
            cout<<sot<<" connection with "<< i <<endl;
            return G.getDirection(sot,i);
     	}    
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
	string loc;
	if(sort[sot-1].getsLoc()==-1)
	{
	//	cout<<AskLoc(sot)<<endl;
		sort[sot-1].setsLoc(getAskLoc(AskLoc(sot),sort));
		cout<<"I get it location :) \n";
		cout<<sot<<" location is "<<sort[sot-1].getsLoc()<<endl;
	}
	if(robot.getLoc()!= sort[sot-1].getsLoc())
 	{
		 flag=Move(sort[sot-1].getsLoc());
		robot.setLoc(sort[sot-1].getsLoc());
		if(robot.getHold()!=0)
            sort[robot.getHold()-1].setsLoc(sort[sot-1].getsLoc());
        if(robot.getPlate()!=0)
            sort[robot.getPlate()-1].setsLoc(sort[sot-1].getsLoc());
	}
	return flag;
}
void Devil::checkPlate(Robot &robot,Graph G)
{
	cout<<"This is checkPlate\n";
	int plate = robot.getPlate();
	if(plate == 0) {
		return;
	} else {
		if(checkConnectionSmall(plate,G)==0)
		{
			FromPlate(plate);
			robot.setPlate(0);
			PutDown(plate);
			cout<<"This sort in my plate is useless i will putdown\n";
		}
	}

	cout<<"checkPlate()\n";
}
void Devil::checkHold(Robot &robot,Graph &G)
{
	cout<<"{{{{{{{{{{{{{This is checkHold}}}}}}}}}}}}}}}\n";
	int hold = robot.getHold();
	int flag = 0;
	if(hold == 0)
	{
		return;
	}
	else
	{
		cout<<"robot.getUseHold()->"<<robot.getUsehold()<<endl
			<<"robot.getUseplate()->"<<robot.getUseplate()<<endl;
		if(robot.getUsehold() == 0 && robot.getUseplate() == 0)
		{
			if(checkConnectionSmall(hold,G) == 0)
			{
				PutDown(hold);
				robot.setHold(0);
				cout<<"This sort in my hand is useless i will putdown "<<hold<<endl;
			}
			if(checkConnectionSmall(hold,G)==4)
			{
				G.setStatus(hold,0,PutDown(hold));
				robot.setHold(0);
				cout<<"This sort i need putdown"<<endl;
			}
		}
		else if(robot.getUsehold() == 1 && robot.getUseplate() == 0)
		{
			ToPlate(hold);
			robot.setPlate(hold);
			robot.setHold(0);
			robot.setUseplate(4);
			robot.setUsehold(0);
		}
	}
	cout<<"{{{{{{{{{{{{{{{{{{{{{{{{{{checkHold is over}}}}}}}}}}}}}}}}}}\n";

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
	cout<<"\n==================================================="<<endl;
	int flag = 0;
	if(!sort[sot-1].getsClosed())
	{
		cout<<"No."<<sot<<" closed "<<sort[sot-1].getsClosed()<<endl;
		cout<<"==================================================="<<endl;
		return 1;
	}
//	if(G.getStatus(sot,0)==0)
//	  return 1;
	int checkHold = 0, checkPlate=0;
	cout<<"\nthis is open, i will checkHold\n";
	checkHold = checkConnectionSmall(robot.getHold(),G);
	cout<<"\nthis is open, checkHold is over\n";
	cout<<"\nthis is open, i will checkPlate\n";
	checkPlate = checkConnectionSmall(robot.getPlate(),G);
	cout<<"\nthis is open, checkPlate is over\n";
	if(robot.getUsehold()==0&&robot.getUseplate()==0)
    {
		cout<<"deal with something in open()\n";
		if(checkHold!=0&&robot.getHold()!=0&&robot.getPlate()==0)
		{
			cout<<"Before open big sort,my hand have other sort, i need it->"<<robot.getHold()<<" put it in plate\n";
			ToPlate(robot.getHold());
			robot.setPlate(robot.getHold());
			robot.setHold(0);
		}
		if(checkHold!=0&&checkPlate!=0&&robot.getHold()!=0&&robot.getPlate()!=0)
		{
			cout<<"In my hand and plate sort i need they,so i will putdown hand->"<<robot.getHold()<<endl;
			PutDown(robot.getHold());
			robot.setHold(0);
		}
		if(checkHold!=0&&checkPlate==0&&robot.getHold()!=0&&robot.getPlate()!=0)
		{
			cout<<"I need my hand and i don't need my plate,so i will putdown my plate,let my hand to my plate"<<endl;
			cout<<"这个地方步骤有些多余,还可以省略"<<endl;
			PutDown(robot.getHold());
			FromPlate(robot.getPlate());
			PutDown(robot.getPlate());
			PickUp(robot.getHold());
			ToPlate(robot.getHold());

			robot.setPlate(robot.getHold());
			robot.setHold(robot.getPlate());
		}
  //      if(checkConnectionSmall(robot.getHold(),G)!= 0 && robot.getHold()!=0)
  //    {
  //          cout<<"Befor open big sort,my hand have other sort, i need it -> "<<robot.getHold()<<" i will put it in my plate"<<endl;
  //          ToPlate(robot.getHold());
  //          robot.setPlate(robot.getHold());
  //          robot.setHold(0);
 //       }
 		if(checkHold==0&&robot.getHold()!=0)
		{
			cout<<"Before open action,my hand has a useless sort,i will putdown ->"<<robot.getHold()<<endl;
			

			PutDown(robot.getHold());
			robot.setHold(0);
		}
  //      else if(checkConnectionSmall(robot.getHold(),G)==0&&robot.getHold()!=0)
   //    {
   //         cout<<"Before open big sort,my hand have other sort, i need pudown it -> "<<robot.getHold()<<endl;
   //         PutDown(robot.getHold());
   //         robot.setHold(0);
    //    }
    }
    //此处对约束进行处理
    if(robot.getUsehold()==1)
    {
		cout<<"this is open, robot.getUsehold == 1"<<endl;
		if(robot.getHold() != 0 && robot.getPlate() == 0)
		{
		   	ToPlate(robot.getHold());
      	    robot.setPlate(robot.getHold());
       	    robot.setHold(0);
       	    robot.setUsehold(0);
      	    robot.setUseplate(1);
		}
		if(robot.getHold() == 0 )
		{
			robot.setUsehold(0);
		}
    }
    if(robot.getUseplate()==1&&robot.getHold()!=0)
    {
           PutDown(robot.getHold());
           robot.setHold(0);
    }

	if(checkOpen(sot,sort)==0)
	{
		flag = Open(sot);
		sort[sot-1].setsClosed(0);
		cout<<"Sir,I'm open :"<<sot<<" statue :"<<flag
			<<" checkOpen result :"<<checkOpen(sot,sort)<<endl;	
	} else if(checkOpen(sot,sort)== 1)
	{
        flag = -1;
	}
	cout<<"open() is over"<<endl;
	cout<<"====================================================="<<endl;
	return flag;
}

int Devil::takeout(int sot,Sort sort[],Robot &robot,Graph G)
{
	cout<<"\nthis is takeout\n";
	int flag = 0,checkOpen = 0;
	int act2 = sort[sot-1].getsInside();
	cout<<"this is my location -> "<<robot.getLoc()
		<<" the target location is -> "<<sort[act2-1].getsLoc()<<endl;
	if(robot.getLoc() != sort[act2-1].getsLoc())
	{
		move(act2,sort,robot);
	}
//	if(G.getStatus(sot,act2)==0)
//	  return 0;
	cout<<"This is take -> "<<sot<<" from -> "<<act2<<endl;
	checkOpen = open(act2,sort,robot,G);
	if(checkOpen==1)
	{
		cout<<"I open this sort ->"<<act2<<endl;
	}
	else if (checkOpen == 0 )
	{
		cout<<"Sorry, I can't open this sort -> "<<act2<<endl;
	}
	else if(checkOpen == -1)
    {
        cout<<"door is opened\n";
    }
	if(robot.getHold()!=0 && robot.getPlate() == 0 && robot.getUseplate() == 0)
	{
		ToPlate(robot.getHold());
		robot.setPlate(robot.getHold());
		robot.setHold(0);
	}
    flag = TakeOut(sot,act2);
	if(flag == 0)
	{
		cout<<"THis is takeout(), i will open :"<<act2<<endl;
		Open(act2);
		cout<<"This is takeout(), open is over "<<endl;
		flag = TakeOut(sot,act2);
	}
    if(flag == 1)
    {
        robot.setHold(sot);
        sort[sot-1].setsInside(-1);
    }
	cout<<"Sir, I'm takeout: "<<sot<<" from "<<act2<<endl;
	cout<<"takeout is over\n";
	return flag;
}

int Devil::close(int sot,Sort sort[],Robot &robot,Graph &G)
{
	int flag = 0,flag2=0;
	int check_container = 0;
	//在关闭前应当检查该物体内部有没有
	//其他任务所需要的物品
	check_container = checkContainer(sot,sort,G);
	if(check_container != 0)
	{
		cout<<"In this container,have a sort -> ";
		printVector(sort[sot-1].sinsideD);
		cout<<" i need it"<<endl;
		flag2 = takeout(check_container,sort,robot,G);
		if(checkTakeout(check_container,sot,G)==-1)
			G.setStatus(check_container,sot,flag2);
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
	cout<<"***************************************\n";
	int flag = 0;
	checkHold(robot,G);
	cout<<"I want get "<<sot<<endl;
    if(robot.getLoc() != sort[sot-1].getsLoc())
    {
        move(sot,sort,robot);
        if(sort[sot-1].getsInside()!=-1)
        {
			cout<<"This is getSort, i will into takeout\n";
            flag = takeout(sot,sort,robot,G);
			cout<<"I from takeout() get to getSort()\n";
        }
		else
		{	cout<<"This is getSort, i will into pickup\n";
            flag = pickup(sot,sort,robot,G);
			cout<<"I from pickup() get to getSort()\n";
		}
    }
    else
    {
        cout<<"This sort loc same with me"<<endl;
        if(sort[sot-1].getsInside()!=-1)  //inside
        {
            flag = takeout(sot,sort,robot,G);
        }
        if(robot.getHold()!=sot&&robot.getPlate()!=sot)
        {
            flag = pickup(sot,sort,robot,G);
        }
    }
	cout<<"getSort is over\n";
	cout<<"***************************************\n";
	return flag;
}
int Devil::putin(int smallsot,int sot,Sort sort[],Robot &robot,Graph &G)
{
	int flag = 0,flag2=0;
	int act1;
	cout<<"\nmy location is -> "<<robot.getLoc()<<endl;
	cout<<"\nmy sort location is -> "<<sort[smallsot-1].getsLoc()<<endl;
	if(robot.getPlate() != smallsot && robot.getHold() == 0 && robot.getLoc() == sort[smallsot-1].getsLoc())
	{
		PickUp(smallsot);
		robot.setHold(smallsot);
	}
//	open(sot,sort,robot,G);
	if(robot.getHold()==0&&robot.getPlate() == smallsot)
	{
		cout<<"my plate -> "<<robot.getPlate()<<" now put it to hand"<<endl;
		cout<<"smallsot -> "<<smallsot<<endl;
		FromPlate(robot.getPlate());
		robot.setHold(robot.getPlate());
		robot.setPlate(0);
	}
	act1 = robot.getHold();
	cout<<"i will putin"<<act1<<" "<<sot<<" "<<G.getStatus(act1,sot)<<endl;
	if(G.getStatus(act1,sot)==0)
	  return 0;
//	open(sot,sort,robot,G);
	if(act1 == smallsot)	//可能手中不是本次任务所需的物品
		flag = PutIn(act1,sot);
	else
	{
		flag2 = PutIn(act1,sot);
		robot.setHold(0);
		G.setStatus(act1,sot,flag2);
		getSort(smallsot,sort,robot,G);
		flag = PutIn(robot.getHold(),sot);
	}
	if(flag == 0)
	{
		PutDown(robot.getHold());
		Open(sot);
		PickUp(robot.getHold());
		flag = PutIn(robot.getHold(),sot);
	}
	if(flag == 0)
	{
		sense(robot);
	}
	robot.setHold(0);
	sort[act1-1].setsInside(sot);
	cout<<"Sir, I'm put "<<act1 <<" in "<<sot<<endl;
	return flag;
}
int Devil::puton(int sotx,int soty,Sort sort[],Robot &robot,Graph &G)
{
	cout<<"\nThis is puton()\n";
	int flag = 0,obj2;
	getSort(sotx,sort,robot,G);
	//此处obj2为另一个任务中的小物体，其目的地与当前任务相同
	obj2 = checkConnectionBig(soty,G,G.getDirection(sotx,soty),sotx);
	cout<<"This is puton obj2 --> "<<obj2<<endl;
	if(obj2 != 0 && robot.getUseplate() == 0)
    {
		cout<<"\nthis is puton i want to get other sort, i will into getsort\n";
        getSort(obj2,sort,robot,G);
		cout<<"\n i come from getsort to puton\n";
    }
    move(soty,sort,robot);
    if(obj2 == 0)
    {
        cout<<"puton---only---obj1\n";
       // flag = putdown(robot.getHold(),sort,robot,G); //pickup --bug
	   	flag = putdown(sotx,sort,robot,G);
        robot.setHold(0);
    }else
    {
        cout<<"puton---obj1---obj2\n";
        cout<<"robot.getHold()---"<<robot.getHold()<<endl;
        putdown(robot.getHold(),sort,robot,G);
        FromPlate(robot.getPlate());
        robot.setHold(robot.getPlate());
        robot.setPlate(0);
        flag = putdown(robot.getHold(),sort,robot,G);

        G.setStatus(obj2,soty,flag);
        cout<<"checkputon"<<obj2<<"----"<<soty<<"----"<<G.getStatus(obj2,soty)<<endl;
    }
	cout<<"puton() over!\n";
	return flag;
}
int Devil::putdown(int sot,Sort sort[],Robot &robot,Graph &G)
{

	int act1;
	int flag = 0;
	cout<<"I will put"<<sort[sot-1].getsName()<<" down"<<endl;
	if(robot.getHold()!=sot&&robot.getPlate()!=sot)
	{
		getSort(sot,sort,robot,G);
	}
	if(robot.getHold()==sot&&robot.getPlate()!=0)
    {
        flag = PutDown(robot.getHold());
    }
	else if(robot.getHold() == sot && robot.getPlate()==0)
	{
		flag = PutDown(robot.getHold());
	}else if(robot.getHold() == 0 && robot.getPlate()==sot)
	{
		FromPlate(robot.getPlate());
		robot.setHold(robot.getPlate());
		robot.setPlate(0);

		flag=PutDown(robot.getHold());
	}else if(robot.getHold() !=0 && robot.getPlate()==sot)
	{
		int flag1 = 0;
		for(int i=0;i<maxNode;i++)
		{
			if(G.getStatus(sot,i)==1)
			{
				flag1 = 1;
				break;
			}
		}
		if(flag1 == 1)
		{
			PutDown(robot.getHold());

			FromPlate(robot.getPlate());
			robot.setHold(robot.getPlate());
			robot.setPlate(0);
			flag = PutDown(robot.getHold());
		}
	}
	if(flag==1)
		robot.setHold(0);
	return flag;
}
int Devil::pickup(int sot,Sort sort[],Robot &robot,Graph G)
{
	cout<<"\n\nthis is pickup()\n\n";
	int flag = 0;
	if(robot.getHold()!=sot&&robot.getHold()!=0&&robot.getUsehold()==0)
	{
		PutDown(robot.getHold());
		cout<<"i need:"<<sot<<"\t";
		cout<<"I'm running Pickup ,i need putdown "<<robot.getHold()<<endl;
		robot.setHold(0);
	}
	if(robot.getUsehold()==4&&robot.getHold()!=0)
    {//针对约束
        ToPlate(robot.getHold());
        robot.setPlate(robot.getHold());
        robot.setHold(0);
        robot.setUsehold(0);
        robot.setUseplate(4);
    }
	if(sort[sot-1].getsInside()==-1)
	{
		cout<<"i will pickup -> "<<sot;
		flag = PickUp(sot);
		cout<<" result -> "<<flag<<endl;
	}
	else
	{	
		cout<<" i will takeout -> "<<sot;
		flag = takeout(sot,sort,robot,G);
		cout<<" result -> "<<flag<<endl;
	}
	if(flag==1)
	{
		robot.setHold(sot);
//		if(robot.getPlate()==0&&checkConnectionSmall(robot.getHold(),G)!=0)
//			{//嵌套的if防止当前物体在任务位置被放进盘子中
				//此处处理的不好，当pickup完后可能会直接放到盘子里
//				int obj2 = checkConnectionLoc(robot.getHold(),G);
//				if(sort[obj2-1].getsLoc()!=robot.getLoc())
//				{
//					cout<<"This is pickup - ToPlate running :)\n";
//					cout<<sort[obj2-1].getsName()<<" location is "<<sort[obj2-1].getsLoc()<<endl;
//					cout<<"robot location is "<<robot.getLoc()<<endl;
//					ToPlate(robot.getHold());
//					robot.setPlate(robot.getHold());
//					robot.setHold(0);
//				}
//			}
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


void Devil::getLostLocFromTask(Task task[],int taskNum,Sort sort[])
{
	cout<<"This is getLostLocFromTask()"<<endl;
	int where[30]={0};
	int j = -1;
	//mark
	for(int i=0; i<=taskNum;i++)
	{
		if(task[i].getTaskLocx()==-1)
		{
			cout<<"task_sort:"<<task[i].getTaskAct1()<<" "<<task[i].getTaskLocx()<<endl; 
			where[i] = task[i].getTaskAct1(); //mark
		}
	}
	//find
	for(int i=0; i<30;i++)
	{
		if(where[i] != 0 &&sort[where[i]-1].getsLoc()==-1)
		{
			j =  getAskLoc(AskLoc(where[i]),sort);
			if(j == -1)
			{
				j = getAskLoc(AskLoc(where[i]),sort);
				if(j == -1)
				{
					j = getAskLoc(AskLoc(where[i]),sort);
				}
			}
			task[i].setTaskLocx(j);
			sort[task[i].getTaskAct1()-1].setsLoc(j);
			cout<<"Sort:"<<task[i].getTaskAct1()<<" "<<" loc is "
				<<sort[task[i].getTaskAct1()-1].getsLoc()<<endl;
		}
	}
	//reduction
	cout<<"getLostLocFromTask() is over"<<endl;
}


void Devil::dealwithpickup(Task task[],int taskNum,Sort sort[],Robot &robot,Graph G)
{
	cout<<"\nthis is dealwithpickup() \n";
	for(int i = 0; i <= taskNum; i++)
	{
		if(task[i].getTaskAction()=="pickup")
		{
			if(robot.getHold() == task[i].getTaskAct1() || robot.getPlate()== task[i].getTaskAct1())
			{
				break;
			}
			getSort(task[i].getTaskAct1(),sort,robot,G);
		/*	
		 	move(task[i].getTaskAct1(),sort,robot);
			if(robot.getHold() != 0 && robot.getPlate() == 0)
			{
				ToPlate(robot.getHold());
				robot.setHold(0);
			}
			else if(robot.getHold() !=0 && robot.getPlate() != 0)
			{
				PutDown(robot.getHold());
				robot.setHold(0);
			}

			PickUp(task[i].getTaskAct1());
			robot.setHold(task[i].getTaskAct1());
		*/
		}
	}
	cout<<"\ndealwithpickup is over\n";
}
void Devil::dealwithgoto(Task task[],int taskNum,Sort sort[],Robot &robot)
{
	for(int i = 0;i<=taskNum;i++)
 	{
		if(task[i].getTaskAction()=="goto")
		{
			move(task[i].getTaskAct1(),sort,robot);
 		}
	}
}

void Devil::dealwithputdown(Task task[],int taskNum,Sort sort[],Robot &robot)
{
	cout<<"\n\nThis is dealwithputdown()\n\n";
	int i,j;
	int hold = robot.getHold();
	int plate = robot.getPlate();
	int flag1 = 0, flag2 = 0;
	for(i = 0; i <= taskNum; i++)
	{
		if(robot.getUsehold() == 0 && robot.getUseplate() == 0)
		{
			cout<<"i -> "<<i<<" flag1 -> "<<flag1
				<<" flag2 -> "<<flag2<<endl;
			if( hold == 0 && plate == 0)
			{ 
				break;		
			}
			if( hold == task[i].getTaskAct1())
			{
				cout<<"this is hold "<<task[i].getTaskAct1()<<endl;
					flag1 = 1;
			}
			if(plate == task[i].getTaskAct1())
			{
				cout<<"this is plate "<<task[i].getTaskAct1()<<endl;
					flag2 = 1;
	 		}
			
			
		}
	}


	if(hold !=0 && plate != 0 && flag1 == 0 && flag2 == 0)
	{
		cout<<"i will putdown "<<hold<<" "<<plate<<endl;
		PutDown(hold);
		robot.setHold(0);
		FromPlate(plate);
		PutDown(plate);
		robot.setPlate(0);
	}
	if( hold != 0 && flag1 == 0 && flag2 == 1)
	{
		cout<<"i will putdown "<<hold<<endl;
		PutDown(hold);
		robot.setHold(0);
	}

	cout<<"\n\ndealwithputdown() is over\n"<<endl;
}

void Devil::sense(Robot robot)
{
	vector <unsigned int> sort;
	Sense(sort);
	for(vector<unsigned int>::iterator it = sort.begin();it!=sort.end();it++)
		cout<<"I can see "<<*it<<" My location is "<<robot.getLoc()<<endl;
}
