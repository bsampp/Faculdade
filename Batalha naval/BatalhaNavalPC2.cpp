// Desenvolvedor: Bruno Sampietro
// Data: 28/10/2021
// Funcionalidade: Jogo de batalha naval

#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define Tamanho 8
#define max_jogadores 100
#define numEmbarcTotal 1
using namespace std;
//
int i = 0;
// Introdução do jogo
void introducao()
{
    SetConsoleOutputCP(CP_UTF8);
    cout << "               |   |   |                 " << endl;
    cout << "              )_)  )_)  )_)              " << endl;
    cout << "             )___))___))___)            " << endl;
    cout << "            )____)____)_____)" << endl;
    cout << "          _____|____|____|____" << endl;
    cout << "-----------                   /----------------------------" << endl;
    cout << "   ^^^^^ ^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << "     ^^^^      ^^^^     ^^^    ^^" << endl;
    cout << "-------------------------BATALHA NAVAL-----------------------" << endl;
    cout << "Você aceita entrar nesta batalha de vida ou morte no oceano?" << endl;
    cout << "              Aperte enter para aceitar." << endl;
}
// Construção dos tabuleiros - sem retorno - faz a passagem de uma matriz por parâmetro
void construcao_tabuleiro(string t[][Tamanho])
{
    int c, ln;
    char l;

    for (int l = 0; l < Tamanho; l++)
    {
        for (int c = 0; c < Tamanho; c++)
        {
            t[l][c] = "[ ]";
        }
    }
}
// Exibição do tabuleiro do jogador durante a partida - sem retorno - faz a passagem de uma matriz por parâmetro
void exibir_tabuleiro_jogador(string tabuleiro[][Tamanho])
{
    int c, ln;
    char l;
    char linha[Tamanho] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    string coluna[Tamanho] = {"   1", "2", "3", "4", "5", "6", "7", "8"};

    SetConsoleOutputCP(CP_UTF8);
    system("cls");
    cout << "Seu tabuleiro" << endl;
    for (int l = 0; l < Tamanho; l++)
    {
        if (l == 0)
        {
            for (int i = 0; i < Tamanho; i++)
            {
                cout << coluna[i] << "   ";
            }
            cout << endl;
            cout << linha[0] << " ";
            for (int j = 0; j < Tamanho; j++)
            {
                cout << tabuleiro[0][j] << " ";
            }
        }
        else
        {
            cout << linha[l] << " ";
            for (int c = 0; c < Tamanho; c++)
            {
                cout << tabuleiro[l][c] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "[ ] = Água / [S] = Submarino / [H] = Hidroavião / [-] = Tiro sem acerto / [X] = Embarcação atingida" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
}
// Exibe o tabuleiro do oponente com suas embarcações expostas ao fim do jogo - sem retorno - faz a passagem de uma matriz por parâmetro
void exibir_tabuleiro_computador_cheat(string tabuleiroRivalVisto[][Tamanho])
{
    int c, ln;
    char l;
    char linha[Tamanho] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    string coluna[Tamanho] = {"   1", "2", "3", "4", "5", "6", "7", "8"};

    cout << "Essas eram as embarcações que você não atingiu" << endl;
    for (int l = 0; l < Tamanho; l++)
    {
        if (l == 0)
        {
            for (int i = 0; i < Tamanho; i++)
            {
                cout << coluna[i] << "   ";
            }
            cout << endl;
            cout << linha[0] << " ";
            for (int j = 0; j < Tamanho; j++)
            {
                cout << tabuleiroRivalVisto[0][j] << " ";
            }
        }
        else
        {
            cout << linha[l] << " ";
            for (int c = 0; c < Tamanho; c++)
            {
                cout << tabuleiroRivalVisto[l][c] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "------------"
         << "[ ] = Água / [-] = Tiro sem acerto / [X] = Embarcação atingida"
         << "-------------" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
}
// Exibe o tabuleiro para o jogador durante o jogo sem expor as embarcações - sem retorno - faz a passagem de uma matriz por parâmetro
void exibir_tabuleiro_computador(string tabuleiroRivalVisto[][Tamanho])
{
    int c, ln;
    char l;
    char linha[Tamanho] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    string coluna[Tamanho] = {"   1", "2", "3", "4", "5", "6", "7", "8"};

    cout << "Tabuleiro do oponente" << endl;
    for (int l = 0; l < Tamanho; l++)
    {
        if (l == 0)
        {
            for (int i = 0; i < Tamanho; i++)
            {
                cout << coluna[i] << "   ";
            }
            cout << endl;
            cout << linha[0] << " ";
            for (int j = 0; j < Tamanho; j++)
            {
                cout << tabuleiroRivalVisto[0][j] << " ";
            }
        }
        else
        {
            cout << linha[l] << " ";
            for (int c = 0; c < Tamanho; c++)
            {
                cout << tabuleiroRivalVisto[l][c] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "------------"
         << "[ ] = Água / [-] = Tiro sem acerto / [X] = Embarcação atingida"
         << "-------------" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
}
// Atribuição da posição dos submarinos - sem retorno - faz a passagem de uma matriz por parâmetro
void posicionar_submarinos(string tabuleiro[][Tamanho])
{
    SetConsoleOutputCP(CP_UTF8);
    bool repetir(true);
    int c, ln;
    char l;
    numSubmarinos = numEmbarcTotal;
    cout << "Insira as embarcações de seu tabuleiro" << endl;

    do
    {
        repetir = true;
        do
        {
            cout << "Número de submarinos restantes: " << numSubmarinos << endl;
            cout << "Selecione a posição de seu submarino" << endl;
            cout << "Submarino = [S]" << endl;
            cout << "Linha(A-H)/Coluna(1-8): " << endl;
            cin >> l;
            cin >> c;
            switch (l)
            {
            case 'A':
                ln = 1;
                break;
            case 'B':
                ln = 2;
                break;
            case 'C':
                ln = 3;
                break;
            case 'D':
                ln = 4;
                break;
            case 'E':
                ln = 5;
                break;
            case 'F':
                ln = 6;
                break;
            case 'G':
                ln = 7;
                break;
            case 'H':
                ln = 8;
                break;
            default:
                ln = 10;
                break;
            }
            if ((ln <= Tamanho && ln >= 1) && (c <= Tamanho && c >= 1) && (tabuleiro[ln - 1][c - 1] == "[ ]"))
            {
                repetir = false;
            }
        } while (repetir);
        ln--;
        c--;
        tabuleiro[ln][c] = "[S]";
        exibir_tabuleiro_jogador(tabuleiro);
        numSubmarinos--;
    } while (numSubmarinos > 0);
}
// Atribuição da posição dos hidroaviões - sem retorno - faz a passagem de uma matriz por parâmetro
void posicionar_hidroavioes(string tabuleiro[][Tamanho])
{
    SetConsoleOutputCP(CP_UTF8);
    bool repetir(true);
    int c, ln;
    char l;
    char posVH, posCB, posED;
    numHidroav = numEmbarcTotal;
    do
    {
        repetir = true;
        do
        {
            cout << "Número de hidroaviões: " << numHidroav << endl;
            cout << "Selecione a posição de seu hidroavião" << endl;
            cout << "Hidroavião = [H][H][H]" << endl;
            cout << "                [H]   " << endl;
            cout << "Linha(A-H)/Coluna(1-8): " << endl;
            cin >> l;
            cin >> c;
            switch (l)
            {
            case 'A':
                ln = 1;
                break;
            case 'B':
                ln = 2;
                break;
            case 'C':
                ln = 3;
                break;
            case 'D':
                ln = 4;
                break;
            case 'E':
                ln = 5;
                break;
            case 'F':
                ln = 6;
                break;
            case 'G':
                ln = 7;
                break;
            case 'H':
                ln = 8;
                break;
            default:
                ln = 10;
                break;
            }
            cout << "Posicionar o hidroavião na vertical ou horizontal? (V/H)" << endl;
            cin >> posVH;
            if (posVH == 'H')
            {
                cout << "Posicionar o hidroavião voltado para cima ou para baixo? (C/B)" << endl;
                cin >> posCB;
                if (posCB == 'C')
                {
                    if (((ln <= Tamanho) & (ln >= 1)) && ((c <= Tamanho) && (c >= 1)) && (((c + 1) <= Tamanho) && ((c + 1) >= 1)) && (((c - 1) <= Tamanho) && ((c - 1) >= 1)) && (((ln - 1) <= Tamanho) && ((ln - 1) >= 1)))
                    {
                        if ((tabuleiro[ln - 1][c - 1] == "[ ]") && (tabuleiro[ln - 1][c] == "[ ]") && (tabuleiro[ln - 1][c - 2] == "[ ]") && (tabuleiro[ln - 2][c - 1] == "[ ]"))
                        {
                            repetir = false;
                        }
                    }
                }
                else if (posCB == 'B')
                {
                    if (((ln <= Tamanho) & (ln >= 1)) && ((c <= Tamanho) && (c >= 1)) && (((c + 1) <= Tamanho) && ((c + 1) >= 1)) && (((c - 1) <= Tamanho) && ((c - 1) >= 1)) && (((ln + 1) <= Tamanho) && ((ln + 1) >= 1)))
                    {
                        if ((tabuleiro[ln - 1][c - 1] == "[ ]") && (tabuleiro[ln - 1][c] == "[ ]") && (tabuleiro[ln - 1][c - 2] == "[ ]") && (tabuleiro[ln][c - 1] == "[ ]"))
                        {
                            repetir = false;
                        }
                    }
                }
            }
            else if (posVH == 'V')
            {
                cout << "Posicionar o hidroavião voltado para esquerda ou direita? (E/D)" << endl;
                cin >> posED;
                if (posED == 'E')
                {
                    if (((ln <= Tamanho) & (ln >= 1)) && ((c <= Tamanho) && (c >= 1)) && (((ln + 1) <= Tamanho) && ((ln + 1) >= 1)) && (((ln - 1) <= Tamanho) && ((ln - 1) >= 1)) && (((c - 1) <= Tamanho) && ((c - 1) >= 1)))
                    {
                        if ((tabuleiro[ln - 1][c - 1] == "[ ]") && (tabuleiro[ln][c - 1] == "[ ]") && (tabuleiro[ln - 2][c - 1] == "[ ]") && (tabuleiro[ln - 1][c - 2] == "[ ]"))
                        {
                            repetir = false;
                        }
                    }
                }
                else if (posED == 'D')
                {
                    if (((ln <= Tamanho) & (ln >= 1)) && ((c <= Tamanho) && (c >= 1)) && (((ln + 1) <= Tamanho) && ((ln + 1) >= 1)) && (((ln - 1) <= Tamanho) && ((ln - 1) >= 1)) && (((c + 1) <= Tamanho) && ((c + 1) >= 1)))
                    {
                        if ((tabuleiro[ln - 1][c - 1] == "[ ]") && (tabuleiro[ln][c - 1] == "[ ]") && (tabuleiro[ln - 2][c - 1] == "[ ]") && (tabuleiro[ln - 1][c] == "[ ]"))
                        {
                            repetir = false;
                        }
                    }
                }
            }
        } while (repetir);
        ln--;
        c--;
        if (posVH == 'H')
        {
            if (posCB == 'C')
            {
                tabuleiro[ln][c] = "[H]";
                tabuleiro[ln][c + 1] = "[H]";
                tabuleiro[ln][c - 1] = "[H]";
                tabuleiro[ln - 1][c] = "[H]";
            }
            if (posCB == 'B')
            {
                tabuleiro[ln][c] = "[H]";
                tabuleiro[ln][c + 1] = "[H]";
                tabuleiro[ln][c - 1] = "[H]";
                tabuleiro[ln + 1][c] = "[H]";
            }
        }
        else if (posVH == 'V')
        {
            if (posED == 'E')
            {
                tabuleiro[ln][c] = "[H]";
                tabuleiro[ln + 1][c] = "[H]";
                tabuleiro[ln - 1][c] = "[H]";
                tabuleiro[ln][c - 1] = "[H]";
            }
            if (posED == 'D')
            {
                tabuleiro[ln][c] = "[H]";
                tabuleiro[ln + 1][c] = "[H]";
                tabuleiro[ln - 1][c] = "[H]";
                tabuleiro[ln][c + 1] = "[H]";
            }
        }
        exibir_tabuleiro_jogador(tabuleiro);
        numHidroav--;
    } while (numHidroav > 0);
}

// Atribuição das embarcações do tabuleiro rival - sem retorno - faz a passagem de uma matriz por parâmetro
void posicionar_embarcacoes_tabuleiro_rival(string tabuleiroRival[][Tamanho])
{
    bool repetir(true);
    int c, ln;
    char l;
    int posPC;
    srand(time(NULL));
    numSubmarinos = numEmbarcTotal;
    do
    {
        repetir = true;
        do
        {
            ln = rand() % 9;
            if (ln == 0)
            {
                ln = 1;
            }
            c = rand() % 9;
            if (c == 0)
            {
                c = 1;
            }
            if ((ln <= Tamanho && ln >= 1) && (c <= Tamanho && c >= 1) && (tabuleiroRival[ln - 1][c - 1] == "[ ]"))
            {
                repetir = false;
            }
        } while (repetir);
        ln--;
        c--;
        tabuleiroRival[ln][c] = "[S]";
        numSubmarinos--;
    } while (numSubmarinos > 0);

    numHidroav = numEmbarcTotal;
    do
    {
        repetir = true;
        do
        {
            ln = rand() % 9;
            if (ln == 0)
            {
                ln = 1;
            }
            c = rand() % 9;
            if (c == 0)
            {
                c = 1;
            }
            posPC = rand() % 4;
            if (posPC == 0)
            {
                if (((ln <= Tamanho) && (ln >= 1)) && ((c <= Tamanho) && (c >= 1)) && (((c + 1) <= Tamanho) && ((c + 1) >= 1)) && (((c - 1) <= Tamanho) && ((c - 1) >= 1)) && (((ln - 1) <= Tamanho) && ((ln - 1) >= 1)))
                {
                    if ((tabuleiroRival[ln - 1][c - 1] == "[ ]") && (tabuleiroRival[ln - 1][c] == "[ ]") && (tabuleiroRival[ln - 1][c - 2] == "[ ]") && (tabuleiroRival[ln - 2][c - 1] == "[ ]"))
                    {
                        repetir = false;
                    }
                }
            }
            else if (posPC == 1)
            {
                if (((ln <= Tamanho) && (ln >= 1)) && ((c <= Tamanho) && (c >= 1)) && (((c + 1) <= Tamanho) && ((c + 1) >= 1)) && (((c - 1) <= Tamanho) && ((c - 1) >= 1)) && (((ln + 1) <= Tamanho) && ((ln + 1) >= 1)))
                {
                    if ((tabuleiroRival[ln - 1][c - 1] == "[ ]") && (tabuleiroRival[ln - 1][c] == "[ ]") && (tabuleiroRival[ln - 1][c - 2] == "[ ]") && (tabuleiroRival[ln][c - 1] == "[ ]"))
                    {
                        repetir = false;
                    }
                }
            }
            else if (posPC == 2)
            {
                if (((ln <= Tamanho) && (ln >= 1)) && ((c <= Tamanho) && (c >= 1)) && (((ln + 1) <= Tamanho) && ((ln + 1) >= 1)) && (((ln - 1) <= Tamanho) && ((ln - 1) >= 1)) && (((c - 1) <= Tamanho) && ((c - 1) >= 1)))
                {
                    if ((tabuleiroRival[ln - 1][c - 1] == "[ ]") && (tabuleiroRival[ln][c - 1] == "[ ]") && (tabuleiroRival[ln - 2][c - 1] == "[ ]") && (tabuleiroRival[ln - 1][c - 2] == "[ ]"))
                    {
                        repetir = false;
                    }
                }
            }
            else if (posPC == 3)
            {
                if (((ln <= Tamanho) && (ln >= 1)) && ((c <= Tamanho) && (c >= 1)) && (((ln + 1) <= Tamanho) && ((ln + 1) >= 1)) && (((ln - 1) <= Tamanho) && ((ln - 1) >= 1)) && (((c + 1) <= Tamanho) && ((c + 1) >= 1)))
                {
                    if ((tabuleiroRival[ln - 1][c - 1] == "[ ]") && (tabuleiroRival[ln][c - 1] == "[ ]") && (tabuleiroRival[ln - 2][c - 1] == "[ ]") && (tabuleiroRival[ln - 1][c] == "[ ]"))
                    {
                        repetir = false;
                    }
                }
            }

        } while (repetir);
        ln--;
        c--;
        if (posPC == 0)
        {
            tabuleiroRival[ln][c] = "[H]";
            tabuleiroRival[ln][c + 1] = "[H]";
            tabuleiroRival[ln][c - 1] = "[H]";
            tabuleiroRival[ln - 1][c] = "[H]";
        }
        if (posPC == 1)
        {
            tabuleiroRival[ln][c] = "[H]";
            tabuleiroRival[ln][c + 1] = "[H]";
            tabuleiroRival[ln][c - 1] = "[H]";
            tabuleiroRival[ln + 1][c] = "[H]";
        }
        if (posPC == 2)
        {
            tabuleiroRival[ln][c] = "[H]";
            tabuleiroRival[ln + 1][c] = "[H]";
            tabuleiroRival[ln - 1][c] = "[H]";
            tabuleiroRival[ln][c - 1] = "[H]";
        }
        if (posPC == 3)
        {
            tabuleiroRival[ln][c] = "[H]";
            tabuleiroRival[ln + 1][c] = "[H]";
            tabuleiroRival[ln - 1][c] = "[H]";
            tabuleiroRival[ln][c + 1] = "[H]";
        }

        numHidroav--;
    } while (numHidroav > 0);
}
// Realiza o ataque do jogador - retorna um valor do tipo int contabilizando o número de acertos - faz a passagem de uma matriz por parâmetro e trabalha com dois ponteiros do tipo int
int ataque_jogador(string tabuleiroRival[][Tamanho], string tabuleiroRivalVisto[][Tamanho], int *contador, int *errosJogador)
{
    SetConsoleOutputCP(CP_UTF8);
    int c, ln;
    char l;
    cout << "Insira as coordenadas de seu ataque: Linha(A-H)/Coluna(1-8)" << endl;
    cin >> l >> c;
    switch (l)
    {
    case 'A':
        ln = 1;
        break;
    case 'B':
        ln = 2;
        break;
    case 'C':
        ln = 3;
        break;
    case 'D':
        ln = 4;
        break;
    case 'E':
        ln = 5;
        break;
    case 'F':
        ln = 6;
        break;
    case 'G':
        ln = 7;
        break;
    case 'H':
        ln = 8;
        break;
    default:
        ln = 10;
        break;
    }
    if ((tabuleiroRival[ln - 1][c - 1] == "[ ]") || (tabuleiroRival[ln - 1][c - 1] == "[-]"))
    {
        cout << "Você errou." << endl;
        tabuleiroRivalVisto[ln - 1][c - 1] = "[-]";
        errosJogador[i]++;
        contador[i]++;
        cout << "Pressione enter para continuar." << endl;
        cin.get();
        return 0;
    }
    else
    {
        cout << "Você acertou uma embarcação." << endl;
        tabuleiroRivalVisto[ln - 1][c - 1] = "[X]";
        tabuleiroRival[ln - 1][c - 1] = "[ ]";
        contador[i]++;
        cout << "Pressione enter para continuar." << endl;
        cin.get();
        return 1;
    }
}
// Realiza o ataque da máquina na dificuldade normal - retorna um valor do tipo int contabilizando o número de acertos - faz a passagem de uma matriz por parâmetro e trabalha com um ponteiro do tipo int
int ataque_maquina(string tabuleiro[][Tamanho], int *errosMaquina)
{
    bool repetir(true);
    int c, ln;
    char l;
    srand(time(NULL));
    repetir = true;
    ln = rand() % 9;
    if (ln == 0)
    {
        ln = 1;
    }
    c = rand() % 9;
    if (c == 0)
    {
        c = 1;
    }

    if ((tabuleiro[ln - 1][c - 1] == "[ ]") || (tabuleiro[ln - 1][c - 1] == "[-]"))
    {
        cout << "Seu oponente errou." << endl;
        tabuleiro[ln - 1][c - 1] = "[-]";
        errosMaquina[i]++;
        cout << "Pressione enter para continuar." << endl;
        cin.get();
        return 0;
    }
    else
    {
        cout << "Uma de suas embarcações foi atingida!." << endl;
        tabuleiro[ln - 1][c - 1] = "[X]";
        cout << "Pressione enter para continuar." << endl;
        cin.get();
        return 1;
    }
}
// Realiza o ataque pela máquina na dificuldade díficil - retorna um valor do tipo int contabilizando o número de acertos - faz a passagem de uma matriz por parâmetro e trabalha com um ponteiro do tipo int
int ataque_maquina_dificil(string tabuleiro[][Tamanho], int *errosMaquina)
{
    bool repetir(true);
    int c, ln;
    char l;
    srand(time(NULL));
    do
    {
        repetir = true;
        ln = rand() % 9;
        if (ln == 0)
        {
            ln = 1;
        }
        c = rand() % 9;
        if (c == 0)
        {
            c = 1;
        }
        if ((tabuleiro[ln - 1][c - 1] != "[X]") || (tabuleiro[ln - 1][c - 1] != "[-]"))
        {
            repetir = false;
        }
    } while (repetir);
    if ((tabuleiro[ln - 1][c - 1] == "[ ]") || (tabuleiro[ln - 1][c - 1] == "[-]"))
    {
        cout << "Seu oponente errou." << endl;
        tabuleiro[ln - 1][c - 1] = "[-]";
        errosMaquina[i]++;
        cout << "Pressione enter para continuar." << endl;
        cin.get();
        return 0;
    }
    else
    {
        cout << "Uma de suas embarcações foi atingida!." << endl;
        tabuleiro[ln - 1][c - 1] = "[X]";
        cout << "Pressione enter para continuar." << endl;
        cin.get();
        return 1;
    }
}
// Monta a tabela de ranking em ordem decrescente deixando os jogadores com mais pontuação no topo - sem retorno - trabalha com dois parâmetros do tipo string e int onde ambos são vetores
void ranking(string user[max_jogadores], int userPontos[max_jogadores])
{
    string auxString;
    int aux;
    for (int i = 0; i < max_jogadores - 1; i++)
    {
        for (int j = i; j < max_jogadores - 1; j++)
        {
            if (userPontos[i] < userPontos[j])
            {
                aux = userPontos[i];
                userPontos[i] = userPontos[j];
                userPontos[j] = aux;
                auxString = user[i];
                user[i] = user[j];
                user[j] = auxString;
            }
        }
    }
}
// Exibição do ranking de jogadores - sem retorno - trabalha com um parâmetro do registro usuario e um vetor do tipo int
void exibir_ranking(string user[max_jogadores], int userPontos[max_jogadores])
{
    for (int i = 0; i < max_jogadores; i++)
    {
        if (userPontos[i] > 0)
        {
            cout << user[i] << " ";
            cout << userPontos[i] << " Pontos" << endl;
        }
    }
}
// Calcula a porcentagem de acertos do jogador retornando um valor do tipo float e trabalhando com 3 parâmetros de ponteiro do tipo int
float porcent(int *acertosJ, int *errosJ, int *tiros)
{
    float porcent = (acertosJ[i] * 100) / tiros[i];
    return porcent;
}
// Registro que contém variáveis com informação do jogador
typedef struct
{
    string user[max_jogadores];
    char dificuldade;
} usuario;
// Preenche os dados do usuário no ínicio do jogo com o nome e dificuldade - sem retorno - faz a passagem do registro usuario como parâmetro
void preencheDados(usuario dados)
{
    
    cout << "              Insira o nome do jogador: " << endl;
    getline(cin, dados.user[i]);
    cout << "       Escolha seu nível de dificuldade: " << endl;
    cout << "                DIFÍCIL(D)       /       NORMAL(N)" << endl;
    cin >> dados.dificuldade;
}
// Funcionamento do jogo
int main()
{
    int pontosNecessarios = 3;
    int a;
    char Continuar = 'S';
    string tabuleiro[Tamanho][Tamanho];
    string tabuleiroRival[Tamanho][Tamanho];
    string tabuleiroRivalVisto[Tamanho][Tamanho];
    usuario info[max_jogadores];
    int tirosContador[max_jogadores] = {};
    int acertosJogadorContador[max_jogadores] = {};
    int errosJogadorContador[max_jogadores] = {};
    int acertosMaquinaContador[max_jogadores] = {};
    int errosMaquinaContador[max_jogadores] = {};
    int userPontos[max_jogadores] = {};
    SetConsoleOutputCP(CP_UTF8);

    introducao();
    cin.get();

    while (Continuar == 'S')
    {
        preencheDados(info[max_jogadores]);
        construcao_tabuleiro(tabuleiro);
        construcao_tabuleiro(tabuleiroRival);
        construcao_tabuleiro(tabuleiroRivalVisto);
        exibir_tabuleiro_jogador(tabuleiro);
        posicionar_submarinos(tabuleiro);
        posicionar_hidroavioes(tabuleiro);
        posicionar_embarcacoes_tabuleiro_rival(tabuleiroRival);
        do
        {
            exibir_tabuleiro_computador_cheat(tabuleiroRival);
            acertosJogadorContador[i] += ataque_jogador(tabuleiroRival, tabuleiroRivalVisto, tirosContador, errosJogadorContador);
            if ((info->dificuldade == 'N') || (info->dificuldade == 'n'))
            {
                acertosMaquinaContador[i] += ataque_maquina(tabuleiro, errosMaquinaContador);
            }
            else if ((info->dificuldade == 'D') || (info->dificuldade == 'd'))
            {
                acertosMaquinaContador[i] += ataque_maquina_dificil(tabuleiro, errosMaquinaContador);
            }
            system("cls");
            exibir_tabuleiro_jogador(tabuleiro);
            cout << acertosJogadorContador[i];
        } while ((acertosJogadorContador[i] != pontosNecessarios) && (acertosMaquinaContador[i] != pontosNecessarios) && ((errosJogadorContador[i] < 32)));
        exibir_tabuleiro_computador_cheat(tabuleiroRival);

        if ((acertosJogadorContador[i] == pontosNecessarios) || (acertosJogadorContador[i] > acertosMaquinaContador[i]))
        {
            cout << "             Parabéns, você ganhou!" << endl
                 << endl;
            cout << "Essas foram suas estatísticas. " << endl;
            cout << fixed << setprecision(2) << "Porcentagem de acertos: " << porcent(acertosJogadorContador, errosJogadorContador, tirosContador) << "%" << endl;
            cout << "Total de tiros realizados: " << tirosContador[i] << endl;
            cout << "Total de acertos: " << acertosJogadorContador[i] << endl;
            cout << "Total de erros: " << errosJogadorContador[i] << endl;
            userPontos[i] = acertosJogadorContador[i];
        }
        if ((acertosMaquinaContador[i] == pontosNecessarios) || (acertosMaquinaContador[i] > acertosJogadorContador[i]))
        {
            cout << "                  Você perdeu! :(" << endl
                 << endl;
            cout << "Essas foram suas estatísticas. " << endl;
            cout << fixed << setprecision(2) << "Porcentagem de acertos: " << porcent(acertosJogadorContador, errosJogadorContador, tirosContador) << "%" << endl;
            cout << "Total de tiros realizados: " << tirosContador[i] << endl;
            cout << "Total de acertos: " << acertosJogadorContador[i] << endl;
            cout << "Total de erros: " << errosJogadorContador[i] << endl;
            userPontos[i] = acertosJogadorContador[i];
        }
        if (acertosMaquinaContador[i] == acertosJogadorContador[i])
        {
            cout << "                    Empate!" << endl
                 << endl;
            cout << "Essas foram suas estatísticas. " << endl;
            cout << fixed << setprecision(2) << "Porcentagem de acertos: " << porcent(acertosJogadorContador, errosJogadorContador, tirosContador) << "%" << endl;
            cout << "Total de tiros realizados: " << tirosContador[i] << endl;
            cout << "Total de acertos: " << acertosJogadorContador[i] << endl;
            cout << "Total de erros: " << errosJogadorContador[i] << endl;
            userPontos[i] = acertosJogadorContador[i];
        }
        ranking(info->user, userPontos);
        cout << "                    Deseja jogar outra partida? (S/N)" << endl;
        cin >> Continuar;
        i++;
        system("cls");
    }
    cout << endl
         << endl
         << endl
         << endl;
    cout << "                              RANKING TOTAL" << endl;
    exibir_ranking(info->user, userPontos);

    cout << "                            Obrigado pelo jogo! :D" << endl;
    cin.get();
    cin.get();
}