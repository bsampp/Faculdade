#include <iostream>
using namespace std;
int main(){
    int satisfeitos = 0, naoSatisfeitos = 0;
	int cidadaos, i, opiniao;

	cin >> cidadaos;

	for (i = 0; i < cidadaos; i++)
	{
		cin >> opiniao;

		if (opiniao == 0)
			satisfeitos++;
		else
			naoSatisfeitos++;

	}

	if (satisfeitos > naoSatisfeitos)
        cout << "Y" << endl;

	else
        cout << "N" << endl;
		
    return 0;
}