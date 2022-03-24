#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    string a, b, vencedor;

    cin >> b >> a;

    if (b == "papel")
    {
        if (a == "pedra")
        {
            vencedor = "b";
        }
        else
            if (a == "tesoura")
            {
                vencedor = "a";
            }
            else
            {
                vencedor = "empate";
            }    
    }
    else
        if (b == "tesoura")
        {
            if (a == "pedra")
            {
                vencedor = "a";
            }
            else
                if (a == "papel")
                {
                    vencedor = "b";
                }
                else
                {
                    vencedor = "empate";
                }    
        }
        else
        {
            if (a == "pedra")
            {
                vencedor = "empate";
            }
            else
                if (a == "papel")
                {
                    vencedor = "a";
                }
                else
                {
                    vencedor = "b";
                }  
        }
    
    cout << vencedor << endl;
        

        
    
                
    return 0;
}
