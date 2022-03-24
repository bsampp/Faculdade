#include <iostream>
#include <iomanip>
#include <string>
#define N 21
using namespace std;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int cpf;
    string nome;
    Data dose1;
    Data dose2;
    Data reforco;

} CartaoDeVacina;

void cadastro(CartaoDeVacina *primeiraDose)
{
    cin >> primeiraDose->cpf;
    cin.get();
    getline(cin, primeiraDose->nome);
    cin >> primeiraDose->dose1.dia;
    cin >> primeiraDose->dose1.mes;
    cin >> primeiraDose->dose1.ano;
    primeiraDose->dose2.dia = 0;
    primeiraDose->dose2.mes = 0;
    primeiraDose->dose2.ano = 0;
    primeiraDose->reforco.dia = 0;
    primeiraDose->reforco.mes = 0;
    primeiraDose->reforco.ano = 0;
}
void inclusaoSegundaDose(CartaoDeVacina *segundaDose)
{
    cin >> segundaDose->dose2.dia;
    cin >> segundaDose->dose2.mes;
    cin >> segundaDose->dose2.ano;
}
void inclusaoReforco(CartaoDeVacina *doseReforco)
{
    cin >> doseReforco->reforco.dia;
    cin >> doseReforco->reforco.mes;
    cin >> doseReforco->reforco.ano;
}
void mostrarCartao(CartaoDeVacina cartao)
{
    cout << cartao.cpf << " " << cartao.nome << " " << cartao.dose1.dia
         << "/" << cartao.dose1.mes << "/" << cartao.dose1.ano
         << " " << cartao.dose2.dia << "/" << cartao.dose2.mes
         << "/" << cartao.dose2.ano << " " << cartao.reforco.dia
         << "/" << cartao.reforco.mes << "/" << cartao.reforco.ano << endl;
}
int buscaCPF(int cpf, CartaoDeVacina cartao[N], int n)
{
    cin >> cpf;
    int i = 0;
    while (cpf != cartao[i].cpf && i < n)
    {
        i++;
    }
    if (i < n)
    {
        return i;
    }
    else
    {
        return -1;
    }
}
int main()
{
    CartaoDeVacina cadastros[N];
    int i = 0;
    int busca;
    char continuar;
    do
    {
        cadastro(&cadastros[i]);
        cin >> continuar;
        i++;
    } while (continuar == 's' || continuar == 'S');
    do
    {
        int cpfCartao = buscaCPF(busca, cadastros, i);
        cout << "encontrou " << cpfCartao << endl; 
        if (cpfCartao != -1)
        {
            inclusaoSegundaDose(&cadastros[cpfCartao]);
            inclusaoReforco(&cadastros[cpfCartao]);
        }
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');
    for (int j = 0; j < i; j++)
    {
        mostrarCartao(cadastros[j]);
    }
    return 0;
}