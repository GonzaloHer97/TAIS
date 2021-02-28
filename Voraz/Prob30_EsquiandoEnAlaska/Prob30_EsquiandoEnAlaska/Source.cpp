
//Gonzalo hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<int> esquiadores, vector<int> esquis) {
	int contador = 0;
	for (int i = 0; i < esquiadores.size(); i++) {
		contador += abs(esquiadores[i] - esquis[i]);
	}
	return contador;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (N ==0)
		return false;

	
	vector<int> esquiadores(N);
	vector<int> esquis(N);
	int aux;
	for (int i = 0; i < N; i++) {
		cin >> aux;
		esquiadores[i] = aux;
	}
	for (int i = 0; i < N; i++) {
		cin >> aux;
		esquis[i] = aux;
	}

	sort(esquiadores.begin(), esquiadores.end());
	sort(esquis.begin(), esquis.end());

	
	// escribir sol
	cout << resolver(esquiadores, esquis) << "\n";

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
