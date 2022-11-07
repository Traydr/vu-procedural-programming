#include <iostream>

// Description of task
// Write a C++ program to find the largest of three chosen numbers.

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
	int first{ 0 };
	int second{ 0 };
	int third{ 0 };

	do
	{
		std::cout << "Enter value 1\n";
		first = read_int();

		std::cout << "Enter value 2\n";
		second = read_int();

		std::cout << "Enter value 3\n";
		third = read_int();

		std::cout << "The largest input num is: " << std::max(first, std::max(second, third)) << "\n";

		first = 0;
		second = 0;
		third = 0;
	} while (tryAgain());

	return 0;
}