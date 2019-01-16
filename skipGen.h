//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: skipGen.h
//DATE: 2/22/17
/*REVISION HISTORY:
2/22/17:
-translated into C++
*/
//PLATFORM:
//REFERENCES:

/*
DESCRIPTION:
A skipGen is a child of the gen class, except that it skips 0, 1 or k values from its sequence.
Also, it cannot cycle through on/off states more than k times.
From gen: k = seqLen
Legal States:
Active/inactive
*/

/*
Assumptions:
Class Invarients:
Sequence values do not change after construction
Valid data types are sent into the constructor
Sequence should not contain BAD_REQ_RETURN_VAL

Interface Invarients:
Copying not supported
The client will send in a uint for seqLength
gen holds active/inactive data memeber
inherits getNext from gen for output generation
overrides reset from gen
When inactive getNext will return BAD_REQ_RETURN_VAL
Reset returns the object to its initial index after construction
*/

#ifndef SKIPGEN_H_
#define SKIPGEN_H_

#include "gen.h"

using namespace std;

class skipGen : public gen 
{
protected: 
	static const int SKIP_INDX_INIT_VAL = 1;
	unsigned int skipVal;
	int resetCount;

public:
	//Constructor
	skipGen();
	skipGen(int, int, unsigned int, unsigned int);
	//Destructor
	~skipGen();
	
	//Description: resets index back to skipVal unless resetCount has been reached
	//Postcondition: skipGen maybe reset
	virtual void reset();

};
#endif