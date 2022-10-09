#include <iostream>
#include <bits/stdc++.h>

// Description of task
// Write a program in C++ that computes the largest common divisor of two numbers

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

int largestCommonDivisor(long u, long v) {
    // Binary GCD Algorithm
    // Based on https://en.wikipedia.org/wiki/Binary_GCD_algorithm
    // Also based on https://github.com/TheAlgorithms
    if (u == 0 && v == 0) {
        return 0;
    }

    if (u == 0 || v == 0) {
        return u + v;
    }

    int k;
    for (k = 0; ((u | v) & 1) == 0; ++k) {
        u >>= 1;
        v >>= 1;
    }

    while ((u & 1) == 0) u >>= 1;

    do {
        while ((v & 1) == 0) v >>= 1;
        if (u > v) std::swap(u, v);
        v = (v - u);
    } while (v != 0);

    return u << k;
}

int main() {
    do {
        std::cout << "Enter First number\n";
        int numOne{readInt()};
        std::cout << "Enter Second number\n";
        int numTwo{readInt()};

        int lcd = largestCommonDivisor(numOne, numTwo);
        std::cout << "The largest common divisor of " << numOne << " and " << numTwo << " is " << lcd << "\n";
    } while (tryAgain());

    return 0;
}
