#include <iostream>
using namespace std;

class student
{
    int money; // private data ascess through function

public:
    int id;
    string name;
    // function to obtain private data
    void setmoney(int mon) // setter
    {
        money = mon;
    }
    void getmoney() // gettter
    {
        cout << money << endl;
    }

    void printinfo()
    {
        getmoney();
        cout << id << endl;
        cout << name << endl;
    }
    /// default construtor
    student()
    {
        cout << "default constructor" << endl;
    }

    /// parametrised constructor
    student(int m, int i, string nam)
    {
        cout << "parametrised constructor";
        this->money = m;
        this->id = i;
        this->name = nam;
    }
    // copy constructor
    student(student &a)
    {
        cout << "copy constructor" << endl;
        this->money = a.money;
        this->id = a.id;
        this->name = a.name;
    }
    // destructor
    ~student()
    {
        cout << "destructor is called \n work of this is deallocating memoray " << endl;
    }
};

int main()
{

    cout << "\n";
    student c;
    cout << "\n";
    student a(323, 32, "bdj");
    a.printinfo();
    cout << "\n";
    student b(4211, 34, "oipo");
    cout << "\n";
    b.printinfo();
    student d(a);
    cout << "\n";
    d.printinfo();

    return 0;
}

// int n;
// cin >> n;
// student arr[n];
// for (int i = 0; i < n; i++)
// {
//     int mon;
//     cout << "money they have =" << endl;
//     cin >> mon;
//     arr[i].setmoney(mon);
//     cout << "id=" << endl;
//     cin >> arr[i].id;
//     cout << "name=" << endl;
//     cin >> arr[i].name;
// }

// for (int i = 0; i < n; i++)
// {
//     arr[i].printinfo();
// }