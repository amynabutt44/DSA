#include <iostream>
#include<queue>
#include<stack>
using namespace std;
queue <int>  reverse(queue<int> q)
{
	stack<int> st;
	while (!q.empty())
	{
		int element = q.front();
		q.pop();
		st.push(element);
	
	}
	while (!st.empty())
	{
		int elemnt = st.top();
		st.pop();
		q.push(elemnt);
	}
	return q;
}
int main()
{
	queue<int> qs;
	qs.push(3);
	qs.push(4);
	qs.push(5);
	qs.push(6);
	reverse(qs);
	cout<<qs.front();
	qs.pop();
	cout << qs.front();
	qs.pop();
	cout << qs.front();
	qs.pop();
}
