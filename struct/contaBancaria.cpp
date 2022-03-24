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
    int id;
    char tipo;
    string titular;
    Data abertura;
    float saldo;
} Conta;
void preencheSemPonteiro(Conta conta)
{
    cin >> conta.tipo;
    cin >> conta.id;
    cin.get();
    getline(cin, conta.titular);
    cin >> conta.abertura.dia >> conta.abertura.mes >> conta.abertura.ano;
    cin >> conta.saldo;
}
void preencheComPonteiro(Conta *conta)
{
    cin >> conta->tipo;
    cin >> conta->id;
    cin.get();
    getline(cin, conta->titular);
    cin >> conta->abertura.dia >> conta->abertura.mes >> conta->abertura.ano;
    cin >> conta->saldo;
}
void mostrarConta(Conta contaBancaria)
{
    cout << fixed << setprecision(2);
    cout << "Tipo de conta: " << (contaBancaria.tipo == 'P' ? "Poupanca" : "Corrente") << endl;
    cout << contaBancaria.id << " " << contaBancaria.titular << endl;
    cout << "Cliente desde " << contaBancaria.abertura.dia << "/";
    cout << contaBancaria.abertura.mes << "/" << contaBancaria.abertura.ano << endl;
    cout << "Saldo: R$" << contaBancaria.saldo << endl;
}
int buscarConta(int id, Conta conta[], int n)
{
    cin >> id;
    int i = 0;
    while ((id != conta[i].id) && (i < n))
    {
        i++;
    }
    return i;
}
int main()
{
    Conta novaConta[N];
    char continuar;
    int i = 0;
    int idBusca;
    do
    {
        preencheComPonteiro(&novaConta[i]);
        cin >> continuar;
        i++;
    } while (continuar == 's' && continuar == 'S');
    //for (int j = 0; j < i; j++)
    //{
    //    mostrarConta(novaConta[j]);
    //}
    buscarConta(idBusca, novaConta, i);
    return 0;
}