#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < 4; i++)
        {
            int temp;
            if (a[0] < a[i])
            {
                a[i] = temp;
                temp = a[0];
            }
            cout << a[0];
        }
    }
    return 0;
}
