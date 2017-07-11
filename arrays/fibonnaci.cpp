#include<iostream>
#include<vector>

using namespace std;

double fibonacci(int n)
{
	vector<int> x(n);
	x[0] = 0;
	x[1] = 1;
	for(int i=2; i < n; i++)
		x[i] = x[i-1] + x[i-2];

	return x[n-1];
}


int main(void)
{
	int n;
	cout << "Enter a number." << endl;
	cin >> n;
	cout << fibonacci(n) << endl;

	return 0;
}
	
	