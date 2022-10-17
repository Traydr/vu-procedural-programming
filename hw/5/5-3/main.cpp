#include <iostream>
#include <cmath>

// Description of task
// Write the program which counts the area of circles. Radius of circles changes from 200 to 100 using step 4.
// The first 10 and last 10 results must be displayed on the screen. Use for, if  continue, break.

double areaOfCircle(double radius) {
    return std::numbers::pi * (radius * radius);
}

int main() {
    const int upperBound{200};
    const int lowerBound{100};
    const int step{4};
    const int listedNumbers{10};

    for (int i = upperBound; i > upperBound - step * listedNumbers; i -= 4) {
        std::cout << "Area of circle with radius " << i << " is " << areaOfCircle(i) << "\n";
    }

    for (int i = lowerBound + step * listedNumbers; i > lowerBound; i -= 4) {
        std::cout << "Area of circle with radius " << i << " is " << areaOfCircle(i) << "\n";
    }

    return 0;
}
