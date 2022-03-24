#include <iostream>
using namespace std;
int main()
{
    int A[8], B[8], a;

    for (int i = 0; i < 8; i++)
    {
        cin >> A[i];
        B[i] = A[i]*3;
    }
    for (int j = 0; j < 8; j++)
    {
        cout << B[j] << " ";
    }
    return 0;
}
