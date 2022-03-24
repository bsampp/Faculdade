#include <iostream>
using namespace std;
int main()
{
    int soma = 0;

    for (int i = 0; i <= 500; i++)
    {
        if (i % 2 == 0)
        {
            soma = soma + i;
        }
        
    }
    cout << soma << endl;

    return 0;
}
