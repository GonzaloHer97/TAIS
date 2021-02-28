
// Gonzalo Hernández Hernández

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

#include "Digrafo.h"// propios o los de las estructuras de datos de clase

using namespace std;


class SeryEsc {
public:
	SeryEsc(vector<int> const& g, int v, int K) :visit(g.size(), false), dist(g.size()), jugadas(0) {
		bfs(g, v, K);
		jugadas = dist[g.size() - 1];
	}
	int sol() {
		return jugadas;
	}

private:
	vector<bool> visit;
	vector<int> dist;
	int jugadas;


	void bfs(vector<int> const &g, int v,int K) {
		queue<int> cola;
		dist[v] = 0; visit[v] = true;
		cola.push(v);
		while (!cola.empty()) {
			int v = cola.front(); cola.pop();
			for (int i = 1; i <= K && v + i < g.size(); i++) {
				int w = v + i;
				if (g[w] != 0) {
					w = g[w];
				}
				if (!visit[w]) {
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
	int N, K, S, E;
	cin >> N >> K >> S >> E;

	if (N==0&&K==0&&S==0&&E==0)
		return false;

	vector<int> auz(N*N);

	for (int i = 0; i < S + E; i++) {
		int a, b;
		cin >> a >> b;
		auz[a - 1] = b - 1;
	}

	SeryEsc sol(auz, 0, K);

	// escribir sol
	cout << sol.sol() << "\n";

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
