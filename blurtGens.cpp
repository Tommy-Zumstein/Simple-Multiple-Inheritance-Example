//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: blurtGens.cpp
//DATE: 2/22/17
/*REVISION HISTORY:
*/
//PLATFORM:
//REFERENCES:

/*Description:
blurtGens is a combination of a blurtRep object and a gen object using multiple inheritance.
it generates the output of both blurtReps and gen through combinedOuput.
if both either the gen or blurtReps functionality become inactive this object becomes inactive.
resetting this object calls the reset functionality of both gen and blurtReps.
refer to gen and blurtReps documentation for more info.
*/

/*Assumptions:
Implementation invarients:
combinedOuput echoes the functionality of both gen::getNext and blurtReps::ping
reset echoes the functionality of both gen::reset and blurtReps::reset
*/

#include "blurtGens.h"
using namespace std;

//Blank Constructor
blurtGens::blurtGens()
{
	active = false;
	//blurtReps inherited data members
	blurtString = "";
	state = PLAINSTATE;
	repCount = 0;
	pingCount = 0;
	blurtReps::active = false;
	srand(time(0));
	//gen inherited data members
	gen::active = false;
	seqBase = 0;
	seqConst = 0;
	seqLen = 0;
	seqIndx = GEN_INDX_INIT_VAL;
}

//Constructor
/*Preconditions:
inBlurtString must be of < 5 characters
inState must be 1, 2, or 3
inRepCount must be >= 0 
Sequence should not contain BAD_REQ_RETURN_VAL
*/
blurtGens::blurtGens(string inBlurtString, int inState, int inRepCount, int seqBaseSet, int seqConstSet, unsigned int seqLenSet)
{
	active = true;
	//blurtReps inherited data members
	blurtReps::active = true;
	blurtString = inBlurtString;
	state = inState;
	repCount = inRepCount;
	pingCount = 0;
	//gen inherited data members
	gen::active = true;
	seqBase = seqBaseSet;
	seqConst = seqConstSet;
	seqLen = seqLenSet;
	seqIndx = GEN_INDX_INIT_VAL;
}

//Deconstructor
blurtGens::~blurtGens() 
{
	//No Heap Memory Used
}

//Description: Returns both outputs from gen and blurtReps as a single string
//Post-condition: blurtGens object may be inactive
string blurtGens::combinedOutput() 
{
	string output = "";
	if (blurtGens::active) 
	{
		stringstream ss;
		int genOutp = getNext();
		ss << genOutp;
		output += ping() + " " + ss.str();
		if (!gen::active || !blurtReps::isActive())
		{
			blurtGens::active = false;
		}
	}
	return output;
}

bool blurtGens::isActive()
{
	return blurtGens::active;
}

//Description: calls reset functions for both blurtReps and gen
void blurtGens::reset() 
{
	gen::reset();
	blurtReps::reset();
	blurtGens::active = true;
}