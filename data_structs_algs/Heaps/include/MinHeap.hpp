#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#include <vector>
#include <iostream>
#include "Heap.hpp"

using namespace std;

template<typename T>
class MinHeap : public Heap<T>
{
	public:
		MinHeap();

		MinHeap(vector<T> vals);

		virtual ~MinHeap();

		virtual void add(T val);

		virtual void remove();
	
		T getMin();

	private:

		void HeapifyUp();

		void HeapifyDown();
};


#endif

