#include <iostream>
#include <random>

// Description of task
// Write a code that would allow you to solve the math problem 47 + 15 ...?.. 35 +5
// by entering the correct math sign >, <, = from the keyboard. Use Switch Case, method.
// Use goto for repeating the task.

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

int main()
{
	const int leftSum = 47 + 15;
	const int rightSum = 35 + 5;

	do
	{
		std::cout << "Solve this:\t 47 + 15 ...?... 35 + 5\t you may only answer with <, > and =\n";
		char input;
		std::cin >> input;

		if (input == '<') goto less;
		else if (input == '>') goto greater;
		else if (input == '=') goto equal;
		else
		{
			std::cout << "Wrong input\n";
		}

	less:
		std::cout << "incorrect\n";
		continue;
	greater:
		std::cout << "correct\n";
		continue;
	equal:
		std::cout << "incorrect\n";
	} while (tryAgain());
	return 0;
}
