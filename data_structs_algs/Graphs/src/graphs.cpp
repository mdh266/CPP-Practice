#include "../include/graphs.hpp"

//template<typename T>
//Graph<T>::
Graph::
Graph(std::vector<std::pair<char,char>> & collections,
			bool directed)
	: directed(directed)
	{
		add_collections(collections);
	}

//template<typename T>
void 
Graph::
add_collections(std::vector<std::pair<char,char>> & collections)
{
	for(auto & node : collections)
		add_node(node);
}

bool
Graph::
is_connected(std::pair<char,char> node)
{
	std::map<char,std::set<char>>::iterator it;
	std::set<char>::iterator it2;

	it = graph.find(node.first);
	if(it == graph.end())
		return false;
	else
	{
		it2 = graph[node.first].find(node.second);
		if(it2 == graph[node.first].end())
			return false;
		else
			return true;
	}
}


//template<typename T>
void 
Graph::
add_node(std::pair<char,char> node)
{
	graph[node.first].insert(node.second);
	if(directed == false)
		graph[node.second].insert(node.first);

}


void
Graph::
remove(char node)
{
	std::map<char, std::set<char>>::iterator it;
	std::set<char>::iterator it2;
	
	// remove the node from outgoing nodes targets
	for(it = graph.begin(); it != graph.end(); it++)
	{
		it2 = (it->second).find(node);
		if(it2 != (it->second).end())
			(it->second).erase(node);
	}
		
	// remove the actual node
	it = graph.find(node);
	if(it != graph.end())
		graph.erase(node);
}

void 
Graph::
DFS(char node)
{
	std::vector<char> visited;
	std::stack<char> s;
	s.push(node);
	
	while(!s.empty())
	{
	 	char vertex = s.top();
		s.pop();

		// not found -> not visited
		bool found = false;
		for(auto & x: visited)
		{
				if(x == vertex)
					found = true;
		}

		if(!found) 
		{
			// if this vertex hasnt been visited yet add it 
			// to the list of visited now
			visited.push_back(vertex);
			//std::cout << vertex << std::endl;
			
			// go through its outgoing edges 
			// and if the vertices at the end of them havent been visited
			// then push them onto the stack.
			std::set<char>::iterator it2 = graph[vertex].begin();
			
			for( ; it2 != graph[vertex].end(); it2++)
			{
				 	bool found2 = false;

					for(auto & x : visited)
					{
						if(x == *it2)
							found2 = true;
					}

					// not found -> not visited
				 if(!found2)
						s.push(*it2);
				
			} // for it2
		} // if not visited
	
	} // while stack not empty

	// now print it out
	for(auto & x: visited)
		std::cout << x << " ";

	std::cout <<  std::endl;
}


std::ostream& 
operator<<(std::ostream & os, Graph & g)
{
	std::string str = "";

	for (std::map<char,std::set<char>>::iterator it=g.graph.begin();
			 it != g.graph.end();
			 it++)
	{
		str += "[";
		str += it->first;
		str += "]: ";

		for(std::set<char>::iterator it2=it->second.begin();
				it2 != it->second.end();
				it2++)
		{
			str += *it2;
			str += " ";
		}

		str += "\n";
	
	} // it

	os << str;

	return os;

} // overload<<



void 
Graph::
BFS(char node)
{
	std::vector<char> visited;
	std::queue<char> q;
	q.push(node);

	while(!q.empty())
	{
		char vertex = q.front();
		q.pop();
		
		// see if vertex has been visited before!
		bool found = false;
		for(auto & x : visited)
		{
			if(x == vertex)
				found = true;
		}
		// if not visited go add visisted through outgoing nodes and 
		// add them to queue if havent been visited before.
		if(!found)
		{
			visited.push_back(vertex);

			std::set<char>::iterator it = graph[vertex].begin();
			for(; it != graph[vertex].end(); it++)
			{
				bool found2 = false;
				for(auto & x : visited)
				{
					if(x == *it)
						found2 = true;
				}
				// if not in the visited vertices push into queue
				if(!found2)
					q.push(*it);
			}	// for it
		
		}  // vertex found
	} // while queue is not empy

	for(auto & x : visited)
		std::cout << x << " ";
	
	std::cout << std::endl;	

}

