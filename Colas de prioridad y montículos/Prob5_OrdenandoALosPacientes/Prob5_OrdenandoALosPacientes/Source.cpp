

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


struct paciente {
	string nombre;
	long long int gravedad;
	long long int llegada;
};

bool operator<(paciente const& a, paciente const& b) {
	return a.gravedad > b.gravedad || (a.gravedad == b.gravedad) && a.llegada <b.llegada;
}


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	long long int n;
	cin >> n;
	if (n == 0)
		return false;

	PriorityQueue<paciente> cola;
	long long int llegada = 0;

	for (long long int i = 0; i < n; i++) {
		char tipo;
		cin >> tipo;
		if (tipo == 'I') {
			string nombre; long long int gravedad;
			cin >> nombre >> gravedad;
			cola.push({ nombre, gravedad, llegada });
			llegada++;
		}
		else if (tipo == 'A') {
			cout << cola.top().nombre << endl;
			cola.pop();
		}
	}

	cout << "---" << endl;


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
