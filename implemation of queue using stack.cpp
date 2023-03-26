#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s1.empty())
            return-1;
        else
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();

            }
        int temp = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();

        }
        return temp;
    }

    int peek() {
        int temp = pop();
        return temp;
    }

    bool empty() {
        return s1.empty();
    }
};
int main()
{
    MyQueue* obj = new MyQueue();
    for (int i = 0; i < 5; i++)
    {
        obj->push(i + 2);
    }
    for (int i = 0; i < 5; i++)
    {
        cout << obj->pop() << " ";
    }
}
