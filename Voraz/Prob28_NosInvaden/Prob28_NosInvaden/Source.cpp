
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(priority_queue<int, vector<int>,less<int>>  enemigos, priority_queue<int, vector<int>, less<int>> defensores,int n) {
	int victorias = 0;
	int def = defensores.top(); defensores.pop();
	for(int i = 0; i < n;i++){
		int ene = enemigos.top(); enemigos.pop();
		if (def >= ene) {
			victorias++;
			def = defensores.top(); defensores.pop();
		}
	}
	return victorias;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;
	if (!std::cin)  // fin de la entrada
		return false;


	priority_queue<int,vector<int>,less<int>> enemigos;
	priority_queue<int, vector<int>,less<int>> defensores;

	int aux;

	for (int i = 0; i < N; i++) {
		cin >> aux;
		enemigos.push(aux);
	}
	for (int i = 0; i < N; i++) {
		cin >> aux;
		defensores.push(aux);
	}



	int sol = resolver(enemigos,defensores,N);

	// escribir sol

	cout << sol << "\n";

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
