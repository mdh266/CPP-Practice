#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

// prints the unique elements of v1 that dont occur in v2,


// this works O(n log(n))
void uniqueElements(vector<int> & v1, vector<int> & v2)
{
	// sort the vectors
	sort(v1.begin(),v1.end());	
	sort(v2.begin(),v2.end());	
	
	int iter1=0;
	int iter2=0;
	
	// compare until at reach the end of each list
	while((iter1 < v1.size()) && (iter2 < v2.size()))
	{
		
		if(v1[iter1] < v2[iter2])
		{
			cout << v1[iter1] << " ";
			iter1++;
		}
		else if(v1[iter1] > v2[iter2])
		{
			iter2++;
		}
		else // theyre equal and dont print, just move on
		{
			iter1++;
			iter2++;
		}
	}
	// now if iter1 != v1.length() then iter2 = v2.length()
	// and just print out elements of v1 until hit end of array
	while(iter1 < v1.size())
	{
			cout << v1[iter1] << " ";
			iter1++;
	}		
	cout << endl;
}

// should be O(n), but doesnt work
void uniqueElements2(vector<int> & v1, vector<int> & v2)
{
	unordered_map<int, int> v1_map;
	unordered_map<int, int> v2_map;

	int count;
	for(int i=0; i<9; i++) //v1.size(); i++)
	{	
		count = v1_map.count(v1[i]);
		if(count > 0)
		{
			v1_map[v1[i]] = count+1;
		}
		else
			v1_map.insert(pair<int,int>(v1[i],1));
	}
	for(int i=0; i<v2.size(); i++)
	{	
		count = v2_map.count(v2[i]);
		if(count > 0)
			v2_map[v2[i]] = count+1;
		else
			v2_map.insert(pair<int,int>(v2[i],1));
	}
	
	int diff;

	for(auto& x : v1_map)
	{
		diff = x.second - v2_map.count(x.first);
		for(int i=0; i < diff; i++)
			cout << x.first << " ";
	}
	cout << endl;
}



int main()
{
	vector<int> v1 = {1,3,5,6,7,5,5,9}; //100,1903};
	vector<int> v2 = {3,4,8,7,5,99,10,2};
	uniqueElements2(v1,v2);
	return 0;
}
