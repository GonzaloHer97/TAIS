
// Gonzao Hernández Hernández
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


class colocarGuardias {
private:
	vector<bool>visit;
	vector<bool>guardia;
	int numGuardias;
	bool posible;
	int g1, g2;

	void dfs(Grafo const& G, int v) {
		
		visit[v] = true;

		for (int w : G.ady(v)) {
			if (!visit[w]) {
				if (!guardia[v]) {
					guardia[w] = true;
					g1++;
				}
				else {
					guardia[w] = false;
					g2++;
				}
				dfs(G, w);
			}
			else if (guardia[v] == guardia[w]) {
				posible = false;
			}
		}
	}

public:
	colocarGuardias(Grafo const& G) : visit(G.V(), false), guardia(G.V(), false), posible(true), numGuardias(0), g1(0), g2(0) {
		for (int v = 0; v < G.V(); v++ && posible) {
			if (!visit[v]) {
				g2++;
				dfs(G, v);
				if (posible) {
					numGuardias += std::min(g1, g2);
				}
				g1 = 0;
				g2 = 0;
			}
		}
	}

	int minimo() const {
		return numGuardias;
	}

	bool esPosible() const {
		return posible;
	}

};


bool resuelveCaso() {
	int vertices, aristas;

	cin >> vertices;
	if (!std::cin)
		return false;

	std::cin >> aristas;

	Grafo grafo(vertices);
	
	for (int i = 0; i < aristas; ++i) {
		int a1, a2;
		cin >> a1 >> a2;
		grafo.ponArista(a1 - 1, a2 - 1);
	}

	colocarGuardias colocar(grafo);

	if (!colocar.esPosible()) {
		std::cout << "IMPOSIBLE" << '\n';
	}
	else {
		std::cout << colocar.minimo() << '\n';
	}

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
