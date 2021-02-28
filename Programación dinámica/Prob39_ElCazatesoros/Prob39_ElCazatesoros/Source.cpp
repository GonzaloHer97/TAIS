
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "Matriz.h"// propios o los de las estructuras de datos de clase


using namespace std;

struct cofre {
	int profundidad;
	int tiempo;
	int oro;
	
};



double mochila_rec(vector<cofre> const& obj, int i, int j, Matriz<double> & mochila) {
	if (mochila[i][j] != -1) // subproblema ya resuelto
		return mochila[i][j];
	if (i == 0 || j == 0) mochila[i][j] = 0;
	else if (obj[i - 1].tiempo > j)
		mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
	else
		mochila[i][j] = max(mochila_rec(obj, i - 1, j, mochila),mochila_rec(obj, i - 1, j - obj[i - 1].tiempo, mochila) + obj[i - 1].oro);
	return mochila[i][j];
}


double mochila(vector<cofre> const& objetos, int M) {
	int n = objetos.size();
	int cont = 0;
	Matriz<double> mochila(n + 1, M + 1, -1);
	double valor = mochila_rec(objetos, n, M, mochila);
	// cálculo de los objetos
	int i = n, j = M;
	vector<bool> sol(n, false);
	while (i > 0 && j > 0) {
		if (mochila[i][j] != mochila[i - 1][j]) {
			sol[i - 1] = true; j = j - objetos[i - 1].tiempo;
			cont++;
		}
		--i;
	}

	cout << valor << "\n";
	cout << cont << "\n";

	for (int i = 0; i < sol.size(); i++) {
		if (sol[i]) {
			cout << objetos[i].profundidad << " " << objetos[i].oro << "\n";
		}
	}

	cout << "---\n";



	return valor;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada

	int T, N;
	cin >> T >> N;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<cofre> cofres;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		cofres.push_back({a, a+(2*a),b });
	}

	mochila(cofres, T);

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
