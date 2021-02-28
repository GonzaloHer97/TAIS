
//Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct edificio{
	int este;
	int oeste;
};


bool operator<(edificio op1, edificio op2) {
	return op1.este < op2.este || (op1.este == op2.este && op1.oeste < op2.oeste);
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<edificio> edificios) {
	int contador = 1;
	int este = edificios[0].este;
	int oeste = edificios[0].oeste;
	for (int i = 1; i < edificios.size(); i++) {
		if (oeste <= edificios[i].este) {
			contador++;
			este = edificios[i].este;
			oeste = edificios[i].oeste;
		}
		else {
			este = edificios[i].este;
			if (oeste > edificios[i].oeste)
				oeste = edificios[i].oeste;
		}
	}
	return contador;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;

	if (N == 0)
		return false;

	vector<edificio> edificios(N);

	for (int i = 0; i < N;i++) {
		int a, b;
		cin >> a >> b;
		edificios[i].este = a;
		edificios[i].oeste = b;
	}

	sort(edificios.begin(), edificios.end());
	int sol = resolver(edificios);

	// escribir sol
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
