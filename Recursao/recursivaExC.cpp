using namespace std;
#include <cstdio>
#include <iostream>

float teste2(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return n%10 + teste2(n/10);
    }
}
int main()
{
    int x;
    cin >> x;
    cout << teste2(x);
    return 0;
}