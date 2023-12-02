#include <iostream>
using namespace std;
// this is paramiterise constructor
class newconst
{
public:
    int n;
    newconst(int n)
    {
        this->n = n;
    }
    int setn(int n2) // function for setting val of n
    {
        n = n2;
    }
    int getn() // getting val of
    {
        return n;
    }
};

int main()
{

    // newconst n1;

    return 0;
}