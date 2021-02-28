
// Gonzalo Hernández Hrenández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


using namespace std;

struct tSolucion {
	int horaComienzo;
	int finalizacion;
};

bool operator<(tSolucion op1, tSolucion op2) {
	return (op1.finalizacion < op2.finalizacion || (op1.finalizacion == op2.finalizacion && op1.horaComienzo < op2.horaComienzo));
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<tSolucion> datos) {
	int contador = 1;
	sort(datos.begin(), datos.end());
	int primerElemento = datos[0].finalizacion;
	for (int i = 1; i < datos.size(); i++) {
		if (primerElemento + 10 <= datos[i].horaComienzo) {
			contador++;
			primerElemento = datos[i].finalizacion;
		}
	}
	return contador;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int duracion;
	int numCasos;
	cin >> numCasos;
	vector<tSolucion> datos(numCasos);
	if (numCasos == 0)
		return false;

	for (int i = 0; i < numCasos; i++) {
		int horas, minutos;
		char aux;
		cin >> horas >> aux >> minutos >> duracion;
		int tiempoInicio = horas * 60 + minutos;
		datos[i].horaComienzo = tiempoInicio;
		datos[i].finalizacion = tiempoInicio + duracion;
	}

	// escribir solución

	cout << resolver(datos) << "\n";

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
