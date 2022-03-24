#include <iostream>
using namespace std;
int main()
{
    string n;
    char t;
    int p;
    getline(cin, n);
    p = n.length() - 1;
    for(int i=0; i<n.length()/2; i++)
    {
        t = n[i];
        n[i] = n[p];
        n[p] = t;
        p--;
    }
    cout << n << endl;
    return 0;
}
