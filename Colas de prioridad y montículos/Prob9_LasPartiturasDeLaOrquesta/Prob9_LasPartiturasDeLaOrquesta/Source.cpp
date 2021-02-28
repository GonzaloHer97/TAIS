
// Gonzalo Hernández Hernández
// TAIS39

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
/*
Metes en la cola el numero de instrumentos ordenados por el tamoño de su grupo,
si hay mas partituras que instrumentos divides a la mitad el mayor grupo de
instrumentos, si no es una divison exacta le sumas 1 al grupo
*/

#include <iostream>
#include <fstream>
#include <string>

#include "PriorityQueue.h"// propios o los de las estructuras de datos de clase

using namespace std;


struct grupos {
	int numInstrumentos;
	int partituras;
	int grupo;
};

bool operator<(grupos const& a, grupos const& b) {//comparador para tener en top el instrumento que formaria el mayor grupo
	return a.grupo > b.grupo;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {//O(NlogN)

	// leer los datos de la entrada

	int instrumentos, partituras, musicos;

	cin >> partituras >> instrumentos;
	if (!std::cin)  // fin de la entrada
		return false;

	PriorityQueue<grupos> cola;


	//O(NlogN) siendo N el numero de instrumentos
	for (int i = 0; i < instrumentos; i++) {//metemos en la cola suponiendo que hay elmismo número de instrumentos que de partituras
		cin >> musicos;
		cola.push({ musicos,1,musicos });
	}

	int partiturasSobrantes = partituras - instrumentos;//si hay mas partiturras que instrumentos

	//O(KlogN) siendo K el numero de partitruas sobrantes
	for (int i = 0; i < partiturasSobrantes; i++) {
		
		grupos aux = cola.top();//O(1) 
		cola.pop();//O(logN)
		aux.partituras++;

		aux.grupo = aux.numInstrumentos / aux.partituras;//divido el tamaño del grupo a la mitad

		if (aux.numInstrumentos % aux.partituras != 0)//si al dividirlo no es igual le sumo 1 al grupo
			aux.grupo++;

		cola.push(aux);//O(logN)
	}

	// escribir sol

	cout << cola.top().grupo << "\n";


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
