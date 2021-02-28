
// Gonzalo Hernández Hernández
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




// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(PriorityQueue < int, greater<int>> &v9, PriorityQueue < int, greater<int>> &v15, int &drones) {
	

	while (!v9.empty() && !v15.empty()) {
		int horas = 0;
		vector<int> v9usadas;
		vector<int> v15usadas;
		for (int i = 0; i < drones && !v9.empty() && !v15.empty(); i++) {
			
			int pila9 = v9.top(); v9.pop();
			int pila15 = v15.top(); v15.pop();
			
			if (pila9 < pila15) {
				pila15 -= pila9;
				horas += pila9;
				v15usadas.push_back(pila15);
			}
			else {
				pila9 -= pila15;
				horas += pila15;
				if(pila9 > 0)
					v9usadas.push_back(pila9);
			}

			}

		for (int i = 0; i < v9usadas.size(); i++) {
			v9.push(v9usadas[i]);
		}
		for (int i = 0; i < v15usadas.size(); i++) {
			v15.push(v15usadas[i]);
		}

		cout << horas << " ";
	}
	cout << "\n";

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int drones, pilas9, pilas15;
	cin >> drones >> pilas9 >> pilas15;
	if (!std::cin)  // fin de la entrada
		return false;

	PriorityQueue <int, greater<int>> v9;
	PriorityQueue <int, greater<int>> v15;

	for (int i = 0; i < pilas9; i++) {
		int a;
		cin >> a;
		v9.push(a);
	}
	for (int i = 0; i < pilas15; i++) {
		int a;
		cin >> a;
		v15.push(a);
	}

	resolver(v9, v15, drones);
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
