#include<iostream>



class Complex
{
	public:
		Complex(int a, int b) :
		a(a),
		b(b)
		{}
			
		Complex() : a(0), b(0)
		{}

		// compy construtor
		Complex(const Complex & c)
		{
			a = c.re();
			b = c.im();
		}

		// these need to be declared const if they are going
		// to be passed to a function where we are passing
		// a const complex number
		int re() const
		{
			return a;
		}

		int im() const
		{	
			return b;
		}
			
		Complex operator+(const Complex & x) const
		{
			Complex sum(this->re() + x.re(),
									this->im() + x.im());

			return sum;
		}
		
		friend std::ostream & operator<<(std::ostream & os, const Complex & c)
		{
				os << c.re() << " + " << c.im() << "i";
				return os;
		}
	
	private:
		int a, b;

};

// CAN ALSO BE OVERLOADED OUTSIDE OFTHE CLASS
/*
Complex operator+(const Complex & c1, const Complex & c2)
{
	return Complex(c1.re() + c2.re(), c1.im() + c2.im());
}

std::ostream & operator<<(std::ostream & os, const Complex & c)
{
	os << c.re() << " + " << c.im() << "i"; 
	return os;
}
*/
	
int main()
{
	Complex c1(1,1);
	Complex c2(1,2);
	Complex c3 = c1 +c2;
	std::cout << c3 << std::endl;

	return 0;
}