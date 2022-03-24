using namespace std;
#include <cstdio>
#include <iostream>

int preenche(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        *v = i;
        v++;
    }
    return 0;
}
void exibe(int *v, int n)
{
    cout << *v << endl;
    int *f = &v[n];
    while (v < f)
    {
        cout << *v << " ";
        v++;
    }
}
int main()
{
    int *v, n;
    cin >> n;
    if (!(v = new (nothrow) int[n]))
    {
        cout << "falha na alocacao" << endl;
        return -1;
    }
    preenche(v, n);
    exibe(v, n);
    delete[] v;
    v = NULL;

    return 0;
}