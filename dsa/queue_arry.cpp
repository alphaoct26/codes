#include <bits/stdc++.h>
using namespace std;
#define size 100
class Queue
{
private:
    int *arr;
    int back;
    int front;

public:
    Queue()
    {
        front = -1;
        back = -1;
        arr = new int[size];
    }

    void enqueue(int a)
    {
        if (back == size - 1)
        {
            cout << "stack is overflowed" << endl;
        }
        else
        {
            back++;
            arr[back] = a;
        }
        if (front == -1)
        {
            front++;
        }
    }

    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "no elements are present in the queue" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "no elements are present in the queue" << endl;
            return 0;
        }
        else
        {
            cout << arr[front] << endl;
        }
    }

    void empty()
    {
        if (front == -1 || front > back)
        {
            cout << "empty" << endl;
            return;
        }
        else
        {
            cout << "elements are present";
        }
    }
    void diplay(class Queue q1)
    {

        int p;
        for (int i = front; i <= back; i++)
        {
            p = q1.peek();
            q1.dequeue();
        }
        cout << " ";
    }
};
int main()
{
    Queue q1;
    q1.enqueue(32);
    q1.enqueue(12);
    q1.enqueue(90);
    q1.enqueue(72);
    q1.enqueue(92);
    q1.enqueue(74);
    cout << "front of queue: ", q1.peek();
    q1.diplay(q1);

    return 0;
}