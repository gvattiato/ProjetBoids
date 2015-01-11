//****************************************************************************
//
//
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>




// ===========================================================================
//                             Include Project Files
// ===========================================================================

#include "Sky.h"



// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================




// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  // Creation of a flock of 10 preys, all starting at (0,0) with a speed of (1,1), R=3, c=1
  int size = 4;
  Vector position;
  Vector speed;
  Prey* preys = new Prey[size];

  for (int i=0; i<size; i++)
  {
    position.setX(i);
    position.setY(i);
    speed.setX(i);
    speed.setY(i);
    Prey p(3, 1, position, speed);
    preys[i] = p;
    printf("position%d = (%lg,%lg)\n", i, preys[i].getPosition().getX(), preys[i].getPosition().getY());
  }

  Sky my_sky(preys, size);
  printf("size= %d\n", my_sky.getFlockSize());

  for (int i=0; i<size; i++)
  {
    printf("\n\n\nFor i=%d\n\nspeed0 = (%lg,%lg)\n", i, preys[i].getSpeed().getX(), preys[i].getSpeed().getY());
    Vector v1 = my_sky.alignment(i, 2);
    Vector v2 = my_sky.centerMass(i, 2);
    Vector v3 = my_sky.tooNear(i, 2);
    preys[i].updateSpeed(0.1, 0.2, 0.2, 0.2, v1, v2, v3);
    printf("speed%d = (%lg,%lg)\n", i+1, preys[i].getSpeed().getX(), preys[i].getSpeed().getY());
  }

  printf("\nHello World !\n");

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================




