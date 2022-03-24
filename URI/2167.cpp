#include <iostream>
using namespace std;
int main() {

    int t, b=0, a[200], x;
    cin >> t;
    for(int i=0; i<t ;i++)
    {
        cin >> a[i];
    }
    x = 1;
    for(int i=0; i<t-1; i++)
    {
        if(a[i+1] < a[i])
        {
            x = 0;
            cout << i+2 << endl;
            break;
        }
    }
    if(x == 1)
    cout << "0" << endl;
    return 0;
}