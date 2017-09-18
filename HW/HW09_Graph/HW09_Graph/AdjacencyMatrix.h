//AdjacencyMatrix.h
//Jieyi Hu
//DUE Dec 12

#ifndef ADJACENCYMATRIX_H
#define	ADJACENCYMATRIX_H

#include <string>
#include <iostream>

using namespace std;

class AdjacencyMatrix
{
private:
	int** m_data;
	string* m_item;
	int m_size;
	string* m_item2;
	int m_size2;

public:
	string m_name;
	AdjacencyMatrix();
	//Big-3
	AdjacencyMatrix& operator=(const AdjacencyMatrix&);
	AdjacencyMatrix(const AdjacencyMatrix&);
	~AdjacencyMatrix();
	//other Fns
	void alterweight(const string,const string,const int);
	void clear();
	void insert(const string);
	bool isEmpty() const;
	bool isNeighbors(const int,const int) const;
	bool isNeighbors(const string,const string) const;
	string item(const int) const;
	int item(const string) const;
	void path(int&);
	void rec_path(const string,int&);
	void print();
	int weight(const string,const string) const;
	int weight(const int,const int) const;
};

//constructor
AdjacencyMatrix::AdjacencyMatrix()
{
	m_size=0;
	m_data=NULL;
	m_item=NULL;
}

//distructor
AdjacencyMatrix::~AdjacencyMatrix()
{
	clear();
	delete []m_item2;
}

//alterweight
void AdjacencyMatrix::alterweight(const string x, const string y, const int weight) //from x to y
{
	int a,b;
	try
	{
		a=item(x);
		b=item(y);
		m_data[a][b]=weight;
	}
	catch (string x)
	{
		cout<<"!!!Error: no match for element \""<<x<<"\""<<endl;
	}
}

//clear()
void AdjacencyMatrix::clear()
{
	if(m_size>1)
	{
		delete []m_item;
		for(int i=0;i<m_size;i++)
		{
			delete []m_data[i];
		}
		delete []m_data;
	}
	else if(m_size==1)
	{
		delete []m_item;
		delete []m_data[0];delete []m_data;
	}
	m_data=NULL;
	m_item=NULL;
}

//insert()
void AdjacencyMatrix::insert(const string x)
{
	bool isDuplicate=false;
	if(!isEmpty())											//if not empty, test for duplicate
	{
		for(int i=0;i<m_size;i++)
		{
			if(m_item[i]==x)
			{
				isDuplicate=true;
			}
		}
		if(isDuplicate!=true)
		{
			//set up new tmp matrix

			//m_size++;
			string* tmp_item=new string [m_size+1];
			int** tmp_data=new int* [m_size+1];
			for(int i=0;i<m_size+1;i++)
			{
				tmp_data[i]=new int [m_size+1];
			}
			//transfer data
			for(int i=0;i<m_size;i++)
			{
				tmp_item[i]=m_item[i];
			}
			tmp_item[m_size]=x;
			for(int i=0;i<m_size;i++)
			{
				for(int j=0;j<m_size;j++)
				{
					tmp_data[i][j]=m_data[i][j];
				}
			}
			for(int i=0;i<m_size+1;i++)
			{
				tmp_data[i][m_size]=0;
				tmp_data[m_size][i]=0;
			}
			tmp_data[m_size][m_size]=0;

			clear();

			m_data=tmp_data;
			m_item=tmp_item;
			m_size++;
			//cout<<"\""<<x<<"\" is inserted"<<endl;

		}
	}
	else
	{
		m_size++;
		m_item=new string [1];
		m_item[0]=x;
		m_data=new int* [1];
		m_data[0]=new int [1];
		m_data[0][0]=0;
		//cout<<"\""<<x<<"\" is inserted"<<endl;
	}



}

//isEmpty()
bool AdjacencyMatrix::isEmpty() const
{
	if(m_size==0){return true;}
	else{return false;}
}

//isNeighbors(ints)
bool AdjacencyMatrix::isNeighbors(const int x,const int y) const
{
	if(m_data[x][y]>0){return true;}
	else{return false;}
}

//isNeighbors(strings)
bool AdjacencyMatrix::isNeighbors(const string x,const string y) const
{
	int a,b;
	try
	{
		a=item(x);
		b=item(y);
		if(m_data[a][b]>0){return true;}
		else{return false;}
	}
	catch (string x)
	{
		cout<<"!!!Error: no match for element \""<<x<<"\""<<endl;
		return false;
	}
}

//item(int)
string AdjacencyMatrix::item(const int x) const
{
	return m_item[x];
}

//item(string)
int AdjacencyMatrix::item(const string x) const
{
	for(int i=0;i<m_size;i++)
	{
		if(m_item[i]==x){return i;}
	}
	throw x;
}

//path()
void AdjacencyMatrix::path(int& m)
{
	m_item2=new string [m_size];
	m_size2=0;
	rec_path("airport",m);
}

//rec_path()
void AdjacencyMatrix::rec_path(const string x, int& m)
{
	int a=item(x);
	for(int i=0;i<m_size;i++)
	{
		if(isNeighbors(a,i)&&m-weight(a,i)>=0)
		{

			bool duplicate=false;
			for(int j=0;j<m_size2;j++)
			{
				if(m_item2[j]==item(i)){duplicate=true;}
			}
			if(!duplicate)
			{
				m_item2[m_size2]=item(i);
				m_size2++;
				m=m-weight(a,i);
				//cout<<"go from "<<x<<" to "<<item(i)<<", used "<<weight(a,i)<<", "<<m<<" left."<<endl;
				rec_path(item(i),m); 
				m=m+weight(a,i);
				//cout<<"get back "<<weight(a,i)<<", now has "<<m<<", going back to "<<x<<endl;
			}			
			else
			{
				m=m-weight(a,i);
				//cout<<"go from "<<x<<" to "<<item(i)<<", used "<<weight(a,i)<<", "<<m<<" left."<<endl;
				rec_path(item(i),m); 
				m=m+weight(a,i);
				//cout<<"get back "<<weight(a,i)<<", now has "<<m<<", going back to "<<x<<endl;
			}
		}
		else{}
	}




}

//print()
void AdjacencyMatrix::print()
{
	/*cout<<"|"<<m_name<<"|"<<endl;
	for(int i=0;i<m_size;i++){if(i==0){cout<<" \t";}cout<<i+1<<"\t";}
	cout<<endl;
	for(int i=0;i<m_size;i++){if(i==0){cout<<" \t";}cout<<"-\t";}
	cout<<endl;
	for(int i=0;i<m_size;i++)
	{
		for(int j=0;j<m_size;j++)
		{
			if(j==0){cout<<i+1<<"|\t";}
			cout<<m_data[i][j]<<"\t";
			if(j==m_size-1){cout<<endl;}
		}
	}*/
	/////////////////////////////////
	cout<<"In "<<m_name<<", Bender can reach:"<<endl;
	if(m_size2!=0)
	{
		for(int i=0;i<m_size2;i++)
		{
			cout<<m_item2[i]<<endl;
		}
	}
	else{cout<<"nothing :-("<<endl;}
	cout<<endl;
}

//weight(strings)
int AdjacencyMatrix::weight(const string x,const string y) const
{
	int a,b;
	try
	{
		a=item(x);
		b=item(y);
		return m_data[a][b];
	}
	catch (string x)
	{
		cout<<"!!!Error: no match for element \""<<x<<"\""<<endl;
		return -1;
	}

}

//weight(ints)
int AdjacencyMatrix::weight(const int x,const int y) const
{
	try
	{
		if(x<m_size&&y<m_size)
		{return m_data[x][y];}
		else{throw "";}
	}
	catch (string x)
	{
		cout<<"!!!Error: no match for element \""<<x<<"\""<<endl;
		return -1;
	}
}



#endif