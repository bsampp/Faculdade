#include <iostream>
using namespace std;
int main(){
    int a, n, f, quantidade = 0;

    cin >> a >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> f;
        if (f * a >= 40000000)
        {
            quantidade++;
        }
        
    }
    cout << quantidade << endl;
    


    return 0;
}