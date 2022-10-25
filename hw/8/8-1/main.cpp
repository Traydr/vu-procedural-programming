#include <iostream>

// Description of task
// Write a C++ program which enable you to enter word from keyboard. Print the word to screen spelling the word by letter. Use FOR cycle.

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

int main()
{
	do
	{
		std::string input;
		std::cout << "Enter any word\n";
		std::getline(std::cin, input);

		for (char c : input)
		{
			if (c == ' ') break;
			std::cout << c << "\n";
		}
	} while (tryAgain());

	return 0;
}