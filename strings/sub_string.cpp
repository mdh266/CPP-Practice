#include<iostream>
#include<string>

using namespace std;


// return the locaiton of string str_2 in str_1
int sub_string(string & str_1, string & str_2)
{
	if(str_2.length() == 0 || str_1.length() == 0)
	{
		cout << "Atleast one string is empty!" << endl;
		return -1;
	}
	else
	{
		int iter_1=0;
		int iter_2=0;
		int char_2 = str_2[0];
		int count = 0;
		int loc = -1;
		while(iter_1 < str_1.length())
		{
			if(static_cast<int>(str_1[iter_1]) == char_2)
			{
				loc = iter_1;
				while((iter_2 < str_2.length()) || (iter_1 < str_1.length()))
				{
					if(str_2[iter_2] == str_1[iter_1])
					{
						count++;
						iter_1++;
						iter_2++;
					}
					else
						break;
				} // end while
				if(count == str_2.length())
					return loc;
				else
				{
					count=0;
					iter_2=0;
				}
			}
			else
				iter_1++;
		}
		cout << "String 2 is not in string 1" << endl;
		return -1;
	}
}


int main(int argc, char *argv[])
{
	string s_1 = "saturday is tur fun";
	string s_2 = "tur ";

	cout << sub_string(s_1, s_2) << endl;

	return 0;
}