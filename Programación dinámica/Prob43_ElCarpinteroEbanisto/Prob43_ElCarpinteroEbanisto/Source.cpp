
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "Matriz.h"// propios o los de las estructuras de datos de clase


using namespace std;


int corte(vector<int> & cortes, int L) {
	int n = cortes.size();
	Matriz<int> tabla(n, n, 0);
	for (int d = 2; d <= n; d++) {//diagonales
		for (int f = 0; f < n - d; f++) { //filas
			int c = f + d; //la columna es la fila + la diagonal
			tabla[f][c] = 1000000000;
			int mini;
			for (int k = f + 1; k < c; k++) {
				mini = tabla[f][k] + tabla[k][c] + (2 * (cortes[c] - cortes[f]));
				if (mini < tabla[f][c]) {
					tabla[f][c] = mini;
				}
			}
			
		}
	}

	return tabla[0][n - 1];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada


	int L, N;
	cin >> L >> N;
	if (L == 0 && N == 0)  // fin de la entrada
		return false;

	vector<int> vector(N + 2);
	vector[0] = 0;
	vector[N + 1] = L;

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		vector[i] = a;
	}

	cout << corte(vector, L) << "\n";
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
