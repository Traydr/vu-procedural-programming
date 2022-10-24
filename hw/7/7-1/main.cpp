#include <iostream>

// Description of task
// Write the program using C++. Program must calculate the area of trapezoid.
// Use two different types of functions and variables (one integer, another float).
// The name of both functions is the same Atrap.

const float half = 0.5;

bool tryAgain() {
  char answer;
  std::cout << "Would you like to try again? (y)\n";
  std::cin >> answer;
  return answer == 'y';
}

int readInt() {
  int input{0};
  bool valid{false};

  do {
    std::cin >> input;
    if (std::cin.good()) {
      valid = true;
    } else {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Invalid input; please re-enter.\n";
    }
  } while (!valid);

  return input;
}

int aTrap(int a, int b, int height) {
  return half * (a + b) * height;
}

float aTrap(float a, float b, int height) {
  return half * (a + b) * height;
}

int main() {
  do {
    std::cout << "Enter num\n";
    int x{readInt()};
  } while (tryAgain());

  return 0;
}
