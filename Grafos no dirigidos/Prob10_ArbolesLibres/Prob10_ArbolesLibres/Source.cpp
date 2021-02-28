
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Grafo.h" // propios o los de las estructuras de datos de clase

using namespace std;


class CaminosDFS {
private:
	vector<bool> visit;
	vector<int> ant;
	int s;
	void dfs(Grafo const& g, int v) {
		visit[v] = true;
		for (int w : g.ady(v)) {
			if (!visit[w]) {
				ok++;
				ant[w] = v;
				dfs(g, w);
			}
		}
	}
public:
	int ok;
	CaminosDFS(Grafo const& g, int s) :visit(g.V(), false), ant(g.V()), s(s),ok(1){
		dfs(g,s);
	}
};
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	long int A, V;
	cin >> V;
	if (!std::cin)  // fin de la entrada
		return false;
	cin >> A;

	Grafo grafo(V);

	for (int i = 0; i < A; i++) {
		int ini, fin;
		cin >> ini >> fin;
		grafo.ponArista(ini, fin);
	}

	CaminosDFS dfs(grafo, 0);

	if (dfs.ok == V && grafo.A() == grafo.V() - 1)
		cout << "SI" << "\n";
	else
	{
		cout << "NO" << "\n";
	}
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
