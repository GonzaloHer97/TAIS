
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#include "GrafoValorado.h"// propios o los de las estructuras de datos de clase

using namespace std;

class Camiones {
public:

	Camiones(GrafoValorado<int> const& g,long int origen,long int fin,long int anchura) : visit(g.V(), false), anchura(anchura),ok(false) {
		dfs(g, origen, fin);
		ok = visit[fin];
	}

	bool visitado() {
		return ok;
	}

private:
	vector<bool>visit;
	int anchura;
	bool ok;

	void dfs(GrafoValorado<int> const& g,int v, int fin) {
		visit[v] = true;
		for (Arista<int> w : g.ady(v)) {
			if (!visit[w.otro(v)] && w.valor() >= anchura) {
				visit[w.otro(v)] = true;
				if (w.otro(v) == fin)
					return;
				dfs(g, w.otro(v),fin);
			}
		}

	}


};


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	long int V, E;
	cin >> V >> E;

	if (!std::cin)  // fin de la entrada
		return false;

	GrafoValorado<int> grafo(V);

	for (int i = 0; i < E; i++) {
		long int a, b, v;
		cin >> a >> b >> v;
		grafo.ponArista({ a - 1,b - 1,v });
	}
	
	// escribir sol

	int K;
	cin >> K;

	for (int i = 0; i < K; i++) {
		long int a, b, v;
		cin >> a >> b >> v;
		Camiones c({ grafo,a - 1,b - 1,v });

		if (c.visitado())
			cout << "SI" << "\n";
		else
			cout << "NO" << "\n";
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
