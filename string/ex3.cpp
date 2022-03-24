#include <iostream>
using namespace std;
int main()
{
    int i, j;
    string n;

    getline(cin, n);
    
    for (i = 0; n[i] != '\0'; i++)
    {
        switch (n[i])
        {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
            j = i;
            n[j] = '*';
            j++;
        }
        
    }

    cout << n << endl;

    return 0;
}
