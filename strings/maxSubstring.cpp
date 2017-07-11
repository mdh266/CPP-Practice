#include<iostream>
#include<string>

using namespace std;

// Returns substring that is the max number of continugously repeated chars 

string maxRepeats(string & str)
{
	int n = str.length();
	char max_char   = str[0];
	char curr_char  = str[0];
	int max_repeats = 1;
  int curr_repeats = 0;

	// find the max number of contigous repeated chars
	for(unsigned int i=1; i<n; i++)
	{
		if(curr_char == str[i+1])
			curr_repeats++;
		else
		{
			curr_char = str[i+1];
			curr_repeats = 1;
		}
		if(curr_repeats > max_repeats)
		{
			max_repeats = curr_repeats;
			max_char = curr_char;
		}
	}

	// build substring
	string new_str = string();
	new_str.append(max_repeats,max_char);
	
	return new_str;
}


void print(string str)
{
	int n = str.length();
	for(int i=0; i <n; i++)
		cout << str[i];

	cout << endl;
}

int main()
{
	string s1 = "aabbbccdd";
	string new_s1 = maxRepeats(s1);
	print(new_s1);
	string s2 = "abbcccc";
	string new_s2 = maxRepeats(s2);
	print(new_s2);

	return 0;
}