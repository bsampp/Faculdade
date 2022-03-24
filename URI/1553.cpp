#include <iostream>
using namespace std;
int main()
{
    int n, k, p, cont;
    while((cin >> n >> k) && n+k > 0)
    {
        int v[1001] = {};
        cont = 0;
        for (int i = 0; i < n; ++i)     
        {
            cin >> p;
            v[p] += 1; 
        }
        for (int j = 0; j < 1001; ++j)
        {
            if(v[j] >= k)
                cont++;
        }
        cout << cont << endl;
    }
    return 0;
}
