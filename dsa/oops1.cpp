#include <iostream>
using namespace std;
class fist
{
public:
    int n;
    char ch;

    // fist(int n)
    // {
    //     this->n = n;
    // }
    // consructer

    fist()
    {
        cout << " consrtructor callled " << endl;
    }
    // parameterised constructor

    fist(int n)
    {
        cout << "this -> " << this << endl;
        this->n = n; // this stores address of current object
        // if you want to acesss the data memeber or current object then this use
        // besically ""this"" is used as pointer to point to current object
    }

    int setn(int n2) // function for setting val of n
    {
        n = n2;
    }

    char setp(int p2) // function for setting val of p
    {
        ch = p2;
    }

    char getp() // getting val of p
    {
        return ch;
    }

    int getn() // getting val of
    {
        return n;
    }
};

int main()
{
    // this object created statically
    fist f1; // this is creating object //boz of this constructor is called
    // this object is callled dynamically
    cout << "address of" << &f1 << endl; // this is address of our n
    f1.getn();
    fist *f = new fist;
    // dnyamic memmory allocation
    fist *newval = new fist(3436);
    // cout << "addres of me " << &vaibhav;
    // vaibhav.getn();
    // satic memory allocation
    //     f1.setn(13);
    // f1.setp(3);
    // cout << "\n";
    // cout << "val :" << f1.getn() << endl;
    // cout << "val :" << f1.getp() << endl;
    // cout << "\n";

    // newval->setn(565);
    // newval->setp('A');
    // cout << "val :" << newval->getn() << endl;
    // cout << "val :" << newval->getp() << endl;
    // cout << "\n";
    return 0;
}