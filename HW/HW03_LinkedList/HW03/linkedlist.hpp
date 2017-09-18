//Jieyi Hu
//Sep 20 2013
//LinkedList implement

using namespace std;

//**************************getFirstPtr Fn************************** checked
template<typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
	if(this->isEmpty()==true){cout<<"PANIC in LinkedList.getFirstPtr() - empty list"<<endl;return NULL;}
	else{return this;}
}

//**************************getLastPtr Fn************************** checked
template<typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
	/*if(this->isEmpty()==true){return NULL;}
	else
	{
		LinkedList* ptr=m_next;
		while(ptr->m_next!=NULL)
		{
			while(ptr->m_next->m_next==NULL)
			{return ptr;}
			ptr=ptr->m_next;
		}
		return this;
	}*/
	if(this->isEmpty()==true){cout<<"PANIC in LinkedList.getFirstPtr() - empty list"<<endl;return NULL;}
	else
	{
		LinkedList* ptr=this;
		while(ptr->m_next!=NULL)
		{
			while(ptr->m_next->m_next==NULL)
			{return ptr;}
			ptr=ptr->m_next;
		}
		return this;
	}
}


//**************************getAtPtr Fn************************** checked
template<typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
	if(i<0){return NULL;}else{}
	LinkedList* ptr;
	ptr=this;
	int k=0;
	while(k<i&&ptr->m_next!=NULL)
	{
		ptr=ptr->m_next;
		k++;
	}
	if(ptr->m_next==NULL){cout<<"PANIC in LinkedList.getAtPtr() - invalid index"<<endl;return NULL;}
	return ptr;
}

//**************************clear Fn************************** checked
template<typename T>
void LinkedList<T>::clear()
{
	
	LinkedList* ptr;
	while(this->isEmpty()!=true)
	{
		ptr=this->getLastPtr();
		delete ptr->m_next;
		ptr->m_next=NULL;
	}
}

//**************************operator==************************** checked
template<typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
	LinkedList* tmp; //runner on rhs
	LinkedList* ptr; //runner on this
	if(m_data!=rhs.m_data){return false;}
	tmp=rhs.m_next;
	ptr=m_next;
	while(ptr->m_next!=NULL&&tmp->m_next!=NULL)
	{
		if(ptr->m_data!=tmp->m_data){return false;}
		tmp=tmp->m_next;
		ptr=ptr->m_next;
	}
	if(ptr->m_next==NULL&&tmp->m_next==NULL){return true;}
	else{return false;}
}

//**************************operator=************************** checked
template<typename T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
	if(this!=&rhs)
	{
		this->clear();
		LinkedList* tmp; //runner on rhs
		LinkedList* ptr; //runner on this
		tmp=rhs.m_next;
		if(tmp==NULL){return *this;}
		m_data=rhs.m_data;
		m_next=new LinkedList<T>;
		ptr=m_next;
		while(tmp->m_next!=NULL)
		{
			ptr->m_next=new LinkedList;
			ptr->m_data=tmp->m_data;
			tmp=tmp->m_next;
			ptr=ptr->m_next;
		}
		ptr->m_next=NULL;
	}
	return *this;
}

//**************************copy constructor************************** checked
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
	m_next=new LinkedList;
	*this=rhs;
}

//**************************size Fn************************** checked
template<typename T>
int LinkedList<T>::size() const
{
	if(this->isEmpty()==true){return 0;}
	else
	{
		int count=0;
		LinkedList* ptr;
		ptr=m_next;
		while(ptr!=NULL)
		{ptr=ptr->m_next;count++;}
		return count;
	}
}

//**************************isEmpty Fn************************** checked
template<typename T>
bool LinkedList<T>::isEmpty() const
{
	if(m_next==NULL){return true;}
	else{return false;}
}

//**************************insert_front Fn************************** checked
template<typename T>
void LinkedList<T>::insert_front(const T& x)
{
	LinkedList* tmp=new LinkedList;
	tmp->m_next=m_next;
	tmp->m_data=m_data;
	m_next=tmp;
	m_data=x;

}

//**************************insert Fn************************** checked
template<typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
	LinkedList* tmp=new LinkedList;
	tmp->m_next=pos->m_next;
	tmp->m_data=pos->m_data;
	pos->m_next=tmp;
	pos->m_data=x;
}

//**************************remove Fn************************** checked
template<typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
	LinkedList* tmp;
	tmp=pos->m_next;
	pos->m_data=tmp->m_data;
	pos->m_next=tmp->m_next;
	delete tmp;
}

//**************************find Fn************************** checked
template<typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
	LinkedList* tmp;
	tmp=this;
	while(tmp->m_next!=NULL&&tmp->m_data!=x)
	{
		tmp=tmp->m_next;
	}
	if(tmp->m_next==NULL){return NULL;}
	else{return tmp;}
}

//**************************append Fn************************** checked
template<typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
	LinkedList<T> ylist(xlist);
	this->getLastPtr()->m_next->m_data=ylist.m_data;
	this->getLastPtr()->m_next->m_next=ylist.m_next;
}


//**************************reverse Fn************************** checked
template<typename T>
void LinkedList<T>::reverse()
{
	LinkedList* tmp=new LinkedList;
	LinkedList* this2=m_next;
	const LinkedList* tmph=tmp;
	int size=this->size();
	for(int i=0;i<size;i++)
	{
		tmp->m_data=this->getAtPtr(size-1-i)->m_data;
		tmp->m_next=new LinkedList;
		tmp=tmp->m_next;
	}
	tmp->m_next=NULL;
	this->m_data=tmph->m_data;
	this->m_next=tmph->m_next;
	delete tmph;

	LinkedList* ptr;
	while(this2->isEmpty()!=true)
	{
		ptr=this2->getLastPtr();
		delete ptr->m_next;
		ptr->m_next=NULL;
	}
	delete ptr;

}	
