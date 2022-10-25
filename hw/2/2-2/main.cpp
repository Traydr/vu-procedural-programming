#include <iostream>

// Description of task
// Write a C++ program that will display all even positive number that are less than the first even number entered

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
		std::cout << "Enter an even number:\n";
		input = read_int();

		if (input % 2 != 0)
		{
			std::cout << "That is not an even number, Please try again\n";
			continue;
		}

		std::cout << "All even numbers less than " << input << " are:\n";
		for (int i = input; i > 0; i -= 2)
		{
			std::cout << i << "\n";
		}
	} while (tryAgain());

	return 0;
}