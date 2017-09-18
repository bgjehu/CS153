//Jieyi Hu
//CS153 Sec A
//allrobots.cpp

#include "robotclasses.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	int num;
	cin>>num;
	Robot** R=new Robot* [num];
	for(int i=0;i<num;i++)
	{
		int tmp;
		cin>>tmp;
		if(tmp==0)
		{
			string n;
			int PS;
			int GC;
			cin>>n>>PS>>GC;
			R[i]=new Bender(n,PS,GC);
		}
		else if(tmp==1)
		{
			string n;
			int PS;
			int AP;
			float AD;
			cin>>n>>PS>>AP>>AD;
			R[i]=new Welder(n,PS,AP,AD);
		}
		else if(tmp==2)
		{
			string n;
			int CPU;
			int APPS;
			int legs;
			cin>>n>>CPU>>APPS>>legs;
			R[i]=new Legged(n,CPU,APPS,legs);
		}
		else if(tmp==3)
		{
			string n;
			int CPU;
			int APPS;
			int wheels;
			cin>>n>>CPU>>APPS>>wheels;
			R[i]=new Wheeled(n,CPU,APPS,wheels);
		}
		else if(tmp==4)
		{
			string n;
			int CPU;
			int APPS;
			int rockets;
			int AGE;
			cin>>n>>CPU>>APPS>>rockets>>AGE;
			R[i]=new Hover(n,CPU,APPS,rockets,AGE);
		}
	}

	//speed
	float max_speed=0;
	float min_speed=-1;
	int max_speed_robot;
	int min_speed_robot;

	float sum_speed=0;
	for(int i=0;i<num;i++)
	{
		sum_speed=sum_speed+R[i]->speed();
		if(R[i]->speed()>max_speed){max_speed_robot=i;max_speed=R[i]->speed();}
		if(R[i]->speed()<min_speed||min_speed==-1){min_speed_robot=i;min_speed=R[i]->speed();}
	}
	float av_speed=sum_speed/num;


	cout<<setprecision(4)
        <<"[Speed]"<<endl
		<<"The average speed is "<<av_speed<<" circus-rings per second."<<endl
		<<"The highest speed value is "<<max_speed<<" by "<<R[max_speed_robot]->getName()<<"."<<endl
		<<"The lowest speed value is "<<min_speed<<" by "<<R[min_speed_robot]->getName()<<"."<<endl
		<<endl;

	//strength
	float max_strength=0;
	float min_strength=-1;
	int max_strength_robot;
	int min_strength_robot;

	float sum_strength=0;
	for(int i=0;i<num;i++)
	{
		sum_strength=sum_strength+R[i]->strength();
		if(R[i]->strength()>max_strength){max_strength_robot=i;max_strength=R[i]->strength();}
		if(R[i]->strength()<min_strength||min_strength==-1){min_strength_robot=i;min_strength=R[i]->strength();}
	}
	float av_strength=sum_strength/num;

	cout<<setprecision(4)
        <<"[Strength]"<<endl
		<<"The average strength is "<<av_strength<<" dinosaur-power."<<endl
		<<"The highest strength value is "<<max_strength<<" by "<<R[max_strength_robot]->getName()<<"."<<endl
		<<"The lowest strength value is "<<min_strength<<" by "<<R[min_strength_robot]->getName()<<"."<<endl
		<<endl;


	//Toughness
	float max_toughness=0;
	float min_toughness=-1;
	int max_toughness_robot;
	int min_toughness_robot;

	float sum_toughness=0;
	for(int i=0;i<num;i++)
	{
		sum_toughness=sum_toughness+R[i]->toughness();
		if(R[i]->toughness()>max_toughness){max_toughness_robot=i;max_toughness=R[i]->toughness();}
		if(R[i]->toughness()<min_toughness||min_toughness==-1){min_toughness_robot=i;min_toughness=R[i]->toughness();}
	}
	float av_toughness=sum_toughness/num;

	cout<<setprecision(4)
        <<"[Toughness]"<<endl
		<<"The average toughness is "<<av_toughness<<" wrecking-balls."<<endl
		<<"The highest toughness value is "<<max_toughness<<" by "<<R[max_toughness_robot]->getName()<<"."<<endl
		<<"The lowest toughness value is "<<min_toughness<<" by "<<R[min_toughness_robot]->getName()<<"."<<endl
		<<endl;

	//intelligence
	float max_intelligence=0;
	float min_intelligence=-1;
	int max_intelligence_robot;
	int min_intelligence_robot;

	float sum_intelligence=0;
	for(int i=0;i<num;i++)
	{
		sum_intelligence=sum_intelligence+R[i]->intelligence();
		if(R[i]->intelligence()>max_intelligence){max_intelligence_robot=i;max_intelligence=R[i]->intelligence();}
		if(R[i]->intelligence()<min_intelligence||min_intelligence==-1){min_intelligence_robot=i;min_intelligence=R[i]->intelligence();}
	}
	float av_intelligence=sum_intelligence/num;

	cout<<setprecision(4)
        <<"[Intelligence]"<<endl
		<<"The average intelligence is "<<av_intelligence<<" nano-Turings."<<endl
		<<"The highest intelligence value is "<<max_intelligence<<" by "<<R[max_intelligence_robot]->getName()<<"."<<endl
		<<"The lowest intelligence value is "<<min_intelligence<<" by "<<R[min_intelligence_robot]->getName()<<"."<<endl;

	for(int i=0;i<num;i++)
	{
		delete R[i];
	}
	delete []R;
}
