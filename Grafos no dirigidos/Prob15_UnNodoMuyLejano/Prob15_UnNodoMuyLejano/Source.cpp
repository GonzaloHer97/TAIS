
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>


#include "Grafo.h"// propios o los de las estructuras de datos de clase

using namespace std;

class Nodo {
public:
	Nodo(Grafo const& g, int origen, int ttl) :visit(g.V(), false), ttl(ttl),dist(g.V()), posibles(g.V()) {
		bfs(g, origen,ttl);
		int aux = posibles;
		for (int i = 0; i < aux; i++) {
			if (visit[i] && dist[i] <= ttl)
				posibles--;
		}
	}
	int tam(){
		return posibles;
	}

private:
	vector<bool> visit;
	vector<int> dist;
	int posibles;
	int ttl;


	void bfs(Grafo const& g, int v, int ttl) {
		queue<int> cola;
		dist[v] = 0; visit[v] = true;
		cola.push(v);
		while (!cola.empty()) {
			int v = cola.front(); cola.pop();
			for (int w : g.ady(v)) {
				if (!visit[w]){
					dist[w] = dist[v] + 1;
					visit[w] = true;
					cola.push(w);
				}
			}
		}
	}
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N, C;
	cin >> N >> C;
	if (!std::cin)  // fin de la entrada
		return false;
	Grafo grafo(N);
	for (int i = 0; i < C; i++) {
		int a, b;
		cin >> a >> b;
		grafo.ponArista(a - 1, b - 1);
	}

	int aux;
	cin >> aux;

	for (int j = 0; j < aux; j++) {
		int a, b;
		cin >> a >> b;
		Nodo nodo(grafo, a-1, b);
		cout << nodo.tam() << "\n";
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
