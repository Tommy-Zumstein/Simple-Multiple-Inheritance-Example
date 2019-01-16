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
Refer to skipGen.h for more information.
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
seqIndx = 1
resetCount = 0
skipVal = 0

Reset Values:
all values unchanged except seqIndx = skipVal + 1 and resetCount is incremented
*/

#include "skipGen.h"
using namespace std;

//Blank Constructor
skipGen::skipGen() 
{
	//Non-Inherited Items
	skipVal = 0;
	resetCount = 0;

	//Inherited Items
	active = false;
	seqBase = 0;
	seqConst = 0;
	seqLen = 0;
	seqIndx = SKIP_INDX_INIT_VAL;
}

//Constructor
skipGen::skipGen(int seqBaseSet, int seqConstSet, unsigned int seqLenSet, unsigned int skipValSet)
{
	//Non-Inherited Items
	skipVal = skipValSet;
	resetCount = 0;

	//gen Inherited Items
	active = true;
	seqBase = seqBaseSet;
	seqConst = seqConstSet;
	seqLen = seqLenSet + skipVal;
	seqIndx = SKIP_INDX_INIT_VAL + skipVal;
}

//Deconstructor
skipGen::~skipGen()
{
	//No heap memory used
}

//Reset
//Description: resets index back to skipVal unless resetCount has been reached
//Postcondition: skipGen maybe reset
void skipGen::reset() 
{
	if (resetCount < seqLen - skipVal)
	{
		gen::reset();
		seqIndx += skipVal + SKIP_INDX_INIT_VAL;
		resetCount++;
	}
}