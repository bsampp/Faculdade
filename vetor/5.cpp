#include <iostream>
#define N 20
using namespace std;
int main()
{
    int A[N], B[N], j, i;

    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    j = N-1;
    for (i = 0; i < N; i++)
    {
        B[j] = A[i];
        j = j - 1;
    }
    for (int i = 0; i < N; i++)
    {
        cout << B[i] << " ";
    }
    
    return 0;
}