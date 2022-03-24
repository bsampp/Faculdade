#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int largada[24];
    int chegada[24];
    int comp[24];
    int ultrapassagens, n, aux;

    while (cin >> n)
    {
        ultrapassagens = 0;

        aux = 0;
        while (aux < n)
        {
            cin >> largada[aux];
            aux++;
        }
        aux = 0;
        while (aux < n)
        {
            cin >> chegada[aux];
            aux++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (largada[i] == chegada[j])
                {
                    comp[j] = i + 25;
                }
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int l = k + 1; l < n; l++)
            {
                if (comp[k] > comp[l])
                {
                    aux = comp[l];
                    comp[l] = comp[k];
                    comp[k] = aux;
                    ultrapassagens++;
                }
            }
        }
        cout << ultrapassagens << endl;
    }
    return 0;
}