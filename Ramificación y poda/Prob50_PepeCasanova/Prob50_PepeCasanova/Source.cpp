
// Gonzalo Hernández Hernández
//TAIS39
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct cancion {
	double duracion;
	double puntuacion;

};

struct Nodo {
	vector<bool> sol;
	int k;
	int tiempoC;
	int tiempoC2;
	double puntuacion;
	double puntuacion_est;
	bool operator<(Nodo const& otro) const {
		return otro.puntuacion_est > puntuacion_est;
	}
};

double calculo_voraz(vector<cancion> const& canciones, double M, Nodo const& X) {
	double hueco = 2 * M - X.tiempoC - X.tiempoC2, puntuacion_est = X.puntuacion;
	int i = X.k + 1;
	while (i < canciones.size() && canciones[i].duracion <= hueco) {
		if (canciones[i].duracion <= hueco) {
			hueco -= canciones[i].duracion;
			puntuacion_est += canciones[i].puntuacion;
			i++;
		}

	}
	if (i < canciones.size()) {
		puntuacion_est += (hueco / canciones[i].duracion) * canciones[i].puntuacion;
	}
	return puntuacion_est;
}

void cinta(vector<cancion> const& canciones, double M, vector<bool>& sol_mejor, double& beneficio_mejor) {
	int N = canciones.size();
	//se genera la raiz
	Nodo Y;
	Y.sol = vector<bool>(N);
	Y.k = -1;
	Y.puntuacion = Y.tiempoC = 0, Y.tiempoC2 = 0;
	Y.puntuacion_est = calculo_voraz(canciones, M, Y);
	priority_queue<Nodo> cola;
	cola.push(Y);
	beneficio_mejor = -1;
	while (!cola.empty() && cola.top().puntuacion_est > beneficio_mejor) {
		Y = cola.top(); cola.pop();
		Nodo X(Y);
		X.k++;
		//Probamos 1er hijo meterlo en la primera cara
		if (Y.tiempoC + canciones[X.k].duracion <= M) {
			X.sol[X.k] = true;
			X.tiempoC = Y.tiempoC + canciones[X.k].duracion;
			X.puntuacion = Y.puntuacion + canciones[X.k].puntuacion;
			X.puntuacion_est = Y.puntuacion_est;
			if (X.k == N - 1) {
				sol_mejor = X.sol; beneficio_mejor = X.puntuacion;
			}
			else cola.push(X);


		}
		//Probamos 2 hijo metarla en la cara 2
		if (Y.tiempoC2 + canciones[X.k].duracion <= M) {
			X.sol[X.k] = true;
			X.tiempoC2 = Y.tiempoC2 + canciones[X.k].duracion;
			X.puntuacion = Y.puntuacion + canciones[X.k].puntuacion;
			X.puntuacion_est = Y.puntuacion_est;
			if (X.k == N - 1) {
				sol_mejor = X.sol; beneficio_mejor = X.puntuacion;
			}
			else cola.push(X);


		}
		//No meterla
		X.sol[X.k] = false;
		X.puntuacion = Y.puntuacion; X.tiempoC = Y.tiempoC;
		X.puntuacion_est = calculo_voraz(canciones, M, X);
		if (X.puntuacion_est > beneficio_mejor) {
			if (X.k == N - 1) {
				sol_mejor = X.sol; beneficio_mejor = X.puntuacion;
			}
			else {
				cola.push(X);
			}
		}
	}
}

// función que resuelve el problema
// comentario sobre el puntuacion, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numCanciones, duracion;
	double beneficionMejor;
	// leer los datos de la entrada
	cin >> numCanciones;
	if (numCanciones == 0)
		return false;
	cin >> duracion;
	vector<cancion> canciones(numCanciones);
	vector<bool> solMejor(numCanciones);
	for (int i = 0; i < numCanciones; i++) {
		cin >> canciones[i].duracion >> canciones[i].puntuacion;
	}

	cinta(canciones, duracion, solMejor, beneficionMejor);
	cout << beneficionMejor << "\n";


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
