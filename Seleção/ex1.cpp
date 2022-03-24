#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float p, pFinal;
    int c;

    cin >> p >> c;
    switch (c)
    {
    case 1:
        pFinal = p - (p * 0.1);
        break;
    case 2:
        pFinal = p - (p * 0.05);
        break;
    case 3:
        pFinal = p;
        break;
    case 4:
        pFinal = p + (p * 0.1);
        break;
    }
    cout << pFinal << endl;   
    return 0;
}