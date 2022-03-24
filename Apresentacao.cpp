#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int numTestes;
    float Lado1T1, Lado2T1, Lado1T2, Lado2T2, areaT1, areaT2, Porcentagem, PorcentagemDif;
    string Bairro1, Bairro2;

    cin >> numTestes; // Aqui o programa pede a quantidade de comparações que serão feitas como entrada de dados.

    for (int i = 0; i < numTestes; i++) // Estrutura de repetição com váriavel de controle que utiliza o dado fornecido anteriormente.
    {
        cin.get();
        getline(cin, Bairro1);       
        cin >> Lado1T1 >> Lado2T1;  // O programa dessa vez pede as medidas dos dois lados do terreno.

        cin.get();
        getline(cin, Bairro2);
        cin >> Lado1T2 >> Lado2T2;

        areaT1 = (Lado1T1 * Lado2T1); // Área calculada com as medidas dos dois terrenos .
        areaT2 = (Lado1T2 * Lado2T2);

        cout << "Área do terreno do bairro " << Bairro1 << ": " << fixed << setprecision(2) << areaT1 << " metros quadrados;" << endl;
        cout << "Área do terreno do bairro " << Bairro2 << ": " << fixed << setprecision(2) << areaT2 << " metros quadrados;" << endl;

        if (areaT1 > areaT2) // Estrutura de decisão que garante a saída do dado de comparação das duas áreas dos terrenos.
        {
            Porcentagem = (100 * (float)areaT1) / (float)areaT2;
            PorcentagemDif = Porcentagem - 100;
            cout << "A área do terreno do bairro " << Bairro1 << " é " << fixed << setprecision(2) << PorcentagemDif << "% maior." << endl;
        }
        else if (areaT2 > areaT1)
        {
            Porcentagem = (100 * (float)areaT2) / (float)areaT1;
            PorcentagemDif = Porcentagem - 100;
            cout << "A área do terreno do bairro " << Bairro2 << " é " << fixed << setprecision(2) << PorcentagemDif << "% maior." << endl;
        }
        else
        {
            cout << "Os terrenos têm o mesmo valor de área." << endl;
        }
        cout << endl;
    }

    return 0;
}

