
#ifndef __home_Sort_h__
#define __home_Sort_h__
#include <iostream>
#include <vector>
#include <string.h>
#include "Task.h"
#include "Robot.h"
using namespace std;
class Sort{
public:
        Sort();
        void setsNum(int num);
        void setsLoc(int Loc);
        void setsInside(int inside);
        void setsName(string name);
        void setsColor(string color);
        void setsSize(string _size);
        void setsClosed(string closed);
        void setsClosed(int closed);
        void setsType(string type);
		void setsBigSort(string name);
        void setsLock();
        void setsConsnot(string action);
        int getsNum();
        int getsLoc();
        int getsInside();
        string getsName();
        string getsColor();
        string getsSize();
        string getsType();
        bool getsLocked();
        bool getsClosed();
        int getsConsnot();
		int taskLock; //任务锁，针对putdown
		int bigSort; //标记大物体
    	//针对处理任务的一些属性
		string expectTask;
		//小物体
		int used;		//判断当前物体是否需要
		int giveme;		//针对human
		string  expectMove;	//期望移动到哪个物体
		vector<int> sinsideD;	//针对大物体内有哪个小物体
	   	int expectInsiding;	//期望处于哪个物体内部
		int expectOn;		//期望在哪个物体上

		//大物体
		int expectInsided;	//期望内部有哪个物体
		int expectClosed;	//期望门关闭
		int expectOnBig; //针对puton中的大物体
		int appareCount;	//本物体在任务中出现的次数
		int needMatch; //针对同名物体设立
private:
        int snum;
        int sloc;
        int sinside;	//针对小物体处于哪个大物体内
        string sname;
        string scolor;
        string ssize;
        bool scontainer;
        bool sclosed;
        int cons_not;
        bool slock;
};
#endif
