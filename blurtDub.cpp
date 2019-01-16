//AUTHOR: Carl "Tommy" Zumstein
//FILENAME: blurtDub.cpp
//DATE: 2/22/17
/*REVISION HISTORY:
*/
//PLATFORM:
//REFERENCES:

/*Description:
blurtGens is a combination of a blurtRep object and a dubGen object using multiple inheritance.
it generates the output of both blurtReps and dubGen through combinedOuput.
if both either the dubGen or blurtReps functionality become inactive this object becomes inactive.
resetting this object calls the reset functionality of both dubGen and blurtReps
refer to dubGen and blurtGens documentation for more info.
*/

/*Assumptions:
Implementation invarients:
combinedOuput echoes the functionality of both gen::getNext and blurtReps::ping
reset echoes the functionality of both gen::reset and blurtReps::reset
*/

#include "blurtDub.h"

using namespace std;

//Constructor
blurtDub::blurtDub(string inBlurtString, int inState, int inRepCount, int seqBaseSet, int seqConstSet, unsigned int seqLenSet, unsigned int seqDoublerSet)
{
	active = true;
	//blurtReps inherited data members
	blurtReps::active = true;
	blurtString = inBlurtString;
	state = inState;
	repCount = inRepCount;
	pingCount = 0;
	//dubGen inherited data members
	dubGen::active = true;
	dubGen::seqBase = seqBaseSet;
	dubGen::seqConst = seqConstSet;
	dubGen::seqLen = seqLenSet;
	dubGen::seqDoubler = seqDoublerSet;
	dubGen::seqIndx = DUB_INDX_INIT_VAL;
}

//Deconstructor
blurtDub::~blurtDub()
{
	//No heap memory used
}

string blurtDub::combinedOutput()
{
	string output = "";
	if (blurtDub::active)
	{
		stringstream ss;
		int genOutp = dubGen::getNext();
		ss << genOutp;
		output += ping() + " " + ss.str();
		if (!dubGen::active || !blurtReps::isActive())
		{
			blurtDub::active = false;
		}
	}
	return output;
}

//Description: calls reset functions for both blurtReps and dubGen
void blurtDub::reset() 
{
	blurtReps::reset();
	dubGen::reset();
	blurtDub::active = true;
}