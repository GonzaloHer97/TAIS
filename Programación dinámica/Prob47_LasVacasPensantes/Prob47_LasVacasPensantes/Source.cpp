
// Gonzalo Hernández Hernández
//TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "Matriz.h"// propios o los de las estructuras de datos de clase


using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<int> & datos) {
	int n = datos.size();
	Matriz<int> matriz(n, n, 0);

	for (int i = 1; i < n - 1; i++) {
		matriz[i][i + 1] = max(datos[i], datos[i + 1]);
	}
	for (int i = 1; i < n; i++) {
		matriz[i][i] = datos[i];
	}

	for (int d = 2; d < n - 1; d++) {
		for (int i = 1; i < n - d; i++) {
			int j = i + d;

			int izq, dcha;

			//elegirDcha
			if (datos[j - 1] > datos[i])
				dcha = matriz[i][j - 2] + datos[j];
			else
				dcha = matriz[i + 1][j - 1] + datos[j];

			//elegirIzda

			if (datos[j] > datos[i + 1])
				izq = matriz[i + 1][j - 1] + datos[i];
			else
				izq = matriz[i + 2][j] + datos[i];

			matriz[i][j] = max(izq, dcha);
		}
	}
	return matriz[1][n- 1];


}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	int N;
	cin >> N;

	if (N==0)
		return false;

	vector <int> v(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	// escribir sol
	cout << resolver(v) << "\n";

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
