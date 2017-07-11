#include<iostream>
#include<vector>

using namespace std;

// speed
template<typename T> 
void max_at_beg(vector<T> & v)
{
	if(v.size() != 0)
	{		
		int max = v[0];
		vector<int> max_indices;

		for(int i=1; i < v.size(); i++)
		{
			if(v[i] == max)
			{
				max = v[i];
				max_indices.push_back(i);
			}
			if(v[i] > max)
			{
				max = v[i];
				max_indices.clear();
				max_indices.push_back(i);
			}
		}
		for(int i=0; i<max_indices.size(); i++)
		{
			v[max_indices[i]] = v[i];
			v[i] = max;
		}
	}
}

// optmize for memory
template<typename T> 
void max_at_beg2(vector<T> & v)
{
	if(v.size() != 0)
	{		
		int max = v[0];

		for(int i=1; i < v.size(); i++)
		{
			if(v[i] > max)
				max = v[i];
		}
		int index =0;
		for(int i=0; i < v.size(); i++)
		{
			if(v[i] == max)
			{
				v[i] = v[index];
				v[index] = max;
				index++;
			}
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
		vector<int> v = {6,2,3,5,1,3,6,3,6};
		print(v);
		max_at_beg2(v);
		print(v);
		return 0;
}