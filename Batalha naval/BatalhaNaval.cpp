//Desenvolvedor: Bruno Sampietro
//Data: 28/10/2021
//Funcionalidade: Jogo de batalha naval

#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define Tamanho 8
#define max_jogadores 100
using namespace std;
//
const int numEmbarcTotal = 3;
int numSubmarinos, numHidroav;
bool repetir(true);
int i = 0;
//Váriaveis tabuleiros
string tabuleiro[Tamanho][Tamanho];
string tabuleiroRival[Tamanho][Tamanho];
string tabuleiroRivalVisto[Tamanho][Tamanho];
char linha[Tamanho] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
string coluna[Tamanho] = {"   1", "2", "3", "4", "5", "6", "7", "8"};
int c, ln;
char l;
//Construção dos tabuleiros
void construcao_tabuleiros()
{
    for (int l = 0; l < Tamanho; l++)
    {
        for (int c = 0; c < Tamanho; c++)
        {
            tabuleiro[l][c] = "[ ]";
            tabuleiroRival[l][c] = "[ ]";
            tabuleiroRivalVisto[l][c] = "[ ]";
        }
    }
}
//Exibição do tabuleiro do jogador
void exibir_tabuleiro_jogador()
{
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
//Exibição do tabuleiro do oponente
void exibir_tabuleiro_computador_cheat()
{
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
                cout << tabuleiroRival[0][j] << " ";
            }
        }
        else
        {
            cout << linha[l] << " ";
            for (int c = 0; c < Tamanho; c++)
            {
                cout << tabuleiroRival[l][c] << " ";
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
void exibir_tabuleiro_computador()
{
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
//Atribuição da posição dos submarinos
void posicionar_submarinos()
{
    SetConsoleOutputCP(CP_UTF8);
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
        exibir_tabuleiro_jogador();
        numSubmarinos--;
    } while (numSubmarinos > 0);
}
//Atribuição da posição dos hidroaviões
char posVH, posCB, posED;
void posicionar_hidroavioes()
{
    SetConsoleOutputCP(CP_UTF8);
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
        exibir_tabuleiro_jogador();
        numHidroav--;
    } while (numHidroav > 0);
}

//Atribuição das embarcações do tabuleiro rival
int posPC;
void posicionar_embarcacoes_tabuleiro_rival()
{
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
//Ataque realizado pelo jogador
int acertosJ[max_jogadores] = {};
int tiros[max_jogadores] = {};
int errosJ[max_jogadores] = {};
int errosM = 0, acertosM = 0;
void ataque_jogador()
{
    SetConsoleOutputCP(CP_UTF8);
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
    if (tabuleiroRival[ln - 1][c - 1] == "[ ]")
    {
        cout << "Você errou." << endl;
        tabuleiroRivalVisto[ln - 1][c - 1] = "[-]";
        errosJ[i]++;
        tiros[i]++;
    }
    else if ((tabuleiroRival[ln - 1][c - 1] == "[S]") || (tabuleiroRival[ln - 1][c - 1] == "[H]"))
    {
        cout << "Você acertou uma embarcação." << endl;
        tabuleiroRivalVisto[ln - 1][c - 1] = "[X]";
        tabuleiroRival[ln - 1][c - 1] = "[ ]";
        acertosJ[i]++;
        tiros[i]++;
    }
    cout << endl;
    cin.get();
}
//Ataque realizado pela máquina
void ataque_maquina()
{
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

    if (tabuleiro[ln - 1][c - 1] == "[ ]")
    {
        cout << "Seu oponente errou." << endl;
        tabuleiro[ln - 1][c - 1] = "[-]";
        errosM++;
    }
    else if ((tabuleiro[ln - 1][c - 1] == "[S]") || (tabuleiro[ln - 1][c - 1] == "[H]"))
    {
        cout << "Uma de suas embarcações foi atingida!." << endl;
        tabuleiro[ln - 1][c - 1] = "[X]";
        acertosM++;
    }
    cout << "Pressione enter para continuar." << endl;
    cin.get();
}
//Ataque realizado pela máquina na difialdade díficil
void ataque_maquina_dificil()
{
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
    if (tabuleiro[ln - 1][c - 1] == "[ ]")
    {
        cout << "Seu oponente errou." << endl;
        tabuleiro[ln - 1][c - 1] = "[-]";
        errosM++;
    }
    else if ((tabuleiro[ln - 1][c - 1] == "[S]") || (tabuleiro[ln - 1][c - 1] == "[H]"))
    {
        cout << "Uma de suas embarcações foi atingida!." << endl;
        tabuleiro[ln - 1][c - 1] = "[X]";
        acertosM++;
    }
    cout << "Pressione enter para continuar." << endl;
    cin.get();
}
//Ranking de jogadores
string user[max_jogadores];
int userPontos[max_jogadores] = {};
string auxString;
int aux;
void ranking()
{
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
//Exibição do ranking
void exibir_ranking()
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
//Estatísticas
void estatisticas()
{
    float porcent;
    porcent = (acertosJ[i] * 100) / tiros[i];
    cout << "Essas foram suas estatísticas. " << endl;
    cout << fixed << setprecision(2) << "Porcentagem de acertos: " << porcent << "%" << endl;
    cout << "Total de tiros realizados: " << tiros[i] << endl;
    cout << "Total de acertos: " << acertosJ[i] << endl;
    cout << "Total de erros: " << errosJ[i] << endl;
}

//Funcionamento do jogo
int pontosNecessarios = numEmbarcTotal * 5;
int a;
char Continuar = 'S', Dificuldade;
int main()
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
    cin.get();

    while (Continuar == 'S')
    {
        cout << "              Insira o nome do jogador: " << endl;
        cin >> user[i];
        cout << "       Escolha seu nível de dificuldade: " << endl;
        cout << "                DIFÍCIL(D)       /       NORMAL(N)" << endl;
        cin >> Dificuldade;
        construcao_tabuleiros();
        exibir_tabuleiro_jogador();
        posicionar_submarinos();
        posicionar_hidroavioes();
        posicionar_embarcacoes_tabuleiro_rival();
        do
        {
            exibir_tabuleiro_computador();
            ataque_jogador();
            if ((Dificuldade == 'N') || (Dificuldade == 'n'))
            {
                ataque_maquina();
            }
            else if ((Dificuldade == 'D') || (Dificuldade == 'd'))
            {
                ataque_maquina_dificil();
            }
            system("cls");
            exibir_tabuleiro_jogador();
        } while ((acertosJ[i] != pontosNecessarios) && (acertosM != pontosNecessarios) && ((errosJ[i] < 32)));
        exibir_tabuleiro_computador_cheat();

        if ((acertosJ[i] == pontosNecessarios) || (acertosJ[i] > acertosM))
        {
            cout << "             Parabéns, você ganhou!" << endl
            << endl;
            estatisticas();
            userPontos[i] = acertosJ[i];
        }
        if ((acertosM == pontosNecessarios) || (acertosM > acertosJ[i]))
        {
            cout << "                  Você perdeu! :(" << endl
                 << endl;
            estatisticas();
            userPontos[i] = acertosJ[i];
        }
        if (acertosM == acertosJ[i])
        {
            cout << "                    Empate!" << endl
                 << endl;
            estatisticas();
            userPontos[i] = acertosJ[i];
        }
        ranking();
        cout << "                    Deseja jogar outra partida? (S/N)" << endl;
        cin >> Continuar;
        i++;
        system("cls");
    }
    cout << endl << endl << endl << endl;
    cout << "                              RANKING TOTAL" << endl;
    exibir_ranking();

    cout << "                            Obrigado pelo jogo! :D" << endl;
    cin.get();
    cin.get();
}
