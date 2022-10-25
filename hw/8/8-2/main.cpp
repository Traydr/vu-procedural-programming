#include <iostream>
#include <random>

// Description of task
// Write a C++ program which enable you to enter word from keyboard. Change one letter in word. Write the output to screen.

bool tryAgain() {
  char answer;
  std::cout << "Would you like to try again? (y)\n";
  std::cin >> answer;
  return answer == 'y';
}

int main() {
  do {
    std::string input;
    std::cout << "Enter any word\n";

    // Clear cin before getline since getline() and >> operators handle input differently (trailing \n chars and whitespace)
    std::cin.clear();
    std::cin.sync();
    // Cleared and should be reset

    std::getline(std::cin, input);
    int inputLength = input.length() > 0 ? input.length() : 1;
    int randomIndex = rand()%inputLength;

    int counter{0};
    for (char c : input) {
      if (c == ' ') break;
      if (counter == randomIndex) {
        char randomChar = 'a' + rand()%26;
        std::cout << randomChar  << "\n";
        counter++;
        continue;
      }

      std::cout << c << "\n";
      counter++;
    }
  } while (tryAgain());

  return 0;
}