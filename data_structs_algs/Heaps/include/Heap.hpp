#ifndef __HEAP_H__
#define __HEAP_H__

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class Heap
{
	public:
		Heap();

		Heap(vector<T> vals);

		virtual ~Heap();

		virtual void add(T val) = 0;

		virtual void remove() = 0;

		int len() const;

		void print();

	protected:
		vector<T> array;

		void swap(int index1, int index2);

		int leftChildIndex(int index) const;

		int rightChildIndex(int index) const;

		int parentIndex(int index) const;

		bool hasParent(int index) const;
		
		bool hasLeftChild(int index) const;

		bool hasRightChild(int index) const;
		
};





#endif

