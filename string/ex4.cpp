#include <iostream>
using namespace std;
int main()
{
    int i = 0, j;
    string n;

    getline(cin, n);
    
    while(n[i] != '\0')
    {
        switch (n[i])
        {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
            j = i;
            while (n[j] != '\0')
            {
                n[j] = n[j+1];
                j++;
            }
            break;
        default:
            i++;
        }
        
    }

    cout << n << endl;

    return 0;
}
