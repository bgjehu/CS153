iusing namespace std;

//**************************Destructor**************************
template <typename T>
ArrayList<T>::~ArrayList()
{
	delete []m_data;
}



//**************************Operator=**************************
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
	if(this!=&rhs)
	{
		if(rhs.m_size==0&&rhs.m_max==0&&rhs.m_data==NULL)
		{
			delete []m_data;
			m_data=NULL;
			m_max=0;
			m_size=0;
		}
		else
		{
			if(m_max==0&&m_size==0&&m_data==NULL)
			{
				m_data=new T[1];
			}
			else{}
			delete []m_data;
			m_size=rhs.m_size;
			m_max=rhs.m_max;
			m_data=new T[m_max];
			for(int i=0;i<m_size;i++)
			{
				m_data[i]=rhs.m_data[i];
			}
		}
	}
	else{}
	return *this;
}

//**************************Copy Constructor**************************
template <typename T>
ArrayList<T>::ArrayList<T>(const ArrayList<T>& cpy)
{
	m_max=cpy.m_max;
	m_size=cpy.m_size;
	m_data=new T[m_max];
	for(int i=0;i<m_size;i++)
	{
		m_data[i]=cpy.m_data[i];
	}
}



//**************************Size Fn**************************
template <typename T>
int ArrayList<T>::size() const
{
	return m_size;
}


//**************************insert_back Fn**************************
template <typename T>
void ArrayList<T>::insert_back(const T& x)		
{
	if(m_size==m_max&&m_max!=0)
	{
		T* tmp;
		tmp=new T[m_max];
		for(int i=0;i<m_size;i++)
		{
			tmp[i]=m_data[i];
		}
		delete []m_data;
		m_max=m_max*2;
		m_data=new T[m_max];
		for(int i=0;i<m_size;i++)
		{
			m_data[i]=tmp[i];
		}
		delete []tmp;
		tmp=NULL;

	}
	else if (m_size==m_max&&m_max==0)
	{
		m_data=new T[1];
		m_max=1;
	}
	else{}
	m_data[m_size]=x;
	m_size++;
}

//**************************insert Fn**************************
template<typename T> 
void ArrayList<T>::insert(const T& x, int i)
{
	if(i<m_size&&i>=0) 
	{
		if(m_size==m_max)	//regular maxed out situation
		{
			T* tmp;
			m_max=m_max*2;
			tmp=new T[m_max];
			for(int j=0;j<i;j++)
			{
				tmp[j]=m_data[j];
			}
			tmp[i]=x;
			for(int j=i+1;j<m_size+1;j++)
			{
				tmp[j]=m_data[j-1];
			}
			delete []m_data;
			m_data=new T[m_max];
			for(int j=0;j<m_size+1;j++)
			{
				m_data[j]=tmp[j];
			}
			delete []tmp;
			tmp=NULL;


		}
		else						//non maxed out arraylist
		{
			T* tmp;
			tmp=new T[m_max];
			for(int j=0;j<i;j++)
			{
				tmp[j]=m_data[j];
			}
			tmp[i]=x;
			for(int j=i+1;j<m_size+1;j++)
			{
				tmp[j]=m_data[j-1];
			}
			delete []m_data;
			m_data=new T[m_max];
			for(int j=0;j<m_size+1;j++)
			{
				m_data[j]=tmp[j];
			}
			delete []tmp;
			tmp=NULL;
		}
		m_size++;
	}
	else
	{
		if(i==0&&m_max==0) //inserting into empty arraylist
		{
			m_data=new T[1];
			m_data[i]=x;
			m_max=1;
		}
		else{cout<<"!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)"<<endl;}
	}
}



//**************************first Fn**************************
template<typename T>
const T& ArrayList<T>::first() const
{
	if(m_max==0)
	{
		cout<<"!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)"<<endl;
		return m_errobj;
	}
	return m_data[0];
}




//**************************operator[]**************************
template<typename T>
T& ArrayList<T>::operator[](int i)
{
	if(i<0||i>=m_size)
	{
		cout<<"!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)"<<endl;
		return m_errobj;
	}
	return m_data[i];
}

template<typename T>
const T& ArrayList<T>::operator[](int i) const
{
	if(i<0||i>=m_size)
	{
		cout<<"!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)"<<endl;
		return m_errobj;
	}
	return m_data[i];
}


//**************************clear Fn**************************
template<typename T>
void ArrayList<T>::clear()
{
	if(m_max==0){}
	else
	{
		delete []m_data;
		m_data=NULL;
		m_max=0;
		m_size=0;
	}
}


//**************************remove Fn**************************
template<typename T>
void ArrayList<T>::remove(int i)
{
	if(m_max==0){cout<<"!-- ERROR : PANIC in ARRAYLIST!!.remove()  (List is empty)"<<endl;}
	else
	{
		if(i>=0&&i<m_size)
		{
			if(m_size-1<m_max/4){m_max=m_max/2;}
			else{}
			T* tmp;
			tmp=new T[m_max];
			for(int j=0;j<i;j++)
			{
				tmp[j]=m_data[j];
			}
			for(int j=i+1;j<m_size;j++)
			{
				tmp[j-1]=m_data[j];
			}
			delete []m_data;
			m_data=new T[m_max];
			for(int j=0;j<m_size-1;j++)
			{
				m_data[j]=tmp[j];
			}
			delete []tmp;
			tmp=NULL;
			m_size--;
		}
		else{cout<<"!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)"<<endl;}
	}

}


//**************************find Fn**************************
template<typename T>
int ArrayList<T>::find(const T& x)
{
	for(int i=0;i<m_size;i++)
	{
		if(m_data[i]==x)
		{
			return i;
		}
		else{}
	}
	return -1;
}

//**************************swap Fn**************************
template<typename T>
void ArrayList<T>::swap(int i, int k)
{
	if(m_max<2){cout<<"!-- ERROR : PANIC in ARRAYLIST!!.swap()  (too few elements to execute swap)"<<endl;}
	else{}
	if(i<m_size&&k<m_size)
	{
		T* tmp;
		tmp=new T[m_max];
		if(i==k){/*do nothing or give error*/}
		else if(i>k){int s=k;k=i;i=s;}
		else{}
		for(int j=0;j<i;j++)
		{
			tmp[j]=m_data[j];
		}
		tmp[i]=m_data[k];
		for(int j=i+1;j<k;j++)
		{
			tmp[j]=m_data[j];
		}
		tmp[k]=m_data[i];
		for(int j=k+1;j<m_size;j++)
		{
			tmp[j]=m_data[j];
		}
		for(int j=0;j<m_size;j++)
		{
			m_data[j]=tmp[j];
		}
		delete []tmp;
		tmp=NULL;
	}
	else{cout<<"!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)"<<endl;}
}


//**************************append Fn**************************
template<typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
	T* tmp;
	if(m_max==0){m_data=new T[1];}else{}
	m_max=m_max+alist.m_max;
	tmp=new T[m_max];
	for(int i=0;i<m_size;i++)
	{
		tmp[i]=m_data[i];
	}
	for(int i=m_size;i<alist.m_size+m_size;i++)
	{
		tmp[i]=alist.m_data[i-m_size];
	}
	m_size=m_size+alist.m_size;
	delete []m_data;
	m_data=new T[m_max];
	for(int i=0;i<m_size;i++)
	{
		m_data[i]=tmp[i];
	}
	delete []tmp;
	tmp=NULL;
}


//**************************purge Fn**************************
template<typename T>
void ArrayList<T>::purge()
{
	if(m_max<2){cout<<"!-- ERROR : PANIC in ARRAYLIST!!.purge()  (too few elements to execute purge)"<<endl;}
	else
	{
		for(int i=1;i<m_size;i++)
		{
jumpout:
			for(int j=0;j<i;j++)
			{
				if(m_data[i]==m_data[j])
				{
					this->remove(i);
					cout<<"a = "<<*this<<endl;
					goto jumpout;
				}
			}
		}
		/*ArrayList<T> tmp(*this);
		int dup=0;
		for(int i=1;i<m_size;i++)
		{
		for(int j=0;j<i;j++)
		{
		if(m_data[i]==m_data[j])
		{
		dup++;
		tmp.remove(i-dup+1);
		}
		}
		}

		*this=tmp;*/
	}
}