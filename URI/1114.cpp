#include <iostream>
using namespace std;
int main() {
    int password;

    password = 0;

    while(password != 2002) {       
        cin >> password;
        if (password == 2002)
        {
            cout << "Acesso Permitido" << endl;
            break;
        }
        else
        {
            cout << "Senha Invalida" << endl;
        }
        

    }
    return 0;
}