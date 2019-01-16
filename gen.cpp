//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: gen.h
//DATE: 2/22/17
/*REVISION HISTORY:
2/22/17:
-translated into C++
*/
//PLATFORM:
//REFERENCES:

/*
DESCRIPTION:
The gen class is a class designed to calculate the values of an arithmatic
sequence in order.
Refer to gen.h for more information.
*/

/*
Assumptions:
Implementation invarients:
All data members are used to calculate getNext
Default values:
active =false
seqBase = 0
seqConst = 0
seqLen = 0
seqIndx = 0
Reset Values:
all values unchanged except seqIndx = 0

*/
#include "gen.h"
using namespace std;

//Blank Constructor
gen::gen() 
{
	active = false;
	seqBase = 0;
	seqConst = 0;
	seqLen = 0;
	seqIndx = GEN_INDX_INIT_VAL;
}

//Constructor
gen::gen(int seqBaseSet, int seqConstSet, unsigned int seqLenSet)
{
	active = true;
	seqBase = seqBaseSet;
	seqConst = seqConstSet;
	seqLen = seqLenSet;
	seqIndx = GEN_INDX_INIT_VAL;
}

//Destructor
gen::~gen() 
{
	//No heap memory used
}

//Description: returns the next value in the sequence, if the object is inactive returns BAD_REQ_RETURN_VAL
//Postcondition: gen object maybe inactive
int gen::getNext()
{
	int seqOutput = BAD_REQ_RETURN_VAL;
	if (active)
	{
		seqOutput = (int)(seqBase - seqConst * (seqIndx - 1));
		seqIndx++;
		checkDeactivate();
	}
	return seqOutput;
}

//Description: resets the object to the initial index value
void gen::reset()
{
	active = true;
	seqIndx = GEN_INDX_INIT_VAL;
}

//Description: If the index has exceeded the sequence length this sets the gen to inactive
//Postcondition: gen object maybe deactivated
void gen::checkDeactivate()
{
	if (seqIndx > seqLen)
	{
		active = false;
	}
}