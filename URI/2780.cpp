#include <iostream>

using namespace std;

int main() {
    
    int distancia;
    
    cin >> distancia;
    
    if (distancia <= 800)
        cout << "1" << endl;
    else if (distancia <= 1400)
        cout << "2" << endl;
    else 
        cout << "3" << endl;
    
    return 0;
}