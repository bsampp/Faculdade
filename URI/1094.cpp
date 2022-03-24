#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n, q, i = 0;
    int total = 0;
    int coelho = 0;
    int sapo = 0;
    int rato = 0;
    char t;

    cin >> n;

    do
    {
        
        cin >> q >> t;

        total += q;

        if (t == 'C')
        {
            coelho += q;
        }
        if (t == 'S')
        {
            sapo += q;
        }
        if (t == 'R')
        {
            rato += q;
        }
        i++;

    } while (n > i);

        cout << "Total: " << total << " cobaias" << endl;
        cout << "Total de coelhos: " << coelho << endl;
        cout << "Total de ratos: " << rato << endl;
        cout << "Total de sapos: " << sapo << endl;
        cout << "Percentual de coelhos: " << fixed << setprecision(2) << (((float)coelho/(float)total)*100.00) << " %" << endl;
        cout << "Percentual de ratos: " << fixed << setprecision(2) << (((float)rato/(float)total)*100.00) << " %" << endl;
        cout << "Percentual de sapos: " << fixed << setprecision(2) << (((float)sapo/(float)total)*100.00) << " %" << endl;

        
        
    
    return 0;
}