#include<iostream>
#include<stack>

using namespace std;

// orders a stack in descending order without explicitly using much
// memory

// copies stack by value so its okay print
template<class T>
void print(stack<T> s1)
{
	while(!s1.empty())
	{
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;
}

template<class T>
void sort(stack<T> & s, T & e)
{
	// if stack is empty or if element > than we can push it
	if(s.empty() || s.top() <= e)
		s.push(e);
	else
	{
		T f = s.top();
		s.pop();
		sort(s,e);
		sort(s,f);
	}
}

template<class T>
void sort(stack<T> & s)
{
	if(!s.empty())
	{
		int top = s.top();
		s.pop();
		sort(s,top);
	}
}
		
int main(void)
{
	stack<int> my_stack;
	int n = 6;
	for(int i=n; i>0; i--)
		my_stack.push(i);

	print(my_stack);
	sort(my_stack);
	print(my_stack);
}
