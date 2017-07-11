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
		// default constructor
		node(node * nextval=NULL)
		{
			next = nextval;
		}
};

class SingleLinkedList
{
	private:
		node * head;
		node * tail;
		node * curr;
		int num_nodes;

	public:
 		SingleLinkedList()	
		{ 
			curr = NULL;
			tail = head = new node;
			num_nodes = 0;
		}
	 
		~SingleLinkedList()
		{
			// delete from left to right
			while(head != NULL)
			{
				curr = head;
				head = head->next;
				delete curr;
			}
		//	cout << "destructor called! " << endl;
		}
		
		void append(int x)
		{
			tail->next = new node(x,NULL);	

			// if only one node in list, keep head and tail pointing at same node
			if(num_nodes != 0)
				tail = tail->next;

			num_nodes++;
		}

		void moveToPos(int position)
		{	
			assert((position >= 0) && (position <= num_nodes));
			
			curr = head;
			for(int i=0; i<position; i++)
				curr = curr->next;
		}
		
		void insert(int x, int position)
		{
			// if at end just append it
			if(position == num_nodes)
				append(x);
			// if at the beginning, need to create a new node that copies head
			// then change the head and make it point to new node
			else if(position == 0 )
			{
				curr = new node(x,head);
				head = curr;
				num_nodes++;
			}
			else
			{	
				// get previous node and insert node between it and next
				moveToPos(position-1);
				curr->next = new node(x, curr->next);
				num_nodes++;
			}
		}

		void remove(int position)
		{
			if(position == 0)
			{
				curr = head->next;
				delete head;
				head = curr;
			}
			else if(position == num_nodes-1)
			{	
				// remove last node
				moveToPos(num_nodes-2);
				delete tail;
				curr->next = NULL;
				tail = curr;
			}
			else 
			{
				moveToPos(position-1);
				node * temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}

			num_nodes--;
		}

		void print()
		{	
			curr = head; // why?
			while(curr != tail)
			{
				cout << curr->data << endl;
				curr = curr->next;
			}
			cout << curr->data << endl;
		}

		void print(int position)
		{
			moveToPos(position);
			cout << curr->data << endl;
		}
	
		int size()
		{
			return num_nodes;
		}
};

int main(int argc, char * argv[])
{
	int N = 5;
	{
		SingleLinkedList list;
		for(int i = 0; i < N; i++)
			list.append(i);

		list.print();

		cout << "After inserting!" << endl;

		list.insert(5,0);
		list.print();

		cout << "After deleteing!" << endl;
		list.remove(0);
		list.print();
		
	}

	cout << "done!" << endl;

	return 0;
}