#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    float y;
    

    cin >> x >> y;
    switch (x)
    {
    case 1:
        cout << fixed << setprecision(2) << "Total: R$ " << y*4 << endl;
        break;
    case 2:
        cout << fixed << setprecision(2) << "Total: R$ " << y*4.50 << endl;
        break;
    case 3:
        cout << fixed << setprecision(2) << "Total: R$ " << y*5 << endl;
        break;
    case 4:
        
        cout << fixed << setprecision(2) << "Total: R$ " << y*2 << endl;
        break;
    case 5:
        cout << fixed << setprecision(2) << "Total: R$ " << y*1.50 << endl;
        break;
    return 0;
    }
}