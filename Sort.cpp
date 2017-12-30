/* Program:		Sort
// Author:		Holly Eaton
// Description:	Program that performs insertion, selection and bubble sorts in order, reverse order and random order.			
//======================================================================================================================*/

#include <iostream>
#include <string>
#include <time.h>
#include "Sort.h"

using namespace std;

int Sort::sortArray[SORT_ARRAY_MAX_SIZE];

/*-------------------------------------------------------------------------------------------------
Function name:	Sort
Description:	Constructor, opens the output file
Arguments:		string outputFilename = "output.csv"
Return value:	None
-------------------------------------------------------------------------------------------------*/
Sort::Sort(string outputFilename)
{
	//Open the output file
	outputFile.open(outputFilename, ios::out|ios::trunc);
}

/*-------------------------------------------------------------------------------------------------
Function name:	~Sort
Description:	Destructor, closes the output file
Arguments:		None
Return value:	None
-------------------------------------------------------------------------------------------------*/
Sort::~Sort()
{
	//Close the output file
	outputFile.close();
}

/*-------------------------------------------------------------------------------------------------
Function name:	runSort
Description:	Runs the specified sorts
Arguments:		None
Return value:	None
-------------------------------------------------------------------------------------------------*/
void Sort::runSort()
{
	//Insertion sort
	outputFile << "Insertion,100,1000,10000,100000,1000000" << endl;//Headers
	cout << "Insertion sort started..." << endl;
	outputFile << "In Order,"
		<< insertion(100,IN_ORDER) << ","
		<< insertion(1000,IN_ORDER) << ","
		<< insertion(10000,IN_ORDER) << ","
		<< insertion(100000,IN_ORDER) << ","
		<< insertion(1000000,IN_ORDER) << endl;
	cout << "Insertion sort, In Order done!" << endl;
	outputFile << "Reverse Order,"
		<< insertion(100,REVERSE) << ","
		<< insertion(1000,REVERSE) << ","
		<< insertion(10000,REVERSE) << ","
		<< insertion(100000,REVERSE) << ","
		<< insertion(1000000,REVERSE) << endl;
	cout << "Insertion sort, Reverse Order done!" << endl;
	outputFile << "Random Order,"
		<< insertion(100,RANDOM) << ","
		<< insertion(1000,RANDOM) << ","
		<< insertion(10000,RANDOM) << ","
		<< insertion(100000,RANDOM) << ","
		<< insertion(1000000,RANDOM) << endl;
	cout << "Insertion sort, Random Order done!" << endl;
	outputFile << endl;
	cout << endl;

	//Selection sort
	outputFile << "Selection,100,1000,10000,100000,1000000" << endl;//Headers
	cout << "Selection sort started..." << endl;
	outputFile << "In Order,"
		<< selection(100,IN_ORDER) << ","
		<< selection(1000,IN_ORDER) << ","
		<< selection(10000,IN_ORDER) << ","
		<< selection(100000,IN_ORDER) << ","
		<< selection(1000000,IN_ORDER) << endl;
	cout << "Selection sort, In Order done!" << endl;
	outputFile << "Reverse Order,"
		<< selection(100,REVERSE) << ","
		<< selection(1000,REVERSE) << ","
		<< selection(10000,REVERSE) << ","
		<< selection(100000,REVERSE) << ","
		<< selection(1000000,REVERSE) << endl;
	cout << "Selection sort, Reverse Order done!" << endl;
	outputFile << "Random Order,"
		<< selection(100,RANDOM) << ","
		<< selection(1000,RANDOM) << ","
		<< selection(10000,RANDOM) << ","
		<< selection(100000,RANDOM) << ","
		<< selection(1000000,RANDOM) << endl;
	cout << "Selection sort, Random Order done!" << endl;
	outputFile << endl;
	cout << endl;

	//Bubble sort
	outputFile << "Bubble,100,1000,10000,100000,1000000" << endl;//Headers
	cout << "Bubble sort started..." << endl;
	outputFile << "In Order,"
		<< bubble(100,IN_ORDER) << ","
		<< bubble(1000,IN_ORDER) << ","
		<< bubble(10000,IN_ORDER) << ","
		<< bubble(100000,IN_ORDER) << ","
		<< bubble(1000000,IN_ORDER) << endl;
	cout << "Bubble sort, In Order done!" << endl;
	outputFile << "Reverse Order,"
		<< bubble(100,REVERSE) << ","
		<< bubble(1000,REVERSE) << ","
		<< bubble(10000,REVERSE) << ","
		<< bubble(100000,REVERSE) << ","
		<< bubble(1000000,REVERSE) << endl;
	cout << "Bubble sort, Reverse Order done!" << endl;
	outputFile << "Random Order,"
		<< bubble(100,RANDOM) << ","
		<< bubble(1000,RANDOM) << ","
		<< bubble(10000,RANDOM) << ","
		<< bubble(100000,RANDOM) << ","
		<< bubble(1000000,RANDOM) << endl;
	cout << "Bubble sort, Random Order done!" << endl;
	outputFile << endl;
	cout << endl;

}

/*-------------------------------------------------------------------------------------------------
Function name:	insertion
Description:	Sorts sortArray using insertion sort
Arguments:		int size - Size of the array to use
				int order - Order to set up array
Return value:	usigned int - Number of clock ticks used to sort
-------------------------------------------------------------------------------------------------*/
unsigned int Sort::insertion(int size, int order)
{
	if (size > SORT_ARRAY_MAX_SIZE)
	{
		size = SORT_ARRAY_MAX_SIZE;
	}
	
	string orderText;
	switch (order)
	{
	case IN_ORDER:
		InOrderArray(size);
		orderText = "In Order";
		break;
	case REVERSE:
		ReverseOrderArray(size);
		orderText = "Reverse Order";
		break;
	case RANDOM:
		RandomOrderArray(size);
		orderText = "Random Order";
		break;
	default:
		InOrderArray(size);
		orderText = "In Order";
		break;
	}

	
	//Start timer and sort
	clock_t timedif;
	clock_t timer = clock();

	int valueComparing;
	int currentSpot;

	for (int i = 1; i < size; i++)
	{
		valueComparing = sortArray[i];//Value that may be moved
		currentSpot = i;

		//Move down until valueComparing is more than what's below the currentSpot
		while (currentSpot > 0 && valueComparing < sortArray[currentSpot-1])
		{
			sortArray[currentSpot] = sortArray[currentSpot-1];
			currentSpot--;
		}

		//Put the value in the currentSpot
		sortArray[currentSpot] = valueComparing;
	}

	timedif = clock() - timer;

	//Return the time taken
	return timedif;
}

/*-------------------------------------------------------------------------------------------------
Function name:	selection
Description:	Sorts sortArray using selection sort
Arguments:		int size - Size of the array to use
				int order - Order to set up array
Return value:	usigned int - Number of clock ticks used to sort
-------------------------------------------------------------------------------------------------*/
unsigned int Sort::selection(int size, int order)
{
	if (size > SORT_ARRAY_MAX_SIZE)
	{
		size = SORT_ARRAY_MAX_SIZE;
	}
	
	string orderText;
	switch (order)
	{
	case IN_ORDER:
		InOrderArray(size);
		orderText = "In Order";
		break;
	case REVERSE:
		ReverseOrderArray(size);
		orderText = "Reverse Order";
		break;
	case RANDOM:
		RandomOrderArray(size);
		orderText = "Random Order";
		break;
	default:
		InOrderArray(size);
		orderText = "In Order";
		break;
	}

	
	//Start timer and sort
	clock_t timedif;
	clock_t timer = clock();

	int min;
	int temp;

	for (int i = 0; i < size-1; i++)
	{
		min = i;
		
		//Find the lowest
		for (int x = i+1; x < size; x++)
		{
			if (sortArray[x] < sortArray[min])
			{
				min = x;
			}
		}

		if (min != i)
		{
			//Swap values
			temp = sortArray[i];
			sortArray[i] = sortArray[min];
			sortArray[min] = temp;
		}
	}

	timedif = clock() - timer;

	//Return the time taken
	return timedif;
}

/*-------------------------------------------------------------------------------------------------
Function name:	bubble
Description:	Sorts sortArray using bubble sort
Arguments:		int size - Size of the array to use
				int order - Order to set up array
Return value:	usigned int - Number of clock ticks used to sort
-------------------------------------------------------------------------------------------------*/
unsigned int Sort::bubble(int size, int order)
{
	if (size > SORT_ARRAY_MAX_SIZE)
	{
		size = SORT_ARRAY_MAX_SIZE;
	}
	
	string orderText;
	switch (order)
	{
	case IN_ORDER:
		InOrderArray(size);
		orderText = "In Order";
		break;
	case REVERSE:
		ReverseOrderArray(size);
		orderText = "Reverse Order";
		break;
	case RANDOM:
		ReverseOrderArray(size);
		orderText = "Random Order";
		break;
	default:
		InOrderArray(size);
		orderText = "In Order";
		break;
	}

	
	//Start timer and sort
	clock_t timedif;
	clock_t timer = clock();

	bool inOrder = false;
	int temp;

	//Keep going through array until it is sorted
	while (!inOrder)
	{
		inOrder = true;//Start with true
		for (int i = 1; i < size; i++)
		{
			if (sortArray[i-1] > sortArray[i])
			{
				//Swap values
				temp = sortArray[i];
				sortArray[i] = sortArray[i-1];
				sortArray[i-1] = temp;
				
				//Remember that swapping happened
				inOrder = false;
			}
		}
	}

	timedif = clock() - timer;

	//Return the time taken
	return timedif;
}

/*-------------------------------------------------------------------------------------------------
Function name:	InOrderArray
Description:	Fills sortArray with integers that are in order
Arguments:		int size - Size of the array to use
Return value:	None
-------------------------------------------------------------------------------------------------*/
void Sort::InOrderArray(int size)
{
	if (size > SORT_ARRAY_MAX_SIZE)
		size = SORT_ARRAY_MAX_SIZE;
	
	for(int i = 0; i < size; i++)
		sortArray[i] = i;
}

/*-------------------------------------------------------------------------------------------------
Function name:	ReverseOrderArray
Description:	Fills sortArray with integers that are in reverse order
Arguments:		int size - Size of the array to use
Return value:	None
-------------------------------------------------------------------------------------------------*/
void Sort::ReverseOrderArray(int size)
{
	if (size > SORT_ARRAY_MAX_SIZE)
		size = SORT_ARRAY_MAX_SIZE;
	
	for(int i = 0, x = size-1; i < size; i++, x--)
		sortArray[i] = x;
}

/*-------------------------------------------------------------------------------------------------
Function name:	makeRandomnOrderArray
Description:	Fills sortArray with integers that are in random order
Arguments:		int size - Size of the array to use
Return value:	None
-------------------------------------------------------------------------------------------------*/
void Sort::RandomOrderArray(int size)
{
	if (size > SORT_ARRAY_MAX_SIZE)
		size = SORT_ARRAY_MAX_SIZE;
	
	srand(42);//Seed with the answer to the universe and everything!
	
	for(int i = 0; i < size; i++)
		sortArray[i] = ((rand() << 16) +rand()) % size;
}