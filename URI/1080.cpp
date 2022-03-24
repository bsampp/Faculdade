#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int i = 0, n;
    int a = 0;
    int m = 0;

    do
    {
        cin >> n;

       if (n > a)
       {
           a = n;
           m = i;
       }
        
        i++;
    } while (i < 100);

    cout << a << endl << m + 1  << endl;
    
    return 0;
}