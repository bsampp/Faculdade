#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    int dividendo, divisor, a = 0, c = 0;

    cin >> dividendo >> divisor;

    do
    {
        a += divisor;
        c++;

    } while (a <= dividendo);

    c--;

    cout << "o divisor cabe " << c << " vez(es) dentro do dividendo." << endl;
    
    return 0;
}
