#include <vector>
#include <iostream>

//#include "Heap.cpp"
#include "MinHeap.cpp"
#include "MaxHeap.cpp"

int main(void)
{
	vector<int> vals = {4,3,7,1,10,8,5};

	MinHeap<int> minheap(vals); //(vals);

	minheap.print();

	cout << "Min: "  << minheap.getMin() << endl;

	minheap.remove();

	minheap.print();

	cout << "New min: " << minheap.getMin() << endl;


	MaxHeap<int> maxheap(vals); //(vals);

	maxheap.print();

	cout << "Min: "  << maxheap.getMax() << endl;

	maxheap.remove();

	maxheap.print();

	cout << "New min: " << maxheap.getMax() << endl;
	return 0;
}