
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "Matriz.h"// propios o los de las estructuras de datos de clase

using namespace std;

struct concierto{
	int grupos;
	int precio;
	
};

int resolver(vector<concierto> &vector, int P) {
	int n = vector.size();
	Matriz<int> matriz(n + 1, P + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= P; j++) {
			if (vector[i - 1].precio > j) {
				matriz[i][j] = matriz[i - 1][j];
			}
			else {
				matriz[i][j] = max(matriz[i - 1][j], matriz[i -1][j - vector[i - 1].precio] + vector[i - 1].grupos);
			}
		}
	}
	return matriz[n][P];
}



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada


	int P, N;
	cin >> P >> N;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<concierto> vector(N+1);
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		vector[i] = { a,b };
	}

	cout << resolver(vector, P) << "\n";


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
