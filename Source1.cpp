#include <iostream>
using namespace std;
template < typename T>
class Stack
{
private:
	T* data;
	int top;
	int capacity;

	void resize(int newCpacity)
	{
		T* temp = new T[newCpacity];
		for (int i = 0; i < top; i++)
		{
			temp[i] = data[i];
		}
		int temptop = top;
		this->~Stack();
		data = temp;
		capacity = newCpacity;
		top = temptop;
	}
public:
	Stack()
	{
		capacity = 0;
		top = 0;
		data = nullptr;
	}
	void push(T val)
	{
		if (isFull())
			resize(capacity == 0 ? 1 : capacity * 2);
		data[top++] = val;
	}
	int isFull()
	{
		if (top == capacity)
		{
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		return top == 0;
	}

	Stack(const Stack<T>& ref)
	{
		if (ref->capacity <= 0)
		{
			data = nullptr;
			capacity = 0;
			return;
		}
		capacity = ref.capacity;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			this - data[i] = ref.data[i];
		}
	}

	//Assignment Operator
	Stack& operator=(const Stack<T>& ref)
	{
		if (ref.data == nullptr)
		{
			data = nullptr;
			capacity = 0;
			//	return;
		}
		if (ref == *this)
		{
			return *this;
		}
		this->~Stack();
		capacity = ref.capacity;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			this->data[i] = ref.data[i];
		}
		return *this;
	}
	T pop()
	{

		if (isEmpty())
			exit(0);
		T val = data[--top];
		if (top > 0 && top == capacity / 4)
			resize(capacity / 2);
		return val;
	}
	T stackTop()
	{
		cout << " the value of top in stack top function is " << endl;
		return data[top-1 ];
	}
	~Stack()
	{
		if (!data)
			return;
		delete[]data;
		data = nullptr;
		capacity = 0;
		top = 0;
	}
	
};
int main()
{
	Stack<int> a;

	for (int i = 0; i < 10; i++)
	{
		a.push(i + 1);
	}
	cout << " stack top " << a.stackTop();

	for (int i = 0; i < 10; i++)

	{
		cout << a.pop();
		cout << endl;
	}



}
