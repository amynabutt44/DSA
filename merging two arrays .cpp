#include<iostream>
using namespace std;
void merge(int* a, int* b, int size, int size2)
{
	int m = 0;
	int n = 0;
	int k = 0;

	int* ptr = new int[m + n ];
	while (m < size && n <size2)
	{
		
		if (a[m] >= b[n])
		{
		
			ptr[k] = b[n];
			k++;
			n++;
		}
		else
		{
			
			ptr[k] =a[m];
			m++;
			k++;
		}
	}
	while (n != size2)
	{
		ptr[k] = b[n];
		n++;
		k++;

	}
	while (m != size)
	{
		ptr[k] = a[m];
		k++;
		m++;
	}
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		
		cout << ptr[i] << endl;
	}
}
int main()
{
	
	int* a = new int[5];
	
	int* b = new int[5];
	b[0] = 2;
	b[1] = 4;
	b[2] = 6;
	b[3] = 8;
	b[4] = 10;
	a[0] = 3;
	a[1] = 5;
	a[2] = 7;
	a[3] = 9;
	a[4] = 11;
	


	cout << "  first array" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "  second array" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << b[i] << " ";
	}
	merge(a, b, 5, 5);
}