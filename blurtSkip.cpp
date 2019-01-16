//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: blurtSkip.cpp
//DATE: 2/22/17
/*REVISION HISTORY:
*/
//PLATFORM:
//REFERENCES:

/*Description:
blurtGens is a combination of a blurtRep object and a skipGen object using multiple inheritance.
it generates the output of both blurtReps and skipGen through combinedOuput.
if both either the skipGen or blurtReps functionality become inactive this object becomes inactive.
resetting this object calls the reset functionality of both skipGen and blurtReps
refer to skipGen and blurtGens documentation for more info.
*/

/*Assumptions:
Implementation invarients:
combinedOuput echoes the functionality of both gen::getNext and blurtReps::ping
reset echoes the functionality of both gen::reset and blurtReps::reset
*/

#include "blurtSkip.h"

using namespace std;

//Constructor
blurtSkip::blurtSkip(string inBlurtString, int inState, int inRepCount, int seqBaseSet, int seqConstSet, unsigned int seqLenSet, unsigned int skipValSet)
{
	active = true;
	//blurtReps inherited data members
	blurtReps::active = true;
	blurtString = inBlurtString;
	state = inState;
	repCount = inRepCount;
	pingCount = 0;
	//skipGen inherited data members
	skipGen::active = true;
	skipGen::seqBase = seqBaseSet;
	skipGen::seqConst = seqConstSet;
	skipGen::seqLen = seqLenSet;
	skipGen::seqIndx = SKIP_INDX_INIT_VAL;
	skipGen::skipVal = skipValSet;
	resetCount = 0;
}

//Deconstructor
blurtSkip::~blurtSkip()
{
	//No heap memory
}

//Description: Returns both outputs from skipGen and blurtReps as a single string if the object is inactive nthing is output
//Post-condition: blurtGens object may be inactive
string blurtSkip::combinedOutput()
{
	string output = "";
	if (blurtSkip::active)
	{
		stringstream ss;
		int genOutp = skipGen::getNext();
		ss << genOutp;
		output += ping() + " " + ss.str();
		if (!skipGen::active || !blurtReps::isActive())
		{
			blurtSkip::active = false;
		}
	}
	return output;
}

//Description: calls reset functions for both blurtReps and skipGen
void blurtSkip::reset() 
{
	blurtReps::reset();
	skipGen::reset();
	blurtSkip::active = true;
}