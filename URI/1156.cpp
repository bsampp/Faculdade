#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float s = 1, n = 3, d = 2;

    do
    {
        s += n / d;
        n += 2;
        d *= 2;


    } while (n < 40);
    
cout << fixed << setprecision(2) << s << endl;

    return 0;
}