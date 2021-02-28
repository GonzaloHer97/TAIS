
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Grafo.h"


using namespace std;


class MaximaCompConexa
{
public:
	MaximaCompConexa(Grafo const& g) :visit(g.V(), false), maxim(0) {
		for (int v = 0; v < g.V(); ++v) {
			if (!visit[v]) {
				int tam = dfs(g, v);
				maxim = max(maxim, tam);
			}
		}
	}
	int maximo() const {
		return maxim;
	}

private:
	vector<bool> visit;
	int maxim;

	int dfs(Grafo const& g, int v) {
		visit[v] = true;
		int tam = 1;
		for (int w : g.ady(v)) {
			if (!visit[w])
				tam += dfs(g, w);
		}
		return tam;
	}
};



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

	// leer los datos de la entrada
	long int N, M;
	cin >> N >> M;
	

	Grafo grafo(N);

	for (int i = 0; i < M; i++) {
		long int A, B;
		cin >> A >> B;
		grafo.ponArista(A-1, B-1);
	}
	// escribir solución

	MaximaCompConexa mcc(grafo);
	cout << mcc.maximo() << "\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
