#define maxNode 25
#define In 1
#define Out 0
#define Unknown -1
class Node
{
	public:
		int status;
		int direction;
		string action;
};
class Obj
{
	public:
		int num;
		int direction;

		Obj()
		{
			num = Unknown;
			direction = Unknown;
		}
};
class Map
{
	public:	
		Obj obj[6];
		int objNum;

		Map()
		{
			objNum = 0;
		}
};
class Graph
{
	public:
		Graph()
		{
			mapNum = 0;
			for(int i=0;i<maxNode;i++)
			{
				for(int j=0;j<maxNode;j++)
				{
					VerList[i][j].status=0;
					VerList[i][j].direction=0;
					VerList[i][j].action = "";
				}
			}
		}
		void setTaskMap()
		void setStatus(int act1,int act2,string action)
		{
			VerList[act1][act2].status = 1;
			VerList[act1][act2].action = action;
			if( act1 && act2 )
			{
				if(action == "takeout")
				  VerList[act1][act2].direction=-1;
				if(action == "putin")
				  VerList[act1][act2].direction=1;
				if(action=="puton")
				  VerList[act1][act2].direction=-4;
			    if(action == "give")
				  VerList[act1][act2].direction=6;
			}


			if(act1 && !act2)
			{
				if(action == "open")
				  VerList[act1][act2].direction=-2;
				if(action == "close")
				  VerList[act1][act2].direction=2;
				if(action == "goto")
				  VerList[act1][act2].direction=3;
				if(action == "putdown")
				  VerList[act1][act2].direction=4;
				if(action == "pickup")
				  VerList[act1][act2].direction=5;
			}
		}
		void setStatus(int i,int j,int success)
		{
		    if(success == 1)
                VerList[i][j].status = 0;
            else
                VerList[i][j].status = 1;
		}
		int getStatus(int i,int j)
		{
			return VerList[i][j].status;
		}
		int getDirection(int i,int j)
		{
			return VerList[i][j].direction;
		}
		void printMatrix()
		{
			int flagx=0,flagy=0;
			int i,j;
			for(i=0;i<maxNode;i++)
			{
				if(flagx==0)
				{
					for(j=0;j<maxNode;j++)
					{
						if(flagx==0)
						  cout<<"  ";
						cout<<j<<" ";
						flagx = 1;
					}
					cout<<endl;
				}
				for(j=0;j<maxNode;j++)
				{
					if(flagy==0)
					  cout<<i<<" ";
					flagy=1;
					cout<<VerList[i][j].direction<<" ";
				}
				flagy = 0;
				cout<<endl;
			}
		}
	private:
		Node VerList[maxNode][maxNode];
		Map taskMap[10];
		int mapNum;
};
