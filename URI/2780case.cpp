#include <iostream>

using namespace std;

int main() {
    
    int distancia;
    
    cin >> distancia;
    switch (distancia)
    {
    case 0 ... 800:
        cout << "1" << endl;
        break;
    case 801 ... 1400:
        cout << "2" << endl;
        break;
    case 1401 ... 2000:
        cout << "3" << endl;
    }
    
    return 0;
}
