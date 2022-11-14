#include <iostream>

// Description of task
// Write the C++ program. Declare the two-dimensional array.
// Fill first column with names of your group mates, second column leave empty.
// Declare one dimensional array and fill it with the age of the group mates.
// Copy data with ages from second array to the second column of first array using pointers.
// You can create the third array in which you can copy the addresses of second array.

// Define the exact sizes of arrays
const uint32_t g_NamesLength{ 10 };

bool tryAgain()
{
	char answer;
	std::cout << "Would you like to try again? (y)\n";
	std::cin >> answer;
	return answer == 'y';
}

void fillNames(std::string arr[2][g_NamesLength])
{
	arr[0][0] = "Titas";
	arr[0][1] = "Yasin";
	arr[0][2] = "Kyrylo";
	arr[0][3] = "Hanna";
	arr[0][4] = "Ivan";
	arr[0][5] = "Bogdan";
	arr[0][6] = "Sasha";
	arr[0][7] = "Timur";
	arr[0][8] = "Alex";
	arr[0][9] = "Kay";
}

void fillAges(std::string ages[g_NamesLength])
{
	for (int i{ 0 }; i < g_NamesLength; i++)
	{
		ages[i] = std::to_string((rand() % 3) + 18);
	}
}

int main()
{
	std::string namesAges[2][g_NamesLength]{};
	std::string ages[g_NamesLength]{};
	//std::pair<std::string, uint32_t> namesAges[2][g_NamesLength]{};

	fillNames(namesAges);

	do
	{
		fillAges(ages);

		for (int i{0}; i < g_NamesLength; i++) {
			namesAges[1][i] = ages[i];
		}

		for (int i{0}; i < g_NamesLength; i++) {
			std::cout << namesAges[0][i] << " is " << namesAges [1][i] << "!\n";
		}

	} while (tryAgain());

	return 0;
}