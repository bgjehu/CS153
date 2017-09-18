/* 
 * Author: Dr. Ricardo Morales
 *   ________________
 *  /                \
 *  |  AbstractHeap  |
 *  \________________/
 *
 * An abstact class that defines the basic operations of 
 * HEAP Abstract Data Type 
 *
 * PRECONDITIONS: - typename T MUST support the 'operator<'
 *                - typename T MUST have a default constructor
 *
 * For Homework #8, your Heap implementation should derive
 * this class.
 *
 * Version 13.3.1
 *
 */

#ifndef ABSTRACTHEAP_H 
#define ABSTRACTHEAP_H

template < typename T >
class AbstractHeap
{
public:

  /*** ---- Accessor Operations ---- ***/

  // Purpose: Checks if a Heap is empty
  // Returns: 'true' if the Heap is empty
  //     'false' otherwise  
  // -- PURE VIRTUAL
  virtual bool isEmpty() const = 0;
  
  // Purpose: Returns the size of the Heap.
  // Returns: the number of elements in the Heap
  // -- PURE VIRTUAL
  virtual int size() const = 0;

  // Purpose: looks at the top of the heap
  // Returns: a reference to the element currently at the root of the Heap
  // Exception: if the Heap is currently empty, throw SOMETHING!!
  // -- PURE VIRTUAL
  virtual const T& top() const = 0;  

  // Purpose: Prints the Heap In-Order with formatting
  //     each level indented 4 spaces, one element per line    
  virtual void print() const = 0;


  /*** ---- Mutator Operations ---- ***/
  
  // Purpose: clears the heap
  // Postconditions: the heap is now empty 
  // -- PURE VIRTUAL
  virtual void clear() = 0;
  
  // Purpose: insert an element into the heap
  // Parameters: x is the item to add to the heap
  // Postconditions: the heap now contains x, 
  // -- PURE VIRTUAL
  virtual void insert(const T& x) = 0;
  
  // Purpose: removes the root (top) of the heap 
  // Postconditions: the element formerly at the root of the heap 
  //     has been removed
  // removing from an empty Heap produces no errors, the Heap remains empty.
  // -- PURE VIRTUAL
  virtual void remove() = 0;
  
  
  // ----------------

  // Purpose: Destructor
  // -- VIRTUAL
	virtual ~AbstractHeap() {};
	
};

#endif 

