#ifndef _PROFESSOR_H__
#define _PROFESSOR_H__

#include "Person.hpp"

class Professor: public Person
{
	public:
		int Publications;
		
	public:
		Professor(std::string name, 
				 int age,
				 int pubs);
		
		virtual ~Professor();

		virtual void get_data();

};
#endif