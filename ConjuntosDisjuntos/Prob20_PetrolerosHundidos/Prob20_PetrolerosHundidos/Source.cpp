
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "ConjuntosDisjuntos.h"// propios o los de las estructuras de datos de clase

using namespace std;

using Mapa = vector<string>;

class Petroleo {
public:

	Petroleo(Mapa const& M, ConjuntosDisjuntos & conjunto) :F(M.size()), C(M[0].size()), visit(F, vector<bool>(C, false)),
	hayPetroleo(false){
		for (int i = 0; i < F; i++) {
			for (int j = 0; j < C; j++) {
				if (!visit[i][j] && M[i][j] == '#') {
					unir(M, conjunto, i, j, C);
				}
			}
		}
	}

	void unir(Mapa const & M, ConjuntosDisjuntos & petroleo, int i, int j, int C) {

		hayPetroleo = true;

		if (correcta(i - 1, j - 1) && M[i - 1][j - 1] == '#')
			petroleo.unir(i * C + j, (i - 1) * C + j - 1);

		if (correcta(i - 1, j) && M[i - 1][j] == '#')
			petroleo.unir(i * C + j, (i - 1) * C + j);

		if (correcta(i - 1, j + 1) && M[i - 1][j + 1] == '#')
			petroleo.unir(i * C + j, (i - 1) * C + j + 1);

		if (correcta(i, j - 1) && M[i][j - 1] == '#')
			petroleo.unir(i * C + j, i * C + j - 1);

		if (correcta(i, j + 1) && M[i][j + 1] == '#')
			petroleo.unir(i * C + j, i * C + j + 1);

		if (correcta(i + 1, j - 1) && M[i + 1][j - 1] == '#')
			petroleo.unir(i * C + j, (i + 1) * C + j - 1);

		if (correcta(i + 1, j) && M[i + 1][j] == '#')
			petroleo.unir(i * C + j, (i + 1) * C + j);

		if (correcta(i + 1, j + 1) && M[i + 1][j + 1] == '#')
			petroleo.unir(i * C + j, (i + 1) * C + j + 1);

	}

	int maximoConjunto(ConjuntosDisjuntos & conjunto) const {

		if (hayPetroleo)
			return max(conjunto.maxConjunto(), 1);
		return 0;
	}

private:
	int F, C;
	vector<vector<bool>> visit;
	bool hayPetroleo;
	bool correcta(int i, int j)const {
		return 0 <= i && i < F && 0 <= j && j < C;
	}

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int F, C;
	cin >> F >> C;
	if (!std::cin)  // fin de la entrada
		return false;

	cin.ignore();

	Mapa mapa(F);
	ConjuntosDisjuntos conjunto(F*C);

	for (string & linea : mapa)
		getline(cin, linea);


	Petroleo petroleo(mapa, conjunto);
	cout <<  petroleo.maximoConjunto(conjunto) <<" ";

	long int nuevo;
	cin >> nuevo;

	for (long int i = 0; i < nuevo; i++) {
		int a, b;
		cin >> a >> b;
		mapa[a-1][b-1] = '#';
		petroleo.unir(mapa, conjunto, a - 1, b - 1, C);
		cout << petroleo.maximoConjunto(conjunto) << " ";
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
