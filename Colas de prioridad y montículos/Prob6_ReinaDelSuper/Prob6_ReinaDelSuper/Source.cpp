

// Gonzalo hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase



using namespace std;


struct clientes {
	int numCaja;
	int tiempo;
};

bool operator<(clientes const& a, clientes const& b) {
	return a.tiempo < b.tiempo || (a.tiempo == b.tiempo) && a.numCaja < b.numCaja;
}


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int nCajas, nClientes;
	cin >> nCajas >> nClientes;
	if (nCajas == 0 && nClientes==0)
		return false;

	PriorityQueue<clientes> cola;

	for (long long int i = 0; i < nClientes; i++) {
		int tiempo;
		cin >> tiempo;
		if (cola.size() < nCajas) {
			cola.push({cola.size()+1, tiempo });
		}
		else if (cola.size() == nCajas) {
			int numCaja = cola.top().numCaja;
			tiempo += cola.top().tiempo;
			cola.pop();
			cola.push({numCaja,tiempo});
		}
	}

	if (cola.size() == nCajas) {
		cout << cola.top().numCaja << endl;
	}
	else {
		cout << cola.size() + 1 << endl;
	}
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
