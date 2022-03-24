#include <iostream>
using namespace std;

int main(){
    int n, x, i = 0;

    cin >> n;

    do
    {
        cin >> x;
        
        if(x == 0){
            cout << "NULL" << endl;
        }else if(x % 2 == 0){
            if(x > 0){
                cout << "EVEN POSITIVE" << endl;
            }else{
                cout << "EVEN NEGATIVE" << endl;
            }

        }else{
            if(x > 0){
                cout << "ODD POSITIVE" << endl;
            }else{
                cout << "ODD NEGATIVE" << endl;
            }
        }

        i++;

    } while (i < n);
    
        
    return 0;
}