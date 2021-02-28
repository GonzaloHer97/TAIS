
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
/*
La solución se basa en coger los dos elementos mas pequeños del vector, sumarlos y  volverlos a sumar
con el esfuerzo total, si el vectorno está vacio meter la suma de los dos primeros elemntos en la pila
denuevo en la posicion que le corresponda.

*/
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>


#include "PriorityQueue.h"// propios o los de las estructuras de datos de clase


using namespace std;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

long long int resolver(PriorityQueue<long long int> pila) {
	long long int suma=0, total=0, aux1, aux2;

	while (pila.size() > 1) {//O(NlogN) siendo N el numero de elemntos del vector

		aux1 = pila.top(); // O(1)
		pila.pop();//O(logN)
		aux2 = pila.top();
		pila.pop();


		suma = aux1 + aux2;
		total += suma;

		if (pila.size() > 0)
			pila.push(suma);//O(logN)
	}
	return total;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	long long int n;
	long long int aux;
	cin >> n;

	if (n == 0)
		return false;

	PriorityQueue<long long int> pila;

	for (long long int i = 0; i < n; i++) {//O(NlogN) siendo N el numero de elemntos del vector
		cin >> aux;
		pila.push(aux);//O(logN)
	}
	
	long long int sol = resolver(pila);

	// escribir sol

	cout << sol << endl;

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
