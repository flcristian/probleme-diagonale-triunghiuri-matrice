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

// Afisare diagonala principala.

void afisareMatriceDiagonalaPrincipala(int x[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		cout << x[i][i];
		cout << " ";
	}
}

// Afisare diagonala secundara.

void afisareMatriceDiagonalaSecundara(int x[100][100], int m, int n) {
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		cout << x[i][j];
		cout << " ";
	}
}

// Afisare triunghi de sub diagonala principala.

void afisareMatriceTriunghiSubDiagPrin(int x[100][100], int m, int n) {
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		for (int j = 0; j < i + 1; j++) {
			cout << x[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi de deasupra diagonalei principale.

void afisareMatriceTriunghiDeasupraDiagPrin(int x[100][100], int m, int n) {
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		for (int j = i; j < n; j++) {
			cout << x[i][j];
			cout << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi de sub diagonala secundara.

void afisareMatriceTriunghiSubDiagSec(int x[100][100], int m, int n) {
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		for (int k = j; k < n; k++) {
			cout << x[i][k];
			cout << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi de deasupra diagonalei secundare.

void afisareMatriceTriunghiDeasupraDiagSec(int x[100][100], int m, int n) {
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		for (int k = 0; k < j + 1; k++) {
			cout << x[i][k];
			cout << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi din nord.

void afisareMatriceTriunghiNord(int x[100][100], int m, int n) {
	for (int i = 0, j = n; i < m / 2 + 1; i++, j--) {
		for (int k = i; k < j; k++) {
			cout << x[i][k] << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi din vest.

void afisareMatriceTriunghiVest(int x[100][100], int m, int n) {
	int z = m / 2;
	if (m % 2 == 0) {
		z--;
	}
	for (int i = 0, j = n - 1, r = 0; i < m; i++) {
		for (int k = j; k < n; k++) {
			cout << x[i][k] << " ";
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
		cout << endl;
	}
}

// Afisare triunghi din sud.

void afisareMatriceTriunghiSud(int x[100][100], int m, int n) {
	int z = 0;
	if (m % 2 == 0) {
		z++;
	}
	for (int i = m / 2, j = i - z; i < m; i++, j--) {
		for (int k = j; k < i + 1; k++) {
			cout << x[i][k] << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi din est.

void afisareMatriceTriunghiEst(int x[100][100], int m, int n) {
	int z = m / 2;
	if (m % 2 == 0) {
		z--;
	}
	for (int i = 0, j = n - 1, r = 0; i < m; i++) {
		for (int k = j; k < n; k++) {
			cout << x[i][k] << " ";
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
		cout << endl;
	}
}