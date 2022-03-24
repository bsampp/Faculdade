#include <iostream>
using namespace std;
int main()
{
    int n, m, b, cont;
    while((cin >> n >> m) && n+m > 0)
    {
        int v[1001] = {};
        cont = 0;
        for (int i = 0; i < m; i++)     
        {
            cin >> b;
            v[b] += 1; 
        }
        for (int j = 0; j < 1001; j++)
        {
            if(v[j] >= 2)
                cont++;
        }
        cout << cont << endl;
    }
    return 0;
}