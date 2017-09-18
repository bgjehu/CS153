//Jieyi Hu
//DUE Nov. 7
//main.cpp
//Running functions in "fnlib.h" to find the right path for Bender to get out of the heist

#include"fnlib.h"
using namespace std;

int main()
{
	int col;
	int row;
	int i=0;
	cin>>col;
	cin>>row;
	cin.ignore();
	while(!(col==0||row==0))
	{
		map bank(col,row);
		bank.input();
		findpath(bank,bank.begin.x,bank.begin.y);
		cout<<"Map : "<<i<<endl;
		bank.output();
		i++;
		cin>>col;
		cin>>row;
		cin.ignore();
	}
	return 0;
}