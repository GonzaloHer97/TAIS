
// Gonzalo Hernández Hernández
// TAIS39 

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "Matriz.h" // propios o los de las estructuras de datos de clase

using namespace std;

/*
 tablero(i,j) = Maximo valor posible hasta la fila i y la columna j del mismo.

 tablero(i,j) = max(tablero[i-1][j-1],tablero[i-1][j],tablero[i-1][j+1]) + tablero[i][j]

 Costes:
	O(N^2) en espacio.
	O(N^2 + N) en tiempo
 */


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resuelve(Matriz<int>& tablero, int& colIni, int& sumaTotal, const int& N) {

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			tablero[i][j] = std::max(tablero[i - 1][j - 1], std::max(tablero[i - 1][j], tablero[i - 1][j + 1])) + tablero[i][j];
	}

	sumaTotal = tablero[N][0];
	colIni = 0;

	for (int i = 1; i <= N; ++i) {
		if (sumaTotal < tablero[N][i]) {
			sumaTotal = tablero[N][i];
			colIni = i;
		}
	}

}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	Matriz<int> matriz(N + 1, N + 2, 0);
	for (int i = 1; i <= N; ++i) {
		for (int n = 1; n <= N; ++n)
			std::cin >> matriz[i][n];
	}

	// escribir sol
	int sol = 0, max = 0;
	resuelve(matriz, sol, max, N);

	std::cout << max << " " << sol << "\n";

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
