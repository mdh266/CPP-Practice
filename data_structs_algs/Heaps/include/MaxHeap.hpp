#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

#include <vector>
#include <iostream>
#include "Heap.hpp"

using namespace std;

template<typename T>
class MaxHeap : public Heap<T>
{
	public:
		MaxHeap();

		MaxHeap(vector<T> vals);

		virtual ~MaxHeap();

		virtual void add(T val);

		virtual void remove();
	
		T getMax();

	private:

		void HeapifyUp();

		void HeapifyDown();
};


#endif

