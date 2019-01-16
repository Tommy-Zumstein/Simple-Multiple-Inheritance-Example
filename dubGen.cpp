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
An dubGen is a child class of gen, that doubles every seqDoubler value from its sequence.
Refer to gen.h for more information.
*/

/*
Assumptions:
Implementation invarients:
All data members are used to calculate getNext
index cannot be 0 or it will cause a floating point exception
Default values:
active =false
seqBase = 0
seqConst = 0
seqLen = 0
seqIndx = 1 (due to calculation in getNext involving index % doubler)
Reset Values:
all values unchanged except seqIndx = 1

*/

#include "dubGen.h"
using namespace std;

//Blank Constructor
dubGen::dubGen()
{
	//Non-inherited Items
	seqDoubler = 0;

	//Inherited Items
	active = false;
	seqBase = 0;
	seqConst = 0;
	seqLen = 0;
	seqIndx = DUB_INDX_INIT_VAL;
}

//Constructor
dubGen::dubGen(int seqBaseSet, int seqConstSet, unsigned int seqLenSet, unsigned int seqDoublerSet)
{
	//Non-inherited Items
	seqDoubler = seqDoublerSet;

	//gen Inherited Items
	active = true;
	seqBase = seqBaseSet;
	seqConst = seqConstSet;
	seqLen = seqLenSet;
	seqIndx = DUB_INDX_INIT_VAL;
}

//Deconstructor
dubGen::~dubGen() 
{
	//No heap memory used
}

//Description: overridden inherited getNext function that doubles every seqDoubler value in the sequence
int dubGen::getNext()
{
	//cout << "dub getnext called";
	int seqOutput = gen::getNext();
	if ((seqIndx - 1) % seqDoubler == 0 && seqOutput != BAD_REQ_RETURN_VAL)
	{
		return (seqOutput * DOUBLE_VAL);
	}
	else
	{
		return seqOutput;
	}
}

//Description: overridden inherited reset function
void dubGen::reset()
{
	gen::reset();
	seqIndx = DUB_INDX_INIT_VAL;
}