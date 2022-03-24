#include <iostream>

using namespace std;

int main(){

	int n;

	cin >> n;

	while(n--){
		int num;
		int cont = 0;
		cin >> num;

		for (int i = 1; i < num / 2 + 1; i++){

			if (num % i == 0)
				cont += i;
		}
		if (cont == 1)
			cout << num << " eh primo" << endl;
		else
			cout << num << " nao eh primo" << endl;


	}

}