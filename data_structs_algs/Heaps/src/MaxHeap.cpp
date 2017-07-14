#include <vector>
#include <iostream>
#include "../include/MaxHeap.hpp"

using namespace std;

template<typename T>
MaxHeap<T>::MaxHeap() : Heap<T>()
{}

template<typename T>
MaxHeap<T>::~MaxHeap()
{}

template<typename T>
MaxHeap<T>::MaxHeap(vector<T> vals)
{
	for(auto & val : vals)
		this->add(val);
}

template<typename T>
void MaxHeap<T>::add(T val)
{
	this->array.push_back(val);
	if(this->len() > 1)
		HeapifyUp();
}

template<typename T>
void MaxHeap<T>::HeapifyUp()
{
	int index = this->len() - 1;

	while(this->hasParent(index) && 
		  (this->array[this->parentIndex(index)] < this->array[index]))
	{
		this->swap(index, this->parentIndex(index));
		index = this->parentIndex(index);
	}
}

template<typename T>
T MaxHeap<T>::getMax()
{
	return this->array[0];
}

template<typename T>
void MaxHeap<T>::remove()
{
	this->array[0] = this->array[this->len()-1];
	this->array.pop_back();

	if(this->len() > 1)
		HeapifyDown();
}

template<typename T>
void MaxHeap<T>::HeapifyDown()
{
	int index = 0;
	int largerIndex;

	while(this->hasLeftChild(index) )
	{
		largerIndex = this->leftChildIndex(index);

		if(this->hasRightChild(index) && 
			(this->array[this->rightChildIndex(index)] > this->array[largerIndex]))
		{
			largerIndex = this->rightChildIndex(index);
		}

		if(this->array[index] > this->array[largerIndex])
			break;
		else
		{
			this->swap(index, largerIndex);
			index = largerIndex;
		}
	}
}
