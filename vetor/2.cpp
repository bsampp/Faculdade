#include <iostream>
using namespace std;
int main()
{
    int A[20], B[20], C[20], a, b;

    for (int i = 0; i < 20; i++)
    {
        cin >> A[i] >> B[i];
        C[i] = A[i] - B[i];
    }
    for (int j = 0; j < 20; j++)
    {
        cout << C[j] << " ";
    }
    return 0;
}
