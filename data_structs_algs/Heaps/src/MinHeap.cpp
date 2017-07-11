#include <vector>
#include <iostream>
#include "Heap.cpp"
#include "../include/MinHeap.hpp"

using namespace std;

template<typename T>
MinHeap<T>::MinHeap() : Heap<T>()
{}

template<typename T>
MinHeap<T>::~MinHeap()
{}

template<typename T>
MinHeap<T>::MinHeap(vector<T> vals)
{
	for(auto & val : vals)
		this->add(val);
}

template<typename T>
void MinHeap<T>::add(T val)
{
	this->array.push_back(val);
	if(this->len() > 1)
		HeapifyUp();
}

template<typename T>
void MinHeap<T>::HeapifyUp()
{
	int index = this->len() - 1;

	while(this->hasParent(index) && 
		  (this->array[this->parentIndex(index)] > this->array[index]))
	{
		this->swap(index, this->parentIndex(index));
		index = this->parentIndex(index);
	}
}

template<typename T>
T MinHeap<T>::getMin()
{
	return this->array[0];
}

template<typename T>
void MinHeap<T>::remove()
{
	this->array[0] = this->array[this->len()-1];
	this->array.pop_back();

	if(this->len() > 1)
		HeapifyDown();
}

template<typename T>
void MinHeap<T>::HeapifyDown()
{
	int index = 0;
	int smallerIndex;

	while(this->hasLeftChild(index) )
	{
		smallerIndex = this->leftChildIndex(index);

		if(this->hasRightChild(index) && 
			(this->array[this->rightChildIndex(index)] < this->array[smallerIndex]))
		{
			smallerIndex = this->rightChildIndex(index);
		}

		if(this->array[index] < this->array[smallerIndex])
			break;
		else
		{
			this->swap(index, smallerIndex);
			index = smallerIndex;
		}
	}
}
