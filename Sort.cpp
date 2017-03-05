#include "Sort.h"
Sort::Sort()
{
    snum=-1;
    sloc=-1;

    sinside=-1;
	sinsideD=-1;

    sname="N_N";
    ssize="N_S";
    scolor="";

    scontainer=false;
    sclosed=false;
    slock=false;

	giveme = 0;
	bigSort = 1;
	used = 0; 
	expectMove = "";
	expectInsiding = -1;

	expectOn = -1;
	expectOnBig = -1;
	expectInsided = -1;
	expectClosed = 0; //与上文sclosed相同
	expectTask="";
	appareCount = 0;
	needMatch = 0;
	taskLock = 0;
}


void Sort::setsNum(int num)
{
    snum=num;
}
void Sort::setsLoc(int Loc)
{
    sloc=Loc;
}
void Sort::setsInside(int inside)
{
    sinside=inside;
}
void Sort::setsSize(string _size)
{
    ssize=_size;
}
void Sort::setsColor(string color)
{
    scolor=color;
}
void Sort::setsName(string name)
{
    sname=name;
}
void Sort::setsClosed(string closed)
{
    if(closed=="closed")
        sclosed=true;
}
void Sort::setsClosed(int closed)
{
    if(closed==1)
        sclosed=true;
    else
        sclosed=false;
}
void Sort::setsType(string type)
{
    if(type=="container")
            scontainer=true;
}
void Sort::setsLock()
{
        slock=true;
}
void Sort::setsBigSort(string name)
{
	if(name == "plant"||name == "book"||name == "can"||name=="remotecontrol"||
name == "bottle"||name=="cup")
	{
		bigSort=0;
	}
}
////////////////////////////
int Sort::getsNum()
{
    return snum;
}
int Sort::getsLoc()
{
    return sloc;
}
int Sort::getsInside()
{
    return sinside;
}
string Sort::getsName()
{
    return sname;
}
string Sort::getsColor()
{
    return scolor;
}
string Sort::getsSize()
{
    return ssize;
}
string Sort::getsType()
{
    if(scontainer)
        return "container";
    else
        return "";
}
bool Sort::getsClosed()

{
    return sclosed;
}
bool Sort::getsLocked()
{
    return slock;
}
