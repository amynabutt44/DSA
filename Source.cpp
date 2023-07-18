#include <iostream>
using namespace std;
template < typename T>
class node
{
public:
	T data;
	node<T>* next;
	node(T val)
	{
		data = val;
		next = nullptr;
	}

};
template <typename T>
class LSLL
{
	node<T>* head;
public:
	LSLL()
	{
		head = nullptr;
	}
	void insertattail(T val)
	{
		node<T>* ptr = new node<T>(val);
		if (head == nullptr)
		{
			head = ptr;
			return;
		}
		node<T>* x = head;
		while (x->next != nullptr)
		{
			x = x->next;
		}
		x->next = ptr;
	}
	void insertathead(T val)
	{
		node<T>* ptr = new node<T>(val);
		if (head == nullptr)
		{
			head = ptr;
			return;
		}
		ptr->next = head;
		head = ptr;
	}
	void insertafter(T val, T key)
	{

		if (!head)
		{
			return;
		}
		node<T>* ptr = new node<T>(val);
		node<T>* x = head;
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
	void insertbeofore(T val, T key)
	{
		if (!head)
		{
			return;
		}
		node<T>* ptr = new node<T>(val);
		if (head->data == key)
		{
			ptr->next = head;//insert at head 
			head = ptr;
			return;
		}
		node<T>* prev = head;
		node<T>* ne = prev->next;
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
		node<T>* x = head;
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
		node<T>* ptr = head;
		node<T>* current = head->next;
		while (current != nullptr)
		{
			ptr = current;
			current = current->next;
		}
		ptr->next = nullptr;
		delete current;
	}
	void removeafter(T key)
	{
		if (!head)
			return;
		node<T>* ptr = head;
		node<T>* x = nullptr;
		while (ptr != nullptr && ptr->data != key)// why we dont ptr-> next!=nullptr 
		{// ptr ma kya haan jo hum ptr ko check kar raheya haan 
			ptr = ptr->next;
		}
		if (ptr != nullptr)
		{
			x = ptr->next;
			ptr->next = x->next;
			delete x;
		}
	}
	void removebefore(T val)
	{
		if (!head)
			return;
		if (head->next->data == val)
		{
			removeathead();
			return;
		}
		node<T>* ptr = head;
		while (ptr->next->next != nullptr && ptr->next->next->data != val)
		{
			ptr = ptr->next;
		}
		node<T>* x = ptr->next;
		if (ptr->next->next != nullptr)
		{
			ptr->next = ptr->next->next;
			delete x;
		}
	}
	void print()
	{
		node<T>* ptr = head;
		while (ptr)
		{
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}
	// pehla hum na middle find karna haan mid sa reverse karna haan 
	// phir hum na compare karna haan 
	node<T>* middle(node <T>* head)
	{
		node<T>* slow = head;
		node<T>* fast = head->next;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	node<T>* reverseLinkList(node<T>* head)
	{

		node<T>* curr = head;
		node<T>* forward = nullptr;
		node<T>* prev = nullptr;

		while (curr != nullptr)
		{
			forward = curr->next;
			curr->next = prev;
			prev = curr;
			curr = forward;
		}
		return prev;
	}
	bool palidrome()
	{
		if (head == nullptr || head->next == nullptr)
		{
			return true;
		}
		// find mid 
		// reverse a half linklist
		// compare two linklist
		node<T>* mid = middle(head);
		// middle k next waleya sa reverse karni haan
		node<T>* midd = mid->next;
		mid->next = reverseLinkList(midd);
		// compare 
		node<T>* head1 = head;
		node<T>* head2 = midd;
		while (head2 != nullptr)
		{
			if (head->data != head2->data)
			{
				return false;
			}
			head1 = head1->next;
			head2 = head2->next;
		}
		return true;

	}
};
int main()
{
	LSLL<int>  one;
	one.insertattail(1);
	one.insertattail(2);
	/*one.insertattail(1);*/
	if (one.palidrome())
	{
		cout << " its palindrome " << endl;
	}
	else
	{
		cout << " not  a palindrome " << endl;
	}


	one.print();

}
