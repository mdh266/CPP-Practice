#include<iostream>
using namespace std;

class Base 
{ 
	public:
		Base() { cout << "Base Constructor " << endl; }
		~Base() { cout << "Base Destructor " << endl; } /* see below */ 
};

class Derived: public Base 
{ 
	public:
		Derived() { cout << "Derived Constructor" << endl; }
	
		~Derived() { cout << "Derived Destructor" << endl; } 
};

class VirtBase 
{ 
	public:
		VirtBase() { cout << "Base Constructor" << endl; }
		virtual ~VirtBase() { cout << "Base Destructor" << endl; } /* see below */ 
};

class VirtDerived: public VirtBase 
{ 
	public:
		VirtDerived() { cout << "Derived Constructor" << endl; }
	
		~VirtDerived() { cout << "Derived Destructor" << endl; } 
};

int main() 
{
	// this will cause a memory leak because derived destructor not called.
	Base *p = new Derived();
	delete p; 
	
	// this will NOT cause a memory leak because derived destructor IS called.
	Derived *pd = new Derived();
	delete pd; 

	// this will NOT cause a memory leak because derived destructor IS called.
	VirtBase *vp = new VirtDerived();
	delete vp; 

	
	return 0;
}