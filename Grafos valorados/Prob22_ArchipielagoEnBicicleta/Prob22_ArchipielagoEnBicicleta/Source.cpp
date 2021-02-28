
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


#include "GrafoValorado.h"// propios o los de las estructuras de datos de clase
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

class Archipielagos {
public:
	Archipielagos(GrafoValorado<int> const& g) :coste(0), ok(false) {
		PriorityQueue<Arista<int>> pq(g.aristas());
		ConjuntosDisjuntos cjto(g.V());
		while (!pq.empty()) {
			auto a = pq.top(); pq.pop();
			int v = a.uno(), w = a.otro(v);
			if (!cjto.unidos(v, w)) {
				cjto.unir(v, w);
				lista.push_back(a);
				coste += a.valor();
				if (lista.size() == g.V() - 1)
					break;
			}
		}
		ok = lista.size() == g.V() - 1;
	}

	bool esOk() const {
		return ok;
	}

	long int total() {
		return coste;
	}

private:
	long int coste;
	vector<Arista<int>> lista;
	bool ok;


};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	long int I, P;

	cin >> I >> P;

	if (!std::cin)  // fin de la entrada
		return false;
	GrafoValorado<int> grafo(I);

	for (int i = 0; i < P; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		grafo.ponArista({ a - 1,b - 1,v });
	}
	// escribir sol
	Archipielagos archipielgao(grafo);

	if (archipielgao.esOk()) {
		cout << archipielgao.total();
	}
	else
	{
		cout << "No hay puentes suficientes";
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
