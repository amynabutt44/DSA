#include<iostream>
using namespace std;
// so this program works as folow
// we conider a sorted array vo checking wether there exsist two numbers which sum ios equal
// the target or not 
bool checkingtarget(int* arr, int size, int target)
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int a = arr[left] + arr[right];
		if (a == target)
			return true;
		else if (a > target)
			right--;
		else
			left--;
	}
	return false;
}
int main()
{
	int* a;
	a = new int[5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 2;
	}
	if (checkingtarget(a, 5, 8))
		cout << (" ohh yeah target exsist ");
	else
		cout << (" :( no target not exsist");
}
//#include<iostream>
//using namespace std;
//bool checkingpalindrome(string n)
//{
//	int left = 0;
//	int right = n.length() - 1;
//	while (left < right)
//	{
//		if (n[left] != n[right])
//			return false;
//		left++;
//		right--;
//	}
//	return true;
//}
//int main()
//{
//	if(checkingpalindrome("amnma"))
//		cout<<(" yeah its palindrome");
//
//		
//}