#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void n_of_node(node *&head)
{
    node *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    cout << n << endl;
    
}

void insert_at_front(node *&head, int a)
{
    node *temp = new node(a);
    temp->next = head;
    head->prev = temp;
    temp = head;
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

main()
{
    node *node1 = new node(10);
    node *head = NULL;
    node *tail = NULL;
    print(head);
    insert_at_front(head, 23);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << "number of node: ";
    n_of_node(head);

    return 0;
}