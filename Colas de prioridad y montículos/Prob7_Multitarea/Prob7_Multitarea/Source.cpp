
// Gonzalo Hernández Hernández
// TASI39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>

#include "PriorityQueue.h"

using namespace std;

struct tarea {
	long long inicio;
	long long fin;
	long long int repeticicon;
};


bool operator<(tarea const& a, tarea const& b) {
	return a.inicio < b.inicio;
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int tareaUnica, tareaPeriodicas, minutos;
	cin >> tareaUnica;
	if (!std::cin)  // fin de la entrada
		return false;
	cin >> tareaPeriodicas >> minutos;

	PriorityQueue<tarea> cola;

	for (int i = 0; i < tareaUnica; i++) {
		long long int ini, fin;
		cin >> ini >> fin;
		cola.push({ ini,fin,0 });
	}

	for (int i = 0; i < tareaPeriodicas; i++) {
		long long int ini, fin, rep;
		cin >> ini >> fin >> rep;
		cola.push({ ini,fin,rep });
	}

	long long int minuAux = 0, periodo = -1;
	bool ok = false, terminado = false;

	while (minuAux < minutos && !cola.empty() && !terminado) {
		tarea aux = cola.top(); cola.pop();

		if (aux.inicio >= minutos)
			terminado = true;
		
		else if (aux.inicio < periodo || (!cola.empty() && aux.inicio == cola.top().inicio)) {
			ok = true;
			terminado = true;
		}
			
		else {
			minuAux = aux.inicio;
			periodo = aux.fin;
			if (aux.repeticicon > 0)
				cola.push({ aux.inicio + aux.repeticicon, aux.fin + aux.repeticicon, aux.repeticicon });
		}
	}

	if (ok)
		cout << "SI" << endl;
	else
		cout << "NO" << endl;

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
