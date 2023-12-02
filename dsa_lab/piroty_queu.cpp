#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~node()
    {
    }
};
class que
{
public:
    int front = -1;
    int rear = 0;
    node *head = NULL;
    void insertion(int d)
    {
        node *temp = new node(d);
        if (head == NULL)
        {

            head = temp;

            front++;
            rear++;
        }
        if (d > head->data)
        {
            temp->next = head;
            head = temp;
            rear++;
        }
        if (d < head->data)
        {
            node *tent = head;
            node *temp1 = NULL;
            while (tent)
            {
                if (d < tent->data)
                {

                    temp1 = tent;
                }
                else
                {
                    break;
                }

                tent = tent->next;
            }
            temp1->next = temp;
            temp->next = tent;
            rear++;
        }
    }
    void display()
    {

        node *te = head;
        while (te)
        {
            cout << te->data << " ";
            te = te->next;
        }
        cout << " total element = " << rear << endl;
    }
    void pop()
    {
        node *temp = head;
        head = temp->next;
        rear--;
        delete temp;
    }
};
int main()
{
    que q;
    cout << " number of element u want to insert " << endl;
    int n;
    cin >> n;
    while (n)
    {
        int x;
        cout << " enter element"
             << " ";
        cin >> x;
        q.insertion(x);
        n--;
    }

    q.display();
    q.pop();
    q.display();
}