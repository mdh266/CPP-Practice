#include<iostream>

// print elements of 2D array in a clockwise spiral

using namespace std;

void fill(int n, int ** A)
{
	int count = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			A[i][j] = count;
			count++;
		}
}

void print(int n, int ** A)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void print_spiral(int n, int ** A)
{
	int beg = 0;
	int end = n;
	while(beg < end)
	{
		for(int i=beg; i<end; i++)
			cout << A[beg][i] << " ";

		// need plus 1 or else printing
		// the corner twice
		for(int i=beg+1; i<end; i++)
			cout << A[i][end-1] << " ";

		// need minus 2 or else printing
		// the corner twice
		for(int i=end-2; i>=beg; i--)
			cout << A[end-1][i] << " ";

		// need minus 2 or else printing
		// the corner twice
		for(int i=end-2; i>beg; i--)
			cout << A[i][beg] << " ";

		beg++;
		end--;
	}
}



int main(void)
{
  int n = 5;
	int ** A = new int*[n];
	for(int i=0; i<n; i++)
		A[i] = new int[n];

	fill(n,A);
	cout << "Normal:" << endl;
	print(n,A);
	cout << "Spiral:" << endl;
	print_spiral(n,A);

	for(int i=0; i<n; i++)
		delete [] A[i];

	delete [] A;

	return 0;
}

