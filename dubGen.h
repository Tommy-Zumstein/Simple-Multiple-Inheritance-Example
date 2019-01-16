//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: dubGen.h
//DATE: 2/22/17
/*REVISION HISTORY:
2/22/17:
-translated into C++
*/
//PLATFORM:
//REFERENCES:

/*
DESCRIPTION:
An dubGen is a child class of gen, except that it doubles every seqDoubler value from its sequence.
Refer to gen class description documentation for more info on sequence
Legal States:
Active/inactive
*/

/*
Assumptions:
Class invarients:
Sequence values do not change after construction
Valid data types are sent into the constructor
Sequence should not contain BAD_REQ_RETURN_VAL

Interface Invarients:
Copying not supported
gen holds active/inactive data member
The client will send in a uint for seqLength
Overrides getNext and reset from gen

*/

#ifndef DUBGEN_H_
#define DUBGEN_H_

#include "gen.h"
#include <iostream> //TODO REMOVE

using namespace std;

class dubGen : public gen
{
protected:
	unsigned int seqDoubler;
	static const int DOUBLE_VAL = 2;
	static const int DUB_INDX_INIT_VAL = 1;

public:
	//Constructor
	dubGen();
	dubGen(int, int, unsigned int, unsigned int);
	//Deconstructor
	~dubGen();
	//Overriden functionality
	//Description: overridden inherited getNext function that doubles every seqDoubler value in the sequence
	int getNext();
	//Description: overridden inherited reset function
	virtual void reset();
};
#endif