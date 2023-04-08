#include <iostream>
using namespace std;
template<typename T>
struct DNode
{
	T val;
	DNode* next;
	DNode* prev;
	DNode( T value)
	{
		val = value;
		next = nullptr;
		prev = nullptr;
	}
};
template <typename T>
class Dsll
{
	DNode <T>* head;
public :
	Dsll()
	{
		head = nullptr;
	}
	void insertathead(T val)
	{
		DNode<T>* ptr = new DNode<T>(val);
		if (!head)
		{
			head = ptr;
			return;
		}
		head->prev = ptr;
		ptr->next = head;
		head = ptr;
	}
	void deleteathead()
	{
		if (!head)
		{
			cout << " :( list is empty" << endl;
			return;
		}
		DNode<T>* temp = head;
		head = temp->next;
		head->prev = nullptr;
		delete temp;
	}
	void insertAtTail(T val)
	{
		if (!head)
		{
			insertathead(val);
			return;
		}
		DNode<T>* ptr = new DNode<T>(val);
		DNode <T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = ptr;
		ptr->prev = current;

	}
	void deleteAtTail()
	{
		if (!head)
		{
			cout << " list is empty" << endl;
			return;
		}
		DNode<T>* ptr = head;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		DNode<T>* x = ptr->prev;
		x->next = nullptr;
		delete ptr;

	}
	void inssertbefore(T val, T key)
	{
		if (!head)
		{
			cout << " list is null " << endl;
			return;
		}
		if (head->val == key)
		{
			insertathead(val);
		}
		
		DNode<T>* temp = head;
		while (temp->next != nullptr && temp->val != key)
		{
			temp = temp->next;
		}
		if (temp->next != nullptr)
		{
			DNode <T>* newnode = new DNode<T>(val);
			newnode->next = temp;
			newnode->prev = temp->prev;
			temp->prev->next = newnode;
			temp->prev = newnode;
		}
		
	}
	void deletebefore(T key)
	{
		if (!head)
		{
			cout << "list is empty" << endl;
			return;
		}
		if (head->val == key)
		{
			return;
		}
		DNode<T>* ptr = head;
		while (ptr->next != nullptr&& ptr->val!=key)
		{
			ptr =ptr->next;
		}
		DNode <T>* temp = ptr->prev;
		
		if (!ptr->next)
		{
			if (temp->prev == nullptr)
			{
				deleteathead();
				return;
			}
			ptr->prev = ptr->prev->prev;
			temp->prev->next= ptr;
			delete temp;
		}
	}
	void insertafter(T val, T key)
	{
		if (!head)
			return;
		
		DNode<T>* temp = head;
		while (temp != nullptr && temp->val != key)
		{
			temp = temp->next;
		}
		if (temp->next != nullptr)
		{
			DNode<T>* newnode = new DNode<T>(val);
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next = newnode;
			if (newnode->next != nullptr)
			{
				newnode->next->prev = newnode;
			}

		}
	}
	void deleteafter( T key)
	{
		if (!head)
		{
			return;
		}
		DNode<T>* temp = head;
		while (temp->next != nullptr && temp->val != key)
		{
			temp = temp->next;
		}
		if (temp->next == nullptr)
		{
			return;
		}
		if (temp->next != nullptr)
		{
			DNode<T>* x = temp->next;
			temp->next = x->next;
			if(x->next!=nullptr)
				x->next->prev = temp;
				delete x;
		}
	}
	void print()
	{
		DNode<T>* temp = head;
		DNode<T>* tail = head;
		while (temp != nullptr)
		{
			cout << temp->val << endl;
			temp = temp->next;
			tail = temp;
		}
		while (tail != nullptr)
		{
			cout << tail->val << endl;
			tail = tail->prev;
		}
	}
};
int main()
{
	Dsll <int> one;
	one.insertathead(5);
	one.insertathead(2);
	one.insertathead(7);
	one.insertathead(45);
	one.insertafter(12, 7);
	
	/*one.insertAtTail(3);*/
	/*one.insertAtTail(1);*/
	one.print();
	cout << " after deleting " << endl;
	/*one.deletebefore(5);*/
	/*one.insertathead(6);
	one.insertathead(3);
	one.insertathead(2);
	one.inssertbefore(4,6);
	one.deleteathead();*/
	/*one.insertAtTail(66);
	one.print();
	cout << " after deleting at head" << endl;
	one.deleteAtTail();*/
	one.deleteafter(2);
	one.print();
}

