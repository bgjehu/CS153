/*
 *Jieyi Hu
 *HW05 - AbstractStack
 *DUE 10/31
*/
#include"ArrayStack.hpp"
#include <cstdlib>
using namespace std;


int main()
{
	ArrayStack<int> data;
	string input;
	while(input!="@")
	{
		cin>>input;
		if(atoi(input.c_str())!=0){data.push(atoi(input.c_str()));}
		else if(atoi(input.c_str())==0&&input=="0"){data.push(0);}
		else
		{
			switch (input.at(0))
			{
				int a,b,c;
			case '+':
				a=data.top();
				data.pop();
				b=data.top();
				data.pop();
				c=b+a;
				data.push(c);
				break;
			case'-':
				a=data.top();
				data.pop();
				b=data.top();
				data.pop();
				c=b-a;
				data.push(c);
				break;
			case'*':
				a=data.top();
				data.pop();
				b=data.top();
				data.pop();
				c=b*a;
				data.push(c);
				break;
			case'/':
				a=data.top();
				data.pop();
				b=data.top();
				data.pop();
				c=b/a;
				data.push(c);
				break;
			case'%':
				a=data.top();
				data.pop();
				b=data.top();
				data.pop();
				c=b%a;
				data.push(c);
				break;
			case'!':
				a=data.top();
				data.pop();
				data.push(-a);
				break;
			case'$':
				data.clear();
				break;
			case 's':
				data.sum();
				break;
			case 'p':
				data.prod();
				break;
			case '#':
				data.print();
				break;
			}
		}
		
	}

	
	return 0;
}