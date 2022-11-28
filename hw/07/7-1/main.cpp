#include <iostream>

// Description of task
// Write the program using C++. Program must calculate the area of trapezoid.
// Use two different types of functions and variables (one integer, another float).
// The name of both functions is the same Atrap.

const float Half = 0.5;

bool TryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}
float ReadFloat()
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
			std::cout << "Invalid input; please re-enter.\n";
		}
	} while (!valid);

	return input;
}

int ReadInt()
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

int ATrap(int a, int b, int height)
{
	return Half * (a + b) * height;
}

float ATrap(float a, float b, float height)
{
	return Half * (a + b) * height;
}

int main()
{
	do
	{
		char input;
		bool useInt{ false };
		std::cout << "Would you like to use (i)nt or (f)loat?\n";
		std::cin >> input;

		if (input == 'i')
		{
			useInt = true;
		}

		std::cout << "Enter base a, then base b, lastly height\n";

		if (useInt)
		{
			int a{ ReadInt() };
			int b{ ReadInt() };
			int height{ ReadInt() };

			std::cout << "Area is " << ATrap(a, b, height) << "\n";
		}
		else
		{
			float a{ ReadFloat() };
			float b{ ReadFloat() };
			float height{ ReadFloat() };

			std::cout << "Area is " << ATrap(a, b, height) << "\n";
		}
	} while (TryAgain());

	return 0;
}
