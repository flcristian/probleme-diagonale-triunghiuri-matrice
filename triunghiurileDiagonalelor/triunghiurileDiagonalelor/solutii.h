#include "functii.h"

// Triunghiurile de sub si deasupra diagonalelol secundare si principale.

void triunghiuriDiagonale() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << endl;
	cout << "Triunghiul de sub diagonala principala." << endl;
	cout << endl;
	afisareMatriceTriunghiSubDiagPrin(x, m, n);
	cout << endl;
	cout << "Triunghiul de deasupra diagonalei principale." << endl;
	cout << endl;
	afisareMatriceTriunghiDeasupraDiagPrin(x, m, n);
	cout << endl;
	cout << "Triunghiul de sub diagonala secundara." << endl;
	cout << endl;
	afisareMatriceTriunghiSubDiagSec(x, m, n);
	cout << endl;
	cout << "Triunghiul de deasupra diagonalei secundare." << endl;
	cout << endl;
	afisareMatriceTriunghiDeasupraDiagSec(x, m, n);
}

// Triunghiurile NORD, VEST, SUD, EST.

void triunghiuriNordVestSudEst() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << endl;
	cout << "Triunghiul din nord." << endl;
	cout << endl;
	afisareMatriceTriunghiNord(x, m, n);
	cout << endl;
	cout << "Triunghiul din vest." << endl;
	cout << endl;
	afisareMatriceTriunghiVest(x, m, n);
	cout << endl;
	cout << "Triunghiul din sud." << endl;
	cout << endl;
	afisareMatriceTriunghiSud(x, m, n);
	cout << endl;
	cout << "Triunghiul din est." << endl;
	cout << endl;
	afisareMatriceTriunghiEst(x, m, n);
}