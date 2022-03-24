using namespace std;
#include <cstdio>
#include <iostream>

int main()
{
    int *v, n;
    cin >> n;
    v = new (nothrow) int[n];
    if (v == nullptr)
    {
        cout << "falha na alocacao" << endl;
        return -1;
    }
    for (int i = 0; i = n; i++)
    {
        v[i] = i;
    }
    for (int j = 0; j < n; j++)
    {
        cout << v[j] << " ";
    }
    delete[] v;
    v = NULL;
    
    return 0;
}