#include "../include/Person.hpp"

// declare/initialize the static variable here.
int Person::count=0;

Person::Person(std::string name,
			   int age) 
: name(name),
  age(age)
{
	id = count;
	count++;
}
		
Person::~Person()
{
//	std::cout << "Person Destructor called! " << std::endl;
}
		
void Person::get_data()
{	
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << std::to_string(age) << std::endl;
	std::cout << "Id: " << std::to_string(id) << std::endl;
}


