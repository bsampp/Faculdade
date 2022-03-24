#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float salary, nSalary, per;

    cin >> salary;

    if (salary <= 400)
    {
        per = 15;
        nSalary = salary + (per * salary)/100;
    }
    else if (salary > 400 && salary <= 800)
    {
        per = 12;
        nSalary = salary + (per * salary)/100;
    }
    else if (salary > 800 && salary <= 1200)
    {
        per = 10;
        nSalary = salary + (per * salary)/100;
    }
    else if (salary > 1200 && salary <= 2000)
    {
        per = 7;
        nSalary = salary + (per * salary)/100;
    } 
    else
    {
        per = 4;
        nSalary = salary + (per * salary)/100;

    }
      
    cout << "Novo salario: " << fixed << setprecision(2) << nSalary << endl;
    cout << "Reajuste ganho: " << fixed << setprecision(2) << (nSalary - salary) << endl;
    cout << "Em percentual: " << fixed << setprecision(0) << per << " %" << endl;

    return 0;
}
