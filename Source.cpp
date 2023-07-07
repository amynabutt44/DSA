#include <iostream>
#include<math.h>
using namespace std;
bool binarysearch(int * ptr, int start, int end,int key)
{
	
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (ptr[mid] == key)
			return true;
		else if (ptr[mid] > key)
		{
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return false;
}
int main()
{
	/*int n;
	int ans = 0;
	int i = 0;
	cout << " enter  a number " << endl;
	cin >> n;
	while (n != 0)
	{
		int digit = n % 10;
		n = n / 10;
		if (digit == 1)
		{
			ans = ans + pow(2, i);
		}
		i++;
	}
	cout << ans;*/
	//int n;
	//int ans=0;
	//cout << " enter a number" << endl;
	//cin >> n;
	//for (int i = 0; n > 0; i++)
	//{
	//	int rem = n % 2;
	//	n = n / 2;
	//	ans = (rem * pow(10, i)) + ans;

	//}
	///*int digit = n & 1;
	//cout << digit;
	//ans =( digit * pow(10, 0));*/
	//cout << ans;
}