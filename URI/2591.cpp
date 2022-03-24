#include<iostream>
using namespace std;
int main(){
	int c, i, a_1, a_2, a_total;
	string ataque;

	cin >> c;

	while(c--) {
		cin >> ataque;

		i = 0;
		a_1 = 0;
		a_2 = 0;

		while(ataque[i] != '\0') {
			if(ataque[i] == 'h') {
				i++;
				while(ataque[i] == 'a') {
					a_1++;
					i++;
				}
			}
			if(ataque[i] == 'k') {
				i++;
				while(ataque[i] == 'a') {
					a_2++;
					i++;
				}
			}

			i++;
		}

		a_total = a_1 * a_2;

		cout << "k";

		while(a_total--) {
			cout << "a";
		}

		cout << endl;
	}

	return 0;
}