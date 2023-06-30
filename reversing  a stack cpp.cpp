#include <iostream>
#include <stack>
using namespace std;
void insertatbottom(stack<int>& stack, int element)
{
    if (stack.empty())
    {
        stack.push(element);
        return;
    }
    int num = stack.top();
    stack.pop();
    insertatbottom(stack, element);
    stack.push(num);

}
void reverseStack(stack<int>& stack) {
    // Write your code here
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertatbottom(stack, num);
}
int main()
{
	stack<int> one;
	
		one.push(3);
        one.push(1);
        one.push(2);
	
	cout << " reversing a stack";
	for (int i = 0; i < 3; i++)
	{
		cout << one.top() << endl;
		one.pop();
	}
}