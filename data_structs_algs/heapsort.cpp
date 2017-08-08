#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int> & x, int i, int j)
{
	int temp =  x[i];
	x[i] = x[j];
	x[j] = temp;
}

void HeapifyDown(vector<int> & x, int index, int last_index)
{
	int max_index = 2 * index + 1;
	while (max_index <= last_index)
	{
		// check to see if have right child and if its greater than left
		if((max_index + 1) <= last_index && (x[max_index+1] > x[max_index]))			max_index +=1; 

		// see if child is bigger than parent
		if(x[max_index] > x[index])
		{
			swap(x, index, max_index);
			index = max_index;
			max_index = 2 * index + 1;
		}
		else
			break;
	}
}

void HeapSort(vector<int> & x)
{
	int size = x.size() - 1;
	int lastPossibleParent = size / 2;

	// build heap in place O(n)
	for(int i=lastPossibleParent; i >=0 ; i--)
		HeapifyDown(x, i, size);

	// now take the max value from top of heap
	// and insert into the back of the array
	// and at the head of the sorted portion.
	// O(n log(n))
	for(int i=size; i >= 0; i--)
	{
		if(x[0] > x[i])
		{
			swap(x, 0, i);
			HeapifyDown(x, 0, i-1);
		}	
	}

}




	

int main(void)
{
	vector<int> x = {10, 2, 8, 9, 7, 19, 22, 5};

	for(auto & val : x)
		cout << val << " ";
	cout << endl;
	
	HeapSort(x);

	for(auto & val : x)
		cout << val << " ";
	cout << endl;

	return 0;
}