// Gonzalo Hernández Hernández 
// TAIS39

#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>


using namespace std;

class ColaMediana {
private:
	priority_queue<int, vector<int>, std::greater<int>> colaMenor;
	priority_queue<int, vector<int>, std::less<int>> colaMayor;
	int med;

public:
	void insertar(int n) {
		if (colaMenor.empty()) {
			colaMenor.push(n);
		}
		else if (n > colaMenor.top()) {
			colaMenor.push(n);
		}
		else {
			colaMayor.push(n);
		}

		/*Balanceo de las colas*/
		if (colaMenor.size() == colaMayor.size() + 2) {
			colaMayor.push(colaMenor.top());
			colaMenor.pop();
		}
		else if (colaMayor.size() == colaMenor.size() + 2) {
			colaMenor.push(colaMayor.top());
			colaMayor.pop();
		}
	}

	bool vacia() {
		return colaMayor.empty() && colaMenor.empty();
	}

	int mediana() {

		if (colaMayor.empty() && colaMenor.empty()) {
			med = -1;
		}
		else {
			quitarMediana();
		}

		return med;
	}

	void quitarMediana() {
		if (colaMenor.size() > colaMayor.size()) {
			med = colaMenor.top();
			colaMenor.pop();
		}
		else if (colaMayor.size() > colaMenor.size()) {
			med = colaMayor.top();
			colaMayor.pop();
		}
		else { /*Numero par de elementos*/
			med = colaMayor.top();
			colaMayor.pop();
		}
	}
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int num, n;

	std::cin >> num;
	if (!std::cin)  // fin de la entrada
		return false;

	ColaMediana cola;

	for (int i = 0; i < num; ++i) {
		std::cin >> n;

		if (n == 0) {
			int med = cola.mediana();
			if (med == -1) {
				std::cout << "ECSA ";
			}
			else {
				std::cout << med << " ";
			}
		}
		else {
			cola.insertar(n);
		}
	}

	std::cout << "\n";

	return true;
}


int main() {

#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}