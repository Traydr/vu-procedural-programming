#include <iostream>

// Description of task
// Write the function to calculate the frequency. The bus frequency 100, the multiplier is float type. Use template.

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

template<typename T>
double CalculateFrequency(int busFrequency, T multiplier)
{
	return busFrequency * multiplier;
}

int main()
{
	do
	{
		std::cout << "Enter bus frequency\n";
		int bus{ ReadInt() };
		std::cout << "Enter multiplier\n";
		float mult{ ReadFloat() };

		double output{ CalculateFrequency(bus, mult) };
		std::cout << "The output frequency is " << output << "\n";
	} while (TryAgain());

	return 0;
}