#include <iostream>
using namespace std;
int main()
{
    int cont = 1, i;
    string n;

    getline(cin, n);

    for (i = 0; n[i] != '\0'; i++)
    {
        if ((n[i] == ' ') || (n[i] == '\0'))
        {
            cont++;
        }
    }

    cout << cont << endl;

    return 0;
}
