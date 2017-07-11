#include<iostream>
#include<vector>

using std::cout;
using std::endl;

template <typename T>
void quicksort(std::vector<T> & v, int left, int right)
{
	int i=left, j=right;
	T pivot = v[ (i+j)/2 ];
	T temp;
	while(i <= j)
	{
		// find left value that is greater than pivot
		while(v[i] < pivot)
			i++;
		// find right value that is less than pivot
		while(v[j] > pivot)
			j--;
		
		// makes sure j < pivot < i
		if(i <= j)
		{
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
			i++;
			j--;
		}
	}
	
	// preform quick search on (left, j) and (i, right)
	if(left < j)
		quicksort(v, left, j);

	if(right > i)
		quicksort(v, i, right);

	// else done!
}


template<typename T>
void merge(std::vector<T> & v, int left, int right, int mid)
{
	int i = left;
	int k = left; // copy index
	int j = mid + 1;
	int temp[50];
	while(i <= mid && j <= right)
	{
		// if least on left is less than least on right copy it over
		if(v[i] < v[j])
		{
			temp[k] = (v[i]);
			i++;
			k++;
		}
		else // copy over right
		{
			temp[k] = (v[j]);
			j++;
			k++;
		}
		while(i <= mid) // now if j = right copy over rest of left side
		{	
			temp[k] = (v[i]);
			i++;
			k++;
		}
		while(j <= right) // now if i == mid  copy over the rest of right side
		{
			temp[k] = (v[j]);
			j++;
			k++;
		}
	}	
	// now copy over the temp vector
	for(i = left; i < k; i++)
		v[i] = temp[i];
		
}


template<typename T>
void mergesort(std::vector<T> & v, int left, int right)
{
	int mid;
	if(left < right)
	{
		mid = (left+right)/2;
		mergesort(v, left, mid);
		mergesort(v, mid+1, right);
		merge(v, left, right, mid);
	}
}

	


template <typename T>
void print(std::vector<T> & v)
{
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}


template <typename T>
void makeVector(std::vector<T> & vec)
{
	vec.push_back(1);
	vec.push_back(12);
	vec.push_back(5);
	vec.push_back(26);	
	vec.push_back(7);
	vec.push_back(14);
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(2);	
}

int main()
{
	std::vector<int> vec;
	
	makeVector(vec);

	print(vec);

	cout << "Quick sort" << endl;

	quicksort(vec, 0, vec.size()-1);
	
	print(vec);

	std::vector<int> vec2;
	
	makeVector(vec2);

	print(vec2);

	cout << "Merge sort" << endl;

	mergesort(vec2, 0, vec2.size()-1);

	print(vec2);

	return 0;
}