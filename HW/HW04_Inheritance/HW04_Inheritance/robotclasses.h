//Jieyi Hu
//CS153 Sec A
//robotclasses.h

#include "robot.h"
using namespace std;

class IndBot: public Robot
{
protected:
	int m_PS; //PowerSource
public:
	IndBot(string,int);
};
IndBot::IndBot(string n, int PS): Robot(n)
{
	m_PS=PS;
}

class DomBot: public Robot
{
protected:
	int m_CPU;
	int m_APPS;
public:
	DomBot(string,int,int);
};
DomBot::DomBot(string n,int CPU,int APPS):Robot(n)
{
	m_CPU=CPU;
	m_APPS=APPS;
}

/* _________________
  /                 \
  |     Bender      |
  \_________________/
*/
class Bender: public IndBot
{
protected:
	int m_GC; //geometric coprocessors
public:
	virtual float speed();
	virtual float strength();
	virtual float toughness();
	virtual float intelligence();
	Bender(string,int,int);
};

Bender::Bender(string n,int PS,int GC) : IndBot(n,PS)
{
	m_GC=GC;
}
float Bender::speed()
{
	return 0.3*this->m_PS+0.02*this->m_GC;
}
float Bender::strength()
{
	return 0.55*this->m_PS;
}
float Bender::toughness()
{
	return 3.1415;
}
float Bender::intelligence()
{
	return 0.34+1.3*this->m_GC;
}

/* _________________
  /                 \
  |     Welder      |
  \_________________/
*/
class Welder: public IndBot
{
protected:
	int m_AP; //Armor Plates
	float m_AD; //Armor Density
public:
	virtual float speed();
	virtual float strength();
	virtual float toughness();
	virtual float intelligence();
	Welder(string,int,int,float);
};
Welder::Welder(string n,int PS,int AP,float AD):IndBot(n,PS)
{
	m_AP=AP;
	m_AD=AD;
}
float Welder::speed()
{
	if(0.1*this->m_PS-0.22*this->m_AP*this->m_AD<0){return 0;}
	return 0.1*this->m_PS-0.22*this->m_AP*this->m_AD;
}
float Welder::strength()
{
	return 3.15*this->m_PS;
}
float Welder::toughness()
{
	return 5.19*this->m_AP*this->m_AD;
}
float Welder::intelligence()
{
	return 0.45;
}

/* _________________
  /                 \
  |     Legged      |
  \_________________/
*/
class Legged: public DomBot
{
protected:
	int m_legs;
public:
	virtual float speed();
	virtual float strength();
	virtual float toughness();
	virtual float intelligence();
	Legged(string,int,int,int);
};
Legged::Legged(string n,int CPU,int APPS,int legs):DomBot(n,CPU,APPS)
{
	m_legs=legs;
}
float Legged::speed()
{
	if(7.15-0.04*this->m_legs*this->m_legs<0){return 0;}
	return 7.15-0.04*this->m_legs*this->m_legs;
}
float Legged::strength()
{
	return 0.123;
}
float Legged::toughness()
{
	return 1.4*(1/float(this->m_legs));
}
float Legged::intelligence()
{
	return 2.4*(this->m_CPU/float(this->m_APPS));
}

/* _________________
  /                 \
  |     Wheeled     |
  \_________________/
*/
class Wheeled: public DomBot
{
protected:
	int m_wheels;
public:
	virtual float speed();
	virtual float strength();
	virtual float toughness();
	virtual float intelligence();
	Wheeled(string,int,int,int);
};
Wheeled::Wheeled(string n,int CPU,int APPS,int wheels):DomBot(n,CPU,APPS)
{
	m_wheels=wheels;
}
float Wheeled::speed()
{
	return 0.33*this->m_wheels*this->m_wheels;
}
float Wheeled::strength()
{
	return 4.444;
}
float Wheeled::toughness()
{
	return 5.12-0.7*this->m_wheels;
}
float Wheeled::intelligence()
{
	return 1.3*(this->m_CPU/float(this->m_APPS));
}


/* _________________
  /                 \
  |      Hover      |
  \_________________/
*/
class Hover: public DomBot
{
protected:
	int m_rockets;
	int m_AGE; //anti-gravity engine
public:
	virtual float speed();
	virtual float strength();
	virtual float toughness();
	virtual float intelligence();
	Hover(string,int,int,int,int);
};
Hover::Hover(string n,int CPU,int APPS,int rockets,int AGE):DomBot(n,CPU,APPS)
{
	m_rockets=rockets;
	m_AGE=AGE;
}
float Hover::speed()
{
	return 0.59*this->m_rockets*this->m_AGE;
}
float Hover::strength()
{
	return 1.12*(1/float(this->m_AGE));
}
float Hover::toughness()
{
	return 0.99;
}
float Hover::intelligence()
{
	return 5.2*(this->m_CPU/float(this->m_APPS))-0.8*(1/float(this->m_rockets));
}
