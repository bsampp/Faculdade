#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float n, m;
    int x, positivos;
    x = 0;
    positivos = 0;

    while (x < 6)
    {
        cin >> n;
        x++;
        if (n >= 0)
        {
            positivos++;
            m = (m + n);

        }
        
    }
    cout << positivos << " valores positivos" << endl;
    cout << fixed << setprecision(1) << m / positivos << endl;
    

    return 0;
}