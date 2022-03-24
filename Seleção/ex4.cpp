#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, d, aPar, bPar, cPar, dPar, n;
    
    cin >> a >> b >> c >> d;

    n = (abs(a) + abs(b) + abs(c) + abs(d));

    aPar = (a % 2 == 0 ? a : n);
    bPar = (b % 2 == 0 ? b : n);
    cPar = (c % 2 == 0 ? c : n);
    dPar = (d % 2 == 0 ? d : n);

    if (aPar < (bPar, cPar, dPar))
    {
        cout << aPar << endl;
    }
    else
        if (bPar < (cPar, dPar))
        {
            cout << bPar << endl;
        }
        else
            if (cPar < dPar)
            {
                cout << cPar << endl;
            }
            else 
                if (dPar < (aPar,bPar,cPar))
                {
                    cout << dPar << endl;
                }
                else
                    if ((aPar == n) && (bPar == n) && (cPar == n) && (dPar == n))
                    {
                    cout << "Todos numeros impares";
                }
                
    return 0;
}