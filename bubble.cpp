#include <iostream>

int bubble(int &input, int inputSize)
{
	// declare local variables
	bool done = false;
	bool switched;
	int *cp = &input;
	int sData;
	// walk through data
	while (!done)
	{
		switched = false;
		for (int i = 0; i < inputSize - 1; i++)
		{
			//compare
			if (*(cp + i) > *(cp + i + 1))
			{
				switched = true;
				sData = *(cp + i);
				*(cp + i) = *(cp + i + 1);
				*(cp + i + 1) = sData;
			}
		}
		// check if no switch arounds

		if (!switched)
		{
			done = true;
		}
	}

	return 0;
}

int main()
{
	int size = 50000;
	int data[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = rand() - 1073741824;
	}

	bubble(data[0], size);
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << '\n';
	}
}