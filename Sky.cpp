//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================

#include <math.h>
#include <cstring>


// ===========================================================================
//                                 Project Files
// ===========================================================================

#include "Sky.h"


//############################################################################
//                                                                           #
//                        	  		Class Sky                            	 #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Sky::Sky(void)
{
  flock_size = 0;
  flock = NULL;
}

Sky::Sky(Prey* prey_population, int new_size)
{
  flock_size = new_size; 
  flock = new Prey[flock_size];
  Prey p;
  memcpy(flock, prey_population, flock_size*(sizeof p));
}



// ===========================================================================
//                                  Destructor
// ===========================================================================
Sky::~Sky(void)
{
	delete [] flock;
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


//============================================================================
//  							Methods definition
//============================================================================


int Sky::getFlockSize(void) const
{
	return flock_size;
}

void Sky::setFlockSize(int new_size)
{
	flock_size = new_size;
}


//-----------------------------------------------------------------------------
//							Movement rules
//-----------------------------------------------------------------------------

// Calculates the alignement speed v1 for the Prey at index "index"
Vector Sky::alignment(int index, float K)
{
	Vector v1, vi;
	int i;
	
	for (i=0; i<flock_size; i++) // For every bird of the flock
	{
		Prey myself = flock[index];
		Vector other_position = flock[i].getPosition();
		if(myself.isSomeoneNear(other_position) == true)  // Finding birds in radius of perception
		{
			vi = (flock[i].getSpeed() - myself.getSpeed())/K; // Calculating alignment speed vector given by ONE nearby bird
		}

		v1.setX(v1.getX() + vi.getX()); // Updating the total speed
		v1.setY(v1.getY() + vi.getY());
	}
	printf("v1=%lg\n", v1.getX());

	return v1;
}


// Calculates v2 for the Prey at index "index"
Vector Sky::centerMass(int index, float K)
{
	Vector v2, vi;
	int i;
	
	for (i=0; i<flock_size; i++) // For every bird of the flock
	{
		Prey myself = flock[index];
		Vector other_position = flock[i].getPosition();
		if(myself.isSomeoneNear(other_position) == true)  // Finding birds in radius of perception
		{
			vi = (flock[i].getSpeed() - myself.getSpeed())/K; // Calculating alignment speed vector given by ONE nearby bird
		}

		v2.setX(v2.getX() + vi.getX()); // Updating the total speed
		v2.setY(v2.getY() + vi.getY());
	}
	printf("v2=%lg\n", v2.getX());

	return v2;
}

// Calculates v3 for the Prey at index "index". OBSTACLES TO BE ADDED.
Vector Sky::tooNear(int index, float K)
{
	Vector v3, vi;
	int i;
	
	for (i=0; i<flock_size; i++) // For every bird of the flock
	{
		Prey myself = flock[index];
		Vector other_position = flock[i].getPosition();
		if(myself.isSomeoneTouching(other_position) == true)  // Finding birds in radius of perception
		{
			vi = (flock[i].getSpeed() - myself.getSpeed())/(-K)	; // Calculating alignment speed vector given by ONE nearby bird
		}

		v3.setX(v3.getX() + vi.getX()); // Updating the total speed
		v3.setY(v3.getY() + vi.getY());
	}
	printf("v3=%lg\n", v3.getX());

	return v3;
}








