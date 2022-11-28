#include <iostream>

// Description of task
// Write a program in C++ that calculates the factorial of a number.

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

int readInt()
{
	int input{ 0 };
	bool valid{ false };

	do
	{
		std::cin >> input;
		if (std::cin.good())
		{
			valid = true;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid input; please re-enter.\n";
		}
	} while (!valid);

	return input;
}

int main()
{
	do
	{
		std::cout << "Enter a number\n";
		int input{ readInt() };

		long fact{ 1 };
		for (int i{ 1 }; i <= input; i++) fact *= i;

		std::cout << input << "! is " << fact << "\n";
	} while (tryAgain());

	return 0;
}
