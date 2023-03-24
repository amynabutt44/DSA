#include <iostream>
using namespace std;
void leader(int* ptr, int size)
{
	int max = ptr[size - 1];
	cout << "the leader is" << endl;
	for (int i = size - 2; i >= 0; i--)
	{
		if (ptr[i] > max)
		{
			max = ptr[i];
			cout << ptr[i] << " ";
		}
	}
}
int main()
{
	int n = 0;
	cout << "enter the size of an array" << endl;
	cin >> n;
	cout << "enter values for the array" << endl;
	int* ptr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> ptr[i];
	}
	leader(ptr, n);

}
