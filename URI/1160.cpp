#include <iostream>
using namespace std;
int main() {
    int T, PA, PB, i, anos, sec;
    double GA, GB;

    i = 0;
    cin >> T;

    while (i++ < T)
    {
        
        cin >> PA >> PB >> GA >> GB;
        anos = 0;
        while (PA <= PB)
        {
            PA += (PA * GA) / 100;
            PB += (PB * GB) / 100;
            anos++;
            if (anos > 100)
            {
                sec = 1;
                break;
            }
            
        }

    }
     if (sec == 0)
        {
            cout << anos << endl;
        }
    else
        {
            cout << "Mais de 1 seculo." << endl;
        }
        
    
    return 0;
}