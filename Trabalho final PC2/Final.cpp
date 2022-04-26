#include <iostream>
#include <iomanip>
#include <fstream>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    string email;
    string usuario;
    string senha;
    string nickname;
    int id;
} Registro;
void troca(int *v1, int *v2)
{
    int aux;
    aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}
void ordenaBubble(int *v, int n)
{
    int i;
    int j;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                troca(&v[j], &v[j + 1]);
            }
        }
    }
}
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
            cout << "ID/E-mail/Senha/Usuário/Nickname: ";
            cin >> contas.id;
            cin.get();
            getline(cin, contas.email);
            getline(cin, contas.senha);
            getline(cin, contas.usuario);
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
    string linha;
    Registro contas;
    ifstream arquivo("contas.csv", ios::in);
    if (!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo contas.csv" << endl;
        return -1;
    }
    while (!(arquivo.eof()))
    {
        arquivo >> contas.id;
        cout << contas.id << " ";
        getline(arquivo, linha, ',');
        getline(arquivo, contas.email, ',');
        cout << contas.email << " ";
        getline(arquivo, contas.senha, ',');
        cout << contas.senha << " ";
        getline(arquivo, contas.usuario, ',');
        cout << contas.usuario << " ";
        getline(arquivo, contas.nickname);
        cout << contas.nickname << endl;
    }
    arquivo.close();
    return 0;
}
Registro *busca_conta(int idBusca, ifstream &arquivo)
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
    ifstream arquivo("contas.csv");
    if (!arquivo)
    {
        cout << "Nao foi possivel abrir o arquivo contas.csv" << endl;
        return -1;
    }
    do
    {
        cout << "Qual conta de usuário deseja procurar (0 (zero) para finalizar)? ";
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

void del_line(const char *file_name, int n)
{
    ifstream fin(file_name);
    ofstream fout;
    fout.open("contas.csv", ios::out);

    char ch;
    int line = 1;
    while (fin.get(ch))
    {
        if (ch == '\n')
            line++;

        if (line != n) // content not to be deleted
            fout << ch;
    }
    fout.close();
    fin.close();
    remove(file_name);
    rename("contas.csv", file_name);
}

int main()
{
    int x;
    SetConsoleOutputCP(CP_UTF8);
    //insere();
    lista_contas();
    cin >> x;
    //del_line("contas.csv", x);
    busca();
    return 0;
}
