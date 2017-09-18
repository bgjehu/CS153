//Jieyi Hu
//DUE Nov. 7
//fnlib.h
//Holding the functions those are needed for the main.cpp

#include<iostream>
using namespace std;



//********************************************************
//class coordinate:2 int for x(goes down), y(goes right)**
//********************************************************
class coordinate
{
public:
	int x;
	int y;
};

//*********************************
//			class map declaration**
//*********************************
class map
{
public:
	int m_col;	//number of columns of the map
	int m_row;	//number of rows of the map
	coordinate begin;	//coordinate of beginning point

	/*
	-----unnecessary member variables-----
	coordinate end;		//coordinate of ending point
	coordinate* traps;	////coordinate of traps
	int not;	//number of traps
	*/

	
	char** mapco; //the coordinater to the 2-D array map
	map(int,int);
	~map();
	void input();
	void output();
};

//********************************************************************************
//					constructor:setting up 2-D array to form the map			**
//********************************************************************************
map::map(int col, int row)	
{
	m_col=col+1;			//col+1 for \n column
	m_row=row;
	mapco=new char* [m_row];
	for(int k=0;k<m_row;k++)
	{
		mapco[k]=new char [col];
	}

	/*
	not=0;					//initiate number of traps
	*/
}

//********************************************************************************
//										distructor								**
//********************************************************************************
map::~map()	
{
	for(int k=0;k<m_row;k++)
	{
		delete []mapco[k];
	}
	delete []mapco;
}


//********************************************************************************
//										input Fn								**
//					i as row, j as column, i first then j, last column is all \n**
//********************************************************************************
void map::input()
{
	for(int i=0;i<m_row;i++)
	{
		for(int j=0;j<m_col;j++)
		{
			cin.get(mapco[i][j]);/*cout<<i<<","<<j<<"take in"<<mapco[i][j]<<endl;*/
			if(mapco[i][j]=='B'){begin.y=j;begin.x=i;/*cout<<"beginning pts="<<begin.x<<","<<begin.y<<endl;*/}
			/*
			--------------------------------------
			if(mapco[i][j]=='E'){end.y=i;end.x=j;}
			if(mapco[i][j]=='T'){not++;}
			*/
		}
	}
	
	/*
	-----------------------------------------------------------------
	traps=new coordinate [not];		//dynamic memory for traps
	int tmpcounter=0;				//counter for the order of traps;
	for(int i=0;i<m_row;i++)
	{
		for(int j=0;j<m_col;j++)
		{
			if(mapco[i][j]=='T'){traps[tmpcounter].y=i;traps[tmpcounter].x=j;tmpcounter++;}
		}
	}
	*/
}
//*****************************
//					output Fn**
//*****************************
void map::output()
{
	for(int i=0;i<m_row;i++)
	{
		for(int j=0;j<m_col;j++)
		{
			cout<<mapco[i][j];
		}
	}
	cout<<endl;
}






//***********************************
//					find path in map*
//***********************************
bool findpath(map&,int,int);
bool findpath(map& m_map, int x, int y)
{

	int newx=x;
	int newy=y;
	bool solve=false;
	int i=0;
	do
	{
		newx=x;newy=y;
		//cout<<"x="<<x<<"\ny="<<y<<endl;
		switch (i){case 0:newx=x+1;/*cout<<"going south\t"<<newx<<","<<newy<<endl;*/break;case 1:newy=y+1;/*cout<<"going east\t"<<newx<<","<<newy<<endl;*/break;case 2:newx=x-1;/*cout<<"going north\t"<<newx<<","<<newy<<endl;*/break;case 3:newy=y-1;/*cout<<"going west\t"<<newx<<","<<newy<<endl;*/break;}
		if(m_map.mapco[newx][newy]==' '){m_map.mapco[newx][newy]='.';/*cout<<"change("<<newx<<","<<newy<<")to . "<<endl;*/solve=findpath(m_map,newx,newy);}
		if(m_map.mapco[newx][newy]=='E'){solve=true;}
		if(solve){return true;}
		else{}
		i++;
		if(i==4){m_map.mapco[x][y]=' ';}

	}
	while(i<=3);
	return false;
}
	
