#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    float s = 0, n = 1;

    do
    {
        s += 1/n;
        n++;

    } while (n <= 100);
    
cout << fixed << setprecision(2) << s << endl;

    return 0;
}