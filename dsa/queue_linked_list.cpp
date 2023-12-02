#include <bits/stdc++.h>
using namespace std;

class Qnode
{
public:
    int data;
    Qnode *next;

    Qnode(int a)
    {
        this->data = a;
        this->next = NULL;
    }
};
class Queue
{
public:
    Qnode *back;
    Qnode *front;
    Qnode *head;

    Queue()
    {
        back = front = NULL;
    }
    void enqueue(int b)
    {
        Qnode *temp = new Qnode(b);
        if (back == NULL)
        {
            front = back = temp;
            return;
        }
        back->next = temp;
        back = temp;
    }

    void dequeue()
    {

        if (back == NULL)
        {
            return;
        }

        Qnode *temp = front;
        front = front->next;
        if (front == NULL)
            back = NULL;
        delete (temp);
    }
};
void print(Qnode *&head)
{
    Qnode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Queue q1;
    q1.enqueue(32);
    q1.enqueue(42);
    q1.enqueue(65);
    q1.enqueue(21);
    q1.enqueue(89);
    q1.enqueue(65);
    q1.enqueue(54);
    cout << "Queue Front : " << ((q1.front != NULL) ? (q1.front)->data : -1) << endl;
    cout << endl;
    cout << "Queue back:" << ((q1.back != NULL) ? (q1.back)->data : -1) << endl;
    cout << endl;

    return 0;
}