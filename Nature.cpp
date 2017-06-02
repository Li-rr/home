/*
 * Simulation@Home Competition.
 * File: Nature.cpp
 * Author: WenBin Fan
 * E-mail:0zheyu@sogou.com
 * Affiliation: Innovation Lab.
 *              HeFei Normal University.
 */

#include "Nature.h"
#include <boost/concept_check.hpp>
using namespace std;


string toLowerCase(string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			bool findpoitflag = false;
			for(int j = i; j > i -3; j--)
			{
				if(str[j] == '.')
				{
					findpoitflag = true;
				}
			}
			if(findpoitflag == false)
			{
				str[i-1] = '.';
			}
		}
	}
	string temp;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		if((str.substr(i)).find(" ")!=0)
		{
			temp+=str.substr(i,1);
		}
	}
	    return temp;
}
string FindObject(string str)
{
	if(str.find("which")!=-1)
	{
		str=str.substr(0,str.find("which"));
		if(str.find("couch")!=-1)
			return "couch";
		else if(str.find("cupboard")!=-1)
			return "cupboard";
		else if(str.find("chair")!=-1)
			return "chair";
		else if(str.find("worktable")!=-1)
			return "worktable";
		else if(str.find("teapoy")!=-1)
			return "teapoy";
		else if(str.find("book")!=-1)
			return "book";
		else if(str.find("can")!=-1)
			return "can";
		else if(str.find("wash machine")!=-1 || str.find("washmach1ne")!= -1  || str.find("wash_machine")!=-1 || str.find("washmachine")!=-1)
			return "washmachine";
		else if((str.find("closet")!=-1) || (str.find("cl0set") != -1))
			return "closet";
		else if((str.find("remotecontrol")!=-1)||(str.find("remote control")!=-1)||(str.find("remotec0ntrol")!=-1))
			return "remotecontrol";
		else if((str.find("refrigerator")!=-1) || (str.find("refriger&tor") != -1))
			return "refrigerator";
		else if((str.find("television")!=-1)||(str.find("televisi0n")!=-1))
			return "television";
		else if(str.find("bottle")!=-1)
			return "bottle";
		else if(str.find("plant")!=-1)
			return "plant";
		else if(str.find("cup")!=-1)
			return "cup";
		else if(str.find("sofa")!=-1)
			return "sofa";
		else if((str.find("airconditioner")!=-1)||(str.find("air conditioner")!=-1)||(str.find("airc0nditi0ner")!=-1))
			return "airconditioner";
		else if(str.find("workspace")!=-1)
			return "workspace";
		else if(str.find("table")!=-1)
			return "table";
		else if(str.find("bed")!=-1)
			return "bed";
		else if(str.find("desk")!=-1)
			return "desk";
		else if(str.find("microwave") != -1)
			return "microwave";
		else if(str.find("plate")!=-1)
			return "plate";
		else if(str.find("human")!=-1)
			return "human";
	}
	else
	{
		if(str.find("couch")!=-1)
			return "couch";
		else if(str.find("cupboard")!=-1)
			return "cupboard";
		else if(str.find("chair")!=-1)
			return "chair";
		else if(str.find("worktable")!=-1)
			return "worktable";
		else if(str.find("teapoy")!=-1)
			return "teapoy";
		else if(str.find("book")!=-1)
			return "book";
		else if(str.find("can")!=-1)
			return "can";
		else if(str.find("wash machine")!=-1 || str.find("washmach1ne") != -1 || str.find("wash_machine")!=-1 || str.find("washmachine")!=-1)
			return "washmachine";
		else if((str.find("closet")!=-1) || (str.find("cl0set") != -1))
			return "closet";
		else if((str.find("remotecontrol")!=-1)||(str.find("remote control")!=-1)||(str.find("remotec0ntrol")!=-1))
			return "remotecontrol";
		else if((str.find("refrigerator")!=-1) || (str.find("refriger&tor") != -1))
			return "refrigerator";
		else if((str.find("television")!=-1)||(str.find("televisi0n")!=-1))
			return "television";
		else if(str.find("bottle")!=-1)
			return "bottle";
		else if(str.find("plant")!=-1)
			return "plant";
		else if(str.find("cup")!=-1)
			return "cup";
		else if(str.find("sofa")!=-1)
			return "sofa";
		else if((str.find("airconditioner")!=-1)||(str.find("air conditioner")!=-1)||(str.find("airc0nditi0ner")!=-1))
			return "airconditioner";
		else if(str.find("workspace")!=-1)
			return "workspace";
		else if(str.find("table")!=-1)
			return "table";
		else if(str.find("bed")!=-1)
			return "bed";
		else if(str.find("desk")!=-1)
			return "desk";
		else if(str.find("microwave") != -1)
			return "microwave";
		else if(str.find("plate")!=-1)
			return "plate";
		else if(str.find("human")!=-1)
			return "human";
	}
	return "";
}
string FindColor(string str)
{
	if(str.find("which")!=-1)
	{
		

		if(str.find("whichiswhite")!=-1)
			return "white";
		else if(str.find("whichisred")!=-1)
			return "red";
		else if(str.find("whichisgreen")!=-1)
			return "green";
		else if(str.find("whichisyellow")!=-1)
			return "yellow";
		else if(str.find("whichisblue")!=-1)
			return "blue";
		else if(str.find("whichisblack")!=-1)
			return "black";
		str=str.substr(0,str.find("which"));
		if(str.find("white")!=-1)
			return "white";
		else if(str.find("red")!=-1)
			return "red";
		else if(str.find("green")!=-1)
			return "green";
		else if(str.find("yellow")!=-1)
			return "yellow";
		else if(str.find("blue")!=-1)
			return "blue";
		else if(str.find("black")!=-1)
			return "black";
		else return "";

	}
	else
	{
		if(str.find("white")!=-1)
			return "white";
		else if(str.find("red")!=-1)
			return "red";
		else if(str.find("green")!=-1)
			return "green";
		else if(str.find("yellow")!=-1)
			return "yellow";
		else if(str.find("blue")!=-1)
			return "blue";
		else if(str.find("black")!=-1)
			return "black";
		else return "";
	}
	return "";
}
string FindOther(string str)
{
	string newstr;
	if(str.find("which")==-1)
	{
		return "";
	}
	str=str.substr(str.find("which")+5);
	if(str.find("ison")!=-1 || str.find("isnear")!=-1 || str.find("isnextto")!=-1 
	  ||str.find("is0n")!=-1 || str.find("isnea2")!=-1 || str.find("isnextt0")!=-1 )
	{
		newstr+="<";
		newstr+=FindColor(str);
		newstr+=FindObject(str);
		newstr+=">";
		return newstr;
	}
	else if(str.find("isin")!=-1|| str.find("is1n")!=-1)
	  {
		newstr+="[";
		newstr+=FindColor(str);
		newstr+=FindObject(str);
		newstr+="]";
		return newstr;

	}
	return "";
}
string AnalysisObject(string str)
{
	int Mode=0;
	if(str.find("the")==0)
	{
		Mode=2;
		str=str.substr(3);
	}
	else if((str.find("a")==0)&&(str.find("ai")!=0))
	{
		Mode=1;
		str=str.substr(1);
	}
	return FindColor(str)+FindObject(str)+FindOther(str);
}

string Translate(string strTs)
{
	strTs = toLowerCase(strTs);
	int i,j;
	string finish;
	for(i=0,j=strTs.find(".");i+j<strTs.length(),j>0;)
	{
		string str=strTs.substr(i,j);
		int index;
		index=finish.length(); 
		while((str.find("remotecontrol")!=-1))
		{
			string temp;
			temp+=str.substr(0,str.find("remotecontrol"));
			temp+="remotec0ntrol";
			temp+=str.substr(str.find("remotecontrol")+13);
			str=temp;
		}
		while((str.find("remote control")!=-1))
		{
			string temp;
			temp+=str.substr(0,str.find("remote control"));
			temp+="remotec0ntrol";
			temp+=str.substr(str.find("remote control")+14);
			str=temp;
		}
		while((str.find("air conditioner")!=-1))
		{
			string temp;
			temp+=str.substr(0,str.find("air conditioner"));
			temp+="airc0nditi0ner";
			temp+=str.substr(str.find("air conditioner")+15);
			str=temp;
		}
		while((str.find("airconditioner")!=-1))
		{
			string temp;
			temp+=str.substr(0,str.find("airconditioner"));
			temp+="airc0nditi0ner";
			temp+=str.substr(str.find("airconditioner")+14);
			str=temp;
		}
		while((str.find("television")!=-1))
		{
			string temp;
			temp+=str.substr(0,str.find("television"));
			temp+="televisi0n";
			temp+=str.substr(str.find("television")+10);
			str=temp;
		}
		while(str.find("washmachine")!=-1)
		{
			string temp;
			temp+=str.substr(0,str.find("washmachine"));
			temp+="washmach1ne";
			temp+=str.substr(str.find("washmachine")+11);
			str=temp;
		}
		while((str.find("closet")!=-1) && (str.find("closethe") == -1))
		{
			string temp;
			temp+=str.substr(0,str.find("closet"));
			temp+="cl0set";
			temp+=str.substr(str.find("closet")+6);
			str=temp;
		}
		while(str.find("refriger&tor")!=-1)
		{
			string temp;
			temp+=str.substr(0,str.find("refrigerator"));
			temp+="refriger&tor";
			temp+=str.substr(str.find("refrigerator")+12);
			str=temp;
		}
		if(str.find("give")!=-1) 
		{
			if(str.find("dono")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			finish+="give(human,";
			if(str.find("onthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("onthe"));
				temp+="whichis";
				temp+=str.substr(str.find("onthe"));
				str=temp;
			}
			if(str.find("nearthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("nearthe"));
				temp+="whichis";
				temp+=str.substr(str.find("nearthe"));
				str=temp;
			}
			if(str.find("nexttothe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("nexttothe"));
				temp+="whichis";
				temp+=str.substr(str.find("nexttothe"));
				str=temp;
			}
			if(str.find("inthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("inthe"));
				temp+="whichis";
				temp+=str.substr(str.find("inthe"));
				str=temp;
			}
			if(str.find("tome")!=-1)
			{
				str=str.substr(str.find("give")+4,str.find("tome")-str.find("give")-4);
				finish+=AnalysisObject(str);
			}
			else
			{
				finish+=AnalysisObject(str.substr(str.find("me")+2));
			}
			finish+=").";
		}
		else if(str.find("pickup")!=-1)
		{

			if(str.find("dono")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			if(str.find("onthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("onthe"));
				temp+="whichis";
				temp+=str.substr(str.find("onthe"));
				str=temp;
			}
			if(str.find("nearthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("nearthe"));
				temp+="whichis";
				temp+=str.substr(str.find("nearthe"));
				str=temp;
			}
			if(str.find("nexttothe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("nexttothe"));
				temp+="whichis";
				temp+=str.substr(str.find("nexttothe"));
				str=temp;
			}
			if(str.find("inthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("inthe"));
				temp+="whichis";
				temp+=str.substr(str.find("inthe"));
				str=temp;
			}
			finish+="pickup(";
			finish+=AnalysisObject(str.substr(str.find("pickup")+6));
			finish+=").";
		}
		else if(str.find("pick")!=-1)
		{
			if(str.find("dono")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			if(str.find("onthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("onthe"));
				temp+="whichis";
				temp+=str.substr(str.find("onthe"));
				str=temp;
			}
			if(str.find("nearthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("nearthe"));
				temp+="whichis";
				temp+=str.substr(str.find("nearthe"));
				str=temp;
			}
			if(str.find("nexttothe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("nexttothe"));
				temp+="whichis";
				temp+=str.substr(str.find("nexttothe"));
				str=temp;
			}
			if(str.find("inthe")!=-1)
			{
				string temp;
				temp+=str.substr(0,str.find("inthe"));
				temp+="whichis";
				temp+=str.substr(str.find("inthe"));
				str=temp;
			}
			finish+="pickup(";
			finish+=AnalysisObject(str.substr(str.find("pick")+4));
			finish+=").";
		}
		else if((str.find("take") != -1) && (str.find("out") != -1))
		{
			string temp;
			if(str.find("dono") == 0)
			{
				finish+="not";
				str = str.substr(5);
			}
			finish+="takeout(";
			if(str.find("from") != -1)
			{
				finish+=AnalysisObject(str.substr(0,str.find("from")));
				finish+=",";
				finish+=AnalysisObject(str.substr(str.find("from")+4)); 
			}
			else if(str.find("outof") != -1)
			{
				finish+=AnalysisObject(str.substr(0,str.find("outof")));
				finish+=",";
				finish+=AnalysisObject(str.substr(str.find("outof")+5)); 
			}
			
			finish+=").";
		}
		else if(str.find("put")!=-1 && (str.find("down")!=-1) && (str.find("downto")==-1))
		{
			if(str.find("dono")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			if(str.find("putdown")!=-1)
			{
				finish+="putdown(";
				finish+=AnalysisObject(str.substr(str.find("putdown")+7));
				finish+=").";
			}
			else
			{
				finish+="putdown(";
				str=str.substr(str.find("put")+3);
				finish+=AnalysisObject(str.substr(0,str.find("down")));
				finish+=").";
			}
		}
		else if (str.find("put")!=-1)
		{
			if(str.find("dono")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			int middle,len;
			string tempstr=str;
			
			while((str.find("whichison")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichison"));
				temp+="whichis0n";
				temp+=str.substr(str.find("whichison")+9);
				str=temp;
			}
			while((str.find("whichisnear")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisnear"));
				temp+="whichisnea2";
				temp+=str.substr(str.find("whichisnear")+11);
				str=temp;
			}
			while((str.find("whichisnextto")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisnextto"));
				temp+="whichisnextt0";
				temp+=str.substr(str.find("whichisnextto")+13);
				str=temp;
			}
			while((str.find("whichisin")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisin"));
				temp+="whichis1n";
				temp+=str.substr(str.find("whichisin")+9);
				str=temp;
			}
			if(str.find("on")!=-1)
			{
				middle=str.find("on");
				len=2;
				finish+="puton(";
			}
			else if (str.find("near")!=-1)
			{
				middle=str.find("near");
				len=4;
				finish+="puton(";
			}
			else if (str.find("nextto")!=-1)
			{
				middle=str.find("nextto");
				len=6;
				finish+="puton(";
			}
			else if (str.find("downto")!=-1)
			{
				middle=str.find("downto");
				len=6;
				finish+="puton(";
			}
			else if (str.find("inside")!=-1)
			{
				middle=str.find("inside");
				len=6;
				finish+="putin(";
			}
			else if (str.find("in")!=-1)
			{
				middle=str.find("in");
				len=2;
				finish+="putin(";
			}
			str=tempstr;
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=",";
			finish+=AnalysisObject(str.substr(middle+len));

			finish+=").";
		}
		else if(str.find("goto")!=-1)
		{
			if(str.find("dono")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			finish+="goto(";
			finish+=AnalysisObject(str.substr(str.find("goto")+4));
			finish+=").";
		}
		else if(str.find("open")!=-1 && str.find("isnotopen") == -1 && str.find("isopen")==-1 && str.find("beopen")==-1 && str.find("anopen")==-1)
		{
			if(str.find("dono")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			if((str.find("each") != -1) || (str.find("every") != -1) || (str.find("all") != -1))
			{
				finish+="opendoor(every).";
			}
			else
			{
				//open the microwave.
				finish+="opendoor(";
				finish+=AnalysisObject(str.substr(str.find("open")+4));
				finish+=").";	
			}
			
		}
		else if(str.find("isopen")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichison")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichison"));
				temp+="whichis0n";
				temp+=str.substr(str.find("whichison")+9);
				str=temp;
			}
			if(str.find("isopen")!=-1)
			{
				middle=str.find("isopen");
				len=6;
			}
			str=tempstr;
			finish+="dooropen(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=").";
		}
		else if(str.find("isnotopen")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichison")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichison"));
				temp+="whichis0n";
				temp+=str.substr(str.find("whichison")+9);
				str=temp;
			}
			if(str.find("isnotopen")!=-1)
			{
				middle=str.find("isnotopen");
				len=9;
			}
			str=tempstr;
			finish+="doorclose(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=").";
		}
		else if(str.find("anopen")!=-1 && str.find("beanopen")==-1)
		{
			finish+="dooropen(";
			finish+=AnalysisObject(str.substr(10));
			finish+=").";
		}
		else if(str.find("isontheplate")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichison")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichison"));
				temp+="whichis0n";
				temp+=str.substr(str.find("whichison")+9);
				str=temp;
			}
			if(str.find("isonthe")!=-1)
			{
				middle=str.find("isonthe");
				len=7;
			}
			
			str=tempstr;
			finish+="onplate(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=").";
		}
		else if(str.find("isonplate")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichison")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichison"));
				temp+="whichis0n";
				temp+=str.substr(str.find("whichison")+9);
				str=temp;
			}
			if(str.find("ison")!=-1)
			{
				middle=str.find("ison");
				len=4;
			}
			str=tempstr;
			finish+="onplate(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=").";
		}
		else if(str.find("isintheplate")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichisin")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisin"));
				temp+="whichis1n";
				temp+=str.substr(str.find("whichisin")+9);
				str=temp;
			}
			if(str.find("isinthe")!=-1)
			{
				middle=str.find("isinthe");
				len=7;
			}
			str=tempstr;
			finish+="onplate(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=").";
		}
		else if(str.find("isinplate")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichisin")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisin"));
				temp+="whichis1n";
				temp+=str.substr(str.find("whichisin")+9);
				str=temp;
			}
			if(str.find("isin")!=-1)
			{
				middle=str.find("isin");
				len=4;
			}
			str=tempstr;
			finish+="onplate(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=").";
		}
		else if(str.find("ison")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichison")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichison"));
				temp+="whichis0n";
				temp+=str.substr(str.find("whichison")+9);
				str=temp;
			}
			if(str.find("ison")!=-1)
			{
				middle=str.find("ison");
				len=4;
			}
			
			str=tempstr;
			finish+="on(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=",";
			finish+=AnalysisObject(str.substr(middle));
			finish+=").";
		}
		else if(str.find("isinside")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichisinside")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisinside"));
				temp+="whichis1n";
				temp+=str.substr(str.find("whichisinside")+13);
				str=temp;
			}
			if(str.find("isinside")!=-1)
			{
				middle=str.find("isinside");
				len=8;
			}
			
			str=tempstr;
			finish+="inside(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=",";
			finish+=AnalysisObject(str.substr(middle));
			finish+=").";
		}
		else if(str.find("isin")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichisin")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisin"));
				temp+="whichis1n";
				temp+=str.substr(str.find("whichisin")+9);
				str=temp;
			}
			if(str.find("isin")!=-1)
			{
				middle=str.find("isin");
				len=8;
			}
			str=tempstr;
			finish+="inside(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=",";
			finish+=AnalysisObject(str.substr(middle));
			finish+=").";
		}
		else if(str.find("isnear")!=-1 || str.find("isnextto")!=-1 || str.find("isdownto")!=-1)
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichisnear")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisnear"));
				temp+="whichisnea2";
				temp+=str.substr(str.find("whichisnear")+11);
				str=temp;
			}
			while((str.find("whichisnextto")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichisnextto"));
				temp+="whichisnextt0";
				temp+=str.substr(str.find("whichisnextto")+13);
				str=temp;
			}
			if (str.find("isnear")!=-1)
			{
				middle=str.find("isnear");
				len=6;
			}
			else if (str.find("isnextto")!=-1)
			{
				middle=str.find("isnextto");
				len=8;
			}
			else if (str.find("isdownto")!=-1)
			{
				middle=str.find("isdownto");
				len=8;
			}
			str=tempstr;
			finish+="near(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=",";
			finish+=AnalysisObject(str.substr(middle));
			finish+=").";
		}
		else if(str.find("thereis")==0 )
		{
			int middle,len;
			if(str.find("ontheplate")!=-1)
			{
				middle=str.find("ontheplate");
				len=10;
				finish+="onplate(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=").";
			}
			else if(str.find("onplate")!=-1)
			{
				middle=str.find("onplate");
				len=10;
				finish+="onplate(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=").";
			}
			else if(str.find("open")!=-1)
			{
				middle=str.find("open");
				len=4;
				finish+="dooropen(";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if(str.find("close")!=-1 && str.find("closet") == -1)
			{
				middle=str.find("close");
				len=5;
				finish+="doorclose(";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if(str.find("on")!=-1)
			{
				middle=str.find("on");
				len=2;
				finish+="on(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if (str.find("near")!=-1)
			{
				middle=str.find("near");
				len=4;
				finish+="near(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if (str.find("inside")!=-1)
			{
				middle=str.find("inside");
				len=5;
				finish+="inside(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if (str.find("in")!=-1)
			{
				middle=str.find("in");
				len=2;
				finish+="inside(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if (str.find("nextto")!=-1)
			{
				middle=str.find("nextto");
				len=6;
				finish+="near(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
		}
		else if(str.find("theremust")==0 || str.find("must") != -1)
		{
			if(str.find("mustbe")!=-1)
			{
				int middle,len;
				if(str.find("ontheplate")!=-1)
				{
					middle=str.find("ontheplate");
					len=10;
					finish+="notnotonplate(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("onplate")!=-1)
				{
					middle=str.find("onplate");
					len=7;
					finish+="notnotonplate(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("intheplate")!=-1)
				{
					middle=str.find("intheplate");
					len=10;
					finish+="notnotonplate(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("inplate")!=-1)
				{
					middle=str.find("inplate");
					len=7;
					finish+="notnotonplate(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("open")!=-1)
				{
					middle=str.find("open");
					len=4;
					finish+="notnotdooropen(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("close")!=-1 && str.find("closet") == -1)
				{
					middle=str.find("close");
					len=4;
					finish+="notnotdoorclose(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("on")!=-1)
				{
					middle=str.find("on");
					len=2;
					finish+="notnoton(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=",";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=").";
				}
				else if (str.find("near")!=-1)
				{
					middle=str.find("near");
					len=4;
					finish+="notnotnear(";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=",";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if (str.find("inside")!=-1)
				{
					middle=str.find("inside");
					len=5;
					finish+="notnotinside(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=",";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=").";
				}
				else if (str.find("in")!=-1)
				{
					middle=str.find("in");
					len=2;
					finish+="notnotinside(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=",";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=").";
				}
				else if (str.find("nextto")!=-1)
				{
					middle=str.find("nextto");
					len=6;
					finish+="notnotnear(";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=",";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
			}
			else{
				int middle,len;
				if(str.find("ontheplate")!=-1)
				{
					middle=str.find("ontheplate");
					len=10;
					finish+="notonplate(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("onplate")!=-1)
				{
					middle=str.find("onplate");
					len=10;
					finish+="notonplate(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("open")!=-1)
				{
					middle=str.find("open");
					len=4;
					finish+="notdooropen(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("close")!=-1 && str.find("closet") == -1)
				{
					middle=str.find("close");
					len=5;
					finish+="notdoorclose(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=").";
				}
				else if(str.find("on")!=-1)
				{
					middle=str.find("on");
					len=2;
					finish+="noton(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=",";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=").";
				}
				else if (str.find("near")!=-1)
				{
					middle=str.find("near");
					len=4;
					finish+="notnear(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=",";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=").";
				}
				else if (str.find("inside")!=-1)
				{
					middle=str.find("inside");
					len=5;
					finish+="notinside(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=",";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=").";
				}
				else if (str.find("in")!=-1)
				{
					middle=str.find("in");
					len=2;
					finish+="notinside(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=",";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=").";
				}
				else if (str.find("nextto")!=-1)
				{
					middle=str.find("nextto");
					len=6;
					finish+="notnear(";
					finish+=AnalysisObject(str.substr(0,middle));
					finish+=",";
					finish+=AnalysisObject(str.substr(middle+len));
					finish+=").";
				}
			}
		}
		else if(str.find("beon")!=-1 || str.find("benear")!=-1 || str.find("benextto")!=-1 || str.find("bein")!=-1 )
		{
			if(str.find("mustnotbe")!=-1)
			{
				finish+="not";
			}
			else if(str.find("mustbe")!=-1)
			{
				finish+="notnot";
			}
			int middle,len;
			if(str.find("beontheplate")!=-1)
			{
				middle=str.find("beontheplate");
				len=4;
				finish+="onplate(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=").";
			}
			else if(str.find("beonplate")!=-1)
			{
				middle=str.find("beonplate");
				len=4;
				finish+="onplate(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=").";
			}
			
			else if(str.find("beintheplate")!=-1)
			{
				middle=str.find("beintheplate");
				len=4;
				finish+="onplate(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=").";
			}
			else if(str.find("beinplate")!=-1)
			{
				middle=str.find("beintheplate");
				len=4;
				finish+="onplate(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=").";
			}
			else if(str.find("beon")!=-1 )
			{
				middle=str.find("beon");
				len=4;
				finish+="on(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if (str.find("benear")!=-1)
			{
				middle=str.find("benear");
				len=6;
				finish+="near(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if (str.find("beinside")!=-1)
			{
				middle=str.find("inside");
				len=7;
				finish+="inside(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if (str.find("bein")!=-1)
			{
				middle=str.find("in");
				len=4;
				finish+="inside(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
			else if (str.find("benextto")!=-1)
			{
				middle=str.find("benextto");
				len=8;
				finish+="near(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=",";
				finish+=AnalysisObject(str.substr(middle+len));
				finish+=").";
			}
		}
		else if(str.find("beopen")!=-1 )
		{
			if(str.find("mustnotbe")!=-1)
			{
				finish+="not";
			}
			else if(str.find("mustbe")!=-1)
			{
				finish+="notnot";
			}
			int middle,len;
			if(str.find("beopen")!=-1)
			{
				middle=str.find("beopen");
			
				finish+="dooropen(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=").";
			}
		}
		else if(str.find("beclose")!=-1 && str.find("becloset") == -1)
		{
			if(str.find("mustnotbe")!=-1)
			{
				finish+="not";
			}
			else if(str.find("mustbe")!=-1)
			{
				finish+="notnot";
			}
			int middle,len;
			if(str.find("beclose")!=-1)
			{
				middle=str.find("beclose");
			
				finish+="doorclose(";
				finish+=AnalysisObject(str.substr(0,middle));
				finish+=").";
			}
		}
		else if(str.find("close") != -1 && str.find("isnotclose") == -1 && str.find("isclose")==-1 && str.find("beclose")==-1 && str.find("anclose")==-1 )
		{
			if(str.find("donot")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			if((str.find("each") != -1) || (str.find("every") != -1) || (str.find("all") != -1))
			{
				finish+="closedoor(every).";
			}
			else
			{
				finish+="closedoor(";
				finish+=AnalysisObject(str.substr(str.find("close")+5));
				finish+=").";	
			}
			
		}
		else if(str.find("isclose")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichison")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichison"));
				temp+="whichis0n";
				temp+=str.substr(str.find("whichison")+9);
				str=temp;
			}
			if(str.find("isclose")!=-1)
			{
				middle=str.find("isclose");
				len=7;
			}
			str=tempstr;
			finish+="doorclose(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=").";
		}
		else if(str.find("isnotclose")!=-1 )
		{
			int middle,len;
			string tempstr=str;
			while((str.find("whichison")!=-1))
			{
				string temp;
				temp+=str.substr(0,str.find("whichison"));
				temp+="whichis0n";
				temp+=str.substr(str.find("whichison")+9);
				str=temp;
			}
			if(str.find("isnotclose")!=-1)
			{
				middle=str.find("isnotclose");
				len=10;
			}
			str=tempstr;
			finish+="dooropen(";
			finish+=AnalysisObject(str.substr(0,middle));
			finish+=").";
		}
		else if(str.find("anclose")!=-1 && str.find("beanclose")==-1)
		{
			finish+="doorclose(";
			finish+=AnalysisObject(str.substr(11));
			finish+=").";
		}
		else if(str.find("beatplate")!= -1 && str.find("must") != -1)
		{
			if(str.find("not")==0)
			{
				finish+="not";
				str=str.substr(5);
			}
			else
			{
				finish+="notonplate(";
				finish+=AnalysisObject(str.substr(0,str.find("must")));
				finish+=").";	
			}
		}
		i=i+j+1;
		j=strTs.substr(i,strTs.length()).find(".");
	}
	finish = dealwithfinish(finish);
	return finish;
}

string dealwithfinish(string str)
{
	string finish = "";
	string temp = "";
	string tmp1,tmp2;
	int i,j;
	finish += "(:ins ";
	for(i=0,j=str.find(".");i+j<str.length(),j>0;)
	{
		temp=str.substr(i,j);
		if((int)temp.find(",") != -1)
		{
			tmp1 = temp.substr(temp.find("(") + 1,temp.find(",") - temp.find("(") - 1);
			tmp2 = temp.substr(temp.find(",") + 1,temp.find(")") - temp.find(",") - 1);
			if((tmp1 == "") || (tmp2 == ""))
			{
				i=i+j+1;
				j=str.substr(i,str.length()).find(".");
				continue;
			}
		}
		else
		{
			tmp1 = temp.substr(temp.find("(") + 1, temp.find(")") - temp.find("(") - 1);
			if(tmp1 == "")
			{
				i=i+j+1;
				j=str.substr(i,str.length()).find(".");
				continue;
			}
		}
		
		if((int)temp.find("notnot") != -1)
		{
			finish += "(:cons_notnot ";
			if((int)temp.find("give") != -1)
			{
				finish += "(:task (give human X) (:cond ";
				finish += dealwithobject(tmp2,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("puton") != -1)
			{
				finish += "(:task (puton X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";
			}
			else if((int)temp.find("goto") != -1)
			{
				finish += "(:task (goto X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("putdown") != -1)
			{
				finish += "(:task (putdown X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("pickup") != -1)
			{
				finish += "(:task (pickup X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("opendoor") != -1)
			{
				if(temp.find("every") != -1)
				{
					finish += "(:task (open X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:task (open X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}
			    
			}
			else if((int)temp.find("closedoor") != -1)
			{
				if(temp.find("every") != -1)
				{
					finish += "(:task (close X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:task (close X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}			
			}
			else if((int)temp.find("putin") != -1)
			{
				finish += "(:task (putin X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			    
			}
			else if((int)temp.find("takeout") != -1)
			{
				finish += "(:task (takeout X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			
			}
			else if((int)temp.find("near") != -1)
			{
				finish += "(:info (at X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			
			}
			else if((int)temp.find("onplate") != -1)
			{
				finish += "(:info (plate X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";				
			}
			else if((int)temp.find("inside") != -1)
			{
				finish += "(:info (inside X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";				
			}
			else if((int)temp.find("dooropen") != -1)
			{			   
				if(temp.find("##") != -1)
				{
					finish += "(:info (opened X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:info (opened X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}			
			}
			else if((int)temp.find("doorclose") != -1)
			{
				if(temp.find("##") != -1)
				{
					finish += "(:info (closed X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:info (closed X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}	
			}
			else if((int)temp.find("on") != -1 )
			{
				finish += "(:info (on X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";				
			}
			else
			{
				//////////////////DEBUG/////////////////////////
				if(NATURE_DEBUG == 1)
				{
					cout<<endl<<"nature : error: The task or info is out of rules."<<endl;
				}
				//////////////////DEBUG/////////////////////////				
			}
			finish = finish.substr(0,finish.length()-1);
			finish += ") ";
		}
		else if((int)temp.find("not") != -1)
		{
			finish += "(:cons_not ";
			if((int)temp.find("give") != -1)
			{
				finish += "(:task (give human X) (:cond ";
				finish += dealwithobject(tmp2,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("puton") != -1)
			{
				finish += "(:task (puton X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";
			}
			else if((int)temp.find("goto") != -1)
			{
				finish += "(:task (goto X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("putdown") != -1)
			{
				finish += "(:task (putdown X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("pickup") != -1)
			{
				finish += "(:task (pickup X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("opendoor") != -1)
			{
				if(temp.find("every") != -1)
				{
					finish += "(:task (open X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:task (open X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}
			    
			}
			else if((int)temp.find("closedoor") != -1)
			{
				if(temp.find("every") != -1)
				{
					finish += "(:task (close X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:task (close X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}			
			}
			else if((int)temp.find("putin") != -1)
			{
				finish += "(:task (putin X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			    
			}
			else if((int)temp.find("takeout") != -1)
			{
				finish += "(:task (takeout X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			
			}
			else if((int)temp.find("near") != -1)
			{
				finish += "(:info (at X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			
			}
			else if((int)temp.find("onplate") != -1)
			{
				finish += "(:info (plate X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";				
			}
			
			else if((int)temp.find("inside") != -1)
			{
				finish += "(:info (inside X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";				
			}
			else if((int)temp.find("dooropen") != -1)
			{			   
				if(temp.find("every") != -1)
				{
					finish += "(:info (opened X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:info (opened X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}			
			}
			else if((int)temp.find("doorclose") != -1)
			{
				if(temp.find("every") != -1)
				{
					finish += "(:info (closed X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:info (closed X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}	
			}
			else if((int)temp.find("on") != -1)
			{
				finish += "(:info (on X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";				
			}
			else
			{
				//////////////////DEBUG/////////////////////////
				if(NATURE_DEBUG == 1)
				{
					cout<<endl<<"nature : error: The task or info is out of rules."<<endl;
				}
				//////////////////DEBUG/////////////////////////				
			}
			finish = finish.substr(0,finish.length()-1);
			finish += ") ";
		}
		else
		{
			if((int)temp.find("give") != -1)
			{
				finish += "(:task (give human X) (:cond ";
				finish += dealwithobject(tmp2,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("puton") != -1)
			{
				finish += "(:task (puton X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";
			}
			else if((int)temp.find("goto") != -1)
			{
				finish += "(:task (goto X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("putdown") != -1)
			{
				finish += "(:task (putdown X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("pickup") != -1)
			{
				finish += "(:task (pickup X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";
			}
			else if((int)temp.find("opendoor") != -1)
			{
				if(temp.find("every") != -1)
				{
					finish += "(:task (open X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:task (open X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}
			    
			}
			else if((int)temp.find("closedoor") != -1)
			{
				if(temp.find("every") != -1)
				{
					finish += "(:task (close X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:task (close X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}			
			}
			else if((int)temp.find("putin") != -1)
			{
				finish += "(:task (putin X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			    
			}
			else if((int)temp.find("takeout") != -1)
			{
				finish += "(:task (takeout X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			
			}
			else if((int)temp.find("near") != -1)
			{
				finish += "(:info (near X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";			
			}
			else if((int)temp.find("onplate") != -1)
			{
				finish += "(:info (plate X) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish = finish.substr(0,finish.length()-1);
				finish += ")) ";				
			}
			else if((int)temp.find("inside") != -1)
			{
				finish += "(:info (inside X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";				
			}
			else if((int)temp.find("dooropen") != -1)
			{			   
				if(temp.find("every") != -1)
				{
					finish += "(:info (opened X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:info (opened X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}			
			}
			else if((int)temp.find("doorclose") != -1)
			{
				if(temp.find("every") != -1)
				{
					finish += "(:info (closed X) (:cond (type X container))) ";
				}
				else
				{
					finish += "(:info (closed X) (:cond ";
					finish += dealwithobject(tmp1,1);
					finish = finish.substr(0,finish.length()-1);
					finish += ")) ";
				}	
			}
			else if((int)temp.find("on") != -1)
			{
				finish += "(:info (on X Y) (:cond ";
				finish += dealwithobject(tmp1,1);
				finish += dealwithobject(tmp2,2);
				finish += ")) ";				
			}
			else
			{
				//////////////////DEBUG/////////////////////////
				if(NATURE_DEBUG == 1)
				{
					cout<<endl<<"nature : error: The task or info is out of rules."<<endl;
				}
				//////////////////DEBUG/////////////////////////				
			}

		}
		i=i+j+1;
		j=str.substr(i,str.length()).find(".");
	}
	finish = finish.substr(0,finish.length()-1);
	finish += ")";
	return finish;
}

string dealwithobject(string str,int num)
{
	string final = "";
	string tmp = "";
	string col = "";
	bool color = false;
	if(num == 1)
	{
		if((int)str.find("white") != -1)
		{
			color = true;
			col = "(color X white) ";
		}
		else if((int)str.find("red") != -1)
		{
			color = true;
			col = "(color X red) ";
		}
		else if((int)str.find("green") != -1)
		{
			color = true;
			col = "(color X green) ";
		}
		else if((int)str.find("yellow") != -1)
		{
			color = true;
			col = "(color X yellow) ";
		}
		else if((int)str.find("blue") != -1)
		{
			color = true;
			col = "(color X blue) ";
		}
		else if((int)str.find("black") != -1)
		{
			color = true;
			col = "(color X black) ";
		}
		else
		{
		    
		}
		
		if((int)str.find("human") != -1)
		{
			tmp = "(sort X human) ";
		}
		else if((int)str.find("plant") != -1)
		{
			tmp = "(sort X plant) ";
		}
		else if((int)str.find("couch") != -1)
		{
			tmp = "(sort X couch) ";
		}
		else if((int)str.find("chair") != -1)
		{
			tmp = "(sort X chair) ";
		}
		else if((int)str.find("sofa") != -1)
		{
			tmp = "(sort X sofa) ";
		}
		else if((int)str.find("bed") != -1)
		{
			tmp = "(sort X bed) ";
		}
		else if((int)str.find("worktable") != -1)
		{
			tmp = "(sort X worktable) ";
		}
		else if((int)str.find("table") != -1)
		{
			tmp = "(sort X table) ";
		}
		else if((int)str.find("workspace") != -1)
		{
			tmp = "(sort X workspace) ";
		}
		else if((int)str.find("teapoy") != -1)
		{
			tmp = "(sort X teapoy) ";
		}
		else if((int)str.find("desk") != -1)
		{
			tmp = "(sort X desk) ";
		}
		else if((int)str.find("television") != -1)
		{
			tmp = "(sort X television) ";
		}
		else if((int)str.find("airconditioner") != -1)
		{
			tmp = "(sort X airconditioner) ";
		}
		else if((int)str.find("book") != -1)
		{
			tmp = "(sort X book) ";
		}
		else if((int)str.find("can") != -1)
		{
			tmp = "(sort X can) ";
		}
		else if((int)str.find("remotecontrol") != -1)
		{
			tmp = "(sort X remotecontrol) ";
		}
		else if((int)str.find("bottle") != -1)
		{
			tmp = "(sort X bottle) ";
		}
		else if((int)str.find("cupboard") != -1)
		{
			tmp = "(sort X cupboard) ";
		}
		else if((int)str.find("cup") != -1)
		{
			tmp = "(sort X cup) ";
		}
		else if((int)str.find("washmachine") != -1)
		{
			tmp = "(sort X washmachine) ";
		}
		else if((int)str.find("closet") != -1)
		{
			tmp = "(sort X closet) ";
		}
		else if((int)str.find("refrigerator") != -1)
		{
			tmp = "(sort X refrigerator) ";
		}
		else if((int)str.find("microwave") != -1)
		{
			tmp = "(sort X microwave) ";
		}
		else
		{
			//////////////////DEBUG/////////////////////////
			if(NATURE_DEBUG == 1)
			{
				cout<<endl<<"nature: error: The sort is out of rules."<<endl;
			}
			//////////////////DEBUG/////////////////////////	    
		}
	}
	else if(num == 2)
	{
		if((int)str.find("white") != -1)
		{
			color = true;
			col = "(color Y white) ";
		}
		else if((int)str.find("red") != -1)
		{
			color = true;
			col = "(color Y red) ";
		}
		else if((int)str.find("green") != -1)
		{
			color = true;
			col = "(color Y green) ";
		}
		else if((int)str.find("yellow") != -1)
		{
			color = true;
			col = "(color Y yellow) ";
		}
		else if((int)str.find("blue") != -1)
		{
			color = true;
			col = "(color Y blue) ";
		}
		else if((int)str.find("black") != -1)
		{
			color = true;
			col = "(color Y black) ";
		}
		else
		{
		    
		}
		
		if((int)str.find("human") != -1)
		{
			tmp = "(sort Y human) ";
		}
		else if((int)str.find("plant") != -1)
		{
			tmp = "(sort Y plant) ";
		}
		else if((int)str.find("couch") != -1)
		{
			tmp = "(sort Y couch) ";
		}
		else if((int)str.find("chair") != -1)
		{
			tmp = "(sort Y chair) ";
		}
		else if((int)str.find("sofa") != -1)
		{
			tmp = "(sort Y sofa) ";
		}
		else if((int)str.find("bed") != -1)
		{
			tmp = "(sort Y bed) ";
		}
		else if((int)str.find("worktable") != -1)
		{
			tmp = "(sort Y worktable) ";
		}
		else if((int)str.find("table") != -1)
		{
			tmp = "(sort Y table) ";
		}
		else if((int)str.find("workspace") != -1)
		{
			tmp = "(sort Y workspace) ";
		}
		else if((int)str.find("teapoy") != -1)
		{
			tmp = "(sort Y teapoy) ";
		}
		else if((int)str.find("desk") != -1)
		{
			tmp = "(sort Y desk) ";
		}
		else if((int)str.find("television") != -1)
		{
			tmp = "(sort Y television) ";
		}
		else if((int)str.find("airconditioner") != -1)
		{
			tmp = "(sort Y airconditioner) ";
		}
		else if((int)str.find("book") != -1)
		{
			tmp = "(sort Y book) ";
		}
		else if((int)str.find("can") != -1)
		{
			tmp = "(sort Y can) ";
		}
		else if((int)str.find("remotecontrol") != -1)
		{
			tmp = "(sort Y remotecontrol) ";
		}
		else if((int)str.find("bottle") != -1)
		{
			tmp = "(sort Y bottle) ";
		}
		else if((int)str.find("cupboard") != -1)
		{
			tmp = "(sort Y cupboard) ";
		}
		else if((int)str.find("cup") != -1)
		{
			tmp = "(sort Y cup) ";
		}
		else if((int)str.find("washmachine") != -1)
		{
			tmp = "(sort Y washmachine) ";
		}
		else if((int)str.find("closet") != -1)
		{
			tmp = "(sort Y closet) ";
		}
		
		else if((int)str.find("refrigerator") != -1)
		{
			tmp = "(sort Y refrigerator) ";
		}
		else if((int)str.find("microwave") != -1)
		{
			tmp = "(sort Y microwave) ";
		}
		else
		{
			//////////////////DEBUG/////////////////////////
			if(NATURE_DEBUG == 1)
			{
				cout<<endl<<"nature: error: The sort is out of rules."<<endl;
			}
			//////////////////DEBUG/////////////////////////	    
		}	    
	}
	else
	{
		//////////////////DEBUG/////////////////////////
		if(NATURE_DEBUG == 1)
		{
			cout<<endl<<"nature error."<<endl;
		}
		//////////////////DEBUG/////////////////////////	
	}
	if(num == 1)
	{
	    if(color)
	    {
		final = tmp + col;
	    }
	    else
	    {
		final = tmp;
	    }
	}
	else if(num == 2)
	{
	    if(color)
	    {
		col = col.substr(0,col.length()-1);
		final = tmp + col;
	    }
	    else
	    {
		tmp = tmp.substr(0,tmp.length()-1);
		final = tmp;
	    }
	}
	return final;
}

//end of file.














