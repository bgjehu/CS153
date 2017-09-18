//HW08_MaxHeap_maxheap.h
//Jieyi Hu
//DUE Dec 2

#ifndef MAXHEAP_H 
#define MAXHEAP_H

#include "abstractheap.h"
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class maxHeap : public AbstractHeap<T>
{
public:
	T* m_data;
	int m_max;
	int m_size;
	virtual bool isEmpty() const;
	virtual int size() const;
	virtual const T& top() const;
	void rec_print(int, int, const maxHeap<T>&) const;
	virtual void print() const;
	virtual void clear();
	virtual void insert(const T&);
	virtual void remove();
	maxHeap<T>& operator=(const maxHeap<T>&);
	maxHeap();
	maxHeap(const maxHeap<T>&);
	~maxHeap();

};

template <typename T>
maxHeap<T>::maxHeap()
{
	m_max=20;
	m_data=new T [m_max];
	m_size=0;
}

template <typename T>
bool maxHeap<T>::isEmpty() const
{
	if(m_size>0){return false;}
	else{return true;}

}

template <typename T>
int maxHeap<T>::size() const{return m_size;}

template <typename T>
const T& maxHeap<T>::top() const
{
	if(m_size>0){return m_data[1];}
	else{throw(0);}
} 

template <typename T>
void maxHeap<T>::rec_print(int ix, int pad, const maxHeap<T>& heap) const
{
	string s(pad, ' ');
	if (ix > heap.m_size)
		cout << endl;
	else
	{
		rec_print( ix*2+1, pad+4,heap);
		cout << s << heap.m_data[ix] << endl;
		rec_print( ix*2, pad+4,heap);
	}
}

template <typename T>
void maxHeap<T>::print() const
{
	rec_print(1,0,*this);
}

template <typename T>
void maxHeap<T>::clear(){m_size=0;}


template <typename T>
void pcl_up(const T x,maxHeap<T>& heap)
{
	int hole;
	heap.m_size++; //cout<<"size++"<<endl;
	hole=heap.m_size;
	while(hole>1&&x>heap.m_data[hole/2])
	{
		heap.m_data[hole]=heap.m_data[hole/2];
		hole=hole/2;
	}
	heap.m_data[hole]=x;

}

template <typename T>
void maxHeap<T>::insert(const T& x)
{
	if(m_size+1==m_max)
	{
		m_max=m_max*2;
		T* tmp=new T [m_max];
		for(int i=1;i<m_size+1;i++)
		{
			tmp[i]=m_data[i];
		}
		delete []m_data;
		m_data=tmp;
	}
	pcl_up(x,*this);//cout<<"pcl_up"<<endl;
}


template <typename T>
void pcl_down(maxHeap<T>& heap)
{
	T tmp=heap.m_data[heap.m_size];
	heap.m_size--;
	int hole=1;
	bool done=false;
	int child;
	while(hole*2<=heap.m_size&&!done)
	{
		child=hole*2;
		if(child+1<heap.m_size&&heap.m_data[child+1]>=heap.m_data[child])
		{child++;}
		if(heap.m_data[child]>tmp)
		{
			heap.m_data[hole]=heap.m_data[child];
			hole=child;
		}
		else{done=true;}
	}
	heap.m_data[hole]=tmp;
}

template <typename T>
void maxHeap<T>::remove()
{
	if(m_size+1<m_max/2)
	{
		m_max=m_max/2;
		T* tmp=new T [m_max];
		for(int i=1;i<m_size+1;i++)
		{
			tmp[i]=m_data[i];
		}
		delete []m_data;
		m_data=tmp;
	}
	pcl_down(*this);
}

template <typename T>
maxHeap<T>& maxHeap<T>::operator=(const maxHeap<T>& rhs)
{

	if(this!=&rhs)
	{
		delete []m_data;
		m_max=rhs.m_max;
		m_size=rhs.m_size;
		m_data=new T [m_max];
		for(int i=1;i<m_size+1;i++)
		{
			m_data[i]=rhs.m_data[i];
		}
	}

	return *this;
}


template <typename T>
maxHeap<T>::maxHeap(const maxHeap<T>& cpy)
{
	m_max=cpy.m_max;
	m_size=cpy.m_size;
	m_data=new T [m_max];
	for(int i=1;i<m_size+1;i++)
	{
		m_data[i]=cpy.m_data[i];
	}
}


template <typename T>
maxHeap<T>::~maxHeap(){delete []m_data,m_data=NULL;}



#endif
