#include <iostream>
using namespace std;

void mult_4()
{
    int x;
    cin >> x;
    if (x % 4 == 0)
    {
        cout << "Multiplo de 4." << endl;
    }
    else
    {
        cout << "Nao e multiplo de 4." << endl;
    }
}
void par_impar()
{
    int x;
    cin >> x;
    if (x % 2 == 0)
    {
        cout << "Numero par" << endl;
    }
    else
    {
        cout << "Numero impar" << endl;
    }
}
void soma_intervalo()
{
    int x, y, soma = 0;
    cin >> x >> y;
    do
    {
        soma += x;
        x++;
    } while (x <= y);
    cout << soma;
}
void volume_esfera()
{
    float raio, volume;
    cin >> raio;
    volume = ((4 * 3.14159) * ((raio * raio) * raio)) / 3;
    cout << volume;
}
void fatorial()
{
    int n, fat;
    cin >> n;
    for (fat = 1; n > 1; n = n - 1)
    {
        fat = fat * n;
    }
    cout << fat;
}
void potenciacao()
{
    int num, pot, resultado = 1;
    cin >> num >> pot;
    for (int i = 0; i < pot; i++)
    {
        resultado *= num;

        if (pot == 0)
        {
            resultado = 1;
        }
    }
    cout << resultado;
}
int main()
{
    mult_4();
    par_impar();
    soma_intervalo();
    volume_esfera();
    fatorial();
    potenciacao();
    return 0;
}
