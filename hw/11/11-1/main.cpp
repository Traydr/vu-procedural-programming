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

void fillNames(std::string *arr[2][g_NamesLength])
{
	arr[0][0] = (std::string*)"Titas";
	arr[0][1] = (std::string*)"Yasin";
	arr[0][2] = (std::string*)"Kyrylo";
	arr[0][3] = (std::string*)"Hanna";
	arr[0][4] = (std::string*)"Ivan";
	arr[0][5] = (std::string*)"Bogdan";
	arr[0][6] = (std::string*)"Sasha";
	arr[0][7] = (std::string*)"Timur";
	arr[0][8] = (std::string*)"Alex";
	arr[0][9] = (std::string*)"Kay";
}

void fillAges(std::string ages[g_NamesLength])
{
	for (int i{ 0 }; i < g_NamesLength; i++)
	{
		ages[i] = std::to_string((rand() % 3) + 18);
	}
}

void printBigArray(std::string *arr[2][g_NamesLength]) {
	for (auto item : *arr) {
		std::cout << &item << "\n";
	}

//	for (int i{0}; i < g_NamesLength; i++) {
//		std::cout << i << ": " << *arr[0][i] << " , Age " << *arr[1][i];
//	}
}

int main()
{
	std::string* namesAges[2][g_NamesLength]{};
	std::string ages[g_NamesLength]{};
	//std::pair<std::string, uint32_t> namesAges[2][g_NamesLength]{};

	fillNames(namesAges);

	printBigArray(namesAges);

	do
	{
		fillAges(ages);
		
		*namesAges[1] = ages;

		printBigArray(namesAges);

	} while (tryAgain());

	return 0;
}