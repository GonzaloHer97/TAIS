
// Gonzalo hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

#include "PriorityQueue.h"// propios o los de las estructuras de datos de clase

using namespace std;



struct registro {
	int momento;
	long long int id;
	int periodo;
};

bool operator<(registro const& a, registro const& b) {
	return a.momento < b.momento || (a.momento == b.momento && a.id < b.id);
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	long long int N;
	cin >> N;
	if (N == 0) return false;


	PriorityQueue<registro> cola;

	for (long long int i = 0; i < N; ++i) {//O(NlogN)siendo N el numero de registros
		long long int id_usu;
		int periodo;
		cin >> id_usu >> periodo;
		cola.push({ periodo, id_usu, periodo }); //O(logN)
	}

	long int envios;
	cin >> envios;

	while (envios--) {//O(KlogN) siendo K el numero de envios
		auto e = cola.top(); cola.pop();//O(1), O(logN)
		cout << e.id << '\n';
		e.momento += e.periodo;
		cola.push(e);//O(logN)
	}
	cout << "---\n";

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
