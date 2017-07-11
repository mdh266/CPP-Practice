#include "../include/Student.hpp"

Student::Student(std::string name,
				 int age,
				 double GPA) 
: Person(name, age), 
  GPA(GPA)
{}

Student::~Student()
{
//	std::cout << "Student destructor called!" << std::endl;
}


void Student::get_data()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << std::to_string(age) << std::endl;
	std::cout << "Id: " << std::to_string(id) << std::endl;
	std::cout << "GPA: " << std::to_string(GPA) << std::endl;
}
