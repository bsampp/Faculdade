#include <iostream>
using namespace std;
int main()
{
    int b, expo, p = 1, i = 0;

    cin >> b >> expo;

    do
    {
        if (expo == 0)
        {
            p = 1;
        }
        else if (expo == 1)
        {
            p = b;
        }
        else
        {
            p *= b;
        }
        i++;

    } while (i < expo);
    cout << p << endl;

    return 0;
}
