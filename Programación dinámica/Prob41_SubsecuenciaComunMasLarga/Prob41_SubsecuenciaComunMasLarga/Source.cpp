
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Matriz.h"  // propios o los de las estructuras de datos de clase
using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
string resolver(const string &cadena1, const string &cadena2) {
	string palabra = "", subcadena = "";
	int size1 = cadena1.size();
	int size2 = cadena2.size();
	Matriz<int> cadenas(size1 + 1, size2 + 1, 0);
	for (int i = 1; i <= size1; i++) {
		for (int j = 1; j <= size2; j++) {
			if (cadena1[i - 1] == cadena2[j - 1]) {
				cadenas[i][j] = cadenas[i - 1][j - 1] + 1;
			}
			else {
				cadenas[i][j] = max(cadenas[i - 1][j], cadenas[i][j - 1]);
			}
		}
	}
	int tamanio = cadenas[size1][size2];
	int i = size1, j = size2;
	while (tamanio > 0) {
		if (cadena1[i - 1] == cadena2[j - 1]) {
			subcadena += cadena1[i - 1];
			tamanio--;
			i--;
			j--;

		}
		else {
			if (cadenas[i][j] == cadenas[i][j - 1]) {
				j--;
			}
			else {
				i--;
			}
		}
	}
	for (int i = subcadena.size(); i > 0; i--) {
		palabra += subcadena[i - 1];
	}
	return palabra;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	string cadena1, cadena2;
	// leer los datos de la entrada
	cin >> cadena1 >> cadena2;
	if (!std::cin)  // fin de la entrada
		return false;

	cout << resolver(cadena1, cadena2) << "\n";

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
