
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
		void setStatic(string name);
        int getsNum();
        int getsLoc();
        int getsInside();
        void reduce(string name);
        string getsName();
        string getsColor();
        string getsSize();
        string getsType();
        bool getsLocked();
        bool getsClosed();
        int getsConsnot();
		int taskLock; //任务锁，针对putdown

		int getsStatic(string name);	//返回静态成员
		int bigSort; //标记大物体
    	//针对处理任务的一些属性
		//小物体
		int used;		//判断当前物体是否需要
		vector<int> sinsideD;	//针对大物体内有哪个小物体

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

		static int book;
		static int can;
		static int remotecontrol;
		static int bottle;
		static int cup;
};
#endif
