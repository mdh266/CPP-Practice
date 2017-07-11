#ifndef _GRAPHS_H__
#define _GRAPHS_H__

#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<stack>
#include<queue>

//template<typename T>
class Graph
{
	protected: 
		bool directed;
		std::map<char,std::set<char>> graph;
		
	public:
		Graph(std::vector<std::pair<char,char>> & collections, 
					bool directed = false);
		
		void add_collections(std::vector<std::pair<char,char>> & collections);
		
		void add_node(std::pair<char,char> node);

		bool is_connected(std::pair<char,char> node);

		void remove(char node);
		
		friend std::ostream & operator<<(std::ostream & os, Graph & g);

		void DFS(char node);

		void BFS(char node);

};

#endif
