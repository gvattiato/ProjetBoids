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
	int i;
	Vector v1(0,0);	
	
	for (i=0; i<flock_size; i++) // For every bird of the flock
	{
		if(i!=index) 
		{
			Vector position1 = flock[index].getPosition();
			Vector position2 = flock[i].getPosition();
			float radius = flock[i].getRadius();

			//printf("ALIGNMENT: position1 for index=%d = (%lg,%lg), position2 for i=%d = (%lg,%lg)\n", index, position1.getPosition().getX(), position1.getPosition().getY(), i, position2.getX(), position2.getY());
			
			if(position1.isSomeoneNear(position2,radius) == true)  // Finding birds in radius of perception
			{
				v1 = v1+(flock[i].getSpeed() - flock[index].getSpeed()); // Calculating alignment speed vector given by ONE nearby bird
				v1 = v1/K;
			}

		}
	}
	//printf("v1=(%lg,%lg)\n", v1.getX(), v1.getY());

	return v1;
}


// Calculates v2 for the Prey at index "index"
Vector Sky::centerMass(int index, float K)
{
	Vector v2(0,0);
	int i;
	
	for (i=0; i<flock_size; i++) // For every bird of the flock
	{
		if(i!=index) // If it's not the bird at index index
		{
			Vector position1 = flock[index].getPosition();
			Vector position2 = flock[i].getPosition();
			float radius = flock[i].getRadius();


			if(position1.isSomeoneNear(position2, radius) == true)  // Finding birds in radius of perception
			{
				v2 = v2 + (flock[i].getPosition() - flock[index].getPosition()); // Calculating v2 given by ONE nearby bird
				v2 = v2/K;
			}
		}
	}

	return v2;
}

// Calculates v3 for the Prey at index "index". OBSTACLES TO BE ADDED.
Vector Sky::tooNear(int index, float K, float O, Vector* obstacles, int n_obstacles)
{
	Vector v3(0,0);
	Vector sum1(0,0);
	Vector sum2(0,0);
	int i;
	Vector position1 = flock[index].getPosition();
	float contact = flock[index].getContact();
	
	for (i=0; i<flock_size; i++) // For every bird of the flock
	{
		if(i!=index) 
		{
			Vector position2 = flock[i].getPosition();			

			if (position1.isSomeoneTouching(position2,contact) == true)  // Finding birds in radius of perception
				sum1 = sum1 + (position2 - position1);
		}
	}
	for (i=0; i<n_obstacles; i++) // For every obstacle
	{	
		Vector obstacle = obstacles[i];			

		if (position1.isSomeoneTouching(obstacle,contact) == true)
			sum2 = sum2 + (obstacle - position1);

				

			//printf("\nsum1 = (%lg,%lg),  sum2 = (%lg,%lg)\n", sum1.getX(), sum1.getY(), sum2.getX(), sum2.getY());
			
	}
	
	//printf("v3=(%lg,%lg)\n", v3.getX(), v3.getY());
	v3 = sum1/(-K) +sum2/(-O);

	return v3;
}

Vector Sky::wind(int index, int length, int height)
{
	Vector wind(0,0);
	int limit = 40;
	int min_speed = 10;
	Vector speed = flock[index].getSpeed();
	Vector position = flock[index].getPosition();
	float x = position.getX();
	float y = position.getY();
	float dx = length - x;
	float dy = height - y;

	if (dx<limit && speed.getX()>0){  						// if bird is near the right border and it's going towards it...
		wind.setX(-min_speed-speed.getX()-1/dx); 			// ...then wind -ve to push it back 
		printf("Near the right border. Wind = (%lg,%lg)   ", wind.getX(), wind.getY());
	} else if (dx<limit && speed.getX()<0) 					// if bird is near right border and it's going away from it...
		wind.setX(-min_speed+speed.getX()-1/dx); 			// ...then wind -ve

	if (x<limit && speed.getX()<0) { 						// if bird is near left border and is going towards it...
		wind.setX(min_speed-speed.getX()+1/x); 				// ...then wind +ve to push it away
		printf("Near the left border. Wind = (%lg,%lg)   ", wind.getX(), wind.getY());
	}
	else if (x<limit && speed.getX()>0) 					// if bird near left border and going away from it...
		wind.setX(min_speed+speed.getX()+1/x); 				// ...then wind +ve

	if(dy<limit && speed.getY()>0) { 						// if bird near bottom border and going towards it...
		wind.setY(-min_speed-speed.getY()-1/dy); 			// ...then wind -ve to push it back up
		printf("Near the bottom border. Wind = (%lg,%lg)   ", wind.getX(), wind.getY());
	} else if (dy<limit && speed.getY()<0) 					// if bird near bottom border and going away from it...
		wind.setY(-min_speed+speed.getY()-1/dy); 			// ...then wind -ve

	if (y<limit && speed.getY()<0) { 						// if bird near top border and going towards it...
		wind.setY(min_speed-speed.getY()+1/y);				// ...then wind +ve to push it back down
		printf("Near the top border. Wind = (%lg,%lg)   ", wind.getX(), wind.getY());
	}
	else if (y<limit && speed.getY()>0) 					// if bird near top border and going away from it...
		wind.setY(min_speed+speed.getY()+1/y); 				// then wind +ve



    return wind;
}






