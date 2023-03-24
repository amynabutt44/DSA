#include <iostream>
using namespace std;
template <typename T,typename R>
class dictionaryPair
{
	T key;
	R value;
public:
	dictionaryPair()
	{

	}
	dictionaryPair( T k, R v)
	{
		key = k;
		value = v;
	}
	void setkey( T k)
	{
		key = k;
	}
	void setvalue(R v)
	{
		value = v;
	}
	T getkey()
	{
		return key;
	}
	 R getvalue()
	{
		 return value;
	}
};
template <typename T ,typename R>
class genericDictionary
{
	dictionaryPair<T, R>* data;
	int capacity;
	int noofitems;
	void resize()
	{
		int newcapacity;
		if (capacity == 0)
		{
			newcapacity = 1;
		}
		else
		{
			newcapacity = capacity * 2;
		}
		dictionaryPair<T, R>* ptr = new dictionaryPair<T, R>[newcapacity];
		for (int i = 0; i < noofitems; i++)
		{
			ptr[i].setkey(data[i].getkey());
			ptr[i].setvalue(data[i].getvalue());
		}
		delete[] data;
		data = ptr;
		capacity = newcapacity;

	}
	int indexcheck(T k)
	{
		for (int i = 0; i < noofitems; i++)
		{
			if (data[i].getkey() == k)
			{
				return i;
			}
		}
		return -1;
	}
public:
	genericDictionary()
	{
		data = nullptr;
		capacity = 0;
		noofitems = 0;
	}
	bool isfull()
	{
		return noofitems == capacity;
	}
	bool isempty()
	{
		return noofitems == 0;
	}
	~genericDictionary()
	{
		if (data)
		{
			delete[] data;
		}
		data = nullptr;
		noofitems = 0;
		capacity = 0;
	}
	void addpair(T k, R v)
	{
		int x = indexcheck(k);
			if (x == -1)
			{
				if (isempty())
				{
					resize();
				}
				if (isfull())
				{
					resize();
				}
				data[noofitems].setvalue(v);
				data[noofitems].setkey(k);
				noofitems++;
			}
			else
			{
				data[x].setvalue(v);
			}
		
	}
	R getvalue(T k)
	{
		int x = indexcheck(k);
		if (x != -1)
		{
			return data[x].getvalue();
		}
		exit(0);
	}
	void print()
	{
		for (int i = 0; i < noofitems; i++)
		{

			cout << data[i].getvalue() << " " << data[i].getkey();
			cout << endl;
		}
	}
};

int main()
{
	genericDictionary<string, int>grocery;
	grocery.addpair("apple", 98);
	grocery.addpair("orange", 45);
	grocery.print();
}