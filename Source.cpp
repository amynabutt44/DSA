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
		while (x->next != nullptr && x->data != key)
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
	void insertbeofore(int val, int key)
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
		node* current = head->next;
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
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}
	node* middlenode()
	{
		node* slow = head;
		node* fast = head;
		while (fast&&fast!=nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;

	}
};
int main()
{
	LSLL  one;
	one.insertattail(7);
	one.insertathead(5);
	one.insertathead(3);
	one.insertathead(2);
	/*one.insertathead(1);*/
	one.print();
	node * ptr=one.middlenode();
	while (ptr)
	{
		cout << ptr->data;
		ptr = ptr->next;
	}
}