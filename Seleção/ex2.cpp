#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int p, s, b;

    cin >> p >> s >> b;
    switch (p)
    {
    case 1:
        p = 180;
        break;
    case 2:
        p = 230;
        break;
    case 3:
        p = 250;
        break;
    case 4:
        p = 350;
        break;            
    }
    switch (s)
    {
    case 1:
        s = 75;
        break;
    case 2:
        s = 110;
        break;
    case 3:
        s = 170;
        break;
    case 4:
        s = 200;
        break;            
    }
    switch (b)
    {
    case 1:
        b = 20;
        break;
    case 2:
        b = 70;
        break;
    case 3:
        b = 100;
        break;
    case 4:
        b = 65;
        break;            
    }
    cout << p + s + b << " Cal" << endl;

    return 0;
}