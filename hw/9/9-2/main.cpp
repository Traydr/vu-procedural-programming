#include <iostream>

// Description of task
// Write a C++ program. Automatically fill the array with numbers using some formula (use the formula of your choice).
// Using FOR cycle print array to screen, also print the average of all numbers.

bool tryAgain() {
  char answer;
  std::cout << "Would you like to try again? (y)\n";
  std::cin >> answer;
  return answer == 'y';
}

int formula(int index) {
  return index * index + index * 3 + 2;
}

int main() {
  int arrLength{10};
  do {
    int arr[arrLength];

    for (int i = 0; i < arrLength; i++) {
      arr[i] = formula(i);
    }

    std::cout << "The whole array:\n";

    int sum{0};
    for (int value : arr) {
      std::cout << value << "\n";
      sum += value;
    }

    float average = sum / arrLength;
    std::cout << "The average of the array is " << average << "\n";
  } while (tryAgain());

  return 0;
}