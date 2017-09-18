/* @file: robot.h
 * Definition of Abstract class Robot
 * @C - MomCorp
 * 
 * Version 13.3.0
 */

#ifndef ROBOT_H
#define ROBOT_H

#include <string>

using namespace std; 



//----------------------------------------
// Auxiliary enumeration type for representing robot types
//
enum robottype {
  BENDER,
  WELDER,
  LEGGED,
  WHEELED,
  HOVER
};


//----------------------------------------
/* _________________
  /                 \
  |   Robot Class   |
  \_________________/
   
    ABSTRACT CLASS

    PURPOSE: Base class for all Robot classes.
 
*/
class Robot {
protected:
  string m_name;      // the name of the Robot


public:  

// Purpose: Default Constructor
// Postconditions: name is set to parameters
// -- INLINE
  Robot(string n) : m_name(n)
  {}
   
// Purpose: Accessor for member variable m_name.
// Returns: The name of the robot.
// -- INLINE, VIRTUAL
  virtual string getName() { return m_name; }

// Purpose: Returns the speed of a robot.
// -- PURE VIRTUAL
  virtual float speed() = 0;

// Purpose: Returns the strength of a robot.
// -- PURE VIRTUAL
  virtual float strength() = 0;

// Purpose: Returns the toughness of a robot.
// -- PURE VIRTUAL
  virtual float toughness() = 0;

// Purpose: Returns the intelligence of a robot.
// -- PURE VIRTUAL
  virtual float intelligence() = 0;

// ----------------

// Purpose: Destructor
// -- VIRTUAL
	virtual ~Robot() {};
  
}; //Spaceship


#endif