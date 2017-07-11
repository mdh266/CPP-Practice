#include<iostream>
#include<vector>

using namespace std;

// returns a vector that is the longest
// increasing subvector

template <class T>
vector<T> largestIncreasingSubArray(vector<T> & v)
{
	int n = v.size();
	int max = 1;
	int index = 0;
	int count = 1;

	for(int i=0; i<n-1; i++)
	{
		if(v[i] < v[i+1])
			count++;
		else
		{
			if(max < count)
			{
				max = count;
				index = i+1-count;
			}
			count=1;
		}
	}
	// now deal with case if 
	// largest subarray was at the end of the array
	if(count > max)
	{
		max = count;
		index = n-count;
	}

	vector<T> sub(max);
	for(int i =0; i < max; i++)
	{
		sub[i] = v[index+i];
	}

	return sub;
}

template<class T>
void print(vector<T> & v)
{
	for(int i=0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main(int argc, char * argv[])
{
	vector<int> v1 = {4,2,3,7,7,4,7};
	vector<int> v2 = {1,3,2,1,2,3};

	print(v1);
	print(v2);
	
	vector<int> v3 = largestIncreasingSubArray(v1);
	vector<int> v4 = largestIncreasingSubArray(v2);

	print(v3);
	print(v4);

	return 0;
}



