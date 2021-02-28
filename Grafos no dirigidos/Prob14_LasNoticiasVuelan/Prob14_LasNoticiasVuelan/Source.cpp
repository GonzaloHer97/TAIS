
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Grafo.h"// propios o los de las estructuras de datos de clase

using namespace std;



class LasNoticias {
public:
	LasNoticias(Grafo const& g) :visit(g.V(), false), usuarios(g.V()), numGrupo(0)  {
		for (int i = 0; i < g.V(); i++) {
			if (!visit[i]) {
				visit[i] = true;
				grupos.push_back(dfs(g, i));
				numGrupo++;
			}
		}
		
	}
	int numConectados(int n) {
		return grupos[usuarios[n]];
	}


private:

	vector<bool> visit;
	vector<int> usuarios;
	vector<int> grupos;
	int numGrupo;

	int dfs(Grafo const& g, int num) {
		int resul = 1;
		usuarios[num] = numGrupo;
		for (int w: g.ady(num)) {
			if (!visit[w]) {
				visit[w] = true;
				usuarios[w] = numGrupo;
				resul += dfs(g, w);
			}
		}

		return resul;
	}


};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	long int V, G;

	cin >> V >> G;

	if (!std::cin)  // fin de la entrada
		return false;
	Grafo grafo(V);

	for (int i = 0; i < G; i++) {
		long int n, a ,b;
		cin >> n;
		if (n != 0) {
			cin >> a;
			for (int j = 1; j < n; j++) {
				cin >> b;
				grafo.ponArista(a - 1, b - 1);
				a = b;
			}
		}
	}

	LasNoticias resul(grafo);


	for (int i = 0; i < V; i++) {
		cout << resul.numConectados(i) << " ";
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
