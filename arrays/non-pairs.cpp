#include <iostream>
#include <map>
#include <vector>

// Finds the non pairs in a vector of ints

using namespace std;

template <typename T>
void print(vector<T> & vec)
{
	for(auto &x : vec)
		cout << x << " ";

	cout << endl;
}

template <typename T>
void print(std::map<T,T> & my_map)
{
	cout << "MAP: " << endl;
	std::map<int,int>::iterator it = my_map.begin();
	for( ; it != my_map.end(); it++)
		cout << it->first << " => " << it->second << endl;
}


template <typename T>
T find_non_pair(vector<T> & v)
{
	// create map with the element in the array
	// and the number of times it occurs in the array
	std::map<int,int> my_map;
	std::map<int,int>::iterator it;
	for(auto & x : v)
	{
		it = my_map.find(x);
		if(it == my_map.end())
			my_map[x] = 1 ; //insert(std::pair<int,int>(x,1));
		else
			my_map[x] += 1;
	}

	print(my_map);
	
	T return_value;
	for(it = my_map.begin(); it != my_map.end(); it++)
	{
		if(it->second % 2 != 0)
		{	
			return_value = it->first;
			break;
		}
	}
	return return_value;
}


int main()
{
	vector<int> v = {1,1,3,4,3,6,3,6,4};

	int value = find_non_pair(v);
	cout << "\nnon pair: " << value << endl;

	return 0;
}