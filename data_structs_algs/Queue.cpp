#include <iostream>
#include <assert.h>

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
		
		node(node * nextval=NULL)
		{
			next = nextval;
		}
};

class Queue
{
	private:
		node * head;
		node * tail;
		int length;

	public:
		Queue()
		{
			// need to be both the same node!
			head = tail = new node;
			head->next = tail;
			length = 0;
		}
	
		~Queue()
		{	
			node * curr;
			while(head != NULL)
			{
				curr = head;
				head = head->next;
				delete curr;
			}
			cout << "Destructed!" << endl;
		}
		
		void enter(int x)
		{
			tail->next = new node(x, NULL);
			
			// dont forget this!
			if(length != 0)
				tail = tail->next;

			length++;
		}
	
		int exit()
		{
			if(length == 0)
			{
				cout << "Empty queue! " << endl;
				assert(false);
			}
		
			int value = head->data;
			node * old_head = head;
			head = head->next;
			delete old_head;
			length--;
			return value;
		}

		void print()
		{
			if(length == 0)
			{
				cout << "Empty queue! " << endl;
				assert(false);
			}

			node * curr = head;
			while(curr != tail)
			{
				cout << curr->data << endl;
				curr = curr->next;
			}
			cout << curr->data << endl;
		}

		int size()
		{
			return length;
		}

};

int main(void)
{
	int N = 5;
	Queue queue;
	
	for(int i=0; i<N; i++)
	{
		queue.enter(i);
		cout << "queue now" << endl;
		queue.print();
	}

//	queue.print();
		
	for(int i=0; i < N; i++)
	{
		cout << "who left: " << queue.exit() << endl; 
		queue.print();
	}

	cout << "size = " << queue.size() << endl;
//	queue.print();
		

	return 0;
}
