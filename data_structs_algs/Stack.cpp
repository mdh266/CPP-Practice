#include <iostream>

using namespace std;

class node
{
	public:
		int data;
		node * next;	

	public:
		node(int x, node * nextval=NULL)
		{
			data = x;
			next = nextval;
		}
		// default constructor
		node(node * nextval=NULL)
		{
			next = nextval;
		}
};

class Stack
{
	public:
		node * head;
		int num_nodes;
		
		Stack()
		{
			head = new node;
			num_nodes=0;
		}

		~Stack()
		{	
			while(head != NULL)
			{
				node * curr = head;
				head = head->next;
				delete curr;
			}
	//		cout << "Destructed!" << endl;
			
		}

		void push(int x)
		{
			// need if statement for case num_nodes == 0 !!
			if(num_nodes == 0)
				head = new node(x, NULL);
			else
			{
				node * new_head = new node(x,head);
				head = new_head;
			}
			
			num_nodes++;
		}

		int peak()
		{
			return head->data;
		}

		int pop()
		{
			node * curr = head;
			head = curr->next;
			int return_value = curr->data;

			delete curr;
			num_nodes--;

			return return_value;
		}
			
		void print()
		{
			if(num_nodes == 0)
				cout << "Empty stack!" << endl;
			else
			{	
				node * curr = head;
				while(curr != NULL)
				{
					cout << curr->data << endl;
					curr = curr->next;
				}
			}
		}

		int size()
		{
			return num_nodes;
		}

};

int main(void)
{
	int N = 10;

	Stack stack;

	for(int i = 0; i < N; i++)
		stack.push(i);

	stack.print();

	for(int i=0; i<N; i++)
		cout << "Popped : " << stack.pop() << endl;

	stack.print();

	return 0;
}