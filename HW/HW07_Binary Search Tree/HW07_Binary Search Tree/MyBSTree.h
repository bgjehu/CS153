//MyBSTree.h
//Jieyi Hu
//DUE 11/14/2013 Thrusday


#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"

using namespace std;


//TreeNode class
template <typename T>
class TreeNode
{
public:
	//member variables
	T m_data;
	TreeNode* m_left;
	TreeNode* m_right;
	//member functions
	TreeNode();
	TreeNode(const T);

	/*******************TreeNode Big-3*****************
	TreeNode<T>& operator=(const TreeNode<T>&);
	~TreeNode();
	*/


};

//NULL constructor
template <typename T>
TreeNode<T>::TreeNode()
{
	m_left=NULL;
	m_right=NULL;
}

//ALT constructor
template <typename T>
TreeNode<T>::TreeNode(const T x)
{
	m_data=x;
	m_left=NULL;
	m_right=NULL;
}

/*******************TreeNode Big-3*****************
//operator= for TreeNode
template <typename T>
TreeNode<T>& TreeNode<T>::operator=(const TreeNode<T>& rhs)
{}

//copy constructor for TreeNode
template <typename T>
TreeNode<T>::TreeNode(const TreeNode<T>& cpy)
{
}

//distructor for TreeNode
template <typename T>
TreeNode<T>::~TreeNode()
{
}
*/

//MyBSTree class
template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
	//member variables
	TreeNode<T>* m_root;
	int m_size;
	int m_height;
	T* pre;
	T* post;
public:
	//member functions
	int size() const;
	bool isEmpty() const;
	int height() const;
	const T& findMax() const;
	const T& findMax(TreeNode<T>*) const;
	const T& findMin() const;
	int contains(const T& x) const;
	void clear();
	void insert(const T& x);
	void remove(const T& x);
	void printPreOrder() const;
	void printPostOrder() const;
	void print() const;
	MyBSTree();
	//Big-3
	MyBSTree<T>& operator=(MyBSTree<T>&);
	MyBSTree(MyBSTree<T>&);
	~MyBSTree();
	//rec_FNS
	void rec_height(TreeNode<T>*&,int&,int&);				//for height()			::count height
	void rec_insert(TreeNode<T>*&,const T,bool&);			//for insert()			::rundown to right place and insert
	void rec_print(const TreeNode<T>*,int) const;			//for print()			::print out an element each line with format
	void rec_pue(TreeNode<T>*&,T*&,int&);					//for operator=			::PICK UP ELEMENTS into an array
															//for constructor		::PICK UP ELEMENTS into an array
	void rec_remove(TreeNode<T>*&,const T&);				//for remove()			::rundown to right place and remove
	void rec_removetree(TreeNode<T>*&);						//for clear()			::empty the tree
															//for distructor		::empty the tree to release memory
															//for operator=			::empty the tree before rebuild
	void PreOrderArray();									//for printPreOrder()	::build PreOrderArray to print
	void rec_PreOrderArray(TreeNode<T>*&,int&);				//for PreOrderArray()	::print PreOrderly while running down the tree
	void PostOrderArray();									//for printPreOrder()	::build PreOrderArray to print
	void rec_PostOrderArray(TreeNode<T>*&,int&);			//for PostOrderArray()	::print PreOrderly while running down the tree
};

//size()
template <typename T>
int MyBSTree<T>::size() const
{
	return m_size;
}

//isEmpty()
template <typename T>
bool MyBSTree<T>::isEmpty() const
{
	if(m_root==NULL){return true;}
	else{return false;}
}

//height()
template <typename T>
int MyBSTree<T>::height() const
{
	return m_height;
}

//findMax()
template <typename T>
const T& MyBSTree<T>::findMax() const
{
	return findMax(m_root);
}
//findMax
template <typename T>
const T& MyBSTree<T>::findMax(TreeNode<T>* t) const
{
	if(t==NULL){throw string("PANIC : Tree is Empty!!");}
	TreeNode<T>* runner;
	runner=t;
	while(runner->m_right!=NULL)
	{runner=runner->m_right;}
	return runner->m_data;
}

//findMin
template <typename T>
const T& MyBSTree<T>::findMin() const
{
	if(m_root==NULL){throw string("PANIC : Tree is Empty!!");}
	TreeNode<T>* runner;
	runner=m_root;
	while(runner->m_left!=NULL)
	{
		runner=runner->m_left;
	}
	return runner->m_data;
}


//contains()
template <typename T>
int MyBSTree<T>::contains(const T& x) const
{
	
	int count=0;
	bool done=false;
	TreeNode<T>* t;//runner
	if(m_root==NULL){return -1;}
	else
	{
		t=m_root;
		while(!done&&x!=t->m_data)
		{
			if(x<t->m_data){t=t->m_left;count++;}
			else if(x>t->m_data){t=t->m_right;count++;}
			else{done=true;count++;}
			if(t==NULL){count=-count;done=true;}
		}
	}
	return count;

}

//clear()
template <typename T>
void MyBSTree<T>::clear()
{
	rec_removetree(m_root);
}

//insert()
template <typename T>
void MyBSTree<T>::insert(const T& x)
{
	bool inserted=false;
	rec_insert(m_root,x,inserted);
	if(inserted){m_size++;int count=0;rec_height(m_root,count,m_height);}
	PreOrderArray();
	PostOrderArray();
}

//remove()
template <typename T>
void MyBSTree<T>::remove(const T& x)
{
	rec_remove(m_root,x);
}

//printPreOrder()
template <typename T>
void MyBSTree<T>::printPreOrder() const
{
	for(int i=0;i<m_size;i++)
	{
		cout<<pre[i]<<endl;
	}
}

//printPostOrder()
template <typename T>
void MyBSTree<T>::printPostOrder() const
{
	for(int i=0;i<m_size;i++)
	{
		cout<<post[i]<<endl;
	}
}

//print()
template <typename T>
void MyBSTree<T>::print() const
{
	rec_print(m_root,0);
}

//constructor
template <typename T>
MyBSTree<T>::MyBSTree()
{
	m_root=NULL;
	m_size=0;
	m_height=0;
	pre=NULL;
	post=NULL;
}

//operator= for MyBSTree
template <typename T>
MyBSTree<T>& MyBSTree<T>::operator=(MyBSTree<T>& rhs)
{
	//empty the tree
	rec_removetree(m_root);
	m_size=0;
	m_height=0;
	//rebuild the tree
	m_size=rhs.m_size;
	m_height=rhs.m_height;
	for(int i=0;i<rhs.m_size;i++)
	{
		this->insert(rhs.pre[i]);
	}
	return *this;
}

//copy constructor for MyBSTree
template <typename T>
MyBSTree<T>::MyBSTree(MyBSTree<T>& cpy)
{
	m_size=cpy.m_size;
	m_height=cpy.m_height;
	m_root=NULL;
	bool inserted;
	pre=new T [cpy.m_size];
	post=new T [cpy.m_size];
	for(int i=0;i<cpy.m_size;i++)
	{
		pre[i]=cpy.pre[i];
		post[i]=cpy.post[i];
	}
	for(int i=0;i<cpy.m_size;i++)
	{
		rec_insert(m_root,pre[i],inserted);
	}
}

//distructor for MyBSTree
template <typename T>
MyBSTree<T>::~MyBSTree()
{
	rec_removetree(m_root);
	if(pre!=NULL){delete []pre;pre=NULL;}
	if(post!=NULL){delete []post;post=NULL;}
}

//rec_height()
template <typename T>
void MyBSTree<T>::rec_height(TreeNode<T>*& t, int& count, int& height)
{
	if(t==NULL){return;}
	else
	{
		for(int i=0;i<2;i++)
		{
			switch(i)
			{
			case 0:count++;if(t->m_left!=NULL){rec_height(t->m_left, count, height);count--;}else{count--;}break;
			case 1:count++;if(t->m_right!=NULL){rec_height(t->m_right, count, height);count--;}else{if(count>height){height=count;}count--;return;}
			}
		}
	}

}

//rec_insert()
template <typename T>
void MyBSTree<T>::rec_insert(TreeNode<T>*& t,const T x, bool& inserted)
{
	if(t==NULL){t=new TreeNode<T>(x);inserted=true;}
	else if(x<t->m_data){rec_insert(t->m_left,x,inserted);}
	else if(x>t->m_data){rec_insert(t->m_right,x,inserted);}
	else{return;}
}

//rec_print()
template <typename T>
void MyBSTree<T>::rec_print(const TreeNode<T>* t, int pad) const
{
	string s(pad, ' ');
	if (t == NULL)
	{cout << endl;}
	else
	{
		rec_print(t->m_right, pad+4);
		cout << s << t->m_data << endl;
		rec_print(t->m_left, pad+4);
	}  

}

//rec_pue()
template <typename T>
void MyBSTree<T>::rec_pue(TreeNode<T>*& t, T*& tmparray, int& count)
{
	TreeNode<T>* dir=t;
	if(t==NULL){return;}
	else
	{
		while(count!=m_size)
		{
			tmparray[count]=dir->m_data;
			//cout<<"tmparray recorded "<<dir->m_data<<" into ["<<count<<"]"<<endl;
			count++;
			for(int i=0;i<2;i++)
			{
				switch(i)
				{
				case 0:
					dir=t->m_left;
					break;
				case 1:
					dir=t->m_right;
					break;
				}
				rec_pue(dir,tmparray,count);
				if(i==1){return;}
			}
		}

	}

}

//rec_remove()
template <typename T>
void MyBSTree<T>::rec_remove(TreeNode<T>*& t,const T& x)
{
	if(t==NULL){return;}
	if(x<t->m_data){rec_remove(t->m_left,x);}
	else if(x>t->m_data){rec_remove(t->m_right,x);}
	else
	{
		if(t->m_right==NULL&&t->m_left==NULL){delete t;t=NULL;}
		else if(t->m_right==NULL){TreeNode<T>* tmp=t;t=t->m_left;delete tmp;}
		else if(t->m_left==NULL){TreeNode<T>* tmp=t;t=t->m_right;delete tmp;}
		else{t->m_data=findMax(t->m_left);rec_remove(t->m_left,t->m_data);}
	}
}

//rec_removetree()
template <typename T>
void MyBSTree<T>::rec_removetree(TreeNode<T>*& t)
{
	if(t==NULL){return;}
	else
	{
		while(t!=NULL)
		{
			if(t->m_left!=NULL&&t->m_right!=NULL){rec_removetree(t->m_left);}
			else if(t->m_right!=NULL&&t->m_left==NULL){rec_removetree(t->m_right);}
			else if(t->m_left!=NULL&&t->m_right==NULL){rec_removetree(t->m_left);}
			else
			{
				//int tmp=t->m_data;
				delete t;t=NULL;
				//cout<<"Deleted treenode <"<<tmp<<">!"<<endl;
				return;
			}
		}
	}
}

//PreOrderArray()
template <typename T>
void MyBSTree<T>::PreOrderArray()
{
	if(pre==NULL){}
	else{delete []pre;}
	pre=new T [m_size];
	int count=0;
	rec_PreOrderArray(m_root,count);
}

//rec_PreOrderArray
template <typename T>
void MyBSTree<T>::rec_PreOrderArray(TreeNode<T>*& t,int& count)
{
	TreeNode<T>* dir=t;
	if(t==NULL){return;}
	else
	{
		while(count!=m_size)
		{
			pre[count]=t->m_data;
			count++;
			for(int i=0;i<2;i++)
			{
				switch(i)
				{
				case 0:dir=t->m_left;break;
				case 1:dir=t->m_right;break;
				}
				rec_PreOrderArray(dir,count);
				if(i==1){return;}
			}
		}

	}

}

//PostOrderArray()
template <typename T>
void MyBSTree<T>::PostOrderArray()
{
	if(post==NULL){}
	else{delete []post;}
	post=new T [m_size];
	int count=0;
	rec_PostOrderArray(m_root,count);
}

//rec_PostOrderArray
template <typename T>
void MyBSTree<T>::rec_PostOrderArray(TreeNode<T>*& t,int& count)
{
	TreeNode<T>* dir=t;
	if(t==NULL){return;}
	else
	{
		while(count!=m_size)
		{
			
			for(int i=0;i<2;i++)
			{
				switch(i)
				{
				case 0:dir=t->m_left;break;
				case 1:dir=t->m_right;break;
				}
				rec_PostOrderArray(dir,count);
				if(i==1){post[count]=t->m_data;count++;return;}
			}
		}

	}

}

#endif 