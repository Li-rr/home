class Node
{
	public:
		int status;
		int direction;
		string action;
};
class Graph
{
	public:
		Graph()
		{
			for(int i=0;i<30;i++)
			{
				for(int j=0;j<30;j++)
				{
					VerList[i][j].status=1;
					VerList[i][j].direction=0;
					VerList[i][j].action = "";
				}
			}
		}
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
			}

			if(act1 && !act2)
			{
				if(action == "open")
				  VerList[act1][act2].direction=-2;
				if(action == "close")
				  VerList[act1][act2].direction=2;
			}
		}
		int getStatus(int i,int j)
		{
			return VerList[i][j].status;
		}
		int getDirection(int i,int j)
		{
			return VerList[i][j].direction;
		}
	private:
		Node VerList[30][30];
};
