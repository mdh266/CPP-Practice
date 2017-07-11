#ifndef _PERSON_H__
#define _PERSON_H__

#include<iostream>
#include<string>

class Person
{
	protected:
		static int count;
		int age;
		int id;
		std::string name;

	public:
		Person(std::string name, int age);
		
		// If destructor wasnt virtual then base class
		// destructor wouldnt get called before derived 
		// class
		virtual ~Person();
		
		// need to be virtual to be overridden when using pointers
		//virtual 
		virtual void get_data();

};
#endif