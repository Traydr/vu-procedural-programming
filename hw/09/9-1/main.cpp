#include <iostream>

// Description of task
// Write a C++ program. Declare the array. Fill array with numbers. Using FOR cycle print array to screen.
// Add the first and the last member of array print them to the screen.

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

int main()
{
	int arrLength{ 10 };
	int randMax{ 1000 };
	do
	{
		int arr[arrLength];

		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = rand() % randMax;
		}

		std::cout << "The whole array:\n";

		for (auto value : arr)
		{
			std::cout << value << "\n";
		}

		int sumOfFirstAndLast = arr[0] + arr[arrLength - 1];
		std::cout << "The sum of the first and last number is " << sumOfFirstAndLast << "\n";
	} while (tryAgain());

	return 0;
}