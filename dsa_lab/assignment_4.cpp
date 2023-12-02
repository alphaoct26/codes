#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node *addNode(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}

Node *addNumbers(Node *num1, Node *num2)
{
    Node *result = nullptr;
    int carry = 0;

    while (num1 || num2 || carry)
    {
        int sum = carry;
        if (num1)
        {
            sum += num1->data;
            num1 = num1->next;
        }
        if (num2)
        {
            sum += num2->data;
            num2 = num2->next;
        }

        carry = sum / 10000;
        sum = sum % 10000;

        result = addNode(result, sum);
    }

    return result;
}

int main()
{
    Node *num1 = nullptr;
    Node *num2 = nullptr;

    // Create the linked lists for the numbers
    int number1 = 681325468132;
    int number2 = 123456789012;

    vector<int> digits1, digits2;

    while (number1 > 0)
    {
        digits1.push_back(number1 % 10000);
        number1 /= 10000;
    }

    while (number2 > 0)
    {
        digits2.push_back(number2 % 10000);
        number2 /= 10000;
    }

    for (int i = digits1.size() - 1; i >= 0; i--)
    {
        num1 = addNode(num1, digits1[i]);
    }

    for (int i = digits2.size() - 1; i >= 0; i--)
    {
        num2 = addNode(num2, digits2[i]);
    }

    // Add the numbers and print the result
    Node *result = addNumbers(num1, num2);

    while (result)
    {
        cout << result->data << " ";
        result = result->next;
    }

    return 0;
}
