
// Gonzalo hernández Hernández
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


struct bateria {
	int id;
	int tiempo;
	int duracion;
};

bool operator<(const bateria &a, const bateria &b) {
	return a.tiempo < b.tiempo || (a.tiempo == b.tiempo && a.id < b.id);
}

void funcionamiento(PriorityQueue<bateria> &cola, vector<bateria> &repuesto, const int Z, const int T) {
	bateria aux = cola.top();
	int nRepuesto = 0;

	for (int i = 1; i <= T && !cola.empty(); i++) {

		while (aux.tiempo == i && !cola.empty()) {
			cola.pop();
			aux.duracion -= Z;
			if (aux.duracion > 0) {
				aux.tiempo = aux.duracion + i;
				cola.push(aux);
			}
			else {
				if (repuesto.size() > 0) {
					aux = repuesto[nRepuesto];
					repuesto.pop_back();
					nRepuesto++;
					aux.tiempo = aux.duracion + i;
					cola.push(aux);
				}
			}

			if (cola.size() > 0)
				aux = cola.top();
		}
	}

}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	
	int N;
	int aux;

	cin >> aux;


	if (!std::cin)  // fin de la entrada
		return false;

	PriorityQueue<bateria> baterias;
	int id = 0;
	for (int i = 0; i < aux; i++) {
		id++;
		int t;
		cin >> t;
		baterias.push({ id,t,t });
	}

	cin >> N;

	vector<bateria> repuesto;


	for (int i = 0; i < N; i++) {
		id++;
		int t;
		cin >> t;
		repuesto.push_back({ id,t,t });
	}


	int recarga, tiempo;

	cin >> recarga >> tiempo;


	funcionamiento(baterias, repuesto, recarga, tiempo);

	if (baterias.empty()) {
		cout << "ABANDONEN INMEDIATAMENTE LA BASE" << "\n";
	}
	else {
		if (baterias.size() != aux) {
			cout << "FALLO EN EL SISTEMA\n";
		}
		else {
			cout << "CORRECTO\n";
		}

		while (!baterias.empty())
		{
			auto aux = baterias.top(); baterias.pop();
			cout << aux.id << " " << aux.tiempo << "\n";
		}
	}

	cout << "---" << "\n";

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
