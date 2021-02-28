
// Gonzalo Hernández Hernández
// TAIS39
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;




struct Actividad {
	int ini;
	int fin;
};


bool operator<(Actividad op1, Actividad op2) {
	return op1.fin < op2.fin || (op1.fin == op2.fin && op1.ini < op2.ini);
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(vector<Actividad> lista) {

	queue<Actividad> listaAux;
	
	listaAux.push(lista[0]);

	for (int i = 1; i < lista.size(); i++) {
		if (lista[i].ini < listaAux.front().fin) {
			listaAux.push(lista[i]);
		}
		else {
			listaAux.pop();
			listaAux.push(lista[i]);
		}
	}

	return listaAux.size() - 1;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int N;
	cin >> N;

	if (N == 0)
		return false;
		
	vector<Actividad> lista(N);
	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		lista[i] = { a,b };
	}

	sort(lista.begin(), lista.end());



	int  sol = resolver(lista);

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
