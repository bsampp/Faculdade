#include <iostream>
using namespace std;
 
int main() {
 
    int N, tam, cont, c, pares;
    char L;
    while(cin >> N)
    {
        int e[61] = {}, d[61] = {};
        cont = 0;
        while(N > 0)
        {
            cin >> tam >> L;
            if(L == 'D')
            {
                d[tam-30]++;
            }
            else
            {
                e[tam-30]++;
            }
            N--;
        }
        for (c = 0,pares = 0; c <= 30; c++)
        {
            if(e[c] > 0 && d[c] > 0)
            {
                while(e[c] != 0 && d[c] != 0)
                {
                    pares++;
                    e[c]--;
                    d[c]--;
                }
            }
        }
        cout << pares << endl;
    }
    
 
    return 0;
}