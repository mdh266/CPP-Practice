#include<iostream>

// rotates a nxn array by 90 degrees, finds its transpose

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

// this is O(n^2) for a general matrix
void rotate(int n, int ** A)
{
	int temp;
	for(int i=0; i <n; i++)
		for(int j=i; j<n; j++)
		{
			temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
}




int main(void)
{
  int n = 4;
	int ** A = new int*[n];
	for(int i=0; i<n; i++)
		A[i] = new int[n];

	fill(n,A);
	cout << "Normal:" << endl;
	print(n,A);
	rotate(n,A);
	cout << "Transpose:" << endl;
	print(n,A);

	for(int i=0; i<n; i++)
		delete [] A[i];

	delete [] A;

	return 0;
}

