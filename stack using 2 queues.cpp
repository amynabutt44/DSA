#include <iostream>
#include <queue>
using namespace std;
class mystack
{
	queue<int> q1;
	queue<int> q2;
public:
	void push(int val)
	{
		while (!q1.empty())
		{
			q2.push(q1.front());
				q1.pop();
		}
		q1.push(val);
		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}
	int pop()
	{
		int ans = q1.front();
		q1.pop();
		return ans;

	}
	bool empty()
	{
		return q1.empty();
	}

};
int main()
{
	

  mystack* obj = new mystack();
  obj->push(1);
  int param_2 = obj->pop();
  cout << param_2 << endl;
  obj->push(2);
  obj->push(3);
  cout << obj->pop() << endl;
  bool param_4 = obj->empty();
 
}