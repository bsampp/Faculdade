#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x, x1, x2, x3, x4;

    cin >> x;
    x1 = ((x / 1000) % 10);
    x2 = ((x / 100) % 10);
    x3 = ((x / 10) % 10);
    x4 = ((x / 1) % 10);

    if (x1 == x4 && x2 == x3)
    {
        cout << "E um capicua." << endl;    
    }
    else
    {
        cout << "Nao e um capicua." << endl;
    }
    
    return 0;
}
