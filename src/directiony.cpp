/*
 * File: direction.cpp
 * -----------------------
 * This file implements the direction.h interface.
 */

#include <string>
#include "directiony.h"

using namespace std;


/*
 * Implementation notes: leftFrom, rightFrom 
 * -------------------------------------------
 * These functions use the remainder operator to cycle through the internal
 * values of the enumeration type. Note that the leftFrom function cannot 
 * subtract 1 from the direction because the result might then be negative; 
 * Adding 3 achieves the same effect but ensures that the values remain positive.
 */

Directiony leftFrom(Directiony dir) {
    return Directiony((dir + 3) % 4);
}

Directiony rightFrom(Directiony dir) {
    return Directiony((dir + 1) % 4);
}


/* 
 * Implementation notes: directionToString
 * -------------------------------------------
 * Most C++ comnpilers require the default clause to make sure that this 
 * function always returns a string even if the direction is not one of the 
 * legal values.
 */

string directionToString(Directiony dir) {
	switch (dir) {
		case NORTH: return "NORTH";
		case EAST: return "EAST";
		case SOUTH: return "SOUTH";
		case WEST: return "WEST";
		default: return "??????";
	}
}


/*
 * <<
 * --
 * Insertion operator for the direction enumeration tue
 */
ostream & operator<<(ostream & os, Directiony dir){
    return os << directionToString(dir);
}

/*
 * ++
 * ----
 * Increment operator for the direction enum
 */
Directiony operator++(Directiony & dir, int) {
    Directiony old = dir;
     dir = Directiony(dir + 1);
     return old;
}
