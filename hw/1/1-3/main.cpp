#include <iostream>

// Description of task
// Write a C++ program to read the value of an integer X and display the value of Y.
// Y is 1 when X > 0, Y is 0 when X = 0 and Y is  -1 when X< 0.

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
	int x{ 0 };

	do
	{
		std::cout << "Enter x value\n";
		x = read_int();

		if (x < 0) std::cout << "y = " << -1 << "\n";
		if (x == 0) std::cout << "y = " << 0 << "\n";
		if (x > 0) std::cout << "y = " << 1 << "\n";

	} while (tryAgain());

	return 0;
}
