#include <iostream>
using namespace std;
int profit(int* ptr, int size)
{
	int buyAtLeastPrice = INT_MAX;
	int maxprofit = 0;
	int profit = 0;
	for (int i = 0; i < size; i++)
	{
		if (ptr[i]<buyAtLeastPrice)
		{
			buyAtLeastPrice = ptr[i];
			cout << "the price of least " << buyAtLeastPrice << endl;
		}
		profit = ptr[i] - buyAtLeastPrice;
		cout << "the price of profit is " << profit<<endl;
		if (maxprofit<profit)
		{
			maxprofit = profit;
		}
		
	}
	return maxprofit;
}
int main()
{
	int* ptr = new int[6];
	ptr[0] = 7;
	ptr[1] = 1;
	ptr[2] = 5;
	ptr[3] = 3;
	ptr[4] = 6;
	ptr[5] = 4;
	cout << profit(ptr, 6);
	
}