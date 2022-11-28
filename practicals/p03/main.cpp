#include <iostream>
#include <regex>

// Description of task
// Write a code count the certain letters in the sentence. Enter the sentence from keyboard and store in string .
// Enter a letter from keyboard. Count how many times the letter was used in sentence

const int LowerCaseOffset{97};

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

bool searchAgain()
{
	char answer;
	std::cout << "Would you like to search again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

int main()
{
	do {
		int alphabet[26]{};

		std::string input{};
		std::cout << "Please enter a sentence.\n";

		std::cin.clear();
		std::cin.sync();
		std::getline(std::cin, input);

		const std::regex keepLetters{"[^A-Za-z]"};
		std::string cleaned{std::regex_replace(input, keepLetters, "")};

		for (char c : cleaned) {
			alphabet[tolower(c) - LowerCaseOffset] += 1;
		}

		do {
			std::cout << "Enter a char that you would like to search for a-z\n";
			char inputChar{};
			std::cin >> inputChar;

			char cleanedChar{std::regex_replace(std::to_string(inputChar), keepLetters, "")[0]};

			std::cout << inputChar << " appears " << alphabet[tolower(cleanedChar) - LowerCaseOffset] << " times\n";
		} while (searchAgain());
	} while (tryAgain());
	return 0;
}
