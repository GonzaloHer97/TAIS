
// Gonzalo hernández Hernández
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

class Repartir {
public:
	Repartir(DigrafoValorado<int> const& g, int orig) :origen(orig), dist(g.V(), INF), pq(g.V()) {
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
	IndexPQ<int> pq;

	void relajar(AristaDirigida<int> a) {
		int v = a.desde(), w = a.hasta();
		if (dist[w] > dist[v] + a.valor()) {
			dist[w] = dist[v] + a.valor();
			pq.update(w, dist[w]);
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

	DigrafoValorado<int> grafo(V);

	for (int i = 0; i < A; i++) {
		int a, b, valor;
		cin >> a >> b >> valor;
		grafo.ponArista({ a - 1,b - 1,valor });
	}


	bool ok = true;
	int o, p, resul = 0;

	cin >> o >> p;

	Repartir paquete(grafo, o - 1);
	Repartir vuelta(grafo.inverso(), o - 1);


	for (int i = 0; i < p; i++) {
		int aux;
		cin >> aux;
		if (!paquete.hayCamino(aux - 1) || !vuelta.hayCamino(aux - 1))
			ok = false; 
		else
			resul += paquete.distancia(aux - 1) + vuelta.distancia(aux - 1); 
	}

	// escribir sol
	

	if (ok) {
		cout << resul;
	}
	else
		cout << "Imposible";

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
