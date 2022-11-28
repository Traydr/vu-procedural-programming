#include <iostream>

// Description of task
// You are provided with a 2d array of grades of students, names of students and subjects.
// Transform this into a struct, then fill the struct of students with data from the 2d array.

int const Students{ 5 };
int const Subjects{ 5 };

struct student
{
	std::string name;
	int programming{};
	int graphics{};
	int appliedMaths{};
	int discreteMaths{};
	int operatingSystems{};
};

void printStudent(const student& i)
{
	std::string formatOut{};

	formatOut += "\nName: " + i.name;
	formatOut += "\nGrades: \n\tProgramming: " + std::to_string(i.programming);
	formatOut += "\n\tGraphics: " + std::to_string(i.graphics);
	formatOut += "\n\tApplied Maths: " + std::to_string(i.appliedMaths);
	formatOut += "\n\tDiscrete Maths: " + std::to_string(i.discreteMaths);
	formatOut += "\n\tOperating Systems: " + std::to_string(i.operatingSystems);
	formatOut += "\n";

	std::cout << formatOut;
}

int main()
{
	// Inputs
	int grades[Students][Subjects]{
		{ 1, 1, 1, 1, 1 },
		{ 2, 2, 2, 2, 2 },
		{ 3, 3, 3, 3, 3 },
		{ 4, 4, 4, 4, 4 },
		{ 5, 5, 5, 5, 5 }};
	std::string names[Students]{ "John", "Mathew", "James", "Roger", "Albert" };

	// Outputs
	student output[Students];

	// Loop to copy data from input to output
	for (int i{ 0 }; i < Students; i++)
	{
		student temp = *new student;
		temp.name = names[i];
		temp.programming = grades[i][0];
		temp.graphics = grades[i][1];
		temp.appliedMaths = grades[i][2];
		temp.discreteMaths = grades[i][3];
		temp.operatingSystems = grades[i][4];
		output[i] = temp;
	}

	// Print the output
	for (const student& i : output)
	{
		printStudent(i);
	}

	std::string holdInput{};
	std::cin >> holdInput;
	return 0;
}
