//MyBSTree.h
//Jieyi Hu
//DUE 11/14/2013 Thrusday


#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"
using namespace std;

/* ________________________________
* /                                \
* |     Binary Search Tree Node    |
* \________________________________/
*/
template <typename T>
class TreeNode
{
public:
	T m_data;
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode();
	TreeNode(T);
};
/* ________________________________
* /                                \
* |             Constructor        |
* \________________________________/
*/
template <typename T>
TreeNode<T>::TreeNode()
{
	m_left=NULL;
	m_right=NULL;
}
template <typename T>
TreeNode<T>::TreeNode(T x)
{
	m_data=x;
	m_left=NULL;
	m_right=NULL;
}




/* ________________________________
* /                                \
* | Encapsulated Binary Search Tree|
* \________________________________/
*/
template <typename T>
class MyBSTree
{
	TreeNode<T>* m_root;
public:
	int m_size;
	int m_height;
	int size() const;
	bool isEmpty() const;
	int height() const;
	const T& findMax() const;
	const T& findMin() const;
	int contains(const T&)  const;
	void clear();
	void insert(T);
	void remove(const T&);
	void printPreOrder() const;
	void printPostOrder() const;
	void print();
	MyBSTree();
	~MyBSTree();
	MyBSTree(MyBSTree<T>&);
	const MyBSTree<T>& operator=(const MyBSTree<T>&);
};

/* ________________________________
* /                                \
* |             Constructor        |
* \________________________________/
*/
template <typename T>
MyBSTree<T>::MyBSTree()
{
	m_root=NULL;
	m_height=0;
	m_size=0;
}



/* ________________________________
* /                                \
* |        rec_deletenode Fn       |
* \________________________________/
*/
template <typename T>
void rec_deletenode(TreeNode<T>*& t)
{
	if(t==NULL){return;}
	else
	{
		while(t!=NULL)
		{
			if(t->m_left!=NULL&&t->m_right!=NULL){rec_deletenode(t->m_left);}
			else if(t->m_right!=NULL&&t->m_left==NULL){rec_deletenode(t->m_right);}
			else if(t->m_left!=NULL&&t->m_right==NULL){rec_deletenode(t->m_left);}
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

/* ________________________________
* /                                \
* |             distructor         |
* \________________________________/
*/
template <typename T>
MyBSTree<T>::~MyBSTree()
{
	rec_deletenode(m_root);	
}



/* ________________________________
* /                                \
* |           rec_print Fn         |
* \________________________________/
*/
template <typename T>
void rec_print(const TreeNode<T>* t, int pad)
{
	string s(pad, ' ');
	if (t == NULL)
		cout << endl;
	else
	{
		rec_print(t->m_right, pad+4);
		cout << s << t->m_data << endl;
		rec_print(t->m_left, pad+4);
	}  
}
/* ________________________________
* /                                \
* |             print Fn           |
* \________________________________/
*/
template <typename T>
void MyBSTree<T>::print()
{
	rec_print(m_root,0);
}


/* ________________________________
* /                                \
* |           isEmpty Fn           |
* \________________________________/
*/
template <typename T>
bool MyBSTree<T>::isEmpty() const
{
	if(m_root==NULL){return true;}
	else{return false;}
}

/* ________________________________
* /                                \
* |         rec_rundownh Fn        |		rundown to calculate height
* \________________________________/
*/
template <typename T>
void rec_rundownh(TreeNode<T>*& t, int& count, int& height)
{
	if(t==NULL){return;}
	else
	{
		for(int i=0;i<2;i++)
		{
			switch(i)
			{
			case 0:
				count++;
				if(t->m_left!=NULL)			//left is not NULL
				{
					rec_rundownh(t->m_left, count, height);
					count--;
				}
				else{count--;}						//left is NULL
				break;
			case 1:
				count++;
				if(t->m_right!=NULL)
				{
					rec_rundownh(t->m_right, count, height);
					count--;
				}
				else
				{
					if(count>height){height=count;}
					count--;
					return;
				}
			}
		}

	}

}

/* ________________________________
* /                                \
* |        rec_insert Fn           |
* \________________________________/
*/
template <typename T>
void rec_insert(TreeNode<T>*& t,T x,int& size)
{
	if(t==NULL){t=new TreeNode<T>(x);size++;}
	else if(x<t->m_data){rec_insert(t->m_left,x,size);}
	else if(x>t->m_data){rec_insert(t->m_right,x,size);}
	else{return;}
}


/* ________________________________
* /                                \
* |           insert Fn            |
* \________________________________/
*/
template <typename T>
void MyBSTree<T>::insert(T x)
{
	rec_insert(m_root,x,m_size);
	int count=0;
	rec_rundownh(m_root,count,m_height);
}





/* ________________________________
* /                                \
* |           height Fn            |
* \________________________________/
*/
template <typename T>
int MyBSTree<T>::height()  const
{
	return m_height;

}


/* ________________________________
* /                                \
* |            size Fn             |
* \________________________________/
*/
template <typename T>
int MyBSTree<T>::size() const
{
	/*int count=0;
	int size=0;
	rec_rundowns(m_root, count, size);
	return size;*/
	return m_size;

}

/* ________________________________
* /                                \
* |           findMax Fn           |
* \________________________________/
*/
template <typename T>
const T& MyBSTree<T>::findMax()  const
{
	if(m_root==NULL){throw string("PANIC : Tree is Empty!!");}
	TreeNode<T>* runner;
	runner=m_root;
	while(runner->m_right!=NULL)
	{
		runner=runner->m_right;
	}
	return runner->m_data;
}
/* ________________________________
* /                                \
* |           findMin Fn           |
* \________________________________/
*/
template <typename T>
const T& MyBSTree<T>::findMin()  const
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



/* ________________________________
* /                                \
* |         rec_rundownp Fn        |		rundown to pick up the elements the tree has
* \________________________________/
*/
template <typename T>
void rec_rundownp(TreeNode<T>*& t, T*& tmparray, int& count, int& size)
{
	TreeNode<T>* dir=t;
	if(t==NULL){return;}
	else
	{
		while(count!=size)
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
				rec_rundownp(dir,tmparray,count,size);
				if(i==1){return;}
			}
		}

	}

}
/* ________________________________
* /                                \
* |           Operator=            |
* \________________________________/
*/
template <typename T>
const MyBSTree<T>& MyBSTree<T>::operator=(const MyBSTree<T>& rhs)
{
	rec_deletenode(m_root);
	this->m_size=0;
	this->m_height=0;
	//reset the tree
	int size=rhs.m_size;
	TreeNode<T>* tmproot=rhs.m_root;
	T* tmparray=new T [size];
	int count=0;
	rec_rundownp(tmproot,tmparray,count,size);
	for(int i=0;i<size;i++)
	{
		this->insert(tmparray[i]);
	}
	//delete tmparray;
	return *this;
}



/* ________________________________
* /                                \
* |           remove Fn            |
* \________________________________/
*/
template <typename T>
void MyBSTree<T>::remove(const T& x)
{
	
	int size=m_size;
	T* tmparray=new T [size];
	int count=0;
	rec_rundownp(m_root,tmparray,count,size);
	rec_deletenode(m_root);
	for(int i=0;i<size;i++)
	{
		if(tmparray[i]!=x)
		{this->insert(tmparray[i]);}
	}
}

/* ________________________________
* /                                \
* |          Copy Constructor      |
* \________________________________/
*/
template <typename T>
MyBSTree<T>::MyBSTree(MyBSTree<T>& cpy)
{
	m_size=cpy.m_size;
	m_height=cpy.m_size;
	m_root=NULL;
	*this=cpy;
}



/* ________________________________
* /                                \
* |       rec_printPreOrder Fn     |		
* \________________________________/
*/
template <typename T>
void rec_printPreOrder(TreeNode<T>*& t,int& count, int& size)
{
	TreeNode<T>* dir=t;
	if(t==NULL){return;}
	else
	{
		while(count!=size)
		{
			cout<<t->m_data<<endl;
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
				rec_printPreOrder(dir,count,size);
				if(i==1){return;}
			}
		}

	}

}
template <typename T>
void MyBSTree<T>::printPreOrder() const
{
	int count=0;
	int size=m_size;
	TreeNode<T>* tmproot=m_root;
	rec_printPreOrder(tmproot,count,size);
}



/* ________________________________
* /                                \
* |       rec_printPostOrder Fn     |		
* \________________________________/
*/
template <typename T>
void rec_printPostOrder(TreeNode<T>*& t,int& count, int& size)
{
	TreeNode<T>* dir=t;
	if(t==NULL){return;}
	else
	{
		while(count!=size)
		{
			
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
				rec_printPostOrder(dir,count,size);
				if(i==1){cout<<t->m_data<<endl;count++;return;}
			}
		}

	}

}
template <typename T>
void MyBSTree<T>::printPostOrder() const
{
	int count=0;
	int size=m_size;
	TreeNode<T>* tmproot=m_root;
	rec_printPostOrder(tmproot,count,size);
}
#endif 