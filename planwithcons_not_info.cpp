#include "devil.hpp"
using namespace _home;
//cons_not_info:表示在环境的任何状态下，info所描述的任何情况都禁止出现
void Devil::planwithcons_not_info(InfoCons cons_not[],Task task[],Sort sort[],Robot &robot,int consnotNum, int taskNum,Graph G )
{
	cout<<"\n\nthis is planwithcons_not_info()\n\n";
    int i,j;
    int obj1,obj2;
    for(i=0 ; i <= consnotNum; i++)
    {
     /*   if(cons_not[i].getState()=="on")
        {

        }
        if(cons_not[i].getState()=="near")
        {

        }
        if(cons_not[i].getState()=="plate")
        {

        }
	*/
        if(cons_not[i].getState()=="inside")
        {
                obj1 = cons_not[i].getState1();
                obj2 = cons_not[i].getState2();
                if(sort[obj1-1].getsInside() == obj2)   //确认出现这种情况的话
                {
                  move(obj2,sort,robot);
                 takeout(obj1,sort,robot,G);
                }
        }
    /*  if(cons_not[i].getState()=="opened")
        {

        }
        if(cons_not[i].getState()=="closed")
        {

        }
   */
	}
	for( i = 0 ; i <= taskNum; i++)
	{
		for(j = 0; j <= consnotNum; j++)
		{
			if(task[i].getTaskNamex() == cons_not[j].getNamex() && task[i].getTaskColorx() == " ")
			{
				cout<<"This task same with cons_not, i will destory it\n";
				cout<<"This task is:"<<task[i].getTaskNo()<<"  "
					<<task[i].getTaskAction()<<"  "
					<<task[i].getTaskNamex()<<"  "
					<<task[i].getTaskNamey()<<endl;
				task[i].setTaskAction("","X","Y");
			}
		}
	}
	cout<<"\n\nplanwithcons_not_info() is over\n\n";
}
void Devil::planwithcons_notnot_info(InfoCons cons_notnot[],Task task[],Sort sort[],Robot &robot,int consnotnotNum,int taskNum)
{
	cout<<"\n this is planwithcons_notnot_info()\n";
	int i,j;
	for(i = 0; i <= taskNum; i++)
	{
		for(j  = 0; j <= consnotnotNum; j++)
		{
			if(task[i].getTaskNamex() == cons_notnot[j].getNamex()
				&& task[i].getTaskColorx() == cons_notnot[j].getColorx())
			{
				cout<<"This task same with cons_notnot, i will destory it\n";
				cout<<"This task is:"<<task[i].getTaskNo()<<"  "
					<<task[i].getTaskAction()<<" namex : "
					<<task[i].getTaskNamex()<<" color : "
					<<task[i].getTaskColorx()<<" namey : "
					<<task[i].getTaskNamey()<<endl;
				task[i].setTaskAction("","X","Y");
				continue;
			}
			if(task[i].getTaskNamex() == cons_notnot[j].getNamex() && task[i].getTaskColorx() == " " )
			{
				cout<<"This task name same with cons_notnot and color is null, i will destory it\n";
				cout<<"This task is:"<<task[i].getTaskNo()<<"  "
					<<task[i].getTaskAction()<<" namex : "
					<<task[i].getTaskNamex()<<" color : "
					<<task[i].getTaskColorx()<<" namey :"
					<<task[i].getTaskNamey()<<endl;

				task[i].setTaskAction("","X","Y");

			}
		}
	}
	cout<<"\nplanwithcons_notnot_info() is over\n\n";
}
