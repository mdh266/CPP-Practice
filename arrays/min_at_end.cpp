#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// optimal for memory
template<typename T> 
void min_at_end(vector<T> & v)
{
	if(v.size() != 0)
	{
		int min = v[0];

		for(int i=1; i < v.size(); i++)
		{
			if(v[i] < min)
				min = v[i];
		}
		int index = v.size()-1;;

		for(int i=v.size()-1; i>=0; i--)
		{
			if(v[i] == min)
			{
				v[i] = v[index];
				v[index] = min;
				index--;
			}
		}
	}
}

// speed
template<typename T> 
void min_at_end2(vector<T> & v)
{
	if(v.size() != 0)
	{	
		int min = v[0];
		stack<int> min_indices;
		
		for(int i=1; i < v.size(); i++)
		{	
			if(v[i] < min)
			{
				min = v[i];
				while(!min_indices.empty())
					min_indices.pop();

				min_indices.push(i);
			}

			if(v[i] == min)
				min_indices.push(i);
		}

		int end_v = v.size()-1;
		for(int i=0; i<min_indices.size(); i++)
		{
			int min_index = min_indices.top();
			min_indices.pop();
			v[min_index] = v[end_v-i];
			v[end_v-i] = min;
		}
	}
}

template<typename T>
void print(vector<T> & v)
{
	for(auto & x : v)
		cout << x << " ";
	cout << endl;
}



int main(int argc, char *argv[])
{
		vector<int> v = {2,3,5,1,3,2,6,1};
		print(v);
		min_at_end(v);
		print(v);
		return 0;
}