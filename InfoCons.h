#ifndef __home_InfoCons_h__
#define __home_InfoCons_h__
#include <iostream>
#include <string.h>
using namespace std;
class InfoCons
{
    public:
        InfoCons();
        void setNo(int _no);
        void  setState(string sta);
        void setState1(string sta1);
        void setState2(string sta2);
        void setState1(int sta1);
        void setState2(int sta2);
        void setNamx(string namex);
        void setColorx(string colorx);
        void setNamy(string namey);
        void setColory(string colory);
        void setSortNo(int no);
        int getNo();
        string getState();
        int getState1();
        int getState2();
        string getNamex();
        string getColorx();
        string getNamey();
        string getColory();
        int getSortNo();
    private:
        int No;
        int sortNo;
        string _state;
        int _state1;
        int _state2;
        string _Namx;
        string _colorx;
        string _Namy;
        string _colory;
};
#endif
