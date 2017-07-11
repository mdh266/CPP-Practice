#include<iostream>
#include<string>

using namespace std;

bool is_palindrom(string & str)
{
	int n = str.length()/2;
	for(int i=0; i<n; i++)
	{
		if(str[i] != str[str.length()-1-i])
			return false;
	}
	return true;
} 

int main(int argc, char* argv[])
{
	string str = "hello";
	cout << is_palindrom(str) << endl;
	string str_2 = "boob";
	cout << is_palindrom(str_2) << endl;
	string str_3 = "abcdcba";
	cout << is_palindrom(str_3) << endl;
		

	return 0;
}