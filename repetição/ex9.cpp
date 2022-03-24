#include <iostream>
using namespace std;
int main()
{
    int n = 1, anterior = 0, atual = 1, prox;

    cout << anterior << endl;

    while (n <= 15)
    {
        cout << atual << endl;
        prox = anterior + atual;
        anterior = atual;
        atual = prox;
        n++;
    }

    return 0;
}
