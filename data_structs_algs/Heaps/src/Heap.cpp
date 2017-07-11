#include <vector>
#include <iostream>

#include "../include/Heap.hpp"

using namespace std;


// public members
template<typename T>
Heap<T>::Heap()
{
}

template<typename T>
Heap<T>::~Heap()
{
}

template<typename T>
int Heap<T>::len() const
{
	return array.size();
}	

template<typename T>
void Heap<T>::print()
{
	for(auto & val : array)
		cout << val << " ";
	cout << endl;
}

template<typename T>
void Heap<T>::swap(int index1, int index2)
{
	T temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

// private members
template<typename T>
int Heap<T>::leftChildIndex(int index) const
{
	return 2 * index + 1;
}

template<typename T>
int Heap<T>::rightChildIndex(int index) const
{
	return 2 * index + 2;
}

template<typename T>
int Heap<T>::parentIndex(int index) const
{
	if(index % 2 == 0)
		return (index / 2 ) -1;
	else
		return index / 2;
}

template<typename T>
bool Heap<T>::hasParent(int index) const
{
	if(parentIndex(index) >= 0)
		return true;
	else
		return false;
}

template<typename T>
bool Heap<T>::hasLeftChild(int index) const
{
	if(leftChildIndex(index) < len())
		return true;
	else
		return false;
}

template<typename T>
bool Heap<T>::hasRightChild(int index) const
{
	if(rightChildIndex(index) < len())
		return true;
	else
		return false;
}




