#include <iostream>

// Description of task
// Write a program that would allow you to calculate the VAT only of 5 entered products

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

float readFloat()
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

int main()
{
	do
	{
		const float VAT_TAX{ 0.21 };
		float sum{ 0 };
		float input;

		std::cout << "Enter 5 prices separated by pressing Enter key\n";

		int counter = 0;
		while (counter < 5)
		{
			input = readFloat();

			if (input < 0)
			{
				std::cout << "Price cannot be negative\n";
				continue;
			}

			sum += input;
			counter++;
		}

		float vat = VAT_TAX * sum;
		std::cout << "Total VAT for " << sum << " is " << vat << "\n";
	} while (tryAgain());

	return 0;
}
