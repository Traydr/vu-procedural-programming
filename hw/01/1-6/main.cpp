#include <iostream>

// Description of task
// Write a C++ program to check whether a given number is even or odd

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

int read_int()
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
	int input{ 0 };

	do
	{
		std::cout << "Enter an integer\n";
		input = read_int();

		std::cout << input << " is " << ((input % 2 == 0) ? "even" : "odd") << "\n";

		input = 0;
	} while (tryAgain());

	return 0;
}