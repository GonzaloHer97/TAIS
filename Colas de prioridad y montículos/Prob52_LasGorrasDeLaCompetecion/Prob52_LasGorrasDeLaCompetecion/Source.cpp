
//Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "PriorityQueue.h"// propios o los de las estructuras de datos de clase

using namespace std;


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	long long int N;
	cin >> N;

	if (N==0)
		return false;

	PriorityQueue<long long int, less<long long int>> equipos;


	for (int i = 0; i < N; i++) {
		long long int a;
		cin >> a;
		equipos.push(a);
	}

	long long int gorras = 0;
	while (equipos.size() > 1) {
		auto equipo1 = equipos.top(); equipos.pop();
		auto equipo2 = equipos.top(); equipos.pop();
		gorras += equipo1 + equipo2;
		equipos.push(equipo1 + equipo2);
	}

	// escribir sol

	cout << gorras << "\n";

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
