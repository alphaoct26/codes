#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        if (this->next = NULL)
        {
            delete next;
            this->next = next;
        }
    }
};

void insert_front(node *&head, int a)
{
    node *temp = new node(a);
    temp->next = head;
    head = temp;
}

void insert_end(node *&tail, int b)
{
    node *temp = new node(b);
    tail->next = temp;
    tail = temp;
}

void insert_at_pos(node *&tail, node *&head, int pos, int c)
{
    node *temp = head;
    int cnt = 1;
    if (pos == 1)
    {
        insert_front(head, c);
    }

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insert_end(tail, c);
        return;
    }
    node *node_in = new node(c);
    node_in->next = temp->next;
    temp->next = node_in;
}

void deletion(node *&head, node *&tail, int pos)
{
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        int cnt = 1;
        node *curr = head;
        node *prev = NULL;
        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if (curr->next != NULL)
        {

            curr->next = NULL;
        }
        else
        {
            tail = prev;
        }
        delete curr;
    }
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    cout << endl;
    node *node1 = new node(32);
    node *head = node1;
    node *tail = node1;
    print(head);
    insert_front(head, 31);
    print(head);
    insert_front(head, 30);
    print(head);
    insert_end(tail, 34);
    print(head);
    insert_at_pos(tail, head, 4, 33);
    print(head);
    deletion(head, tail, 2);
    print(head);
    insert_end(tail, 12);
    print(head);
    deletion(head, tail, 3);
    print(head);
    cout << endl;
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    return 0;
}