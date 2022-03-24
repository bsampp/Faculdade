#include <iostream>
using namespace std;
int main()
{
    int a, prod;

    cin >> a;

    for (int i = 1; i <= 10; i++)
    {
        prod = a * i;
        cout << a << "x" << i << " = " << prod << endl;
    }

    return 0;
}
