
// Gonzalo Hernández Hernández
// TAIS39
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

using namespace std;

const int INFINITO = 1000000000;

struct bombillas {
	int coste;
	int potencia;
};


pair<int, int> bombilla(const vector<bombillas> v, const int &Pmax, const int &Pmin) {
	int n = v.size();
	Matriz<int> tabla(n, Pmax + 1, INFINITO);

	tabla[0][0] = 0;
	for (int i = 1; i <= n - 1; i++) {
		tabla[i][0] = 0;
		for (int j = 1; j <= Pmax; j++) {
			if (v[i].potencia > j) {
				tabla[i][j] = tabla[i - 1][j];
			}
			else {
				tabla[i][j] = min(tabla[i - 1][j], tabla[i][j - v[i].potencia] + v[i].coste);
			}
		}
	}

	int costeMin = tabla[n - 1][Pmin];
	int p = Pmin;

	for (int i = Pmin; i <= Pmax; i++) {
		if (costeMin > tabla[n - 1][i]) {
			costeMin = tabla[n - 1][i];
			p = i;
		}
	}


	return{ costeMin, p };
}


bool resuelveCaso() {
	int N, pMax, pMin;

	cin >> N >> pMax >> pMin;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<bombillas> v(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i].potencia;
	}
	for (int i = 1; i <= N; i++) {
		cin >> v[i].coste;
	}

	pair<int, int> sol = bombilla(v, pMax, pMin);

	if (sol.first == INFINITO) {
		cout << "IMPOSIBLE\n";
	}
	else {
		cout << sol.first << " " << sol.second << "\n";
	}

	return true;
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
