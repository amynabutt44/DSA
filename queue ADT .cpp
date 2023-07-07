#include<iostream>
using namespace std;
template<typename T>
class Queue
{
	T* data;
	int rear;
	int front;
	int noOfElements;
	  int  capacity;
	void resize(int NewSize)
	{
		T* temp = new T[NewSize];
		 int index = front;
		for (int i = 0; i < noOfElements; i++)
		{
			temp[i] = data[index];
			index = (index + 1) % capacity;
		}
		int temprear = noOfElements;
		int tempfront = 0;
		if (data)
		{
			delete[] data;
		}
		data = nullptr;
		front = rear = noOfElements = capacity = 0;
		data = temp;
		capacity = NewSize;
		front = tempfront;
		rear = temprear;
		noOfElements = temprear;
	}
public:
	Queue()
	{
		front = rear = noOfElements = capacity = 0;
		data = nullptr;
	}
	~Queue()
	{
		if (data)
		{
			delete[] data;
		}
		data = nullptr;
		front = rear = noOfElements = capacity = 0;
	}
	Queue(const Queue<T>& ref)
	{
		if (ref.data == nullptr)
		{
			data = nullptr;
			noOfElements = rear = front = capacity = 0;
		}
		capacity = ref.capacity;
		rear = ref.rear;
		noOfElements = ref.noOfElements;
		front = ref.front;
		int index = ref.front;
		 data  = new T[capacity];
		for (int i = 0; i < noOfElements; i++)
		{
			data[i] = ref.data[index];
			index = (index + 1) % capacity;
		}


	}
	Queue<T>& operator=(const Queue<T>& ref)
	{
		if (this == &ref)
			return *this;
		~Queue();
		if (ref.data == nullptr)
		{
			data = nullptr;
			noOfElements = rear = front = capacity = 0;
		}
		capacity = ref.capacity;
		rear = ref.rear;
		noOfElements = ref.noOfElements;
		front = ref.front;
		int index = ref.front;
			data = new T[capacity];
		for (int i = 0; i < noOfElements; i++)
		{
			data[i] = ref.data[index];
			index = (index + 1) % capacity;
		}
		return *this;
	}
	int getnoofelement()
	{
		return noOfElements;
	}
	int getcapacity()
	{
		return capacity;
	}
	bool isEmpty()
	{
		return noOfElements == 0;
	}
	bool isfull()
	{
		return noOfElements == capacity;
	}
	void enqueue(T val)
	{
		if (isfull())
		{
			resize(capacity == 0 ? 1 : capacity * 2);
		}
		data[rear] = val;
		rear = (rear + 1) % capacity;
		noOfElements++;
	}
	T dequeue()
	{
		if (isEmpty())
			exit(0);
		T val = data[front];
		front = (front + 1) % capacity;
		noOfElements--;
		if (noOfElements > 0 && noOfElements == capacity / 4);
		resize(capacity / 2);
		return val;
	}
	T getelelmntAtFront()const
	{
		if (isEmpty())
		{
			exit(0);
		}
		return data[front];
	}

};

int main()
{
	Queue<int> ap;
	ap.enqueue(12);
	ap.enqueue(34);
	ap.enqueue(56);
	cout << ap.dequeue();
	cout << ap.dequeue();
	cout << ap.dequeue();
	Queue<int> ab(ap);
	ab.enqueue(348);
	cout<<ab.dequeue();
}