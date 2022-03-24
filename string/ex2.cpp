#include <iostream>
using namespace std;
int main()
{
    int i;
    string n;

    getline(cin, n);
    
    for (i = 0; n[i] != '\0'; i++)
    {
        if (i == 0 || n[i - 1] == ' ' ) 
            if(n[i] >= 97 && n[i] <= 122)
                n[i] -= 32;
      
    }

    cout << n << endl;

    return 0;
}
