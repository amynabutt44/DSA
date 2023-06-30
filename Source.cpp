#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int>& inputStack, int size, int count)
{
    if (count == size)
    {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, size, count + 1);
    inputStack.push(num);
}

void deleteMiddle(stack<int>& inputStack, int N) {
    int size = N / 2;
    int count = 0;
    solve(inputStack, size, count);
}
//void deleteMiddle(stack<int>& inputStack, int N) {
//    int size = (N + 1) / 2;
//    stack<int> st;
//    int count = 0;
//    for (int i = 0; i < size; i++)
//    {
//        count++;
//        st.push(inputStack.top());
//        inputStack.pop();
//    }
//    inputStack.pop();
//    for (int i = 0; i < count; i++)
//    {
//        inputStack.push(st.top());
//        st.pop();
//    }
//}
int main()
{
    stack <int> inputstack;
    for (int i = 0; i < 5; i++)
    {
        inputstack.push(i + 1);

    }
   
    deleteMiddle(inputstack, 4);
    cout << " stack after deleting middle element ";
    for(int i=0;i<4;i++)
    {
        cout << inputstack.top()<<"  ";
        inputstack.pop();
    }
}