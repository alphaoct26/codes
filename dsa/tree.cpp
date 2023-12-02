#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *buildTree(Node *root)
{

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    cout << endl;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void leveltravel(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data;
        inorder(root->left);
        inorder(root->right);
    }
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        inorder(root->right);
        cout << root->data;
    }
}
void levelordertreebuild(Node *root)
{
    queue<Node *> q2;
    cout << "enter data ";
    int data;
    cin >> data;
    root = new Node(data);
    q2.push(root);

    while (!q2.empty())
    {
        Node *temp = q2.front();
        q2.pop();
        cout << "enter the data for " << root->data << endl;
        int leftdata;
        cin >> leftdata;
        if (!leftdata == -1)
        {
            temp->left = new Node(leftdata);
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    cout << "level travelsing :  \n", leveltravel(root);
    cout << endl;
    cout << "preorder travelsing :  \n", preorder(root);
    cout << endl;
    cout << "postorder travelsing :  \n", postorder(root);
    cout << endl;
    cout << "inorder travelsing :  \n", inorder(root);

    return 0;
}