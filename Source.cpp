#include <iostream>
#include <initializer_list>
using namespace std;
template<typename T>
class NDArray
{
	T* data;
	int  noofdimensions;
	int* sizeofdimensions;
	int* startingindexofdimensions;
	int rowmapping(const initializer_list <int>& a)
	{
		int number = 0;
		int index = 0;
		int sum = 0;
		for (auto b : a)
		{
			number= b-startingindexofdimensions[index]
				for (int i = index + 1; i < noofdimensions; i++)
				{
					number *= sizeofdimensions[i];
			    }
			sum += number;
		}
		return sum;
	}

public:
	NDArray(const initializer_list<int> list = {}, const initializer_list<int> list2 = {})
	{
		noofdimensions = list.size();
		if (noofdimensions == 0)
		{
			sizeofdimensions = nullptr;
			data = nullptr;

		}
		else
		{
			sizeofdimensions = new int[noofdimensions];
			startingindexofdimensions = new int[noofdimensions];
			int i = 0;
			for (auto a : list)
			{
				sizeofdimensions[i] = a;
				i++;
			}
			
		}
		int size = 1;
		for (int j = 0; j < noofdimensions; j++)
		{
			size *= noofdimensions[j];
		}
		data = new T[size];
		if (list2.size() == 0)
		{
			
			for (int i = 0; i < noofdimensions; i++)
			{
				startingindexofdimensions[i] = 0;
			}
		}
	
		else
		{
			int j = 0;
			for (auto a : list2)
			{
				startingindexofdimensions[i] = a;
				j++;
			}
		}
	}
	NDArray(const NDArray<T>& a)
	{
		if (a.data = nullptr)
		{
			this->~NDArray();
		}
		noofdimensions = a.noofdimensions;
		startingindexofdimensions = new int[noofdimensions];
		sizeofdimensions = new int[noofdimensions];
		int size = 1;
		for (int i = 0; i < a.noofdimensions; i++)
		{
			size *= a.noofdimensions[i];
		}
		data = new T[size];
		for (int i = 0; i < noofdimensions; i++)
		{
			sizeofdimensions[i] = a.sizeofdimensions[i];
			noofdimensions[i] = a.noofdimensions[i];
			data[i] = a.data[i];
		}
	}
	NDArray<T>& operator=(const NDArray <T>& a)
	{
		if (a.data = nullptr)
		{
			this->~NDArray();
		}
		if (this == &a)
		{
			return *this;
		}
		noofdimensions = a.noofdimensions;
		startingindexofdimensions = new int[noofdimensions];
		sizeofdimensions = new int[noofdimensions];
		int size = 1;
		for (int i = 0; i < noofdimensions; i++)
		{
			size *= noofdimensions[i];
		}
		data = new T[size];
		for (int i = 0; i < noofdimensions; i++)
		{
			sizeofdimensions[i] = a.sizeofdimensions[i];
			noofdimensions[i] = a.noofdimensions[i];
			data[i] = a.data[i];
		}
	}
	int getnumberofdimension()
	{
		return noofdimensions;
	}
	int getsizeofdimension(int i)
	{
		return sizeofdimensions[i];
	}
	int getdimensionlowerindex(int i)
	{
		return startingindexofdimensions[i];
	}
	int gethigherindexdimension(int i)
	{
		return startingindexofdimensions[i] + sizeofdimensions[i] - 1;
	}
	bool isvalidindex(initializer_list <int> &list)
	{
		int i = 0;
		for (auto a : list)
		{
			if (!(a >= getdimensionlowerindex[i] && a <= getdimensionlowerindex[i]))
			{
				return false;
			}
			return true;
		}
	}
	~NDArray()
	{
		delete[]data;
		delete[]noofdimensions;
		delete[]startingindexofdimensions;
		data = nullptr;
		noofdimensions = nullptr;
		startingindexofdimensions = nullptr;
		noofdimensions = 0;
	}
	T& operator()(const initializer_list<int>& a)
	{
		int index = rowmapping(a);
		return data[i];
	}
};

int main()
{

}
