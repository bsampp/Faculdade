using namespace std;
#include <cstdio>
#include <iostream>
#define N 4

void ordena(int *v, int n)
{
    int i;
    int pos;
    int menor;
    for (int j = 0; j < n - 1; j++)
    {
        pos = j;
        menor = v[j];

        for (i = j + 1; i < n; i++)
        {
            if (v[i] < menor)
            {
                menor = v[i];
                pos = i;
            }
        }
        v[pos] = v[j];
        v[j] = menor;
    }
}
int main()
{
    int v[N];
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    ordena(v, N);
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
}