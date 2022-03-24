#include <iostream>
using namespace std;

bool mult_4(int x)
{
    return (x % 4 == 0 ? true : false);
}
bool par_impar(int x)
{
    return (x % 2 == 0 ? true : false);
}
int soma_intervalo(int x, int y)
{
    int soma = 0; 
    do
    {
        soma += x;
        x++;
    } while (x <= y);
    return soma;
}
float volume_esfera(float raio)
{
    float volume;
    volume = ((4 * 3.14159) * ((raio * raio) * raio)) / 3;
    return volume;
}
int fatorial(int x)
{
    int fat;
    for (fat = 1; x > 1; x = x - 1)
    {
        fat = fat * x;
    }
    return fat;
}
int potenciacao(int num, int pot)
{
    int resultado = 1;
    for (int i = 0; i < pot; i++)
    {
        resultado *= num;

        if (pot == 0)
        {
            resultado = 1;
        }
    }
    return resultado;
}
int main()
{
    int x, y, raio, num, pot;

    cin >> x;
    (mult_4(x) ? cout << "Multiplo de 4." << endl : cout << "Nao e multiplo de 4." << endl);

    cin >> x;
    (par_impar(x) ? cout << "Numero par." << endl : cout << "Numero impar." << endl);

    cin >> x >> y;
    cout << soma_intervalo(x, y) << endl;

    cin >> raio;
    cout << volume_esfera(raio) << endl;

    cin >> x;
    cout << fatorial(x) << endl;

    cin >> num >> pot;
    cout << potenciacao(num, pot) << endl;

    return 0;
}
