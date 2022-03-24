#include <iostream>
using namespace std;
int main()
{
    int q = 1;
    double graos = 1, a = 1;

    do
    {
        a *= 2;
        graos = graos + a;
        q++;

    } while (q <= 64);

    cout << graos << endl;

    return 0;
}
