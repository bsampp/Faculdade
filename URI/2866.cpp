#include <iostream>

using namespace std;

int main() {
    
    int n, cont = 0;
    
    cin >> n;
    cin.ignore();
    
    while(cont < n) {
        
        string palavra;
        int pos = 0;
        
        cin >> palavra;
    
        while (palavra[pos++] != '\0');
        
        while (--pos >= 0) {
            if (palavra[pos] >= 'a' and palavra[pos] <= 'z') {
                cout << palavra[pos];
            }
        }
        
        cout << endl;
        cont++;
        
    }
    return 0;
}