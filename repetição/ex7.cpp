#include <iostream>
using namespace std;
int main()
{
    int b = 3, expo = 0, p;
    
    while (expo <= 15)
    {
        if (expo == 0)
        {
            p = 1;
        }
        if (expo == 1)
        {
            p = b;
        }
        cout << p << endl;
        p *= b;
        expo++;  
    }
    return 0;
}
