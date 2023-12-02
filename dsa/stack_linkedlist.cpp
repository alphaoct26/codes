#include <bits/stdc++.h>
using namespace std;

class stnode
{
public:
    int data;
    stnode *next;

    stnode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~stnode()
    {
        if (this->next = NULL)
        {
            delete next;
            this->next = next;
        }
    }
};
bool isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
stnode *top = NULL;
void push(stnode *&tail, int d)
{
    stnode *temp = new stnode(d);
    tail->next = temp;
    tail = temp;
}

void print(stnode *&head)
{
    stnode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void pop(stnode *&head)
{
    stnode *temp = NULL;
    if (isEmpty())
    {
        cout << "stack underflow" << endl;
        cout << temp << endl;
    }
    else
    {
        temp = top;
        top = top->next;
        cout << temp << endl;
    }
}

int main()
{
    stnode *node1 = new stnode(32);
    stnode *head = node1;
    stnode *tail = node1;
    push(tail, 131);
    push(tail, 132);
    push(tail, 134);
    print(head);
    pop(head);
    return 0;
}