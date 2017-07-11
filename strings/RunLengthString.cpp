#include<iostream>
#include<string>
#include<map>
#include<vector>

// prints run length encoding
// "aaaabcccaa" becomes "4a1b3c2a"

using namespace std;



int main(int argc, char* argv[])
{
	string str = "aaaabcccaad";
	string new_str = "";

	int count=1;
	char ch;
	for(int i=0; i<str.length()-1; i++)
	{
		ch = str[i];
		if(ch == str[i+1])
			count++;
		else
		{
			new_str += to_string(count);
			new_str.push_back(ch);
			count=1;
		}
	}
	if(ch == str[str.length()-1])
	{
		new_str += to_string(count);
		new_str.push_back(ch);	
	}
	if(ch != str[str.length()-1])
	{
		new_str += "1";
		new_str.push_back(str[str.length()-1]);
	}
	cout << str << endl;
	cout << new_str << endl;


	return 0;
}
	