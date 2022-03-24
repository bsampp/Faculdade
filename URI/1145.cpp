#include <iostream>
using namespace std;
int main() {
    int n = 1, i = 1, x, y;

    cin >> x >> y;

    do
    {
        if (x == n)
        {
            cout << i << endl;
            n = 1;
        }
        else
        {
            cout << i << " ";
            n++;
        }
        i++;
        
    } while (i <= y);
     
    return 0;
}