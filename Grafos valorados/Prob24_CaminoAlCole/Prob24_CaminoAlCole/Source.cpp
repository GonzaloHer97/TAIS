
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "GrafoValorado.h"// propios o los de las estructuras de datos de clase
#include "IndexPQ.h"


using namespace std;


class Camino {
public:
	Camino(GrafoValorado<int> const& g) :distTo(g.V(), 10000000000), pq(g.V()), caminos(g.V(),0) {
		resolver(g, 0);
	}

	int Caminos() {
		return caminos.back();
	}

private:

	vector<int> distTo;
	IndexPQ<int> pq;
	vector<int> caminos;


	void resolver(GrafoValorado<int> const& g, int v) {
		distTo[v] = 0;
		pq.push(v, 0);
		caminos[v] = 1;

		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();

			for (auto w : g.ady(v)) {
				int b = w.otro(v);

				if (distTo[b] > distTo[v] + w.valor()) {
					distTo[b] = distTo[v] + w.valor();
					pq.update(b, distTo[b]);
					caminos[b] = caminos[v];
				}
				else {
					if (distTo[b] == distTo[v] + w.valor()) {
						caminos[b] += caminos[v];
					}
				}
			}
		}
	}
};



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int V, A;
	cin >> V >> A;

	if (!std::cin)  // fin de la entrada
		return false;

	GrafoValorado<int> grafo(V);

	for (int i = 0; i < A; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		grafo.ponArista({ a - 1,b - 1,v });
	}

	// escribir sol
	Camino camino(grafo);

	cout << camino.Caminos() << "\n";


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
