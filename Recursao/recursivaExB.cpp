using namespace std;
#include <cstdio>
#include <iostream>

int potencia(int n, int m)
{
    if (m == 0)
    {
        return 1;
    }
    else if (m == 1)
    {
        return n;
    }
    else
    {
        return n * potencia(n, m - 1);
    }
}
int main()
{
    int x, y;
    cin >> x >> y;
    cout << potencia(x, y);
    return 0;
}