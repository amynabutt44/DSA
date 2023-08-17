#include <iostream>
using namespace std;
class heap
{
	int arr[100];
	int size;
public:
	heap()
	{
		arr[0] = -1;
		size = 0;
	}


	void insertion(int val)
	{
		size = size + 1;
		int index = size;
		arr[index] = val;
		
		// sub sa pehla hum na last index par hum na usko add karna haan then hum na usko uski right place par rakhna haan 
		while (index >1)
		{
			
			int parent = index / 2;

			if (arr[parent] < arr[index])
			{
				swap(arr[parent], arr[index]);
				
				index = parent;
			}
			else
			{
				return;
			}
		}
	
	}
	// hum na jab bhi delete karna haan to hum na root ko delete karna haan than hum na 
	// change kardena haan sub sa end wLI KO 
	void deletion()
	{

		if (size == 0)
		{
			cout << "nothing to delete :( " << endl;
		}
		arr[1] = arr[size];
		size--;
		int index = 1;

		while (index < size)
		{
			int left = index * 2;
			int right = index * 2+1;
			if ( left<= size && arr[index] < arr[left] && arr[left] > arr[right])
			{
				swap(arr[left], arr[index]);
				index = left;

			}
			if (right<= size && arr[right] > arr[index] && arr[right] > arr[left])
			{
				swap(arr[right], arr[index]);
				index = right;

			}
			else
			{
				return;
			}
		}
	}
	// heapify sareya nodes ko uski jagha par leya jata haan 
	
	void diplay()
	{
		cout << " values are :  ";
		for (int i = 1; i <= size; i++)
		{
			cout << " " << arr[i] << " ";
		}
	}

};
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = i * 2;
	int right = i * 2 + 1;
	if (left <= n && arr[largest] < arr[left])
	{
		largest = left;
	}
	if (right <= n && arr[largest] < arr[right])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}

}
void heapsort(int arr[], int  n)
{
	int size = n;
	while (size > 1)
	{
		swap(arr[size], arr[1]);
		size--;
		heapify(arr, size , 1);
	}
}



int main()
{
	int arr[6] = { -1,54, 53 , 55,52,50 };
	int n = 5;
	for (int i = 5/ 2; i > 0; i--)
	{
		heapify(arr, n, i);
		}
	cout << " array is " << " :";
	for (int i = 1; i <=n; i++)
	{
		cout << arr[i] << " ";

	}
	cout << " heap sort" << endl;
	heapsort(arr, n);
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";

	}
	/*heap one;
	
	one.insertion(50);
	one.insertion(55);
	one.insertion(53);
	one.insertion(52);
	one.insertion(54);
	one.deletion();
	
	one.diplay();*/
}
    

