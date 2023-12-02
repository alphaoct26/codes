#include <bits/stdc++.h>
using namespace std;
class elements
{
public:
    int i;
    int j;
    int x;
};
class sparse
{
private:
    int m;
    int n;
    int nums;
    elements *el;

public:
    sparse(int m, int n, int nums)
    {
        this->m = m;
        this->n = n;
        this->nums = nums;
        el = new elements[this->nums];
    }
    ~sparse()
    {
        delete[] el;
    }
    void input()
    {
        cout << "rows||colums||value " << endl;
        for (int i = 0; i < nums; i++)
        {

            cin >> el[i].i >> el[i].j >> el[i].x;
        }
    }
    void display()
    {
        cout << endl;
        int k = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (el[k].i == i && el[k].j == j)
                    cout << el[k++].x << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
int main()
{
    sparse s1(2, 2, 2);
    s1.input();
    s1.display();

    return 0;
}