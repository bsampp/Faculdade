#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int t, A, B, C, x, y, z;
    string str;
    float soma = 0, dif = 0, soma1 = 0, soma2 = 0;
    float dif2 = 0, dif1 = 0, p, q, r;
    cin >> t;

    while (t--)
    {
        cin >> str;
        cin >> x >> y >> z;
        soma = soma + x;
        soma1 = soma1 + y;
        soma2 = soma2 + z;
        cin >> A >> B >> C;
        dif = dif + A;
        dif1 = dif1 + B;
        dif2 = dif2 + C;
    }
    p = (dif * 100) / soma;
    q = (dif1 * 100) / soma1;
    r = (dif2 * 100) / soma2;
    cout << fixed << setprecision(2) << "Pontos de Saque: " << p << " %." << endl;
    cout << fixed << setprecision(2) << "Pontos de Bloqueio: " << q << " %." << endl;
    cout << fixed << setprecision(2) << "Pontos de Ataque: " << r << " %." << endl;
    return 0;
}