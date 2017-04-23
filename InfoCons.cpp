#include "InfoCons.h"
InfoCons::InfoCons()
{
    No = -1;
    sortNo=-1;
    _state="";
    _state1=-1;
    _state2=-2;
    _Namx="";
    _colorx=" ";
    _Namy="";
    _colory=" ";
}
void InfoCons::setNo(int _no)
{
    No=_no;
}
void InfoCons::setState(string sta)
{
    _state=sta;
}
void InfoCons::setState1(string sta1)
{
    if(sta1=="X")
    _state1=-1;
}
void InfoCons::setState2(string sta2)
{
    if(sta2=="Y")
    _state2=-2;
}
void InfoCons::setState1(int sta1)
{
    _state1=sta1;
}
void InfoCons::setState2(int sta2)
{
    _state2=sta2;
}
void InfoCons::setNamx(string namex)
{
    _Namx=namex;
}
void InfoCons::setColorx(string colorx)
{
    _colorx=colorx;
}
void InfoCons::setNamy(string namey)
{
    _Namy=namey;
}
void InfoCons::setColory(string colory)
{
    _colory=colory;
}
void InfoCons::setSortNo(int no)
{
    sortNo=no;
}
int InfoCons::getNo()
{
    return No;
}

string InfoCons::getState()
{
    return _state;
}
int InfoCons::getState1()
{
    return _state1;
}
int InfoCons::getState2()
{
    return _state2;
}
string InfoCons::getNamex()
{
    return _Namx;
}
string InfoCons::getColorx()
{
    return _colorx;
}
string InfoCons::getNamey()
{
    return _Namy;
}
string InfoCons::getColory()
{
    return _colory;
}
int InfoCons::getSortNo()
{
    return sortNo;
}
