#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string comodo, continuar;
    double t, area, larg, comprimento;

    t = 0;
    continuar = "sim";

    while (continuar != "não")
    {
        cin >> comodo >> larg >> comprimento;
        area = larg * comprimento;
        t += area;
        cout << fixed << setprecision(2) << area << " metros quadrados" << endl;
        cout << "Continuar calculando novos comodos?" << endl;
        cin >> continuar;
    }
    
    cout << t << " metros quadrados no total" <<endl;

    return 0;
}
