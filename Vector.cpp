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

#include "Vector.h"



//############################################################################
//                                                                           #
//                        	  		Class Vector                            	 #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================

// Default constructor
Vector::Vector(void)
{
	x = 0;
	y = 0;
	norm = sqrt(x*x + y*y);
}

// Copy constructor
Vector::Vector(float new_x, float new_y)
{
	x = new_x;
	y = new_y;
	norm = sqrt(x*x + y*y);
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Vector::~Vector(void)
{
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

void Vector::print(void)
{
	printf("(%lg,%lg)", x, y);
}

float Vector::getX(void)
{
  return x; 
}

float Vector::getY(void)
{
  return y;
}

const float Vector::getNorm(void)
{
	return norm;
}

void Vector::setX(float new_x)
{
	x=new_x;
}

void Vector::setY(float new_y)
{
	y=new_y;
}

void Vector::updateNorm(void)
{
	norm = sqrt(x*x + y*y);
}

Vector Vector::operator*(float f)
{
	x = x*f;
	y = y*f;
	updateNorm();
	return *this;
}

Vector Vector::operator/(float f)
{
	x = x/f;
	y = y/f;
	updateNorm();
	return *this;
}

Vector Vector::operator+(Vector otherVector)
{
	Vector result;
	result.setX(x + otherVector.getX());
	result.setY(y + otherVector.getY());
	result.updateNorm();
	return result;
}

Vector Vector::operator=(Vector otherVector)
{
	x = otherVector.getX();
	y = otherVector.getY();
	updateNorm();
	return *this;
}

Vector Vector::operator-(Vector otherVector)
{
	Vector result;
	result.setX(x - otherVector.getX());
	result.setY(y - otherVector.getY());
	result.updateNorm();
	return result;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================


//============================================================================
//  							Methods definition
//============================================================================

