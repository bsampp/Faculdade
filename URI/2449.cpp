#include <iostream>
 
using namespace std;
 
int main() {
 
    int N, A, cont = 0, aux, h;
    int V[1000];
    cin >> N >> A;
    for(int i = 0; i < N; i++)
    {
        cin >> h;
        V[i] = h;
    }
    for(int j = 0; j < N; j++)
    {
        if(V[j] != A)
        {
            if(V[j] > A)
            {
                aux = V[j] - A;
                V[j] -= aux;
                V[j + 1] -= aux;
            }
            else
            {
                aux = A - V[j];
                V[j] += aux;
                V[j + 1] += aux;
            }
            cont += aux;
        }
    }
    cout << cont << endl;
 
    return 0;
}