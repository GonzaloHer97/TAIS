
// Gonzalo Hernández Hernández
// TAIS39
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "DigrafoValorado.h"// propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

using namespace std;

class Navegador {
public:
	Navegador(DigrafoValorado<int> const& g, int orig) :origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
		dist[origen] = 0;
		pq.push(origen, 0);
		while (!pq.empty()) {
			int v = pq.top().elem; pq.pop();
			for (auto a : g.ady(v)) {
				relajar(a);
			}
		}
	}

	bool hayCamino(int v) const { return dist[v] != INF; }

	int distancia(int v) const { return dist[v]; }

private:
	const int INF = 100000000000;
	int origen;
	vector<int> dist;
	vector<AristaDirigida<int>> ulti;
	IndexPQ<int> pq;

	void relajar(AristaDirigida<int> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			ulti[w] = a;
			pq.update(w, dist[w]);
		}
	}
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int V;
	cin >> V;

	if (V == 0)
		return false;

	DigrafoValorado<int> grafo(V);
	vector<int> tiempos(V);

	for (int i = 0; i < V; i++) {
		int n;
		cin >> n;
		tiempos[i] = n;
	}
	int A;

	cin >> A;

	for (int i = 0; i < A; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		grafo.ponArista({ a - 1,b - 1,v + tiempos[a-1]});
	}

	Navegador nav(grafo, 0);

	if (!nav.hayCamino(V-1)) {
		cout << "IMPOSIBLE";
	}
	else
	{
		cout << nav.distancia(V - 1) + tiempos[V-1];
	}

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
