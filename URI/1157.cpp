#include <iostream>
using namespace std;
int main() {
    int n, a;

    a = 1;

    cin >> n;

    while (a <= n)
    {
        if (n % a == 0)
        {
            cout << a << endl;
        }
        a++;
        
    }


    return 0;
}