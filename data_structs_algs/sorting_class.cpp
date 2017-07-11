#include<iostream>
#include<vector>

template<typename T>
class sorter
{
	public:
		sorter(std::vector<T> v)
		{
			array = v;	
		}

		~sorter()
		{}

		void set_array(std::vector<T> v)
		{
			array = v;
		}

		void print()
		{
			std::cout << "[";
			for(auto & x : array)
				std::cout << x << " , ";
			std::cout << "]\n";
		}

		void quick_sort()
		{	
			inner_quick_sort(0, array.size()-1);						
		}	

		void inner_quick_sort(int left, int right)			
		{
			int i = left;
			int j = right;

			int pivot = array[(i+j)/2];

			while(i <= j)
			{
				while(array[i] < pivot)
					i++;
				
				while(array[j] > pivot)
					j--;

				// switch them!
				if(i <= j)
				{
					T temp = array[i];
					array[i] = array[j];
					array[j] = temp;
					i++;
					j--;
				}
			}
			
			if(left < j)
				inner_quick_sort(left, j);

			if(right > i)
				inner_quick_sort(j, right);
		}

		void merge_sort()
		{
			int N = array.size()-1;
			inner_merge_sort(0, N);
		}
	
		void inner_merge_sort(int left, int right)
		{
		if(left < right)
		{
			int mid = (left+right)/2;
			inner_merge_sort(left, mid);
			inner_merge_sort(mid+1, right);	
				 // a = [left, mid-1]
				// b = [mid, right] 
			int i = left;
			int j = mid+1;
			std::vector<int> temp(50);
			int index = 0;

			// loop over and compare them
			while( i <= mid && j <= right)
			{
				if(array[i] < array[j])
				{
					temp[index] = array[i];
					i++;
					index++;
				}
				else
				{
					temp[index] = array[j];
					j++;
					index++;
				}
			}
			// now fill the rest of temp with 
			// the rest of the vectors
			while(i <= mid)
			{
				temp[index] = array[i];
				i++;
				index++;
			}
			while(j <= right)
			{
				temp[index] = array[j];
				j++;
				index++;
			}
			//now copy it over to the original array
			for(j=0; j < index; j++)
				array[left + j] = temp[j];	
		}
		}
 	
	private:
		std::vector<T> array;

};



int main()
{

	std::vector<int> vec = {34,12,8,2,5,9,13,7};

	sorter<int> sort(vec);

	sort.print();

	sort.quick_sort();

	sort.print();

	sort.set_array(vec);

	sort.print();
	
	sort.merge_sort();

	sort.print();

 
	return 0;
}