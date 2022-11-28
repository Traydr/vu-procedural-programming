#include <iostream>

// Description of task
// Write a program in C++ that sums all the natural numbers with each other that are less than the number you entered.
// e.g. (n=7 1+2+3+4+5+6)

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
		std::cout << "Enter a natural number\n";
		int input = readInt();

		if (input < 0)
		{
			std::cout << "A natural number is any whole number bigger than 0, try again.\n";
			continue;
		}

		int sum{ 0 };
		for (int i = 1; i < input; i++)
		{
			sum += i;
		}

		std::cout << "The sum of all natural numbers less than " << input << " is " << sum << "\n";
	} while (tryAgain());

	return 0;
}

