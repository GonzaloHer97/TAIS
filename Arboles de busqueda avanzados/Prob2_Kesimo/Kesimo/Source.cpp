//Gonzalo Hernández Hernández
//TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "TreeSet_AVL.h"

using namespace std;

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n, posicion, busquedas;
	Set<int> arbol = Set<int>();
	// leer los datos de la entrada
	cin >> n;
	if (n == 0)
		return false;

	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		arbol.insert(p);
	}

	cin >> busquedas;
	for (int j = 0; j < busquedas; j++) {
		cin >> posicion;
		int claves = arbol.k_esimo(posicion);
		if (claves == -1) std::cout << "??\n";
		else std::cout << claves << '\n';
	}

	std::cout << "---\n";

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
