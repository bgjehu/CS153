#include"abstractstack.h"
#include<iostream>
using namespace std;

template < typename T >
class ArrayStack : public AbstractStack<T>
{
	T* m_data;
	int m_max;
	int m_top;
public:
	virtual void clear();
	virtual void push(const T&);
	virtual void pop();
	virtual const T& top() const throw (string);
	virtual bool isEmpty() const;
	ArrayStack();
	~ArrayStack();
	void print();
	void sum();
	void prod();
};

template < typename T >
ArrayStack<T>::ArrayStack()
{
	m_max=10;
	m_data=new T [m_max];
	m_top=0;
}
template < typename T >
ArrayStack<T>::~ArrayStack()
{
	delete []m_data;
}

template < typename T >
void ArrayStack<T>::clear()
{
	m_top=0;
}

template < typename T >
void ArrayStack<T>::push(const T& x)
{
	if(m_top==m_max)
	{
		m_max=m_max*2;
		T* tmp=new T[m_max];
		for(int i=0;i<m_top;i++)
		{
			tmp[i]=m_data[i];
		}
		delete []m_data;
		m_data=tmp;

	}
	m_top++;
	m_data[m_top-1]=x;
}

template < typename T >
void ArrayStack<T>::pop()
{
	if(m_top<0){}
	else{m_top--;}
}

template < typename T >
const T& ArrayStack<T>::top() const throw (string)
{
	if(m_top<=0){throw("Empty Stack");}
	return m_data[m_top-1];
}

template < typename T >
bool ArrayStack<T>::isEmpty() const
{
	if(m_top==0){return true;}
	else{return false;}
}

template < typename T >
void ArrayStack<T>::print()
{
	switch (m_top)
	{
	case 0:
		cout<<"[ ]"<<endl;
		break;
	case 1:
		cout<<"[ "<<m_data[0]<<" ]"<<endl;
		break;
	default:
		cout<<"[ ";
		for(int i=m_top-1;i>=0;i--)
		{
			if(i!=0){cout<<m_data[i]<<", ";}
			else{cout<<m_data[i]<<" ]"<<endl;}
		}
		break;
	}
	

}

template < typename T >
void ArrayStack<T>::sum()
{
	int sum=0;
	int tmp;
	while(!this->isEmpty())
	{
		tmp=this->top();
		this->pop();
		sum=sum+tmp;
	}
	this->push(sum);
}

template < typename T >
void ArrayStack<T>::prod()
{
	int prod=1;
	int tmp;
	while(!this->isEmpty())
	{
		tmp=this->top();
		this->pop();
		prod=prod*tmp;
	}
	this->push(prod);
}