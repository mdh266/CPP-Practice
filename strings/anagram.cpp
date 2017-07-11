#include<iostream>
#include<string>
#include<algorithm>

// prints true or false if strings are anagrams of each other

bool is_anagram(std::string & str1, std::string & str2)
{
	// if not the same length return false
	if(str1.length() != str2.length() )
		return false;
	else
	{
		// sort them and compare element by element
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		for(int i=0; i < str1.length(); i++)
		{
			if(str1[i] != str2[i])
				return false;
		}
		
		return true;
	}
}

int main()
{
	std::string s1 = "hello";
	std::string s2 = "leloh";
	std::string s3 = "othelo";


	std::cout << is_anagram(s1,s2) << std::endl;
	std::cout << is_anagram(s1,s3) << std::endl;

	return 0;
}