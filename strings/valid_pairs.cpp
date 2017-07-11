
// () [] {} [()] is good but not {[}]

#include<iostream>
#include<string>
#include<map>
#include<stack>

bool is_valid(std::string & s)
{
	std::map<char,char> pairs;
	pairs['('] = ')';
	pairs['{'] = '}';
	pairs['['] = ']';

	std::stack<char> unpaired;

	int N = s.length()-1;
	
	int i = 0;
	while (i <= N)
	{
		if((s[i] == '(') ||
			 (s[i] == '[') ||
			 (s[i] == '{') )
		{
			unpaired.push(s[i]);
			i++;
		}
		else
		{
		//	char popped = unpaired.top();
			if(pairs[unpaired.top()] == s[i])
			{
				unpaired.pop();
				i++;
			}
			else
				return false;
		}
	}

	return true;
}


int main()
{
	std::string s = "[({}())]";

	std::cout << "s is " << is_valid(s) << std::endl;

	std::string s2 = "{[(])}";

	std::cout << "s2 is " << is_valid(s2) << std::endl;

	return 0;
}