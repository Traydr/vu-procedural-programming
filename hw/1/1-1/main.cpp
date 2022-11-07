#include <iostream>

// Description of task
// Write a C++ program that convert a temperature from Centigrade to Fahrenheit.

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

float read_int()
{
	float input{ 0 };
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
			std::cout << "Invalid input; please re-enter\n";
		}
	} while (!valid);

	return input;
}

int main()
{
	float celsius{ 0 };
	float fahrenheit{ 0 };

	do
	{
		std::cout << "Please enter a temperature in C\n";
		celsius = read_int();
		fahrenheit = (celsius * 9) / 5 + 32;
		std::cout << celsius << "C in Fahrenheit is " << fahrenheit << "F\n";
		celsius = 0;
		fahrenheit = 0;
	} while (tryAgain());

	return 0;
}
