#ifndef _STUDENT_H__
#define _STUDENT_H__

#include "Person.hpp"

class Student : public Person
{
	public:
		double GPA;
		
	public:
		Student(std::string name, 
				int age,
				double GPA);
		
		virtual ~Student();

		virtual void get_data();

};
#endif