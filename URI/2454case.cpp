#include <iostream>

using namespace std;

int main() {
    int p, r;
    
    cin >> p >> r;
    switch (p)
    {
    case 0:
        cout << "C" << endl;
        break;
    case 1:
        switch (r)
        {
        case 1:
            cout << "A" << endl;
            break;
        case 0:
            cout << "B" << endl;
            break;

        }
    }
    return 0;
}
