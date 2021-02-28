
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include "Digrafo.h" // propios o los de las estructuras de datos de clase

using namespace std;


class Tarea {
public:
	Tarea(Digrafo const& g) :visit(g.V(), false), apilado(g.V(), false), _orden(),hayciclo(false) {
		for (int v = 0; v <g.V(); v++) {
			if (!visit[v])
				dfs(g, v);
		}
	}
	bool hayCiclo() const { return hayciclo; }
	deque<int> const& orden() const {
		return _orden;
	}
private:
	vector<bool> visit;
	vector<bool> apilado;
	deque<int> _orden;
	bool hayciclo;

	void dfs(Digrafo const& g, int v) {
		apilado[v] = true;
		visit[v] = true;
		for (int w : g.ady(v)) {
			if (apilado[w]) {
				hayciclo = true;
				return;
			}
			if (!visit[w]) {
				dfs(g,w);
			}
		}
		_orden.push_back(v+1);
		apilado[v] = false;
	}

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	long int V, A;
	cin >> V >> A;
	if (!std::cin)  // fin de la entrada
		return false;
	Digrafo g(V);

	for (int i = 0; i < A; i++) {
		long int a, b;
		cin >> a >> b;
		g.ponArista(a - 1, b - 1);
	}
	Tarea tarea(g.inverso());
	// escribir sol
	if (tarea.hayCiclo()) {
		cout << "Imposible";
	}
	else
	{
		for (int i = 0; i < tarea.orden().size(); i++) {
			cout << tarea.orden()[i] << " ";
		}
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
