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
		T* teo = new T[newCpacity];
		for (int i = 0; i < top; i++)
		{
			teo[i] = data[i];
		}
		int temptop = top;
		this->~Stack();
		data = teo;
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
		return data[top - 1];
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
string reverse(string  a)
{
	string s;
	Stack<char> h;
	int x = a.size();
	for (int i = 0; i < x; i++)
	{
		h.push(a[i]);
		
	}
	for (int i = 0; i < x; i++)
	{

		s += h.pop();

	}
	return s;
 }
int main()
{
	string k = "amnashahzadi";
	cout << reverse(k);
}