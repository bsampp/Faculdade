using namespace std;
#include <cstdio>
#include <iostream>

int preencheNotas(float *v, int n)
{
    float nota;
    for (int i = 0; i < n; i++)
    {
        cin >> nota;
        *v = nota;
        v++;
    }
    return 0;
}
void exibeMedia(float *v, int n)
{
    float media;
    float *f = &v[n];
    while (v < f)
    {
        media += *v;
        v++;
    }
    cout << "Media: " << media/n << endl;
}
int main()
{
    float *v;
    int alunos;
    cin >> alunos;
    if (!(v = new (nothrow) float[alunos]))
    {
        cout << "falha na alocacao" << endl;
        return -1;
    }
    preenche(v, alunos);
    exibe(v, alunos);
    delete[] v;
    v = NULL;

    return 0;
}