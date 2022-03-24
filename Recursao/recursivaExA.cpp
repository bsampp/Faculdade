using namespace std;
#include <cstdio>
#include <iostream>

int soma(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + soma(n - 1);
    }
}
int main()
{
    int x;
    cin >> x;
    cout << soma(x);
    return 0;
}