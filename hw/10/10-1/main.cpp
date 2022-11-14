#include <iostream>

// Description of task
// Write a C++ program. Declare two 2 dimension array. Fill both arrays with numbers. Use FOR cycle.
// Print the sum of both arrays. (Sum arrays between: a+b, “a” is a member from first array zero line and zero column,
// “b” is a member from second array zero line and zero column and so on)

// Define the exact sizes of arrays
const uint32_t SizeX{ 10 };
const uint32_t SizeY{ 10 };

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

void fillArrayWithNums(uint32_t arr[SizeX][SizeY])
{
	for (int i{ 0 }; i < SizeX; i++)
	{
		for (int j{ 0 }; j < SizeY; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

int main()
{
	// Initialize 2 arrays with 0's
	uint32_t arrA[SizeX][SizeY]{};
	uint32_t arrB[SizeX][SizeY]{};

	do
	{
		// Fill arrays
		fillArrayWithNums(arrA);
		fillArrayWithNums(arrB);

		uint32_t sum{};
		for (auto smallA : arrA)
		{
			for (auto smallB : arrB)
			{
				sum += *smallA + *smallB;
			}
		}
		std::cout << "Here is the sum: " << sum << "\n";
	} while (tryAgain());

	return 0;
}