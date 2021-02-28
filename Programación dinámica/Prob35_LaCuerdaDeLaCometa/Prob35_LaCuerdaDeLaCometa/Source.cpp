
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

#include "EnterosInf.h"
#include "Matriz.h"// propios o los de las estructuras de datos de clase

using namespace std;


struct cordel {
	long long int longitud;
	long long int coste;
};

long long int INF = 1000000000000000000;
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
long long int  diferentes(vector<cordel> &v, int L) {
	int n = v.size();
	Matriz<long long int > nudos(n +1, L+1, 0);

	nudos[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		nudos[i][0] = 1;
		for (int j = 1; j <= L; ++j) {
			if (v[i - 1].longitud > j) {				nudos[i][j] = nudos[i - 1][j];				}			else {				nudos[i][j] = nudos[i - 1][j] + nudos[i - 1][j - v[i - 1].longitud];			}
		}
	}

	return nudos[n][L];
}

long long int  minNum(vector<cordel> &v, int L) {
	int n = v.size();
	Matriz<long long int > nudos(n + 1, L + 1, INF);

	nudos[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		nudos[i][0] = 0;
		for (int j = 1; j <= L; ++j) {
			if (v[i - 1].longitud > j) {				nudos[i][j] = nudos[i - 1][j];			}			else {				nudos[i][j] = min(nudos[i-1][j], nudos[i - 1][j - v[i - 1].longitud] + 1);			}
		}
	}

	return nudos[n][L];
}


long long int minPrecio(vector<cordel> &v, int L) {
	int n = v.size();
	Matriz<long long int> nudos(n + 1, L + 1, INF);
	nudos[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		nudos[i][0] = 0;
		for (int j = 1; j <= L; ++j) {
			if (v[i - 1].longitud > j) {				nudos[i][j] = nudos[i - 1][j];			}			else {				nudos[i][j] = min(nudos[i - 1][j], nudos[i-1][j - v[i - 1].longitud] + v[i - 1].coste);			}
		}
	}

	return nudos[n][L];
}

bool resuelveCaso() {

	// leer los datos de la entrada

	int N, L;
	cin >> N >> L;

	if (!std::cin)  // fin de la entrada
		return false;

	vector<cordel> vector;

	for (int i = 0; i < N; i++) {
		long long int a, b;
		cin >> a>>b;
		vector.push_back({ a,b });
	}

	long long int dif = diferentes(vector, L);
	long long int minN = minNum(vector, L);
	long long int minP = minPrecio(vector, L);
	if (dif == 0) {
		cout << "NO" << "\n";
	}
	else {
		cout << "SI ";
		cout << dif << " " << minN << " " << minP << "\n";
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
