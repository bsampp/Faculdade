#include <iostream>
#define N 15
using namespace std;
int main()
{
    double A[N], B[N], f;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        f = 1;
        for (int j = 1; j <= A[i]; j++)
        {
            f = f*j;
        }
        B[i] = f;
        cout << B[i] << " ";
    }
    return 0;
}