/*
 * maxHeap testing file..
 *
 * Implement each test one at a time.
 *
 */

#include <iostream>
#include <cstdlib>
#include "maxheap.h"

using namespace std;

//------------------------------------------------------
void test1()
{
  maxHeap<int> h;

  cout << endl << endl << "******** " << "Test #1" << endl;

  h.print();
  cout << "Heap empty? " << boolalpha << h.isEmpty() << endl;

  cout << "--" << endl;

  h.insert(7);
  h.insert(6);
  h.insert(10);
  h.insert(5);
  h.insert(9);
  h.insert(13);
  h.insert(4);
  h.insert(15);
  h.insert(2);
  h.print();

  cout << "Heap empty? " << boolalpha << h.isEmpty() << endl;
  cout << "-" << endl;
  cout << "size = " << h.size() << endl;
  cout << "-" << endl;

  return;
}


//------------------------------------------------------
void test2()
{
  maxHeap<string> h;

  cout << endl << endl << "******** " << "Test #2" << endl;

  h.insert(string("Alpha"));
  h.insert(string("Beta"));
  h.insert(string("Gamma"));
  h.insert(string("Sigma"));
  h.insert(string("Pi"));
  h.print();

  cout << "-" << endl;
  cout << "Testing Clear() " << endl;
  h.clear();
  h.print();
  cout << "Heap empty? " << boolalpha << h.isEmpty() << endl;

  h.insert(string("One"));
  h.insert(string("Two"));
  h.insert(string("Three"));
  h.insert(string("Four"));
  h.insert(string("Five"));
  h.print();

  return;
}


//------------------------------------------------------
void test3()
{
  maxHeap<int> h;
  int x;

  cout << endl << endl << "******** " << "Test #3" << endl;

	srand( 42 );
  for(int k=0; k<20; k++){
  	x = rand() % 100;
  	h.insert(x);
  }

  h.print();

  cout << "-" << endl;
	while ( !h.isEmpty() ){
		x = h.top();
		cout << x << ", ";
		h.remove();
	}
	cout << endl;

  h.print();
  cout << "Heap empty? " << boolalpha << h.isEmpty() << endl;

  return;
}

//------------------------------------------------------
void test4()
{
  maxHeap<string> h;
  maxHeap<string> h2;

  cout << endl << endl << "******** " << "Test #4" << endl;

  h.insert(string("Paul"));
  h.insert(string("John"));
  h.insert(string("George"));
  h.insert(string("Ringo"));
  h.insert(string("Fry"));
  h.insert(string("Leela"));
  h.insert(string("Zoidberg"));
  h.print();

  cout << "-" << endl;
  cout << "Testing Operator = " << endl;
  h2 = h;
  h2.print();

  cout << "--" << endl;
  cout << "Is it a deep copy? " << endl;
  h2.remove();
  h2.remove();
  h2.remove();
  cout << "-- copy:" << endl;
  h2.print();
  cout << "-- original:" << endl;
  h.print();

  cout << "-" << endl;
  cout << "Testing Alias Test = " << endl;
  h2 = h2;
  h2.print();

  return;
}


//------------------------------------------------------
void test5()
{
  maxHeap<int> h;
  int x;

  cout << endl << endl << "******** " << "Test #5" << endl;

	srand( 1234 );
  for(int k=0; k<10; k++){
  	x = rand() % 1000;
  	h.insert(x);
  }
  h.print();

  cout << "-" << endl;
  cout << "Testing Copy COnstructor " << endl;
  maxHeap<int> h2(h);
  h2.print();

  cout << "-" << endl;
  cout << "Is it a deep copy? " << endl;
  h2.remove();
  h2.remove();
  h2.remove();
  cout << "-- copy:" << endl;
  h2.print();
  cout << "-- original:" << endl;
  h.print();

  return;
}


//------------------------------------------------------
void test6()
{
  maxHeap<char> h;
  char x;

  cout << endl << endl << "******** " << "Test #6" << endl;
  cout << "Testing Exceptions " << endl;
	cout << "Heap empty? " << boolalpha << h.isEmpty() << endl;
  cout << "--" << endl;

  try {
    h.remove();
  }
  catch (...)
  {
    cout << "Why Fail? "
		     << "Removing from an empty Heap is an empty Heap." << endl;
  }
  try {
    x = h.top();
  }
  catch (...)
  {
    cout << "ERROR: Empty Heap does not has a top element" << endl;
  }

  return;
}


//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
int main ()
{
  cout << "Hello Max Heap Tester!! " << endl;

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();

  return 0;
}

