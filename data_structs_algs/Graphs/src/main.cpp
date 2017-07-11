#include "../include/graphs.hpp"

int main(void)
{
	std::vector<std::pair<char,char>> collections = 
		{std::pair<char,char>('A','B'),
	 	std::pair<char,char>('B','C'),
	 	std::pair<char,char>('C','D'),
 	 	std::pair<char,char>('B','D'),
	 	std::pair<char,char>('E','F'),
	 	std::pair<char,char>('F','C')};
		

	Graph g(collections, true);

	std::cout << g << std::endl;

	std::cout << "C is connected to E is "
					  << g.is_connected(std::pair<char,char>('C','E'))
						<< std::endl;

	std::cout << "E is connected to F is "
					  << g.is_connected(std::pair<char,char>('E','F'))
						<< std::endl;

	g.add_node(std::pair<char,char>('E','D'));

	std::cout << g << std::endl;

	g.remove('A');
	
	std::cout << g << std::endl;

	std::vector<std::pair<char,char>> collections2 = 
		{std::pair<char,char>('A','B'),
	 	std::pair<char,char>('A','C'),
	 	std::pair<char,char>('B','D'),
 	 	std::pair<char,char>('C','E'),
	 	std::pair<char,char>('C','F')};

	Graph g2(collections2, true);
	
	std::cout << "Depth First Search" << std::endl;
	g2.DFS('A');
	std::cout << "Breath First Search" << std::endl;
	g2.BFS('A');

	return 0;
}