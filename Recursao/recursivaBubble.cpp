using namespace std;
#include <cstdio>
#include <iostream>
#define N 4

recursivaBubble(int *v, int n)
{
    int aux;
    if (n == 1)
    {
        return v[0];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            aux = v[i];
            v[i] = v[i + 1];
            v[i + 1] = aux;
        }
        recursivaBubble(v, n - 1);
    }
}
int main()
{
    int v[N];
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    recursivaBubble(v, N);
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
}