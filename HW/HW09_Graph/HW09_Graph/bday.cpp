//bday.cpp
//Jieyi Hu
//DUE Dec 12

#include "AdjacencyMatrix.h"

using namespace std;

int main()
{
	int runs;
	cin>>runs;
	for(int i=0;i<runs;i++)
	{
		int token;
		string name;
		int places;
		AdjacencyMatrix city;
		cin>>token>>name>>places;
		city.m_name=name;
		for(int j=0;j<places;j++)
		{
			string from;
			int des;
			cin>>from>>des;
			city.insert(from);
			for(int k=0;k<des;k++)
			{
				string to;
				int weight;
				cin>>to>>weight;
				city.insert(to);
				city.alterweight(from,to,weight);
			}
		}
		city.path(token);
		city.print();
	}
	return 0;
}