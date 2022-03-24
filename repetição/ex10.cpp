#include <iostream>
using namespace std;
int main()
{
    int c = 10, f;
    

    for (int i = 0; i < 10; i++)
    {
        f = c * 1.8 + 32;
        cout << c << "C = " << f << "F" << endl;
        c += 10;
    }
    
    return 0;
}
