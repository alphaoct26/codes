#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int i;
    int j;
    int x;
    Node *next;

    Node(int row, int col, int val)
    {
        i = row;
        j = col;
        x = val;
        next = NULL;
    }
};

class SparseMatrix
{
private:
    int m;
    int n;
    Node **rows;

public:
    SparseMatrix(int rows, int cols)
    {
        m = rows;
        n = cols;
        this->rows = new Node *[m];
        for (int i = 0; i < m; i++)
        {
            this->rows[i] = NULL;
        }
    }

    ~SparseMatrix()
    {
        for (int i = 0; i < m; i++)
        {
            Node *current = rows[i];
            while (current)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] rows;
    }

    void insert(int row, int col, int val)
    {
        if (row >= 0 && row < m && col >= 0 && col < n)
        {
            Node *newNode = new Node(row, col, val);
            newNode->next = rows[row];
            rows[row] = newNode;
        }
        else
        {
            cout << "Invalid position!" << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < m; i++)
        {
            Node *current = rows[i];
            int colIndex = 0;
            while (current)
            {
                if (current->j == colIndex)
                {
                    cout << current->x << " ";
                    current = current->next;
                }
                else
                {
                    cout << "0 ";
                }
                colIndex++;
            }
            cout << endl;
        }
    }
};


SparseMatrix Input()
{
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    SparseMatrix matrix(rows, cols);

    int numValues;
    cout << "Enter the number of values to insert: ";
    cin >> numValues;

    for (int i = 0; i < numValues; i++)
    {
        int row, col, val;
        cout << "Enter row, column, and value for element " << i + 1 << ": ";
        cin >> row >> col >> val;
        matrix.insert(row, col, val);
    }

    return matrix;
}
SparseMatrix Add()
{
    
}
int main()
{
    SparseMatrix s1 = Input();
    SparseMatrix s2 = Input();

    cout << "Sparse Matrix:" << endl;
    s1.display();

    return 0;
}
