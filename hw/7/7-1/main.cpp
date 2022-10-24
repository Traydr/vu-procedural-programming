#include <iostream>

// Description of task
// Write the program using C++. Program must calculate the area of trapezoid.
// Use two different types of functions and variables (one integer, another float).
// The name of both functions is the same Atrap.

const float Half = 0.5;

bool TryAgain() {
  char answer;
  std::cout << "Would you like to try again? (y)\n";
  std::cin >> answer;
  return answer == 'y';
}

int ReadInt() {
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

int ATrap(int a, int b, int height) {
  return Half * (a + b) * height;
}

float ATrap(float a, float b, int height) {
  return Half * (a + b) * height;
}

int main() {
  do {
    std::cout << "Enter num\n";
    int x{ReadInt()};
  } while (TryAgain());

  return 0;
}
