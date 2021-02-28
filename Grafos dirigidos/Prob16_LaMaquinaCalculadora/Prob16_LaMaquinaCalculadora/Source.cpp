
// Gonzalo Hernández Hernández
// TAIS39
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include "Digrafo.h" // propios o los de las estructuras de datos de clase



using namespace std;


const int MAX = 10000;
const int INF = 1000000000;

int adyacente(int v, int i) {
	switch (i) {
		case 0: return (v + 1) % MAX;
		case 1: return (v * 2) % MAX;
		default: return (v / 3);
	}
}


int bfs(int origen, int destino) {
	if (origen == destino)return 0;
	vector<int> distancia(MAX, INF);
	distancia[origen] = 0;
	queue<int> cola; cola.push(origen);
	while (!cola.empty()) {
		int v = cola.front(); cola.pop();
		for (int i = 0; i < 3; i++)
		{
			int w = adyacente(v, i);
			if (distancia[w] == INF) {
				distancia[w] = distancia[v] + 1;
				if (w == destino)return distancia[w];
				else cola.push(w);
			}
		}
	}
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int origen, destino;
	cin >> origen >> destino;

	if (!std::cin)  // fin de la entrada
		return false;

	cout << bfs(origen, destino) << "\n";

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
