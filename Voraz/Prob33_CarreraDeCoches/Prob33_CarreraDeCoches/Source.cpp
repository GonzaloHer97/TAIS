
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;



int resolver(vector<int>& pilas, const int& voltios) {
	int ini = 0, fin = pilas.size() - 1, contCoches = 0;
	sort(pilas.begin(), pilas.end());
	while (ini < fin) {
		if (pilas[ini] + pilas[fin] >= voltios) { //Ordenamos de forma que haya las menores diferencias entre los pares de pilas.
			contCoches++;
			ini++;
			fin--;
		}
		else ini++;
	}

	return contCoches;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int numPilas, voltajeMin;
	cin >> numPilas >> voltajeMin;
	vector<int> pilas(numPilas);
	for (int i = 0; i < numPilas; i++) {
		cin >> pilas[i];
	}
	// leer los datos de la entrada

	cout << resolver(pilas, voltajeMin) << "\n";

}



int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
