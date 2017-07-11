#include<iostream>
#include<list>

using namespace std;

template<class T>
void print(list<T> & my_list)
{
	typename list<T>::iterator it=my_list.begin();

	for(; it != my_list.end(); it++)
		cout << *it << " ";
	cout << endl;
}


int main(int argc, char * argv[])
{
	int n = 5;
	list<int> my_list;
	for(int i=0; i<n; i++)
		my_list.push_front(i);
	
	print(my_list);
	return 0;
} 