
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct trabajo {
	int ini;
	int fin;
};

bool operator<(trabajo op1, trabajo op2) {
	return op1.ini < op2.ini || (op1.ini == op2.ini && op1.fin < op2.fin);
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<trabajo> lista, int ini , int fin) {
	int cogidos = 0;
	int i = 0;
	int max;
	
	if (lista.size() == 0 || lista[0].ini > ini)
		return 0;
	
	while (ini < fin) {
		max = -1;
		while (i < lista.size() && lista[i].ini <= ini) {
			if (lista[i].fin > max)
				max = lista[i].fin;
			i++;
		}
		if (max == -1)
			return 0;

		++cogidos;
		ini = max;
	}
	return cogidos;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int C, F, N;
	cin >> C >> F >> N;

	if (C == 0 && F == 0 && N == 0) {
		return false;
	}


	vector<trabajo> lista(N);

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		lista[i] = { a,b };
	}
		
	sort(lista.begin(), lista.end());

	int sol = resolver(lista,C,F);

	// escribir sol
	if (sol == 0)
		cout << "Imposible\n";
	else
		cout << sol << "\n";

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
