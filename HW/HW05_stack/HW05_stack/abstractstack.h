/* 
 * Author: Dr. Ricardo Morales
 * Version: 13.3.0
 * 
 * -- AbstractStack
 * An abstract class that defines the basic operations of a 
 * Stack Abstract Data Type 
 *
 * For Homework #5, your Stack implementation should derive
 * this class.
 *
 */
#ifndef ABSTRACTSTACK_H 
#define ABSTRACTSTACK_H

#include <string>

template < typename T >
class AbstractStack
{
public:

  // Purpose: clears the stack
  // Postconditions: the stack is now empty 
  virtual void clear() = 0;
  
  // Purpose: push an element into the stack
  // Parameters: x is the value to push into the stack
  // Postconditions: x is now the element at the top of the stack, 
  virtual void push(const T& x) = 0;
  
  // Purpose: pop the stack
  // Postconditions: the element formerly at the top of the stack has
  // been removed
  // Note: Poping an empty stack results in an empty stack.
  virtual void pop() = 0;
  

  // Purpose: looks at the top of the stack
  // Returns: a const reference to the element currently on top of the stack
  // Exception: if the stack is empty, throw a string with an error message!!!
  virtual const T& top() const throw ( std::string ) = 0;
  
  // Purpose: Checks if a stack is empty
  // Returns: 'true' if the stack is empty
  //     'false' otherwise  
  virtual bool isEmpty() const = 0;
};

#endif