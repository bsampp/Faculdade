using namespace std;
#include <cstdio>
#include <iostream>
#define N 4

void insere(int *v, int n)
{
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
}
void exibe(int *v, int n)
{
    for (int i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
}
void troca(int *v1, int *v2)
{
    int aux;
    aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}
void bubble(int *v, int n)
{
    int i;
    int j;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                troca(&v[j], &v[j + 1]);
            }
        }
    }
}
void bubble_recursivo(int *v, int n)
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
        bubble_recursivo(v, n - 1);
    }
}
void selection(int *v, int n)
{
    int i, j, menor;
    for (i = 0; i < n-1; i++)
    {
        menor = i;
        for (j = i+1; j < n; j++)
        {
            if (v[j] < v[menor])
            {
                menor = j;
            }
            
        }
        if (v[menor] != v[i])
        {
            troca(&v[menor], &v[i]);
        }
    }
    
}
int main()
{
    int v[N];
    insere(v, N);
    bubble(v, N);
    exibe(v, N);
}