#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i, p = 0;
    string n;
    getline(cin, n);
    for (i = 0; n[i] != '\0'; i++)
    {
        if (n[i] != n[n.length() - i - 1])
        {
            p = 1;
            break;
        }
    }
    if (p)
    {
        cout << n << " nao e um palindromo" << endl;
    }
    else
    {
        cout << n << " e um palindromo" << endl;
    }
return 0;
}
