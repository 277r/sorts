#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
// sorting algorithm
// make new array size of old array
// put thing in array, keep array sorted at the start (use bisection to get position to put it)
// when done doing this for every element, place array over old array

//debug function
void opArr(int *data, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << ", ";
	}
	std::cout << '\n';
}

int weirdSort(int &firstInt, int size)
{
}

void moveDown1(int &from, int size)
{
	// move from from to to. for size bytes

	int *c = &from;
	for (int i = 0; i < size; i++)
	{
		*(c+i) = *(c + i+1);
	}
	return;
}

void moveUp()
{
}

// function returns position in array where placement would be best
int bisectLoc(int *data, int size, int input)
//		data = array, size = size of array, input = data to place
{
	// this value will show movement up/down
	int bisector = size / 2;
	// here we give the initial location to start at
	int location = bisector;

	bool stillGoing = true;
	while (stillGoing)
	{
		bisector /= 2;

		// bisector will hit 0 and thing won't stop bisecting, so if bisector == 0, make it one
		if (!bisector)
		{
			bisector++;
		}

		// check if location good
		// needs to be fixed, check if out of bounds of array
		// if (location + 1 >= size)
		// if (location -1 == 0)

		// turn this if statement in multiple ones and make it so that it doesn't matter what way the memory gets moved, or make it move the memory up
		/*if ((data[location - 1] < input && data[location + 1] > input) || data[location - 1] == input || data[location + 1] == input)
		{
			stillGoing = false;
			return location;
		}*/

		if (data[location - 1] < input && data[location + 1] > input)
		{
			return location;
		}

		else if (data[location - 1] == input)
		{
			return location - 1;
		}
		else if (data[location + 1] == input)
		{
			return location;
		}
		else if (data[location] == input)
		{
			return location;
		}

		// check if x+1 is higher
		if (data[location - 1] > input)
		{
			location -= bisector;
		}

		// check if x+1 is lower
		if (data[location + 1] < input)
		{
			location += bisector;
		}
	}
	return -1;
	// might've done already
	// if ((x-1 < input && x+1 > input) || x-1 == input || x+1 == input)
	// if true we can place there with ease, return location
}

int weirdSort2(int *data, int size)
{
	// first we will be making an array the size of
	int *arr = new int[size];
	// currentPos (output)
	int cp = 0;
	memset(arr, 0, size);
	// then we will be placing all integers into the array, but we will be putting it on a place that seems good
	for (int i = 0; i < size; i++)
	{

		// use bisection to get location in array to place, use move function to place it
		cp = bisectLoc(arr, size - 1, data[i]);
		std::cout << data[i] << ':' << cp << ':' << size - cp << '\n';

		// take data[i], place somewhere in thing (multiple ways)
		if (arr[cp] == 0)
		{
			arr[cp] = data[i];
		}
		else if (arr[cp] != 0)
		{
			// get location, move from (location to end of array) to (location+1 to end of array +1)
			// tldr: move everything one bit down

			// memory doesn't get moved right
			// move to start of array, move from Xth position in array (size-cp should work)
			// 6 - 5 = 1
			// move N variables
			// 5 = 5
			// should work?

			moveDown1(arr[0], cp);
			// after moving we can place it, but we have to place it one to the left
			arr[cp] = data[i];
		}
		opArr(arr, size);
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << ':' << arr[i] << '\n';
	}
}

int main()
{

	int c = 4;
	//int x[] = {1, 2, 3, 4, 5, 7};
	int x[] = {1, 2, 7, 7, 3, 7};
	// we need to fix this
	// it works so no fix needed
	//std::cout << bisectLoc(x, 5, c);

	weirdSort2(x, 6);
}

// current problem:
// not a problem anymore
// if the whole array is set to 0's, everything will be placed at the end since there is space
