#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;
	node(int val)
	{
		data = val;
		next = nullptr;
	}

};

class LSLL
{
	node* head;
public:
	class Iterator
	{
		friend class LSLL; 
		node* pointee;
		Iterator(node* curr) : pointee(curr)
		{}
	public:
		int& operator * ()
		{
			if(pointee)
			return pointee->data;
			exit(0);
		}
		const Iterator& operator ++()
		{
			if (pointee == nullptr)
				exit(0);
			pointee = pointee->next;
			return *this;
		}
		bool operator != (const Iterator& other)const
		{
			return pointee != other.pointee;

		}

	};
	LSLL()
	 {
		head = nullptr;
	}
	void insertattail(int val)
	{
		node* ptr = new node(val);
		if (head == nullptr)
		{
			head = ptr;
			return;
		}
		node* x = head;
		while (x->next != nullptr)
		{
			x = x->next;
		}
		x->next = ptr;
	}
	void insertathead(int val)
	{
		node* ptr = new node(val);
		if (head == nullptr)
		{
			head = ptr;
			return;
		}
		ptr->next = head;
		head = ptr;
	}
	void insertafter(int val, int key)
	{
		
		if (!head)
		{
			return;
		}
		node* ptr = new node(val);
		node* x = head;
		while (x->next!=nullptr&& x->data!=key)
		{
			x = x->next;
		}
		if (!x)
		{
			return;
		}
		ptr->next = x->next;
		x->next = ptr;
	}
	void insertbeofore( int val,int key)
	{
		if (!head)
		{
			return;
		}
		node* ptr = new node(val);
		if (head->data == key)
		{
			ptr->next = head;
			head = ptr;
			return;

		}
		
		node* prev = head;
		node* ne = prev->next;
		while (ne != nullptr && ne->data != key)
		{
			prev = ne;
			ne = ne->next;
		}
		if (!ne) {
			return;
		}
		ptr->next = prev->next;
		prev->next = ptr;

	}
	void removeathead()
	{
		if (!head)
		{
			return;
		}
		node* x = head;
		head = head->next;
		delete x;
	}
	void removeattail()
	{
		if (!head)
			return;
		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		node* ptr = head;
		node * current = head->next;
		while (current != nullptr)
		{          
			ptr = current;
			current = current->next;
		}
		ptr->next = nullptr;
		delete current;
	}
	void removeafter(int key)
	{
		if (!head)
			return;
		node* ptr = head;
		node* x = nullptr;
		while (ptr != nullptr && ptr->data != key)
		{
			ptr = ptr->next;
		}
		if (ptr != nullptr)
		{
			x = ptr->next;
			ptr->next = x->next;
			delete x;
		}
	}
	void removebefore(int val)
	{
		if (!head)
			return;
		if (head->next->data == val)
		{
			removeathead();
			return;
		}
		node* ptr = head;
		while (ptr->next->next != nullptr && ptr->next->next->data != val)
		{
			ptr = ptr->next;
		}
		node* x = ptr->next;
		if (ptr->next->next != nullptr)
		{
			ptr->next = ptr->next->next;
			delete x;
		}
	}
	void print()
	{
		node* ptr = head;
		while (ptr)
		{
			cout << ptr->data<<endl;
			ptr = ptr->next;
		}
	}
	Iterator begin()
	{
		return Iterator(head);
	}
};
int main()
{
	LSLL  one;


	one.insertattail(7);
	one.insertattail(2);
	one.insertattail(13);
	LSLL::Iterator a = one.begin();
	++a;
	cout << " aaaa " << endl;
	cout << *a;
	/*one.insertathead(4);
	one.insertafter(6,4);
	one.removeafter(3);
	one.insertafter(3,7);
	one.insertathead(2);
	one.insertbeofore(1,3);
	one.insertathead(23);
	one.insertafter(12, 4);
	one.removeafter(4);
	one.removeathead();
	one.removebefore(7);*/
	
}
