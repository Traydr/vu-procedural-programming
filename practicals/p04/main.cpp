#include <iostream>
#include <vector>

const uint32_t SUBJECTS{ 12 };
const uint32_t TOTAL_CREDITS{ 60 };
const uint32_t STUDENTS_TO_GENERATE{ 30 };

struct student
{
	std::string name;
	uint32_t subjects[12]{};

	student(const std::string& in_name, const std::vector<uint32_t>& in_subjects)
	{
		name = in_name;

		for (int i{ 0 }; i < SUBJECTS; i++)
		{
			subjects[i] = in_subjects.at(i);
		}
	}
};

student createRandomStudent()
{
	std::string names[]{ "Jack", "Johns", "James", "Tom", "Thomas", "Darcy", "Tod", "Nothing" };
	std::vector<uint32_t> grades{};
	std::string name{ names[rand() % names->length()] };
	name += std::to_string(rand() % 1000);

	for (int i{ 0 }; i < SUBJECTS; i++)
	{
		grades.push_back((rand() % 6) + 5);
	}

	return { name, grades };
}

void printStudent(const student& input)
{
	std::cout << "Name: " << input.name << "\nGrades:";

	for (int i{ 0 }; i < SUBJECTS; i++)
	{
		std::cout << " " << i << ":" << input.subjects[i];
	}
	std::cout << "\n";
}

int main()
{
	// Inputs
	uint32_t subject_credits[SUBJECTS]{ 6, 4, 5, 5, 5, 6, 4, 4, 6, 5, 5, 5 };
	std::vector<student> list_of_students{};

	// Add random students
	for (int i{ 0 }; i < STUDENTS_TO_GENERATE; i++)
	{
		list_of_students.push_back(createRandomStudent());
	}

	list_of_students.push_back(student("STAR", { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }));
	list_of_students.push_back(student("CAT 2 student", { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 }));
	list_of_students.push_back(student("Unsatisfactory student", { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }));

	std::cout << "All Students\n";
	for (const student& var : list_of_students)
	{
		printStudent(var);
	}
	std::cout << "\n\n";

	// All categories
	std::vector<student> cat_1{};
	std::vector<student> cat_2{};
	std::vector<student> cat_3{};
	std::vector<student> unsatisfactory{};

	// Calculations
	for (const student& st : list_of_students)
	{
		uint32_t num_grades_10_or_9{};
		uint32_t num_grades_8_or_7{};
		uint32_t num_grades_6_or_5{};
		uint32_t num_grades_other{};

		for (int i{ 0 }; i < SUBJECTS; i++)
		{
			switch (st.subjects[i])
			{
			case 10:
			case 9:
				num_grades_10_or_9 += subject_credits[i];
				break;
			case 8:
			case 7:
				num_grades_8_or_7 += subject_credits[i];
				break;
			case 6:
			case 5:
				num_grades_6_or_5 += subject_credits[i];
				break;
			default:
				num_grades_other += subject_credits[i];
				break;
			}
		}

		if (num_grades_10_or_9 >= 0.8 * TOTAL_CREDITS && num_grades_8_or_7 <= 0.2 * TOTAL_CREDITS
			&& num_grades_6_or_5 + num_grades_other == 0)
		{
			cat_1.push_back(st);
		}
		else if (num_grades_10_or_9 + num_grades_8_or_7 >= 0.75 * TOTAL_CREDITS
			&& num_grades_6_or_5 <= 0.15 * TOTAL_CREDITS && num_grades_other == 0)
		{
			cat_2.push_back(st);
		}
		else if (num_grades_other == 0)
		{
			cat_3.push_back(st);
		}
		else
		{
			unsatisfactory.push_back(st);
		}
	}

	std::cout << " ALL CAT 1 STUDENTS\n";
	for (const student& st : cat_1)
	{
		printStudent(st);
	}
	std::cout << "\n\n";

	std::cout << " ALL CAT 2 STUDENTS\n";
	for (const student& st : cat_2)
	{
		printStudent(st);
	}
	std::cout << "\n\n";

	std::cout << " ALL CAT 3 STUDENTS\n";
	for (const student& st : cat_3)
	{
		printStudent(st);
	}
	std::cout << "\n\n";

	std::cout << " ALL UNSATISFACTORY STUDENTS\n";
	for (student st : unsatisfactory)
	{
		printStudent(st);
	}
}
