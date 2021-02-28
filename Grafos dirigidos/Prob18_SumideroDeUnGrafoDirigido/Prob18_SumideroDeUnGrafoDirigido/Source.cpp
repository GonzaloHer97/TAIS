
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Digrafo.h" // propios o los de las estructuras de datos de clase

using namespace std;



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	long int V, A;

	cin >> V >> A;

	if (!std::cin)  // fin de la entrada
		return false;

	
	vector<vector<int>> matriz(V, vector<int>(V));

	for (int i = 0; i < A; i++) {
		long int a, b;
		cin >> a >> b;
		matriz[a][b]++;
	}

	// escribir sol

	bool ok = false;
	long int candidato = 0;
	long int salida = 0;
	long int entrada = 0;

	for (int i = 1; i < V; i++) {
		if (matriz[candidato][i] == 1) {
			candidato = i;
		}
	}


	for (int i = 0; i < V; i++) {
		if (matriz[candidato][i] == 1) 
			salida++;

	}
	for (int i = 0; i < V; i++) {
		if (matriz[i][candidato] == 1) 
			entrada++;
	}

	if (entrada == V - 1 && salida  == 0)
		ok = true;

	if (ok)
		cout << "SI " << candidato;
	else
		cout << "NO";
	cout << "\n";
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
