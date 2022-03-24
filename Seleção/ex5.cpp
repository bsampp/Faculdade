#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float imc, p, a;

    cin >> p >> a;
    
    imc = (p / (a*a));

    if (imc < 18.5)
    {
        cout << "Abaixo do peso." << endl;
    }
    else
        if (imc >= 18.5 && imc < 25)
        {
            cout << "Peso normal." << endl;
        }
        else
            if (imc >= 25 && imc < 30)
            {
                cout << "Acima do peso." << endl;
            }
            else
                {
                    cout << "Obeso." << endl;
                }
                
    return 0;
}
