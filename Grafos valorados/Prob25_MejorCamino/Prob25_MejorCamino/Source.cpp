
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
#include "GrafoValorado.h"

const int INFINITO = 1000000000;

using namespace std;

class GrafoCiudad {
public:
	GrafoCiudad(GrafoValorado<int> g, int origen, int destino) :visit(g.V(), false), distanciaBfs(g.V(), INFINITO),  distTo(g.V(), INFINITO), aristasV(g.V(),0), pq(g.V()) {
		dest = destino;
		bfs(g, origen);
		Dijkstra(g, origen);
		if (visit[dest])
			aristas = aristasV[dest];

	}

	bool hayCamino()const {
		return visit[dest];
	}

	bool iguales()const {
		return distanciaBfs[dest] == aristas;
	}

	int distancia() {
		return distTo[dest];
	}

private:


	vector<bool> visit;
	vector<int> distanciaBfs;
	int dest;
	int aristas;
	vector<int> distTo;
	vector<int> aristasV;
	IndexPQ<pair<int, int>> pq;

	void bfs(GrafoValorado<int> const&g, int s) {
		queue<int> q;
		distanciaBfs[s] = 0;
		visit[s] = true;
		q.push(s);

		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (Arista<int> e : g.ady(v)) {
				int w = e.otro(v);
				if (!visit[w]) {
					distanciaBfs[w] = distanciaBfs[v] + 1;
					visit[w] = true;
					q.push(w);
				}
			}
		}
	}

	
	void Dijkstra(GrafoValorado<int> g, int s) {
		distTo[s] = 0;
		pq.push(s, { 0,0 });
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (Arista<int> e : g.ady(v)) {
				int w = e.otro(v);
				if (distTo[w] > distTo[v] + e.valor()) {
					distTo[w] = distTo[v] + e.valor();
					aristasV[w] = aristasV[v] + 1;
					pq.update(w, { distTo[w],aristasV[w] });
				}
				else if (distTo[w] == distTo[v] + e.valor() && aristasV[w] > aristasV[v] + 1) {
					aristasV[w] = aristasV[v] + 1;
					pq.update(w, { distTo[w], aristasV[w] });
				}
			}
		}
	}

};

bool resuelveCaso() {
	int N, C;

	cin >> N >> C;

	if (!std::cin)  // fin de la entrada
		return false;

	int c1, c2, longitud;

	GrafoValorado<int> grafo(N);

	for (int i = 0; i < C; i++) {
		cin >> c1 >> c2 >> longitud;
		c1--; c2--;
		grafo.ponArista({ c1, c2, longitud });
	}


	int consultas;
	cin >> consultas;

	for (int i = 0; i < consultas; i++) {
		cin >> c1 >> c2;
		c1--; c2--;
		GrafoCiudad g(grafo, c1, c2);

		if (g.hayCamino()) {
			if (g.iguales()) {
				cout << g.distancia() << " SI";
			}
			else {
				cout << g.distancia() << " NO";
			}

		}
		else {
			cout << "SIN CAMINO";
		}
		cout << "\n";
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