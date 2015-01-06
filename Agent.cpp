//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================

#include <math.h>

// ===========================================================================
//                                 Project Files
// ===========================================================================

#include "Agent.h"



//############################################################################
//                                                                           #
//                           Class Agent                            		 #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================

// Default constructor
Agent::Agent(void)
{
	index = 0;
	radius = 0;
	Vector position;
	position.setX(0);
	position.setY(0);
	Vector speed;
	speed.setX(0);
	speed.setY(0);
}

// Copy constructor
Agent::Agent(int aindex, float aradius, Vector new_position, Vector new_speed)
{
	index = aindex;
	radius = aradius;
	position = new_position;
	speed = new_speed;
}

// Constructor taking only the index and the radius as parameters
Agent::Agent(int aindex, float aradius)
{
	index = aindex;
	radius = aradius;
	position.setX(1);
	position.setY(1);
	speed.setX(1);
	speed.setY(1);
}



// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================




//==========================================================================
//  					Methods definition
//==========================================================================


int Agent::getIndex(void) const 
{
	return index;
}

Vector Agent::getSpeed(void) const
{
	return speed;
}

float Agent::getRadius(void) const
{
	return radius;
}

Vector Agent::getPosition(void) const
{
	return position;
}



void Agent::updatePosition(float dt)
{
//	x_position += dt*x_speed;
//	y_position += dt*y_speed;
}

/*
// Checks if the agent whose position is given as parameter is inside the radius of this agent
bool Agent::isSomeoneNear(float a_x, float a_y)
{
  bool checkRadius = false;
  float dx = x_position - a_x;
  float dy = y_position - a_y;
  float distance = sqrt(dx*dx + dy*dy);

  if (dx<0)
  	dx = -dx;
  if (dy<0)
  	dx = -dx;

  if (distance<radius)
    checkRadius = true;
  
    return checkRadius; 
}
*/
