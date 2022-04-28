#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h>
#include <sstream>
using namespace std;

typedef struct
{
    string email;
    string usuario;
    string senha;
    string nickname;
    int id;
} Registro;
int insere()
{
    char continuar;
    Registro contas;
    ofstream arquivo("contas.csv", ios::app);
    if (!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo contas.csv" << endl;
        return -1;
    }
    else
    {
        do
        {
            system("cls");
            cout << "ID: " << endl;
            cin >> contas.id;
            cin.get();
            cout << "E-mail: " << endl;
            getline(cin, contas.email);
            cout << "Senha: " << endl;
            getline(cin, contas.senha);
            cout << "Usuário: " << endl;
            getline(cin, contas.usuario);
            cout << "Nickname: " << endl;
            getline(cin, contas.nickname);
            arquivo << contas.id << ",";
            arquivo << contas.email << ",";
            arquivo << contas.senha << ",";
            arquivo << contas.usuario << ",";
            arquivo << contas.nickname << endl;
            cout << "Deseja continuar com a inserção?(S/N)" << endl;
            cin >> continuar;
            continuar = toupper(continuar);
        } while (continuar == 'S');
    }
    arquivo.close();
    return 0;
}
int lista_contas()
{
    string linha = "";
    Registro contas;
    ifstream arquivo("contas.csv", ios::in);
    if (!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo contas.csv" << endl;
        return -1;
    }
    while (arquivo.good())
    {

        arquivo >> contas.id;
        getline(arquivo, linha, ',');
        getline(arquivo, contas.email, ',');
        getline(arquivo, contas.senha, ',');
        getline(arquivo, contas.usuario, ',');
        getline(arquivo, contas.nickname, '\n');
        cout << contas.id << " " << contas.email << " " << contas.senha << " " << contas.usuario << " " << contas.nickname << endl;
    }
    arquivo.close();
    return 0;
}
Registro *busca_conta(int idBusca, fstream &arquivo)
{
    string linha;
    Registro *contas;
    contas = new (nothrow) Registro;
    arquivo.seekg(0);
    do
    {
        arquivo >> contas->id;
        getline(arquivo, linha, ',');
        getline(arquivo, contas->email, ',');
        getline(arquivo, contas->senha, ',');
        getline(arquivo, contas->usuario, ',');
        getline(arquivo, contas->nickname);
    } while (contas->id != idBusca && !arquivo.eof());
    if (contas->id == idBusca)
        return contas;
    else
        return NULL;
}
int busca()
{
    int id;
    Registro *contas;
    fstream arquivo("contas.csv");
    if (!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo contas.csv" << endl;
        return -1;
    }
    do
    {
        cout << "Qual conta de usuário deseja procurar(ID) (0 (zero) para finalizar)? ";
        cin >> id;
        if (id != 0)
        {
            contas = busca_conta(id, arquivo);
            if (contas)
            {
                cout << "E-mail: " << contas->email << endl;
                cout << "Senha: " << contas->senha << endl;
                cout << "Usuário: " << contas->usuario << endl;
                cout << "Nickname: " << contas->nickname << endl;
            }
            else
            {
                cout << "Conta não cadastrada" << endl;
            }
        }
    } while (id != 0);
    arquivo.close();
    delete contas;
    contas = NULL;
    return 0;
}
int exporta()
{
    ifstream arquivo("contas.csv");
    ofstream arquivotxt("contas.txt");
    if (!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo contas.txt" << endl;
        return -1;
    }
    else
    {
        while ((arquivo.good()))
        {

            Registro contas;
            string linha = "";
            arquivo >> contas.id;
            getline(arquivo, linha, ',');
            getline(arquivo, contas.email, ',');
            getline(arquivo, contas.senha, ',');
            getline(arquivo, contas.usuario, ',');
            getline(arquivo, contas.nickname, '\n');
            arquivotxt << contas.id << ",";
            arquivotxt << contas.email << ",";
            arquivotxt << contas.senha << ",";
            arquivotxt << contas.usuario << ",";
            arquivotxt << contas.nickname << endl;
        }
    }
    arquivo.close();
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int opcao;
    do
    {
        cout << "Inserir novas contas(1) / Mostrar todas as contas(2) / Realizar busca de contas(3) / Exportar para .txt(4) / Finalizar programa(5)" << endl;
        cin >> opcao;
        switch (opcao)
        {
        case 1:
            insere();
            break;
        case 2:
            lista_contas();
            break;
        case 3:
            busca();
            break;
        case 4:
            exporta();
            break;
        }
    } while (opcao != 5);
    return 0;
}
