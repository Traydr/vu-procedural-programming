#include <iostream>
#include <memory>

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

void fillNames(std::string* arr[2][g_NamesLength], std::string names[g_NamesLength])
{
	arr[0][0] = &names[0];
	arr[0][1] = &names[1];
	arr[0][2] = &names[2];
	arr[0][3] = &names[3];
	arr[0][4] = &names[4];
	arr[0][5] = &names[5];
	arr[0][6] = &names[6];
	arr[0][7] = &names[7];
	arr[0][8] = &names[8];
	arr[0][9] = &names[9];
}

void fillAges(std::string ages[g_NamesLength])
{
	for (int i{ 0 }; i < g_NamesLength; i++)
	{
		ages[i] = std::to_string((rand() % 3) + 18);
	}
}

void printBigArray(std::string* arr[2][g_NamesLength])
{
	for (int i{ 0 }; i < g_NamesLength; i++)
	{
		std::cout << i << ": " << *arr[0][i] << ", Age " << *arr[1][i] << "\n";
	}

	std::cout << std::endl;
}

int main()
{
	std::string names[g_NamesLength]{ "Titas", "Yasin", "Kyrylo", "Hanna", "Ivan",
									  "Bogdan", "Sasha", "Timur", "Alex", "Kay" };
	std::string* namesAges[2][g_NamesLength]{};
	std::string ages[g_NamesLength]{};
	fillNames(namesAges, names);

	do
	{
		fillAges(ages);

		for (int i{ 0 }; i < g_NamesLength; i++)
		{
			namesAges[1][i] = &ages[i];
		}

		printBigArray(namesAges);

	} while (tryAgain());

	return 0;
}