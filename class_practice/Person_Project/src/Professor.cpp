#include "../include/Professor.hpp"

Professor::Professor(std::string name,
				 int age,
				 int pubs) 
: Person(name, age), 
  Publications(pubs)
{}

Professor::~Professor()
{
//	std::cout << "Professor destructor called!" << std::endl;
}


void Professor::get_data()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << std::to_string(age) << std::endl;
	std::cout << "Id: " << std::to_string(id) << std::endl;
	std::cout << "Publications: " << std::to_string(Publications) << std::endl;
}
