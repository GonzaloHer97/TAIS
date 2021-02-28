
// Gonzalo Hernández Hernández
//TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "EnterosInf.h" // propios o los de las estructuras de datos de clase

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
vector<int> resolver(vector<int> const& M, int C) {

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int puntuacion, sector;
	cin >> puntuacion >> sector;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> sectores;

	for (int i = 0; i < sector; i++) {
		int a;
		cin >> a;
		sectores.push_back(a);
	}
	int n = sectores.size();

	vector<EntInf> dianas(puntuacion + 1, Infinito);
	dianas[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = sectores[i - 1]; j <= puntuacion; ++j) {
			dianas[j] = min(dianas[j], dianas[j - sectores[i - 1]] + 1);
		}
	}
	vector<int> sol;

	if (dianas[puntuacion] != Infinito) {
		cout << dianas[puntuacion] << ": ";
		int i = n, j = puntuacion;
		while (j > 0) {
			if (sectores[i - 1] <= j && dianas[j] == dianas[j - sectores[i - 1]] + 1) {
				// tomamos una moneda de tipo i
				sol.push_back(sectores[i - 1]);
				j = j - sectores[i - 1];
			}
			else // no tomamos más monedas de tipo i
				--i;
		}

		for (int i = 0; i < sol.size(); i++) {
			cout << sol[i] << " ";
		}
		cout << "\n";
	}
	else {
		cout << "Imposible" << "\n";
	}
	// escribir sol

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
