#include <iostream>
#define N 15
using namespace std;
int main()
{
    int A[N], B[N], C[N * 2], j, i;

    for (i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
    j = N;
    for (i = 0; i < N; i++)
    {
        C[i] = A[i];
        C[j] = B[i];
        j = j + 1;
    }
    for (int i = 0; i < (N*2); i++)
    {
        cout << C[i] << " ";
    }
    
    return 0;
}