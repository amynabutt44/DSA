#include <iostream>
using namespace std;

template <typename T>
class NDArray
{
	T* data;
	int noOfDimensions;
	int* sizeOfDimensions;
	int* startingIndex;
	int getRowMajorIndexMapping(const initializer_list<int>& list)const
	{
		int index = 0;
		int sum = 0;
		int number;
		for (auto idx : list)
		{
			number = idx - startingIndex[index];
			for (int j = index + 1; j < noOfDimensions; j++)
			{
				number = number * sizeOfDimensions[j];
			}
			sum += number;
			index++;
		}
		return sum;
	}
	bool isValidDimension(int idx)const
	{
		if (idx >= 0 && idx < noOfDimensions)
		{
			return true;
		}
		return false;
	}
public:
	NDArray(const initializer_list<int>l1 = {}, const initializer_list<int>l2 = {})
	{
		noOfDimensions = l1.size();

		if (l1.size() == 0)
		{
			noOfDimensions = 0;
			data = nullptr;
		}
		else
		{
			sizeOfDimensions = new int[noOfDimensions];
			startingIndex = new int[noOfDimensions];
			int i = 0;
			for (auto val : l1)
			{
				sizeOfDimensions[i] = val;

				i++;
			}
		}
		int size = 1;
		for (int i = 0; i < noOfDimensions; i++)
		{
			size *= sizeOfDimensions[i];
		}
		data = new T[size];
		if (l2.size() == 0)
		{
			for (int i = 0; i < noOfDimensions; i++)
			{
				startingIndex[i] = 0;
			}
		}
		else
		{
			int i = 0;
			for (auto val : l2)
			{
				startingIndex[i] = val;

				i++;
			}
		}
	}
	NDArray(const NDArray<T>& ref)
	{
		if (ref.data == nullptr)
		{
			this->~NDArray();
			return;
		}
		noOfDimensions = ref.noOfDimensions;
		sizeOfDimensions = new int[noOfDimensions];
		startingIndex = new int[noOfDimensions];

		for (int i = 0; i < noOfDimensions; i++)
		{
			sizeOfDimensions[i] = ref.sizeOfDimensions[i];
			startingIndex[i] = ref.startingIndex[i];
			data[i] = ref.data[i];
		}

	}
	NDArray<T>& operator=(const NDArray<T>& ref)
	{
		if (ref.data == nullptr)
		{
			this->~NDArray();
			return *this;
		}
		if (ref.data == *this)
		{
			return *this;
		}
		noOfDimensions = ref.noOfDimensions;
		sizeOfDimensions = new int[noOfDimensions];
		startingIndex = new int[noOfDimensions];

		for (int i = 0; i < noOfDimensions; i++)
		{
			sizeOfDimensions[i] = ref.sizeOfDimensions[i];
			startingIndex[i] = ref.startingIndex[i];
			data[i] = ref.data[i];
		}
		return *this;

	}
	int getNumberOfDimensions()const
	{
		return noOfDimensions;
	}
	int getDimensionSize(int i)const
	{
		if (isValidDimension(i))
		{
			return sizeOfDimensions[i];
		}
		exit(0);
	}
	int getDimensionLowerIndex(const int dimension)
	{
		if (isValidDimension(dimension))
		{
			return startingIndex[dimension];
		}
		exit(0);
	}
	int getDimensionHigherIndex(const int dimension)
	{
		if (isValidDimension(dimension))
		{
			return (startingIndex[dimension] + (sizeOfDimensions[dimension] - 1));
		}
	}
	bool isIndexBoundsValid(const initializer_list<int>& list)
	{

		int i = 0;
		for (auto index : list)
		{
			if (!(index >= getDimensionLowerIndex(i) && index <= getDimensionHigherIndex(i)))
			{
				return false;
			}
			i++;
		}
		return true;
	}
	T& operator()(const initializer_list<int>& list)
	{
		int index = getRowMajorIndexMapping(list);
		return data[index];
	}
	const T& operator()(const initializer_list<int>& list)const
	{
		int index = getRowMajorIndexMapping(list);
		return data[index];
	}

	~NDArray()
	{
		if (data)
		{
			data = nullptr;
		}
		delete[]data;
		if (sizeOfDimensions)
		{
			sizeOfDimensions = nullptr;
		}
		delete[]sizeOfDimensions;

		if (startingIndex)
		{
			startingIndex = nullptr;
		}
		delete[]startingIndex;
		noOfDimensions = 0;
	}

};
int main()
{
	//NDArray<int>b({2,4},{5,-1});
//1ST SAMPLE RUN
	// cout<<"Number Of Dimensions : "<<b.getNumberOfDimensions()<<endl;
//    
//     for(int i=0;i<b.getNumberOfDimensions();i++) 
//     {
//     	cout<<"Dim #"<<i<<"  size="<<b.getDimensionSize(i)<<" Index Range= ("<<b.getDimensionLowerIndex(i)<<" ~ "<<b.getDimensionHigherIndex(i)<<")"<<endl;
//     }

//for(int i=b.getDimensionLowerIndex(0);i<=b.getDimensionHigherIndex(0);i++)
//{
//    for(int j=b.getDimensionLowerIndex(1);j<=b.getDimensionHigherIndex(1);j++)
//    {
//       cout<<"["<<i<<":"<<j<<"]= ";
//       cin>>b({i,j});	
//    }
//}

//for(int i=b.getDimensionLowerIndex(0);i<=b.getDimensionHigherIndex(0);i++)
//{
//    for(int j=b.getDimensionLowerIndex(1);j<=b.getDimensionHigherIndex(1);j++)
//    {
//       cout<<b({i,j})<<"\t";
//    }
//    cout<<"\n";
//}

//Sample 3
 //NDArray<int> b({2,4},{-3,2});
// b({1,2})=78;


	//SAMPLE RUN4

  /*NDArray<int> b({2,4,3},{2,7});
	cout<<"Number Of Dimensions : "<<b.getNumberOfDimensions()<<endl;

	 for(int i=0;i<b.getNumberOfDimensions();i++)
	 {
		cout<<"Dim #"<<i<<"  size="<<b.getDimensionSize(i)<<" Index Range= ("<<b.getDimensionLowerIndex(i)<<" ~ "<<b.getDimensionHigherIndex(i)<<")"<<endl;
	 }*/




	 //SAMPLE RUN5
	/*NDArray<int> b({2,4},{2,7,9});
	cout<<"Number Of Dimensions : "<<b.getNumberOfDimensions()<<endl;

	 for(int i=0;i<b.getNumberOfDimensions();i++)
	 {
		cout<<"Dim #"<<i<<"  size="<<b.getDimensionSize(i)<<" Index Range= ("<<b.getDimensionLowerIndex(i)<<" ~ "<<b.getDimensionHigherIndex(i)<<")"<<endl;
	 }*/

	 //SAMPLE RUN 6
  //NDArray<int> a;
//     cout<<"Number of Dimensions = "<<a.getNumberOfDimensions();


	 //SAMPLE RUN 7
	NDArray<int> a({ 5 });
	for (int i = a.getDimensionLowerIndex(0); i <= a.getDimensionHigherIndex(0); i++)
	{
		cout << "[" << i << "]: ";
		cin >> a({ i });
	}

	for (int i = a.getDimensionLowerIndex(0); i <= a.getDimensionHigherIndex(0); i++)
	{
		cout << a({ i }) << ",";
	}

	return 0;
}