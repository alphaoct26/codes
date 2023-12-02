#include <bits/stdc++.h>
using namespace std;
#define size 10
class Stack
{
public:
    int *arr;
    int top;

    // creation of stack
    Stack()
    {

        arr = new int[size];
        top = -1;
    }

    // inserting elements in array
    void push(int a)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = a;
        }
        else
        {
            cout << "stack is overflowed" << endl;
        }
    }

    // removing the top most element
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "no data in stack" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack st;

    st.push(32);
    st.push(12);
    st.push(43);
    st.push(31);
    st.peek();

    return 0;
}