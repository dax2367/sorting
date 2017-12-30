/* Program:		Sort
// Author:		Holly Eaton
// Description:	Program that performs insertion, selection and bubble sorts in order, reverse order and random order.			
//======================================================================================================================*/

#ifndef SORT_
#define SORT_

#include <fstream>
#include <string>
#include "Process.h"

using namespace std;

const int SORT_ARRAY_MAX_SIZE = 1000000;//Max size of the sorting array

#define IN_ORDER 0
#define REVERSE 1
#define RANDOM 2

class Sort
{
public:
	Sort(string outputFilename = "output.csv");
	~Sort();
	void runSort();

private:
	unsigned int insertion(int size = SORT_ARRAY_MAX_SIZE, int order = IN_ORDER);
	unsigned int selection(int size = SORT_ARRAY_MAX_SIZE, int order = IN_ORDER);
	unsigned int bubble(int size = SORT_ARRAY_MAX_SIZE, int order = IN_ORDER);

	void InOrderArray(int size = SORT_ARRAY_MAX_SIZE);
	void ReverseOrderArray(int size = SORT_ARRAY_MAX_SIZE);
	void RandomOrderArray(int size = SORT_ARRAY_MAX_SIZE);

	static int sortArray[SORT_ARRAY_MAX_SIZE];
	ofstream outputFile;
};

#endif