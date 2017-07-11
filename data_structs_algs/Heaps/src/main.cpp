#include <vector>
#include <iostream>

//#include "Heap.cpp"
#include "MinHeap.cpp"

int main(void)
{
	vector<int> vals = {4,3,7,1,10,8,5};

	MinHeap<int> minheap(vals); //(vals);

	minheap.print();

	cout << "Min: "  << minheap.getMin() << endl;

	minheap.remove();

	minheap.print();

	cout << "New min: " << minheap.getMin() << endl;

	return 0;
}