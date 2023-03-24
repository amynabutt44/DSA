#include <iostream>
using namespace std;
template <typename T>
class GenericArray
{
	T* data;
	
	int capacity;
	bool isvalidindex(int index)
	{
		return index >= 0 && index < capacity;
	}
public:
	GenericArray()
	{
		
		data = nullptr;
		capacity = 0;
	}
	GenericArray(int size)
	{
		if (size <= 0)
		{
			return;
		}
		
		capacity = size;
		data = new T[capacity];
	}
	~GenericArray()
	{
		if (data)
		{
			delete[]data;

		}
	   data = nullptr;
	   capacity = 0;
	  
	}
	void resize(int newcap)
	{
		if (newcap <= 0)
		{
			if (data)
			{
				delete[]data;

			}
			data = nullptr;
			capacity = 0;

			return;
		}
		T* ptr = new T[newcap];
		if (capacity > 0)
		{
			int size = newcap < capacity ? newcap : capacity;
			for (int i = 0; i < size; i++)
			{
				ptr[i] = data[i];
			}
		}
	
		if (data)
		{
			delete[]data;

		}
		data = nullptr;
		capacity = 0;

		data = ptr;
		capacity = newcap;
	}
	GenericArray(const  GenericArray <T>& ref)
	{
		if (ref.data == nullptr)
		{
			data = nullptr;
			capacity = 0;
			return;
		}
		capacity = ref.capacity;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			data[i] = ref.data[i];
		}
	}
	int getcapacity()
	{
		return capacity;
	}
	T& operator[](int index)
	{
		if (isvalidindex(index))


		{
			return data[index];
		}
		exit(0);
	}
	GenericArray <T>& operator= (GenericArray<T>  &rhs)
	{ 
		if (this == &rhs)
		{
			return * this;
		}
		~GenericArray();
		if (rhs.data == nullptr)
		{
			capacity = 0;
			data = nullptr;
			return *this;
		}
		capacity = rhs.capacity;
		data = new T[capacity];
		for (int i = 0; i < capacity; i++)
		{
			data[i] = rhs.data[i];
		}

		return *this;
	}
	void setdata(T v, int index)
	{
		if (index >= capacity)
		{
			resize(capacity * 2);
		}
		data[index] = v;
		
		
		/*if (index >= capacity)
		{
			resize(capacity * 2);
		}
		if (isvalidindex(index))
		{
			data[index] = v;
		}

		exit(0);*/
	}
	T getdata(int index)
	{
		if(isvalidindex(index))
			return data[index];
		
		exit(0);
	}

};
int main()
{
	GenericArray<int> pair(5);
	for (int i = 0; i < 6; i++)
	{
		pair.setdata(i, i);
	}
	cout << "          _____________________        " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout<<pair.getdata(i)<<endl;
	}
	
}