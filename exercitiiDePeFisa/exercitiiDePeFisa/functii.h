#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Citire matrice din fisier.

void citireFisier(int x[100][100], int& m, int& n) {
	ifstream f("numere.txt");
	f >> m, f >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			f >> x[i][j];
		}
	}
}

// Afisare matrice.

void afisareMatrice(int x[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		cout << "{";
		int c = n;
		for (int j = 0; j < n; j++) {
			cout << x[i][j];
			if (c > 1) {
				cout << ", ";
				c--;
			}
			else {
				cout << "}" << endl;
			}
		}
	}
}

// Suma elementelor de pe diagonala secundara.

int sumaElementeDiagSec(int x[100][100], int m, int n) {
	int s = 0;
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		s += x[i][j];
	}
	return s;
}

// Suma elementelor de deasupra diagonalei principale.

int sumaElementeDeasupraDiagPrin(int x[100][100], int m, int n) {
	int s = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i; j < n; j++) {
			s += x[i][j];
		}
	}
	return s;
}

// Bubble sort.

void bubbleSort(int x[], int d) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < d - 1; i++) {
			if (x[i] > x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

// Bubble sort descrescator.

void bubbleSortDescrescator(int x[], int d) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < d - 1; i++) {
			if (x[i] < x[i + 1]) {
				int r = x[i];
				x[i] = x[i + 1];
				x[i + 1] = r;
				flag = false;
			}
		}
	} while (flag == false);
}

// Afisare vector.

void afisareVector(int x[], int d) {
	cout << "x[" << d << "] = {";
	int c = d;
	for (int i = 0; i < d; i++) {
		cout << x[i];
		if (c > 1) {
			cout << ", ";
			c--;
		}
		else {
			cout << "}" << endl;
		}
	}
}

// Afisarea elementelor diagonalei principale descrescator
// dupa sortare.

void vectorElementeDiagPrin(int x[100][100], int m, int n) {
	int  y[100];
	int j = 0;
	for (int i = 0; i < m; i++) {
		y[j] = x[i][i];
		j++;
	}
	bubbleSortDescrescator(y, j);
	afisareVector(y, j);
}

// Cati divizori are numarul?

int countDivizori(int n) {
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			c++;
		}
	}
	return c;
}

// Este prim numarul?

bool estePrim(int n) {
	if (countDivizori(n) == 2) {
		return true;
	}
	return false;
}

// Este super prim numarul?

bool esteSuperPrim(int n) {
	if (n == 0) {
		return false;
	}
	while (n != 0) {
		if (estePrim(n) == 0) {
			return false;
		}
		n /= 10;
	}
	return true;
}

// Cate elemente super prime exista sub diagonala secundara.

int countElemSuperPrimeSubDiagSec(int x[100][100], int m, int n) {
	int c = 0;
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		for (int k = j; k < n; k++) {
			if (esteSuperPrim(x[i][k])) {
				c++;
				cout << x[i][k] << endl;
			}
		}
	}
	return c;
}

// Suma elementelor de deasupra diagonalei secundare.

int sumaElementeDeasupraDiagSec(int x[100][100], int m, int n) {
	int s = 0;
	for (int i = 0, j = n; i < m; i++, j--) {
		for (int k = 0; k < j; k++) {
			s += x[i][k];
		}
	}
	return s;
}

// Media aritmetica a elementelor din regiunea de nord a matricei.

double mediaAritElementeNord(int x[100][100], int m, int n) {
	int suma = 0;
	int count = 0;
	for (int i = 0, j = n; i < m / 2 + 1; i++, j--) {
		for(int k = i; k < j; k++){
			suma += x[i][k];
			count++;
		}
	}
	return suma / count;
}

// Cate elemente negative sunt in regiunea de sud a matricei?

int countNegativeRegiuneSud(int x[100][100], int m, int n) {
	int c = 0;
	int z = 0;
	if (m % 2 == 0) {
		z++;
	}
	for (int i = m / 2, j = i - z; i < m; i++, j--) {
		for (int k = j; k < i + 1; k++) {
			if (x[i][k] < 0) {
				c++;
			}
		}
	}
	return c;
}

// Cate elemente pare sunt i nregiunea de est a matricei?

int countPareRegiuneEst(int x[100][100], int m, int n) {
	int c = 0;
	int z = m / 2;
	if (m % 2 == 0) {
		z--;
	}
	for (int i = 0, j = n - 1, r = 0; i < m; i++) {
		for (int k = j; k < n; k++) {
			if (x[i][k] % 2 == 0) {
				c++;
			}
		}
		if (m % 2 == 0) {
			if (i >= z) {
				r++;
			}
			if (r == 0) {
				j--;
			}
			if (r > 1) {
				j++;
			}
		}
		else {
			if (i < z) {
				j--;
			}
			else {
				j++;
			}
		}
	}
	
	return c;
}

// Cel mai mare element din vestul matricei.

int celMaiMareRegiuneVest(int x[100][100], int m, int n) {
	int max = x[0][0];
	int z = m / 2;
	if (m % 2 == 0) {
		z--;
	}
	for (int i = 0, j = 1, r = 0; i < m; i++) {
		for (int k = 0; k < j; k++) {
			if (x[i][k] > max) {
				max = x[i][k];
			}
		}
		if (m % 2 == 0) {
			if (i >= z) {
				r++;
			}
			if (r == 0) {
				j++;
			}
			if (r > 1) {
				j--;
			}
		}
		else {
			if (i < z) {
				j++;
			}
			else {
				j--;
			}
		}
	}

	return max;
}