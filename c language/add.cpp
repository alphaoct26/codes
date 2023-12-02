
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cout << endl;
    while (t--)
    {
        int n;
        int count = 0;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            int r;
            float t;
            r += a[i];
            t = (r / (i + 1)) * 100;
            if (t == 100)
            {
                count++;
            }
        }
        cout << count;
    }
    return 0;
}
