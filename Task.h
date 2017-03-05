#ifndef __home_Task_h__
#define __home_Task_h__
#include <iostream>
#include <string.h>
using namespace std;
class Task
{
    public:
        Task();
        ~Task();
        void setTaskNo(int n);
        void setTaskAction(string act,int act1,int act2);
        void setTaskAction(string act,string act1,string act2);
        void setTaskAct1(int  act1);
        void setTaskAct2(int  act2);
        void setTaskNamex(string namex);
        void setTaskNamey(string namey);
        void setTaskColorx(string colorx);
        void setTaskColory(string colory);
        void setTaskLocx(int locx);
        void setTaskLocy(int locy);
        void setTaskPriority();
        void setTaskContainerx(string name);
        void setTaskContainery(string name);
        void setTaskClosed1();
        void setTaskClosed2();
        int getTaskNo();
        string getTaskAction();
        int getTaskAct1();
        int getTaskAct2();
        string getTaskNamex();
        string getTaskNamey();
        string getTaskColorx();
        string getTaskColory();
        void setTaskSuccess(int succ);
        int getTaskSuccess();
        int getTaskLocx();
        int getTaskLocy();
        int getTaskPriority();
        int getTaskAnalyze();
        bool getTaskContainerx();
        bool getTaskContainery();
        bool getTaskClosed1();
        bool getTaskClosed2();
		string expectMove; //针对goto设立
		int expectPickup; //针对pickup
		int expectGive;	  //针对give
    private:
        int No;
    string Action;
    int Act1;
    int Act2;
    int _locx;
    int _locy;
    string Namex;
    string Namey;
    string Colorx;
    string Colory;
    bool Containerx;
    bool Containery;
    bool Closedx;
    bool Closedy;
    int _priority;
    int tasksuccess;
    int needAnalyze;
};

#endif
