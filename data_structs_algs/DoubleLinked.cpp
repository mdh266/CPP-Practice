#include <iostream>
#include <assert.h>

using namespace std;

class node
{
	public:
		int data;
		node * next;	
		node * prev;

	public:
		node(int x, node * prevval= NULL, node * nextval=NULL)
		{
			data = x;
			prev = prevval;
			next = nextval;
		}
		node(node * prevval=NULL, node* nextval=NULL)
		{
			prev = prevval;
			next = nextval;
		}
};

class DoubleLinkedList
{
	private:
		node * head;
		node * tail;
		node * curr;
		int num_nodes;

	public:
 		DoubleLinkedList()	
		{ 
			curr = NULL;
			tail = head = new node;
			num_nodes = 0;
		}
	 
		~DoubleLinkedList()
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
			tail->next = new node(x,NULL,NULL);
			
			// if only one node, make sure tail points back to head
			if(num_nodes == 0)
			{
				head->prev = NULL;
				tail->prev = head;
			}

			// if only one node in list, keep head and tail pointing at same node
			if(num_nodes != 0)
			{
				curr = tail;
				tail = tail->next;
				tail->prev = curr;
				tail->next = NULL;
			}

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
				curr = new node(x,NULL,head);
				head -> prev = curr;
				head = curr;
				num_nodes++;
			}
			else
			{	
				// get previous node and insert node between it and next
				moveToPos(position-1);
				node * after_next = curr->next;
				curr->next = new node(x, curr, after_next);
				after_next->prev = curr->next;
				
				num_nodes++;
			}
		}

		void remove(int position)
		{
			if(position == 0)
			{
				curr = head;
				head = head->next;
				head->prev = NULL;
				delete curr;
		
			}
			else if(position == num_nodes-1)
			{
				curr = tail;
				tail = tail->prev;
				tail->next = NULL;
				delete curr;
			}
			else 
			{
				// make curr the node before
				moveToPos(position-1);

				// link node before to node after
				node * temp = curr->next;
				node * node_after = temp->next;
				curr->next = node_after;

				// link node after to node before
				node_after->prev = curr;

				// delete node				
				delete temp;

			}
			num_nodes--;
		}

		void printForward()
		{	
			curr = head; 
			while(curr != tail)
			{
				cout << curr->data << endl;
				curr = curr->next;
			}
			cout << curr->data << endl;
		}

		void printBackward()
		{	
			curr = tail; // why?
			while(curr != head)
			{
				cout << curr->data << endl;
				curr = curr->prev;
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
		DoubleLinkedList list;
		for(int i = 0; i < N; i++)
			list.append(i);

		cout << "Forward! " << endl;
		list.printForward();
		cout << "Backward! " << endl;
		list.printBackward();

	
		cout << "After inserting!" << endl;

		list.insert(5,5);

		cout << "Forward! " << endl;
		list.printForward();
		cout << "Backward! " << endl;
		list.printBackward();


		cout << "After deleteing!" << endl;
		list.remove(5);
		cout << "Forward! " << endl;
		list.printForward();
		cout << "Backward! " << endl;
		list.printBackward();


	}

	cout << "done!" << endl;

	return 0;
}