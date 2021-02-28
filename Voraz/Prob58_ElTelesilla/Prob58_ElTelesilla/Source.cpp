
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	int P, N;
	cin >> P >> N;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> pasajeros(N);

	for (int i = 0; i < N; i++) {
		cin >> pasajeros[i];
	}

	sort(pasajeros.begin(), pasajeros.end());

	int cont = 0;
	int menor = 0;
	int mayor = N - 1;
	int telesillas = 0;

	while (cont < N) {
		if (pasajeros[menor] + pasajeros[mayor] > P) {
			cont++;
			mayor--;
		}
		else  {
			cont += 2;
			mayor--;
			menor++;
		}
		telesillas++;
	}

	cout << telesillas << "\n";

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
