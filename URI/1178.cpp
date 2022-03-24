#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double n, v[100];

    cin >> n;
    v[0] = n;
    cout << "N[0] = " << setprecision(4) << fixed << n << endl;

    for(int i = 1; i < 100; i++){

    v[i] = v[i-1]/2;
        
    cout << "N[" << i << "] = " << setprecision(4) << fixed << v[i] << endl;

    }
    return 0;
}