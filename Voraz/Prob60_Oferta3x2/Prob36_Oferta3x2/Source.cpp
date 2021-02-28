
// Gonzalo Hernándz Hernández
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

	int N;
	cin >> N;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<int> libros(N);

	for (int i = 0; i < N; i++) {
		cin >> libros[i];
	}

	sort(libros.begin(), libros.end(), greater<int>());

	if (N < 3) {
		cout << 0 << "\n";
	}
	else {
		int mayor = 0;
		int total = 0;
		int cont = 0;
		int descuento = 0;
		while (total < N) {
			if (cont == 2) {
				descuento += libros[mayor];
				cont = 0;
			}
			else {
				cont++;
			}
			mayor++;
			total++;
		}
		cout << descuento << "\n";
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
