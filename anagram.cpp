
#include<iostream>
using namespace std;
bool checkingpalindrome(string n)
{
	int left = 0;
	int right = n.length() - 1;
	while (left < right)
	{
		if (n[left] != n[right])
			return false;
		left++;
		right--;
	}
	return true;
}
int main()
{
	if(checkingpalindrome("amnma"))
		cout<<(" yeah its palindrome");

		
}
