#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int>& myStack, int x)
{
    //base case
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
     // recurssive call
    solve(myStack, x);
    myStack.push(num);

}
stack<int> pushAtBottom(stack<int>& myStack, int x)
{
    /*stack<int > two;
    while (!myStack.empty())
    {
        two.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    while (!two.empty())
    {
        myStack.push(two.top());
        two.pop();
    }*/
    solve(myStack, x);
    return myStack;
}
int main()
{
    stack<int> one;
    for (int i = 0; i < 5; i++)
    {
        one.push(i + 1);
    }
    solve(one, 6);
    cout << " after inserting a number at the bottom of the stack ";
    for (int i = 0; i < 6; i++)
    {
       cout<< one.top();
       one.pop();
    }

}