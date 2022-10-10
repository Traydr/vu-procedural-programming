#include <iostream>

// Description of task
// Write a code that lets you choose 1 of 5 beverages and quantity of beverages max 5. Use Switch Case method.

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

int main() {
    std::string beverages[]{"Coca Cola", "Pepsi", "Fanta", "Sprite", "Water"};
    do {
        std::cout << "Pick one of these beverages (enter num):\n";

        int i{0};
        for (auto item: beverages) {
            std::cout << "\t" << i << ". " << beverages[i] << "\n";
            i++;
        }

        int input{readInt()};

        switch (input) {
            case 0:
                std::cout << "You picked the coca cola\n";
                break;
            case 1:
                std::cout << "You picked the pepsi\n";
                break;
            case 2:
                std::cout << "You picked the fanta\n";
                break;
            case 3:
                std::cout << "You picked the sprite\n";
                break;
            case 4:
                std::cout << "You picked the water\n";
                break;
        }

        std::string drink{beverages[input]};
        int numBeverages{0};

        do {
            std::cout << "Enter how many " << drink << "\'s you would like (max of 5)\n";
            numBeverages = readInt();
        } while (numBeverages > 6);

        std::cout << "You ordered " << numBeverages << " " << drink << "\'s \n";

    } while (tryAgain());

    return 0;
}
