
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

const int INFINITO = 1000000000;

struct tMoneda {
	int valor;
	int cantidad;
};

bool mayor(const tMoneda& a, const tMoneda& b) {
	return a.valor > b.valor;
}


int minimasMonedas(vector<tMoneda> &datos, const int &precioCoche) {
	Matriz<int> tabla(datos.size() + 1, precioCoche + 1, INFINITO);
	tabla[0][0] = 0;
	for (int i = 1; i <= datos.size(); i++) {
		tabla[i][0] = 0;
		for (int j = 1; j <= precioCoche; j++) {
			tabla[i][j] = tabla[i - 1][j];
			if (j >= datos[i - 1].valor) {
				int aux = INFINITO;

				for (int k = 1; k <= datos[i - 1].cantidad && j - k * datos[i - 1].valor >= 0 && j - k * datos[i - 1].valor <= precioCoche; k++) {
					aux = tabla[i - 1][j - k * datos[i - 1].valor] + k;
					if (aux < tabla[i][j]) {
						tabla[i][j] = aux;
					}
				}

			}
		}
	}
	return tabla[datos.size()][precioCoche];
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numMonedas, precioCoche;
	cin >> numMonedas;
	// leer los datos de la entrada
	if (!std::cin)  // fin de la entrada
		return false;
	vector<tMoneda>datos(numMonedas);

	for (int i = 0; i < numMonedas; i++) {
		cin >> datos[i].valor;
	}
	for (int i = 0; i < numMonedas; i++) {
		cin >> datos[i].cantidad;
	}
	cin >> precioCoche;
	sort(datos.begin(), datos.end(), mayor);

	int sol = minimasMonedas(datos, precioCoche);

	if (sol != INFINITO) {
		cout << "SI " << sol << "\n";
	}
	else {
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
