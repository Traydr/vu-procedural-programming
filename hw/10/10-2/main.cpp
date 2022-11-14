#include <iostream>

// Description of task
// Write a C++ program. Declare 2 dimension array. Fill array with numbers. Use FOR cycle.
// Calculate the average of lines and columns. Print the array and the averages of lines and columns in separate array.

// Define the exact sizes of arrays
const uint32_t MatSize{ 10 };

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

void fillArrayWithNums(uint32_t arr[MatSize][MatSize])
{
	for (int i{ 0 }; i < MatSize; i++)
	{
		for (int j{ 0 }; j < MatSize; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void calcColumnSums(uint32_t arrA[MatSize][MatSize], uint32_t arrB[MatSize][MatSize], uint32_t output[MatSize])
{
	for (int i{ 0 }; i < MatSize; i++)
	{
		uint32_t tempColumnSum{ 0 };

		for (int j{ 0 }; j < MatSize; j++)
		{
			tempColumnSum += arrA[j][i] + arrB[j][i];
		}

		output[i] = tempColumnSum;
	}
}

void calcRowSums(uint32_t arrA[MatSize][MatSize], uint32_t arrB[MatSize][MatSize], uint32_t output[MatSize])
{
	for (int i{ 0 }; i < MatSize; i++)
	{
		uint32_t tempRowSum{ 0 };

		for (int j{ 0 }; j < MatSize; j++)
		{
			tempRowSum += arrA[i][j] + arrB[i][j];
		}

		output[i] = tempRowSum;
	}
}

void printArray(uint32_t arr[MatSize][MatSize])
{
	for (int i{ 0 }; i < MatSize; i++)
	{
		for (int j{ 0 }; j < MatSize; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

int main()
{
	// Initialize 2 arrays with 0's
	uint32_t arrA[MatSize][MatSize]{};
	uint32_t arrB[MatSize][MatSize]{};

	do
	{
		// Fill arrays
		fillArrayWithNums(arrA);
		std::cout << "\tarray A\n";
		printArray(arrA);

		fillArrayWithNums(arrB);
		std::cout << "\tarray B\n";
		printArray(arrB);

		uint32_t columnSums[MatSize]{};
		uint32_t rowSums[MatSize]{};

		calcColumnSums(arrA, arrB, columnSums);
		calcRowSums(arrA, arrB, rowSums);

		int count{ 0 };
		for (uint32_t sum : columnSums)
		{
			std::cout << "Column " << count << " sum is " << sum << "\n";
			count++;
		}

		count = 0;
		for (uint32_t sum : rowSums)
		{
			std::cout << "Row " << count << " sum is " << sum << "\n";
			count++;
		}

	} while (tryAgain());

	return 0;
}