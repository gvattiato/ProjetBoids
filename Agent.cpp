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
	radius = 0;
	contact = 0;
	Vector position;
	position.setX(0);
	position.setY(0);
	Vector speed;
	speed.setX(0);
	speed.setY(0);

}

// Copy constructor
Agent::Agent(float aradius, float acontact, Vector new_position, Vector new_speed)
{
	radius = aradius;
	contact = acontact;
	position = new_position;
	speed = new_speed;

}

// Constructor taking only the index, the radius and the contact distance as parameters
Agent::Agent(float aradius, float acontact)
{
	radius = aradius;
	contact = acontact;
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




Vector Agent::getSpeed(void) const
{
	return speed;
}

float Agent::getRadius(void) const
{
	return radius;
}

float Agent::getContact(void) const
{
	return contact;
}

Vector Agent::getPosition(void) const
{
	return position;
}

 void Agent::setPosition(Vector new_position)
{
	position = new_position;
}

void Agent::setSpeed(Vector new_speed)
{
	speed = new_speed;
}

void Agent::setRadius(float new_radius)
{
	radius = new_radius;
}

void Agent::setContact(float new_contact)
{
	radius = new_contact;
}

void Agent::updatePosition(float dt)
{
	position.setX(position.getX() + dt*speed.getX());
	position.setY(position.getY() + dt*speed.getY());
}


// Checks if the agent whose position is given as parameter is inside the radius of this agent
bool Agent::isSomeoneNear(Vector other_position)
{
  bool check_radius = false;
  Vector delta = position - other_position;
  float norm = delta.getNorm();

  if (norm<radius)
    check_radius = true;
  
    return check_radius; 
}

bool Agent::isSomeoneTouching(Vector other_position)
{
  bool check_contact = false;
  Vector delta = position - other_position;
  float norm = delta.getNorm();

  if (norm<contact)
    check_contact = true;
    
    return check_contact; 
}


