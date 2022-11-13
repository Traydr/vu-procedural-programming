#include <iostream>

// Description of task
// Write a C++ program. Declare 2 dimension array. Fill array with numbers. Use FOR cycle.
// Calculate the average of lines and columns. Print the array and the averages of lines and columns in separate array.

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

void calcColumnSums(uint32_t arrA[SizeX][SizeY], uint32_t arrB[SizeX][SizeY], uint32_t output[SizeX])
{
	for (int i{0}; i < SizeX; i++ ) {
		uint32_t tempColumnSum{0};

		for (int j{0}; j < SizeY; j++) {
			tempColumnSum += arrA[i][j] + arrB[i][j];
		}

		output[i] = tempColumnSum;
	}
}

void calcRowSums(uint32_t arrA[SizeX][SizeY], uint32_t arrB[SizeX][SizeY], uint32_t output[SizeY])
{
	for (int i{0}; i < SizeY; i++ ) {
		uint32_t tempRowSum{0};

		for (int j{0}; j < SizeX; j++) {
			tempRowSum += arrA[i][j] + arrB[i][j];
		}

		output[i] = tempRowSum;
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

		uint32_t columnSums[SizeX]{};
		uint32_t rowSums[SizeY]{};

		calcColumnSums(arrA, arrB, columnSums);
		calcRowSums(arrA, arrB, rowSums);

		int count{0};
		for (uint32_t sum : columnSums) {
			std::cout << "Column " << count << " sum is " << sum << "\n";
			count++;
		}

		count = 0;
		for (uint32_t sum : rowSums) {
			std::cout << "Row " << count << " sum is " << sum << "\n";
			count++;
		}

	} while (tryAgain());

	return 0;
}