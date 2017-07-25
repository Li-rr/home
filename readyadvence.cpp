#include "readyadvence.h"
void getVector(int small[],vector<int> v)
{
	int i=0;
	for(vector<int>::iterator it = v.begin();it!=v.end();it++,i++)
	{
		small[i] = *it;
	}
}
void printVector(vector<int> v)
{
	cout<<"This is printVector()\n";
	for(vector<int>::iterator it = v.begin();it!=v.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<"printVector() is over.\n";
}
void dealwithtask(string TASK,Task task[], int &taskMaxnum)
{/*{{{*/
    int i=-1,flag=0;  //flag用来判断当前字符串是否属于任务
    string str1="",str2="";
    vector<string> vStr;
    boost::split( vStr, TASK, boost::is_any_of( "( ):" ), boost::token_compress_on );
    for( vector<string>::iterator it = vStr.begin(); it != vStr.end(); it++)
    {
        //cout<<*it<<endl;
        if(*it == "task" && * (it-1)=="cons_not"||*it=="task"&& *(it-1)=="cons_notnot")
           {
               continue;
           }
        if(*it == "task")
        {
            i=i+1;
            flag=1;
            task[i].setTaskNo(i+1);
       //     cout<<"this is task"<<endl;
        } else if(*it == "cons_not"||*it=="cons_notnot"||*it=="info")
        {
            flag=0;
        }
        if(flag&&(*it == "open" || *it =="close"||*it=="takeout"|| *it=="putin"||*it=="goto"||*it=="pickup"
                  ||*it=="putdown"||*it=="give"||*it=="puton"))
        {
            cout<<*it<<endl;
            if(*(it+2)!="Y")
                str2="";
            else
                str2=*(it+2);
            task[i].setTaskAction(*it,*(it+1),str2);
        }
        if(flag&& *it=="sort")
        {
            if(*(it+1)=="X")
                task[i].setTaskNamex(*(it+2));
            else if(*(it+1)=="Y")
                task[i].setTaskNamey(*(it+2));
                cout<<"***"<<task[i].getTaskNamex()<<endl;
        }
        if(flag&& *it=="color")
        {
            if(*(it+1)=="X")
                task[i].setTaskColorx(*(it+2));
            else
                task[i].setTaskColory(*(it+2));
        }
        if(flag && *it =="type")
        {
            if(*(it+1)=="X")
                task[i].setTaskNamex(*(it+2));
            else if(*(it+1)=="Y")
                task[i].setTaskNamey(*(it+2));
        }
        taskMaxnum=i;
    }
}/*}}}*/
//
//
//
void dealwithsence(string STR,Sort sort[],Robot &robot, int &senceMax)
{/*{{{*/
 //   cout<<"this is dealwithsence"<<endl;
    int obj1=0,obj2=0;
    string str1="",str2="";
    vector<string> vStr;
    boost::split( vStr, STR, boost::is_any_of( "( )" ), boost::token_compress_on );
    for( vector<string>::iterator it = vStr.begin(); it != vStr.end(); it++)
    {
        if(*it == "at")
        {
            str1 = *(it+1);
            obj1 = atoi(str1.c_str());
            str2 = *(it +2);
            obj2 = atoi(str2.c_str());
            if(obj1)
            {
                  sort[obj1-1].setsLoc(obj2);
                sort[obj1-1].setsNum(obj1);
            }
            else
                 {
                 	robot.setLoc(obj2);
                 }
        }
        if(*it == "plate")
        {
                        str1 = *(it+1);
            obj1 = atoi(str1.c_str());
            robot.setPlate(obj1);
        }
        if(*it == "hold")
        {
                        str1 = *(it+1);
            obj1 = atoi(str1.c_str());
            robot.setHold(obj1);
        }
        if(*it == "sort")
        {
                str1 = *(it+1);
            obj1 = atoi(str1.c_str());
            sort[obj1-1].setsName(*(it+2));
               sort[obj1-1].setsNum(obj1);
			   sort[obj1-1].setsBigSort(*(it+2));
			   sort[obj1-1].setStatic(*(it+2));
        }
        if(*it == "size")
        {
                           str1 = *(it+1);
            obj1 = atoi(str1.c_str());
            sort[obj1-1].setsSize(*(it+2));
               sort[obj1-1].setsNum(obj1);
        }
        if(*it == "color")
        {
                           str1 = *(it+1);
            obj1 = atoi(str1.c_str());
            sort[obj1-1].setsColor(*(it+2));
               sort[obj1-1].setsNum(obj1);
        }
        if(*it == "inside")
        {
            str1 = *(it+1);
            obj1 = atoi(str1.c_str());
              str2 = *(it +2);
            obj2 = atoi(str2.c_str());
            sort[obj1-1].setsInside(obj2);
               sort[obj1-1].setsNum(obj1);
			sort[obj2-1].sinsideD.push_back(obj1);
        }
        if(*it == "closed")
        {
                                                   str1 = *(it+1);
            obj1 = atoi(str1.c_str());
            sort[obj1-1].setsClosed(1);
               sort[obj1-1].setsNum(obj1);
        }
        if(*it == "type")
        {
                    str1 = *(it+1);
            obj1 = atoi(str1.c_str());
            sort[obj1-1].setsType(*(it+2));
               sort[obj1-1].setsNum(obj1);
        }
        if(obj1>senceMax)
        {
            senceMax=obj1;
        }
    }/*}}}*/
}

void dealwithInfoCons(string TASK,InfoCons info_cons[],int &numMax,string SIGN)
{/*{{{*/
    cout<<"this is dealwithInfoCons-start.-"<<SIGN<<endl;
    int i=-1;
    int flag=0;
    string str1="",str2="";
    //choice==1,代表info
//choice==2,代表cons
//choice==3,代表cons_not
//SIGN 代表info || cons || cons_nots
    string Flag[4]={"info","task","cons_not","cons_notnot"};
    vector<string> vStr;
    boost::split( vStr, TASK, boost::is_any_of( "( ):" ), boost::token_compress_on );
    for( vector<string>::iterator it = vStr.begin(); it != vStr.end(); it++)
    {
        if(*it == SIGN)
        {

            if(*(it-1)=="cons_not"||*(it-1)=="cons_notnot")
            {
                //此if针对cons_not或cons_notnot后跟着的info
                continue;
            }
            i++;
            info_cons[i].setNo(i+1);
            flag=1;
            cout<<"I'm find it"<<SIGN<<endl;
        }
        for(int j=0;j<4;j++)
        {
            if(*it!=SIGN&&*it==Flag[j])
                flag=0;
        }
            if((*it=="info"||*it=="task")&&*(it-1)==SIGN)
                    flag=1;
        if(flag&&(*it=="at"||*it== "on"||*it=="near"||*it=="plate"||*it=="inside"||*it=="opened"||*it=="closed"||*it=="give"
           ||*it=="puton"||*it=="goto"||*it=="putdown"||*it=="pickup"||*it=="open"||*it=="putin"||*it=="close"||*it=="takeout"))
        {
            cout<<*it<<endl;
            if(*(it+2)!="Y")
                str2="";
            else
                str2=*(it+2);
            info_cons[i].setState(*it);
           info_cons[i].setState1(*(it+1));
           info_cons[i].setState2(str2);
        }
        if(flag&&(*it=="sort"))
        {
            cout<<"this is info-cons-sort "<<*(it+2)<<endl;
                if(*(it+1)=="X")
                    info_cons[i].setNamx(*(it+2));
                else if(*(it+1)=="Y")
                    info_cons[i].setNamy(*(it+2));
        }
        if(flag&&(*it=="color"))
        {
            cout<<"this is info-cons-color "<<*(it+2)<<endl;
            if(*(it+1)=="X")
                info_cons[i].setColorx(*(it+2));
            else if(*(it+1)=="Y")
                info_cons[i].setColory(*(it+2));
        }
        numMax=i;
    }
}/*}}}*/
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
int findSortByName(int sNum,string name,string color,Sort sort[])
{
	int i;
	for(i=0;i<sNum;i++)
	{
		if(sort[i].getsName()==name&&sort[i].getsColor()==color)
		{
			cout<<"this is findSortByName&Color, i find it: "<<sort[i].getsNum()<<endl;
			return i;
		}
	}
	return -1;
}
int findSortByName(int sNum,string name,Sort sort[])
{/*{{{*/
    int i;
    for(i=0; i<sNum; i++)
     {
        if(sort[i].getsName() ==name)
            return i;
    }
    return -1;
}/*}}}*/
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
void judgewithCons(InfoCons cons_nn[],int consNn,Task task[],int taskNum,Sort sort[],int sortNum)
{/*{{{*/
    string sameName;  //same with sort
    for(int i=0; i<=consNn; i++)
    {
        for(int j=0; j<=taskNum; j++)
        {
            ///////////////////////////////////////////////////////////
            //main body
            //首先保证约束被满足
            if(cons_nn[i].getNamex()==task[j].getTaskNamex())
            {
                // cout<<"We are same. cnx-tx\n";
                sameName=cons_nn[i].getNamex();
                for(int z=0; z<sortNum; z++)
                {
                    if(sameName==sort[z].getsName() && cons_nn[i].getColorx()==sort[z].getsColor())
                    {
                        sort[z].setsLock();
                        sort[z].reduce(sort[z].getsName()); //针对updateTask函数if(sort[j].getsStatic(sort[j].getsName())==1)设立
                        cons_nn[i].setState1(z+1);
                        //cout<<"z--->"<<z<<endl;
                    }
                }
            }
            /////////////////////////////////////////
            if(cons_nn[i].getNamex()==task[j].getTaskNamey())
            {
                // cout<<"We are same.  cnx-ty\n";
                sameName = cons_nn[i].getNamex();
                for(int z=0; z<sortNum; z++)
                {
                    if(sameName==sort[z].getsName()&&cons_nn[i].getColorx()==sort[z].getsColor())
                    {
                        sort[z].setsLock();
                        cons_nn[i].setState1(z+1);
                    }
                }
            }
            //////////////////////////////////////
            if(cons_nn[i].getNamey()==task[j].getTaskNamex())
            {
                //cout<<"We are same. cny-tx.\n";
                sameName=cons_nn[i].getNamey();
                for(int z=0; z<sortNum; z++)
                {
                    if(sameName==sort[z].getsName()&&cons_nn[i].getColory()==sort[z].getsColor())
                    {
                        sort[z].setsLock();
                        cons_nn[i].setState2(z+1);
                    }
                }
            }
            ///////////////////////////////////////////////////////////////
            if(cons_nn[i].getNamey()==task[j].getTaskNamey())
            {
                //cout<<"We are same. cny-ty.\n";
                sameName = cons_nn[i].getNamey();
                for(int z=0; z<sortNum; z++)
                {
                    if(sameName==sort[z].getsName()&&cons_nn[i].getColory()==sort[z].getsColor())
                    {
                        sort[z].setsLock();
                        cons_nn[i].setState2(z+1);
                    }
                }
            }
            //////////////////////////////////////////////////////////////
        }
    }
}/*}}}*/
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/*
 *处理Task中出现同名未匹配的物体
 */
void aboutTaskLackMatch(Task task[],Sort sort[],int sNum,int tNum,Robot &robot)
{
	cout<<"\n this is aboutTaskLackMatch\n";
	int i = 0,j = 0,k=0;
	for( i=0; i<=tNum; i++)
	{
		if(task[i].used)
		  continue;
		for(j=0;j<sNum;j++)
		{
			if(task[i].getTaskNamex()==sort[j].getsName())
			{
                if(!sort[j].taskLock&&task[i].getTaskAction()=="takeout")
				{
					cout<<"this is match takeout act1"<<endl;
					if(sort[j].getsInside()==-1)
                        continue;
					if(sort[sort[j].getsInside()-1].getsName()==task[i].getTaskNamey())
					{
						cout<<"***"<<endl;
						task[i].setTaskAct1(sort[j].getsNum());
						sort[j].used = 1;
						sort[j].needMatch = 0;
						task[i].used = 1;
					}
				}
				if(sort[j].needMatch&&task[i].getTaskAction()=="putdown")
				{
					cout<<"this is match putdown act"<<endl;
					if(sort[j].getsNum()==robot.getHold())
					{
						task[i].setTaskAct1(sort[j].getsNum());
						sort[j].used = 1;
						sort[j].needMatch = 0;
						task[i].used = 1;
						sort[j].taskLock = 1; //此物体在任务中不在被匹配
					}
				}



				if(!sort[j].taskLock&&task[i].getTaskAction()=="putin")
				{
					cout<<"this is mtact putin act1"<<endl;
					if(sort[j].getsNum()==robot.getHold())
					  continue;
					task[i].setTaskAct1(sort[j].getsNum());
					sort[j].used = 1;
					sort[j].needMatch = 0;
					task[i].used = 1;
				}
		}
		}
	}
	cout<<"\n this is aboutTaskLackMatch\n";
}
void updateTask(Sort sort[],Task task[],int sortNum,int taskNum,Robot &robot)
{
	cout<<"\nThis is updateTask\n";
    int i=0,j=0;
	int count = 0;
    for(i=0;i < taskNum + 1;i++)
    {
		count = 0;
        cout<<task[i].getTaskNamey()<<endl;
        for(j=0;j<sortNum;j++)
        {
         //   if(task[i].getTaskNamex()==sort[j].getsName()&&sort[j].getsLocked()==0)
           	if(task[i].getTaskNamex()==sort[j].getsName())
		   	{
               // cout<<"This taskx match "<<task[i].getTaskNamex()<<endl;
                sort[j].needMatch=1;
                    /* if(sort[j].getsStatic(sort[j].getsName())==1&&sort[j].getsLocked()==0)
                    {
                        task[i].setTaskAct1(j+1);
                        task[i].used=1;
                        sort[j].used=1;
                        sort[j].needMatch=0;
                    }*/
                    if(task[i].getTaskColorx()==sort[j].getsColor())
                    {
                        cout<<i<<" "<<j<<" match it "<<sort[j].getsName()<<" "<<sort[j].getsColor()<<endl;
                        task[i].setTaskAct1(j+1);
                        task[i].used=1;
                        sort[j].used=1;
                        sort[j].needMatch=0;
                     }
					if(task[i].used==0&&sort[j].getsStatic(sort[j].getsName())==1&&sort[j].getsLocked()==0)
			 		{
						cout<<"Task."<<task[i].getTaskAction()<<" name."<<task[i].getTaskNamex()
							<<" colorx."<<task[i].getTaskColorx()<<endl;
						cout<<"Sort."<<sort[j].getsName()<<" color."<<sort[j].getsColor()<<endl;
						task[i].setTaskAct1(j+1);
						task[i].used=1;
						sort[j].used=1;
						sort[j].needMatch=0;
					}
					if(task[i].getTaskAction()=="takeout")
					{
						int obj2 = sort[j].getsNum();
						if(sort[obj2-1].getsName()==task[i].getTaskNamey())
						{
							task[i].setTaskAct1(j+1);
							task[i].used=1;
							sort[j].used=1;
							sort[j].needMatch=0;
			 			}
			 		}
            } 
			if(task[i].getTaskNamex()=="container")
			{ 
				if(sort[j].getsType()=="container"&&sort[j].getsLocked()==0)
			 	{
					task[i].setTaskAct1(j+1);
					task[i].used = 1;
					sort[j].used = 1;
					sort[j].needMatch=0;
				}
			}
            if(task[i].getTaskNamey()==sort[j].getsName()&&sort[j].getsLocked()==0)
            { 
                cout<<task[i].getTaskNamey()<<" "<<sort[j].getsName()<<endl;
                    if(sort[j].getsStatic(sort[j].getsName())==1)
                     {
                        task[i].setTaskAct2(j+1);
                        //task[i].used=1;
                        sort[j].used=1;
                        sort[j].needMatch=0;
                    }
                    if(task[i].getTaskColory()==sort[j].getsColor())
                    {
                        task[i].setTaskAct2(j+1);
                        //task[i].used=1;
                        sort[j].used=1;
                        sort[j].needMatch=0;
                     }
					
            }
			if(task[i].getTaskNamey()=="container"&&sort[j].getsType()=="container"  &&count == 0)
			{
				cout<<"\nsdfsd*******************"<<endl;
				task[i].setTaskAct2(j+1);
				cout<<task[i].getTaskAct2()<<endl;
				sort[j].used=1;
				sort[j].needMatch=0;
				count++;
			}
        }
    }
    aboutTaskLackMatch(task,sort,sortNum,taskNum,robot);
	cout<<"\nupdateTask is over\n";
}
void updateTaskCons_not_notnot(Sort sort[],Task task[],InfoCons consNn[],InfoCons consn[],Robot robot,int sNum,int tNum,int cNum,int cnNum)
{
  int flag=0,j=0,i=0,n=0;
    string sameName="";
    //task
	/*
	 *算法思想:
	 *先将sort中与任务同名的物体打上标签
	 *具体情况再由规划算法处理
	 */
//    for(i=0;i<sNum;i++)
//	{
//		for(j=0;j <= tNum;j++)
//		{
//			if(sort[i].getsName()==task[j].getTaskNamex())
//			{
//				if(task[j].getTaskAction()=="open")/*{{{*/
//				{
//					sort[i].expectClosed = 0;
//					sort[i].needMatch = 1;  //打标记
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;   //当前物体被使用
//						sort[i].needMatch = 0;//匹配到，标记去掉
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="close")/*{{{*/
//				{
//					sort[i].expectClosed = 1;
//					sort[i].needMatch = 1;
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						task[j].used = 1;
//						sort[i].needMatch = 0;
//					}
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="takeout")/*{{{*/
//				{
//					sort[i].expectInsiding = 0; //代表物体将被拿出容器
//					sort[i].needMatch = 1;
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="putin")/*{{{*/
//				{
//					sort[i].expectInsiding = 1;	//代表物体将被放入容器
//					sort[i].needMatch = 1;
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="putdown")/*{{{*/
//				{
//					sort[i].expectOn = -2;	//代表物体将直接putdown
//					sort[i].needMatch = 1;
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					/*}}}*/
//				}else if(task[j].getTaskAction()=="puton")/*{{{*/
//				{
//					sort[i].expectOn = 1;
//					sort[i].needMatch = 1;
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="pickup")/*{{{*/
//				{
//					sort[i].expectOn = 0; //代表期望在机器人上
//					sort[i].needMatch = 1;
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(i+1);
//						task[i].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[i].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="give")/*{{{*/
//				{
//					//此处应针对human
//					int temp = findSortByName(sNum,"human",sort);
//					sort[temp].giveme = 1;
//					sort[i].needMatch = 1;
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(temp+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="goto")/*{{{*/
//				{
//					//代表机器人必须要求的地方
//					robot.expectMove = task[j].getTaskNamex();
//					sort[i].needMatch = 1;
//					if(sort[i].getsLocked()==0)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(task[j].getTaskColorx()==sort[i].getsColor())
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//					if(sort[i].getsStatic(sort[i].getsName())==1)
//					{
//						task[j].setTaskAct1(i+1);
//						task[j].used = 1;
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//
//				}
//			}/*}}}*/
//			/*
//			 * 任务中有物体2的有give，puton，putin，takeout
//			 */
//			if(sort[i].getsName()==task[j].getTaskNamey())
//			{
//				if(task[j].getTaskAction()=="takeout")/*{{{*/
//				{
//					sort[i].expectClosed = 0; //代表容器内不想要物体
//					sort[i].needMatch = 1;
//					if(sort[i].getsColor()==task[j].getTaskColory())
//					{
//						task[j].setTaskAct2(i+1);
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="putin")/*{{{*/
//				{
//					sort[i].expectClosed = 1;
//					sort[i].needMatch = 1;
//					if(sort[i].getsColor()==task[j].getTaskColory())
//					{
//						task[j].setTaskAct2(i+1);
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//				}/*}}}*/
//				else if(task[j].getTaskAction()=="puton")/*{{{*/
//				{
//					sort[i].expectOnBig = 1;
//					sort[i].needMatch = 1;
//					if(sort[i].getsColor()==task[j].getTaskColory())
//					{
//						task[j].setTaskAct2(i+1);
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//				}else if(task[j].getTaskAction()=="give")/*}}}*/
//				{/*{{{*/
//					sort[i].expectOn = 1;
//					sort[i].needMatch = 1;
//					if(sort[i].getsColor()==task[j].getTaskColory())
//					{
//						task[j].setTaskAct2(i+1);
//						sort[i].used = 1;
//						sort[i].needMatch = 0;
//					}
//				}/*}}}*/
//			}
//			if(task[j].getTaskNamex()=="container"&&task[j].getTaskAction()=="close")
//			{
//				if(sort[i].getsType()=="container")
//				{
//					sort[i].expectClosed = 1;
//					task[j].setTaskAct1(sort[i].getsNum());
//				}
//			}
//		}
//	}
//	aboutTaskLackMatch(task,sort,sNum,tNum,robot);
    /**************************/
    //  cons
    /************************/
    for(i=0; i<=cNum; i++)
    {/*{{{*/
        flag = 0;
        for(j=0; j<sNum; j++)
        {
            if(consn[i].getNamex()==sort[j].getsName())
            {
                flag++;
                consn[i].setState1(sort[j].getsNum());
                if(flag==2)
                {
                    sameName = consn[i].getNamex();
                    if(sort[j].getsLocked())
                    {
                        consn[i].setState1(sort[j].getsNum());
                    }
                    else
                    {
                        n = findSortByName(sNum,sameName,sort);
                        consn[i].setState1(n+1);
                    }
                }
            }
        }/*}}}*/
        /*************************/
        //
        /*************************/
        flag=0;
        for(j=0; j<sNum; j++)
        {/*{{{*/

            if(consn[i].getNamey()==sort[j].getsName())
            {
                flag++;
                 consn[i].setState2(sort[j].getsNum());
                if(flag==2)
                {
                    sameName=consn[i].getNamey();
                    if(sort[j].getsLocked())
                    {
                        consn[i].setState2(sort[j].getsNum());
                    }
                    else
                    {
                        n = findSortByName(sNum,sameName,sort);
                        consn[i].setState2(n+1);
                    }
                }
            }
        }/*}}}*/
    }
    //consNn
    //
    //
    for(i=0; i<=cnNum; i++)
    {
        flag=0;
        for(j=0; j<sNum; j++)
        {
            if(consNn[i].getNamex()==sort[j].getsName())
            {
                flag++;
                consNn[i].setState1(sort[j].getsNum());
                if(flag==2)
                {
                    sameName = consNn[i].getNamex();
                    if(sort[j].getsLocked())
                    {
                        consNn[i].setState1(sort[j].getsNum());
                    }
                    else
                    {
                        n=findSortByName(sNum,sameName,sort);
                        consNn[i].setState1(n+1);
                    }
                }
            }
        }
        /*************************************/
        //
        /*************************************/
        flag=0;
        for(j=0; j<sNum; j++)
        {
            if(consNn[i].getNamey()==sort[j].getsName())
            {
                consNn[i].setState2(sort[j].getsNum());
                flag++;
                if(flag==2)
                {
                    sameName = consNn[i].getNamey();
                    if(sort[j].getsLocked())
                    {
                        consNn[i].setState2(sort[j].getsNum());
                    }
                    else
                    {
                        n = findSortByName(sNum,sameName,sort);
                        consNn[i].setState2(n+1);
                    }
                }
            }
        }
    }
}
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
void updateSenceByInfo(Sort sort[],InfoCons info[],Robot robot,int SNum,int infoNum)
{
    cout<<"-----------------this is updateSenceByinfo-------------------------\n";
    cout<<"snum-->"<<SNum<<" infoNUm--> "<<infoNum<<endl;
    int i,j,inside=0,flag;
	int obj1,obj2;
	int hold,plate;
	
	hold = robot.getHold();
	plate = robot.getPlate();

	if( hold != 0 && sort[hold-1].getsLoc() == -1)
	{
		cout<<"this sort in my hold, my locaion is "<<robot.getLoc()<<endl;
		sort[hold-1].setsLoc(robot.getLoc());		
	}
	if(plate !=0 && sort[plate-1].getsLoc() == -1)
	{
		cout<<"this sort in my plate, my location is "<<robot.getLoc()<<endl;
		sort[plate-1].setsLoc(robot.getLoc());
	}
    for( i =0; i<SNum; i++)
    {
        for(j=0; j<=infoNum; j++)
        {

            //若名字和颜色都相等则，赋值
           // if(info[j].getNamex()==sort[i].getsName()&&info[j].getColorx()==sort[i].getsColor()&&sort[i].getsLoc()==-1)
           	if(info[j].getNamex()==sort[i].getsName()&&info[j].getColorx()==sort[i].getsColor())
		   	{

				cout<<sort[i].getsName()<<" "<<sort[i].getsColor()<<"--info--"<<info[j].getNamex()<<" "<<info[j].getColorx()<<endl;
				obj1 = findSortByName(SNum,info[j].getNamex(),info[j].getColorx(),sort);
				obj2 = findSortByName(SNum,info[j].getNamey(),info[j].getColory(),sort);
				if(obj1 == -1)
               	{
					obj1 = findSortByName(SNum,info[j].getNamex(),sort);
				}
				if(obj2 == -1)
				{
					obj2 = findSortByName(SNum,info[j].getNamey(),sort);
				}
                cout<<"obj1 --> "<<obj1<<endl;
                if(info[j].getState()=="near"||info[j].getState()=="on")
                {
                    sort[i].setsLoc(sort[obj1].getsLoc());
                }
           //     cout<<"@@@@@@@@@@@@@@@@@@\n";
                if(info[j].getState()=="inside")
                {
					sort[obj1].setsLoc(sort[obj2].getsLoc());
					sort[obj1].setsInside(sort[obj2].getsNum());
					sort[obj2].sinsideD.push_back(obj1+1);
                    sort[i].setsLoc(sort[obj1].getsLoc());
                    cout<<"this is info -- inside\n";
                }
                if(info[j].getState()=="plate")
                {
                    sort[i].setsLoc(robot.getLoc());
                }
                if(info[j].getState()=="closed"||info[j].getState()=="opened")
                {
                    if(info[j].getState()=="opened")
                            flag=0;
                    else
                            flag=1;
					cout<<"This is info judge closed -- "<<flag<<endl;
                    sort[i].setsClosed(flag);
                }
            }
        }
        if(sort[i].getsLoc()==-1&&sort[i].getsInside()!=-1)
        {

           inside=sort[i].getsInside();
           sort[i].setsLoc(sort[inside-1].getsLoc());
        }
        if(sort[i].getsNum()==robot.getHold())
        {
            sort[i].setsLoc(robot.getLoc());
        }
    }
	cout<<"----------------updatesenceByinfo is over----------\n";
}/*}}}*/

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void printTask(Task task[],int count)
{/*{{{*/
    cout<<"/*************************************task**********************************/\n";
    cout<<setw(7)<<setiosflags(ios::left);
    cout<<"No.";
    cout<<setw(10)<<setiosflags(ios::left);
    cout<<"Action";
    cout<<setw(10)<<setiosflags(ios::left);
    cout<<"Act1.";
    cout<<setw(10)<<setiosflags(ios::left);
    cout<<"Act2.";
    cout<<setw(12)<<setiosflags(ios::left);
    cout<<"Namex.";
    cout<<setw(9)<<setiosflags(ios::left);
    cout<<"Colorx";
     cout<<setw(9)<<setiosflags(ios::left);
     cout<<"Namey.";
    cout<<setw(9)<<setiosflags(ios::left);
    cout<<"Colory"<<endl;
    for(int i=0; i<=count; i++)
    {
    //    if(task[i].getTaskNo()!=-1)
    //cout<<"this is i-->"<<i<<endl;
            cout<<setw(7)<<setiosflags(ios::left);
            cout<<task[i].getTaskNo();
            cout<<setw(10)<<setiosflags(ios::left);
            cout<<task[i].getTaskAction();
            cout<<setw(10)<<setiosflags(ios::left);
            cout<<task[i].getTaskAct1();
            cout<<setw(10)<<setiosflags(ios::left);
            cout<<task[i].getTaskAct2();
            cout<<setw(12)<<setiosflags(ios::left);
            cout<<task[i].getTaskNamex();
            cout<<setw(9)<<setiosflags(ios::left);
            cout<<task[i].getTaskColorx();
            cout<<setw(9)<<setiosflags(ios::left);
            cout<<task[i].getTaskNamey();
            cout<<setw(9)<<setiosflags(ios::left);
            cout<<task[i].getTaskColory()<<endl;
        }

    cout<<"/*************************************task**********************************/\n";
}/*}}}*/

void printScence(Robot  robot,Sort sort[],int count)
{/*{{{*/
    cout<<"/******************************sence********************************/"<<endl;
    cout<<"robot:"<<endl;

    cout<<"Location: "<<robot.getLoc()<<"  Hold:  "<<robot.getHold()<<"  Plate:  "<<robot.getPlate()<<endl;
    cout<<"/*********************************************************************/"<<endl;
    cout<<setw(7)<<setiosflags(ios::left);
    cout<<"No.";
    cout<<setw(17)<<setiosflags(ios::left);
    cout<<"Sort";
    cout<<setw(8)<<setiosflags(ios::left);
    cout<<"Loc.";
    cout<<setw(8)<<setiosflags(ios::left);
    cout<<"Color.";
    cout<<setw(8)<<setiosflags(ios::left);
    cout<<"Size.";
    cout<<setw(9)<<setiosflags(ios::left);
    cout<<"Closed";
     cout<<setw(9)<<setiosflags(ios::left);
     cout<<"Inside.";
    cout<<setw(9)<<setiosflags(ios::left);
    cout<<"Type";
	cout<<setw(8)<<setiosflags(ios::left);
	cout<<"Lock"<<endl;
    for(int i=0; i<count; i++)
    {
            cout<<setw(1)<<setw(4)<<sort[i].getsNum();
            cout<<setw(1)<<"   "<<setw(17)<<sort[i].getsName();
            cout<<setw(1)<<" "<<setw(7)<<sort[i].getsLoc();
            cout<<setw(8)<<sort[i].getsColor();
            cout<<setw(8)<<sort[i].getsSize();
            cout<<"   "<<setw(7)<<sort[i].getsClosed();
            cout<<setw(7)<<sort[i].getsInside();
            cout<<setw(12)<<sort[i].getsType();
			cout<<setw(8)<<sort[i].getsLocked();
            cout<<endl;
    }
   cout<<"/*********************************************************************/"<<endl;
}/*}}}*/
//
//
//
void printInfoCons(InfoCons info[],int count,string SIGN)
{/*{{{*/
    cout<<"|--------------------------"<<SIGN<<"---------------------------|\n";
    cout<<setw(7)<<setiosflags(ios::left);
    cout<<"No.";
    cout<<setw(10)<<setiosflags(ios::left);
    cout<<"Static";
    cout<<setw(10)<<setiosflags(ios::left);
    cout<<"StaticX.";
    cout<<setw(10)<<setiosflags(ios::left);
    cout<<"StaticY";
    cout<<setw(8)<<setiosflags(ios::left);
    cout<<"NameX";
    cout<<setw(9)<<setiosflags(ios::left);
    cout<<"ColorX";
    cout<<setw(14)<<setiosflags(ios::left);
    cout<<"NameY";
    cout<<setw(9)<<setiosflags(ios::left);
    cout<<"Colory"<<endl;
    cout<<"This is infocount-->"<<count<<endl;
    for(int i=0; i<=count; i++)
    {
        if(info[i].getNo()!=-1){
        cout<<setw(7)<<setiosflags(ios::left);
        cout<<info[i].getNo();
        cout<<setw(10)<<setiosflags(ios::left);
        cout<<info[i].getState();
        cout<<setw(10)<<setiosflags(ios::left);
        cout<<info[i].getState1();
        cout<<setw(10)<<setiosflags(ios::left);
        cout<<info[i].getState2();
        cout<<setw(8)<<setiosflags(ios::left);
        cout<<info[i].getNamex();
        cout<<setw(9)<<setiosflags(ios::left);
        cout<<info[i].getColorx();
        cout<<setw(9)<<setiosflags(ios::left);
        cout<<info[i].getNamey();
        cout<<setw(9)<<setiosflags(ios::left);
        cout<<info[i].getColory();
        cout<<endl;
        }
    }
 cout<<"|---------------------------"<<SIGN<<"--------------------------------|\n";
}
/*}}}*/
void updateSenceByCons(Sort sort[],InfoCons con[],Robot &robot,int sortNum,int consNum)
{
    int i,j;
    for(i=0;i<=consNum;i++)
    {
        for(j=0; j < sortNum; j++)
        {
            if(con[i].getNamex()==sort[j].getsName()&&con[i].getColorx()==sort[j].getsColor())
            {
                    sort[j].setsConsnot(con[i].getState());
                    cout<<sort[j].getsNum()<<"---cons----"<<sort[j].getsConsnot()<<endl;
                    robot.setUsehold(sort[j].getsConsnot());
                    robot.setUseplate(sort[j].getsConsnot());
            }
        }
    }
}
//void buildTasknum(Task task[],Tasknum tasknum[],Sort sort[],int sortNum,int taskNum)
//{
//    int i,j;
//    string tmp;
//    for(i=0; i<= taskNum;i++)
//    {
//        tasknum[i].taskNum = i;
//        tasknum[i].fUsed = true;
//        tasknum[i].taskname = task[i].getTaskAction();
//        tmp = task[i].getTaskAction();
//        if( tmp == "give"||tmp =="puton"||tmp == "putin"||tmp=="takeout")
//        {
//            if(tmp == "give")
//            {
//					bool fstr1 = true;
//					string str1 = "human";
//					bool fcol1 = false;
//					string col1 = "";
//					bool ftype1 = false;
//
//                    bool fstr2 = task[i].seeobj1fsort();
//					string str2 = task[i].getTaskNamex();
//					bool fcol2 = task[i].seeobj1fcolor();
//					string col2 = task[i].getTaskColorx();
//					bool ftype2 = task[i].getTaskContainerx();
//
//                    int sortnum1[10] = {0,0,0,0,0,0,0,0,0,0};
//                    int sortnum2[10] = {0,0,0,0,0,0,0,0,0,0};
//                    int num1 = FindSortAndSave_Info(sort,sortNum,str1,fstr1,col1,fcol1,ftype1,sortnum1);
//                    int num2 = FindSortAndSave_Info(sort,sortNum,str2,fstr2,col2,fcol2,ftype2,sortnum2);
//            }
//        }
//    }
//}
//int FindSortAndSave_Info(Sort sort[],int sortNum,string str,bool fstr,string col,bool fcol,bool ftype,int sortnum[])
//{
//    int count = 0;
//    if(fstr == false && fcol == false && ftype == false)
//    {
//        cout<<"can't find sort"<<endl;
//    }else if(fstr==false && fcol == false && ftype == true)
//    {
//        for(int i =0 ; i<sortNum; i++)
//        {
//            if(sort[i].getsType()=="container")
//            {
//                sortnum[count++] = i;
//            }
//        }
//    }else if(fstr == false && fcol == true && ftype == false)
//    {
//        for(int i =0; i<sortNum;i++)
//        {
//            if(sort[i].getsColor()!=" ")
//            {
//                if(sort[i].getsColor()==col)
//                {
//                    sortnum[count++] = i;
//                }
//            }
//        }
//    }else if(fstr == false && fcol == true && ftype == true)
//    {
//
//    }
//    else if(fstr == true &&fcol == false && ftype == false)
//    {
//        for(int i =0; i<sortNum;i++)
//        {
//            if(sort[i].getsName()==str)
//            {
//                sortnum[count++] = i;
//            }
//        }
//    }else if(fstr == true && fcol == false && ftype == true)
//    {
//        for(int i =0; i<sortNum;i++)
//        {
//            if(sort[i].getsSize()=="big"&&sort[i].getsType()=="container")
//            {
//                if(sort[i].getsName()==str)
//                {
//                    sortnum[count++] = i;
//                }
//            }
//        }
//    }else if(fstr == true && fcol == true && ftype == false)
//    {
//        for(int i=0;i <sortNum;i++)
//        {
//            if(sort[i].getsName()==str&&sort[i].getsColor()==col)
//            {
//                sortnum[count++] = i;
//            }
//        }
//    }else if(fstr == true &&fcol == true && ftype == true)
//    {
//
//    }
//    return count;
//}
void debugTask(Task task[],Sort sort[],int taskNum,int sortNum,Robot &robot)
{
    for(int i=0; i<= taskNum; i++ )
    {
        if(task[i].getTaskAction()=="pickup")
        {
            int act1 = task[i].getTaskAct1();
            if(robot.getHold()==act1 || robot.getPlate()==act1)
            {
                task[i].setTaskSuccess(1);
            }
        }
        else if(task[i].getTaskAction()=="give")
        {
            int act1 = task[i].getTaskAct1();
            int human = findSortByName(sortNum,"human",sort);
            if(sort[human-1].getsLoc()==sort[act1-1].getsLoc())
            {
                task[i].setTaskSuccess(1);
            }
        }
        else if(task[i].getTaskAction()=="puton")
        {
            int act1 = task[i].getTaskAct1();
            int act2 = task[i].getTaskAct2();
            if(sort[act1-1].getsLoc()==sort[act2-1].getsLoc())
            {
                if(robot.getHold()!=act1&&robot.getPlate()!=act1)
                {
                    task[i].setTaskSuccess(1);
                }
            }
        }
        else if(task[i].getTaskAction()=="putdown")
        {
            int act1 = task[i].getTaskAct1();
            if(robot.getHold()!=act1 || robot.getPlate()!=act1)
            {
                task[i].setTaskSuccess(1);
            }
        }
//        else if()
    }
}

void releaseSenceByCons(Sort sort[],InfoCons info[],Task task[],Robot &robot,int SNum,int infoNum,int tNum)
{
	cout<<"\n\nTHis is releaseSenceBycons"<<endl;
	int i, j;
	int flag = 0;
	int hold = robot.getHold();
	int plate = robot.getPlate();

	if(hold != 0)
	{
		cout<<"\nthis is robot.hold ->"<<sort[hold-1].getsNum()<<"  "
	  	    <<sort[hold-1].getsName()<<"  "
		    <<sort[hold-1].getsColor()<<"  "
	  	    <<sort[hold-1].getsConsnot()<<endl;
		robot.setUsehold(sort[hold-1].getsConsnot());
	}
	if(plate != 0)
	{
		cout<<"\nthis is robot.plate ->"<<sort[plate-1].getsNum()<<"  "
			<<sort[plate-1].getsName()<<"  "
			<<sort[plate-1].getsColor()<<"  "
			<<sort[plate-1].getsConsnot()<<endl<<endl;
		robot.setUseplate(sort[plate-1].getsConsnot());
	}
	for(i = 0; i <= tNum; i++)
	{
		flag = 0;
		for(j = 0; j < SNum; j++)
		{
			/*		cout<<"Name."<<sort[j].getsName()
					<<" Color. "<<sort[j].getsColor()
					<<"  Locked."<<sort[j].getsLocked()
					<<" Used."<<sort[j].used<<endl;
			*/
			if(task[i].getTaskAct1() != 0)
			{
				continue;
			}
			if( task[i].getTaskNamex() == sort[j].getsName()&&!sort[j].getsLocked()&&!sort[j].used)
			{
				cout<<"Name."<<sort[j].getsName()
					<<" Color. "<<sort[j].getsColor()
					<<"  Locked."<<sort[j].getsLocked()
					<<" Used."<<sort[j].used<<endl;
				if( task[i].getTaskColorx() == sort[j].getsColor())
				{
					task[i].setTaskAct1(sort[j].getsNum());
					flag = 1;
					task[i].used = 1;
					sort[j].used = 1;
					sort[j].needMatch = 0;
					break;
				}
				if( flag == 1)
					continue;
				task[i].setTaskAct1(sort[j].getsNum());
				task[i].used = 1;
				sort[j].used = 1;
				sort[j].needMatch = 0;
				
			}
		}
	}
/*	for(i = 0; i < SNum; i++)
	{
		if(i <= infoNum)
		{
			cout<<"this is cons_not  ";
			cout<<info[i].getNo()<<"  "
				<<info[i].getState()<<"  "
				<<info[i].getState1()<<"  "
				<<info[i].getState2()<<"  "
				<<info[i].getNamex()<< "  "
				<<info[i].getColorx()<<"  "
				<<info[i].getNamey()<<"  "
				<<info[i].getColory()<<endl<<endl;	
		}
		if(sort[i].getsConsnot() !=0 )
		{
			cout<<sort[i].getsNum()<<"  "
				<<sort[i].getsName()<<"  "
				<<sort[i].getsColor()<<"  "
				<<sort[i].getsConsnot()<<endl;
		}
	}
*/
	cout<<"\nreleaseSenceBycons is over\n\n\n\n";
}

//此函数是用来判断盘子里的是否需要放下
int judgeIsNotPutDownPlate(Task task[],Sort sort[],int tNum,Robot &robot)
{
	
	cout<<"\nThis is judgeIsNotPutDownPlate\n";
//	printScence(robot,sort,18);
	int flag = 0;
	int plate = robot.getPlate();
	int i,j;
	int sot1,sot2;
/*	if(plate == 0)
	{
		cout<<"\njudegeIsNotPutDownPlate is over\n";
		flag0;
	}
	*/
	if(plate = 0)
	{
		flag = 1;
	}
	for(i = 0; i <= tNum; i++)
	{
		if(task[i].getTaskAction() == "" )
		{
			continue;
		}
		if(plate == task[i].getTaskAct1())
		{
			flag = 1;
		}
		sot1 = task[i].getTaskAct1();
		for(j = i+1; j <= tNum; j++)
		{
			sot2 = task[j].getTaskAct1();
			if(sort[sot1-1].getsLoc()==sort[sot2-1].getsLoc())
			{
				cout<<"i: "<<i<<" j: "<<j<<" "<<sort[sot1-1].getsName()<<" "<<sort[sot2-1].getsName()<<" ";
				cout<<"i need my plate putdown"<<endl;
				flag = 1;
			}
		}
	}
	if(flag == 0)
	{
		robot.setUseplate(1);
	}
	return flag;
	cout<<"\njudegeIsNotPutDownPlate is over\n";
}
