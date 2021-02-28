
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<int> v, int l) {
	int parches = 1;
	int actual = v[0];
	int parche = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] > v[i - 1]) {
			if (parche + abs(actual - v[i]) <= l) {
				parche += abs(actual - v[i]);
				actual = v[i];
			}
			else {
				parches++;
				actual = v[i];
				parche = 0;
			}
		}
	}
	return parches;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int agujeros, longitud;

	cin >> agujeros >> longitud;
	if (!std::cin)  // fin de la entrada
		return false;
	vector<int> manguera(agujeros);

	for (int i = 0; i < agujeros; i++) {
		int a;
		cin >> a;
		manguera[i] = a;
	}

	int sol = resolver(manguera, longitud);

	// escribir sol

	cout << sol << "\n";

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
