#include <iostream>

// Description of task
// Write a C++ program to calculate witch number is bigger. Put your number from keyboard. Use your own function.

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

bool isBigger(int x, int y)
{
	return x > y;
}

int main()
{
	do
	{
		std::cout << "Enter num 1 to compare\n";
		int x{ readInt() };
		std::cout << "Enter num 2 to compare\n";
		int y{ readInt() };

		if (isBigger(x, y))
		{
			std::cout << "First number is bigger!\n";
		}
		else
		{
			std::cout << "Second number is bigger!\n";
		}
	} while (tryAgain());

	return 0;
}
