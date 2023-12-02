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
        front = 0;
        back = 0;
        arr = new int[size];
    }
    void enqueue(int a)
    {
        if ((back + 1) % size == front)
        {
            cout << "stack is overflowed" << endl;
        }
        else
        {
            back = (back + 1) % size;
            arr[back] = a;
        }
        if (front == 0)
        {
            front++;
        }
    }

    void dequeue()
    {
        if (front == 0 || front > back)
        {
            cout << "no elements are present in the queue" << endl;
            return;
        }
        front = (front + 1) % size;
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
        if (front == 0 || front > back)
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
        for (int i = (front + 1) % size; i <= (back + 1) % size; i++)
        {
            p = q1.peek();
            q1.dequeue();
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;
    q1.enqueue(23);
    q1.enqueue(54);
    q1.enqueue(36);
    q1.enqueue(32);
    q1.enqueue(67);
    q1.dequeue();
    cout << "front of queue: ", q1.peek();
    q1.diplay(q1);

    return 0;
}