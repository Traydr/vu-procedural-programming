#include <iostream>

// Description of task
// Write a C++ program. Declare two 2 dimension array. Fill both arrays with numbers. Use FOR cycle.
// Print the sum of both arrays. (Sum arrays between: a+b, “a” is a member from first array zero line and zero column,
// “b” is a member from second array zero line and zero column and so on)

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

void printArray(uint32_t arr[MatSize][MatSize]) {
	for (int i{0}; i < MatSize; i++) {
		for (int j{0}; j < MatSize; j++) {
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
	uint32_t output[MatSize][MatSize]{};

	do
	{
		// Fill arrays
		fillArrayWithNums(arrA);
		std::cout << "\tarray A\n";
		printArray(arrA);

		fillArrayWithNums(arrB);
		std::cout << "\tarray B\n";
		printArray(arrB);

		for (int i{0}; i < MatSize; i++) {
			for (int j{0}; j < MatSize; j++) {
				output[i][j] = arrA[i][j] + arrB[i][j];
			}
		}

		std::cout << "\toutput array\n";
		printArray(output);
	} while (tryAgain());

	return 0;
}