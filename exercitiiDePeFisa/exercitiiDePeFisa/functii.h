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
	int y[100];
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

// Cel mai mare numar de pe diagonala principala.

int minDiagPrincipala(int x[100][100], int m, int n) {
	int min = x[0][0];
	for (int i = 1; i < m; i++) {
		if (x[i][i] < min) {
			min = x[i][i];
		}
	}
	return min;
}

// Care este cel mai mare divizor comun elementelor de pe diagonala
// principala?

int cmmdcDiagPrincipala(int x[100][100], int m, int n) {
	int c = 1, cmmdc = minDiagPrincipala(x, m, n);
	while (cmmdc > 0 && c > 0) {
		c = 0;
		for (int i = 0; i < m; i++) {
			if (x[i][i] % cmmdc != 0) {
				c++;
			}
		}
		if (c > 0) {
			cmmdc--;
		}
	}
	return cmmdc;
}

// Este prima cifra egala cu ultima?

bool primaCifraEgalaUltima(int n) {
	int ultimaCifra = n % 10;
	while ((n / 10) != 0) {
		n /= 10;
	}
	if (n == ultimaCifra) {
		return true;
	}
	return false;
}

// Este diagonala simetrica fata de diagonala principala?

bool simetricaFataDeDiagPrin(int x[100][100], int m, int n) {
	for (int i = 0, c = m - 1; i < m; i++, c--) {
		for (int j = n - 1, k = 0; k < c, j > i; j--, k++) {
			cout << x[c][k] << " - " << x[i][j] << endl;
			if (x[c][k] != x[i][j]) {
				return false;
			}
		}
	}
	return true;
}

// Afisare triunghi din Nord.

void afisareTriunghiNord(int x[100][100], int m, int n) {
	for (int i = 0, j = n; i < m / 2 + 1; i++, j--) {
		for (int k = i; k < j; k++) {
			cout << x[i][k] << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi din Vest.

void afisareTriunghiVest(int x[100][100], int m, int n) {
	int z = m / 2;
	if (m % 2 == 0) {
		z--;
	}
	for (int i = 0, j = 1, r = 0; i < m; i++) {
		for (int k = 0; k < j; k++) {
			cout << x[i][k] << " ";
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
		cout << endl;
	}
}

// Afisare triunghi din Sud.

void afisareTriunghiSud(int x[100][100], int m, int n) {
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

// Afisare triunghi din Est.

void afisareTriunghiEst(int x[100][100], int m, int n) {
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


// Care triunghi isoscel contine cele mai multe numere ale caror
// prima cifra este egala cu ultima?

int careTriunghiMaxNrPrimaUltima(int x[100][100], int m, int n) {
	int maxim = 0, count = 0;
	int indiceMaxim = 0;

	int z = m / 2, s = 1;
	if (m % 2 == 0) {
		z--;
		s++;
	}

	// Verificare triunghi Nord.

	for (int i = 0, j = n - 1; i < m / 2 + 1; i++, j--) {
		for (int k = i + 1; k < j; k++) {
			if (primaCifraEgalaUltima(x[i][k])) {
				count++;
			}
		}
	}
	if (count > maxim) {
		maxim = count;
		indiceMaxim = 1;
	}
	count = 0;

	// Verificare triunghi Vest.

	for (int i = 0, j = 0, r = 0; i < m; i++) {
		for (int k = 0; k < j; k++) {
			if (primaCifraEgalaUltima(x[i][k])) {
				count++;
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
	if (count > maxim) {
		maxim = count;
		indiceMaxim = 2;
	}
	count = 0;

	// Verificare triunghi Sud.

	for (int i = m / 2 + 1, j = i - s; i < m; i++, j--) {
		for (int k = j; k < i; k++) {
			if (primaCifraEgalaUltima(x[i][k])) {
				count++;
			}
		}
	}
	if (count > maxim) {
		maxim = count;
		indiceMaxim = 3;
	}
	count = 0;

	// Verificare triunghi Est.

	for (int i = 0, j = n - 1, r = 0; i < m; i++) {
		for (int k = j + 1; k < n; k++) {
			if (primaCifraEgalaUltima(x[i][k])) {
				count++;
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
	if (count > maxim) {
		maxim = count;
		indiceMaxim = 4;
	}
	count = 0;

	return indiceMaxim;
}


// Cifra de control.

int cifraDeControl(int n) {
	while ((n / 10) != 0) {
		int r = 0;
		while (n != 0) {
			r += n % 10;
			n /= 10;
		}
		n = r;
	}
	return n;
}

// Inlocuirea lui k din triunghiul dreptunghic inferior
// diagonalei secundare cu cifra sa de control.

void inlocuireKDreptunghiSubDiagSec(int x[100][100], int m, int n, int k) {
	int cifraControl = cifraDeControl(k);
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		for (int z = j; z < n; z++) {
			if (x[i][z] == k) {
				x[i][z] = cifraControl;
			}
		}
	}
}

// Cate cifre distincte are numarul?

int cateCifreDistincte(int n) {
	int x[100];
	for (int i = 0; i < 10; i++) {
		x[i] = 0;
	}
	while (n != 0) {
		x[n % 10]++;
		n /= 10;
	}
	int c = 0;
	for (int i = 0; i < 10; i++) {
		if (x[i] > 0) {
			c++;
		}
	}
	return c;
}

// Numarul cu cele mai multe cifre distincte de pe diagonala principala.

int elementMaxCifreDistincte(int x[100][100], int m, int n) {
	int numarul = 0, max = 0;
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		int count = cateCifreDistincte(x[i][j]);
		if (count > max) {
			numarul = x[i][j];
			max = count;
		}
	}
	return numarul;
}

// Apare fiecare numar de la 1-9 o data in vector?

bool esteTipSudokuVectorul(int x[]) {
	int y[100];
	for (int i = 0; i < 9; i++) {
		y[i] = 0;
	}
	for (int i = 0; i < 9; i++) {
		y[x[i] - 1]++;
	}
	for (int i = 0; i < 9; i++) {
		if (y[i] < 1) {
			return false;
		}
	}
	return true;
}

// Este matricea de Tip Sudoku?

bool tipSudoku(int x[100][100], int m, int n) {
	if (m != 9 || n != 9) {
		return false;
	}

	for (int i = 0; i < m; i++) {
		int y[100];
		for (int j = 0; j < n; j++) {
			y[j] = x[i][j];
		}
		if (esteTipSudokuVectorul(y) == 0) {
			return false;
		}
	}

	for (int j = 0; j < n; j++) {
		int y[100];
		for (int i = 0; i < m; i++) {
			y[i] = x[i][j];
		}
		if (esteTipSudokuVectorul(y) == 0) {
			return false;
		}
	}

	return true;
}

// Afisarea vectorului format din toate elementele care au cifra de
// control numar par.

void afisareVectorElementeCifraControlPara(int x[100][100], int m, int n) {
	int y[100];
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (cifraDeControl(x[i][j]) % 2 == 0) {
				y[c] = x[i][j];
				c++;
			}
		}
	}
	afisareVector(y, c);
}

// Impartire vector in doi vectori.

void impartireVector(int x[], int y[], int z[], int d, int p) {
	int c = 0;
	for (int i = 0; i < p; i++) {
		y[c] = x[i];
		c++;
	}
	c = 0;
	for (int i = p; i < d; i++) {
		z[c] = x[i];
		c++;
	}
}

// Alipire vectori intr-un singur vector.

void alipireVector(int x[], int y[], int z[], int d1, int d2) {
	int c = 0;
	for (int i = 0; i < d1; i++) {
		x[c] = y[i];
		c++;
	}
	for (int i = 0; i < d2; i++) {
		x[c] = z[i];
		c++;
	}
}

// Merge

void merge(int x[], int min, int max, int mid) {
	int i = min, j = mid + 1, k = 0;
	int temp[100];
	while(i <= mid && j <= max) {
		if (x[i] < x[j]) {
			temp[k] = x[i];
			k++;
			i++;
		}
		else {
			temp[k] = x[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		temp[k] = x[i];
		k++;
		i++;
	}
	while (j <= max) {
		temp[k] = x[j];
		k++;
		j++;
	}
	for (i = min; i <= max; i++) {
		x[i] = temp[i - min];
	}
}

// Merge sort

void mergeSort(int x[], int min, int max) {
	int mid;
	if (min < max) {
		mid = (min + max) / 2;
		mergeSort(x, min, mid);
		mergeSort(x, mid + 1, max);
		merge(x, min, max, mid);
	}
}

// Merge descrescator.

void mergeDescrescator(int x[], int min, int max, int mid) {
	int i = min, j = mid + 1, k = 0;
	int temp[100];
	while (i <= mid && j <= max) {
		if (x[i] > x[j]) {
			temp[k] = x[i];
			i++;
		}
		else {
			temp[k] = x[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		temp[k] = x[i];
		i++;
		k++;
	}
	while (j <= max) {
		temp[k] = x[j];
		j++;
		k++;
	}
	for (i = min; i <= max; i++) {
		x[i] = temp[i - min];
	}
}

// Merge sort descrescator.

void mergeSortDescrescator(int x[], int min, int max) {
	int mid;
	if (min < max) {
		mid = (min + max) / 2;
		mergeSortDescrescator(x, min, mid);
		mergeSortDescrescator(x, mid + 1, max);
		mergeDescrescator(x, min, max, mid);
	}
}

// Sortarea vectorului de la punctul anterior dupa enuntul de la 2-h.

void sortareVectorElemCCParaProb2h(int x[100][100], int m, int n) {
	int y[100];
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (cifraDeControl(x[i][j]) % 2 == 0) {
				y[c] = x[i][j];
				c++;
			}
		}
	}
	int mijloc = c / 2;
	int part1[100], part2[100];
	int z = 0;
	if (c % 2 == 1) {
		z++;
	}
	int d1 = mijloc, d2 = mijloc + z;
	impartireVector(y, part1, part2, c, mijloc);
	bubbleSort(part1, d1);
	mergeSortDescrescator(part2, 0, d2 - 1);
	alipireVector(y, part1, part2, d1, d2);
	afisareVector(y, c);
}

// Interschimbarea elementelor din triunghiul superior
// diagonalei principale cu cele din triunghiul
// inferior diagonalei secundare.

void interschimbarePentruPb2i(int x[100][100], int m, int n) {
	int y[100][100];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			y[i][j] = x[i][j];
		}
	}
	for (int i = 0, i2 = m - 1, j2 = 1; i < m; i++, i2--, j2++) {
		for (int j = i + 1, k = j2; j < n; j++, k++) {
			x[i][j] = y[i2][k];
		}
	}
}

// Interschimbare minime din N cu maxime din S.

void interschimbarePentruPb2j(int x[100][100], int m, int n) {
	int min = x[0][1];
	int max = x[m - 1][1];
	int z = 0;
	if (m % 2 == 0) {
		z++;
	}
	for (int i = 0, j = n - 1; i < m / 2; i++, j--) {
		for (int k = i + 1; k < j; k++) {
			if (x[i][k] < min) {
				min = x[i][k];
			}
		}
	}
	for (int i = m / 2 + 1, j = i - z; i < m; i++, j--) {
		for (int k = j - 1; k < i; k++) {
			if (x[i][k] > max) {
				max = x[i][k];
			}
		}
	}
	for (int i = 0, j = n - 1; i < m / 2; i++, j--) {
		for (int k = i + 1; k < j; k++) {
			if (x[i][k] == min) {
				x[i][k] = max;
			}
		}
	}
	for (int i = m / 2 + 1, j = i - z; i < m; i++, j--) {
		for (int k = j - 1; k < i; k++) {
			if (x[i][k] == max) {
				x[i][k] = min;
			}
		}
	}
}

// Suma cifre

int sumaCifre(int n) {
	int s = 0;
	while (n != 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

// Merge sort descrescator dupa suma cifrelor.

void mergeSumaCifreDescrescator(int x[], int min, int mid, int max) {
	int i = min, j = mid + 1, k = 0;
	int temp[100];
	while (i <= mid && j <= max) {
		if (sumaCifre(x[i]) > sumaCifre(x[j])) {
			temp[k] = x[i];
			i++;
		}
		else {
			temp[k] = x[j];
			j++;
		}
		k++;
	}
	while (i <= mid) {
		temp[k] = x[i];
		i++;
		k++;
	}
	while (j <= max) {
		temp[k] = x[j];
		j++;
		k++;
	}
	for (i = min; i <= max; i++) {
		x[i] = temp[i - min];
	}
}

void mergeSortSumaCifreDescrescator(int x[], int min, int max) {
	int mid;
	if (min < max) {
		mid = (min + max) / 2;
		mergeSortSumaCifreDescrescator(x, min, mid);
		mergeSortSumaCifreDescrescator(x, mid + 1, max);
		mergeSumaCifreDescrescator(x, min, mid, max);
	}
}

// Sortare diagonala secundare dupa suma cifrelor descrescator.

void matriceDiagSecSortata(int x[100][100], int m, int n) {
	int y[100];
	int c = 0;
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		y[c] = x[i][j];
		c++;
	}
	mergeSortSumaCifreDescrescator(y, 0, c - 1);
	c = 0;
	for (int i = 0, j = n - 1; i < m; i++, j--) {
		x[i][j] = y[c];
		c++;
	}
}

// De cate ori apare cifra K.

int countAparitiiCifraK(int n, int k) {
	int c = 0;
	while (n != 0) {
		if (n % 10 == k) {
			c++;
		}
		n /= 10;
	}
	return c;
}

// Este cifra numarul?

bool esteCifra(int n) {
	if (n / 10 == 0) {
		return true;
	}
	return false;
}

// Care triunghi isoscel are frencventa maxima de aparitii a cifrei K?

int triunghiMaxAparitiiCifraK(int x[100][100], int m, int n, int f) {
	int maxim = 0, count = 0;
	int indiceMaxim = 0;

	int z = m / 2, s = 1;
	if (m % 2 == 0) {
		z--;
		s++;
	}

	// Verificare triunghi Nord.

	for (int i = 0, j = n - 1; i < m / 2 + 1; i++, j--) {
		for (int k = i + 1; k < j; k++) {
			count += countAparitiiCifraK(x[i][k], f);
		}
	}
	if (count > maxim) {
		maxim = count;
		indiceMaxim = 1;
	}
	count = 0;

	// Verificare triunghi Vest.

	for (int i = 0, j = 0, r = 0; i < m; i++) {
		for (int k = 0; k < j; k++) {
			count += countAparitiiCifraK(x[i][k], f);
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
	if (count > maxim) {
		maxim = count;
		indiceMaxim = 2;
	}
	count = 0;

	// Verificare triunghi Sud.

	for (int i = m / 2 + 1, j = i - s; i < m; i++, j--) {
		for (int k = j; k < i; k++) {
			count += countAparitiiCifraK(x[i][k], f);
		}
	}
	if (count > maxim) {
		maxim = count;
		indiceMaxim = 3;
	}
	count = 0;

	// Verificare triunghi Est.

	for (int i = 0, j = n - 1, r = 0; i < m; i++) {
		for (int k = j + 1; k < n; k++) {
			count += countAparitiiCifraK(x[i][k], f);
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
	if (count > maxim) {
		maxim = count;
		indiceMaxim = 4;
	}
	count = 0;

	return indiceMaxim;
}

// Afisare triunghi din Nord fara diagonale.

void afisareTriunghiNordFaraDiag(int x[100][100], int m, int n) {
	for (int i = 0, j = n - 1; i < m / 2; i++, j--) {
		for (int k = i + 1; k < j; k++) {
			cout << x[i][k] << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi din Vest fara diagonale.

void afisareTriunghiVestFaraDiag(int x[100][100], int m, int n) {
	int z = m / 2;
	if (m % 2 == 0) {
		z--;
	}
	for (int i = 0, j = 0, r = 0; i < m; i++) {
		for (int k = 0; k < j; k++) {
			cout << x[i][k] << " ";
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
		cout << endl;
	}
}

// Afisare triunghi din Sud fara diagonale.

void afisareTriunghiSudFaraDiag(int x[100][100], int m, int n) {
	int z = 1;
	if (m % 2 == 0) {
		z++;
	}
	for (int i = m / 2 + 1, j = i - z; i < m; i++, j--) {
		for (int k = j; k < i; k++) {
			cout << x[i][k] << " ";
		}
		cout << endl;
	}
}

// Afisare triunghi din Est fara diagonale.

void afisareTriunghiEstFaraDiag(int x[100][100], int m, int n) {
	int z = m / 2;
	if (m % 2 == 0) {
		z--;
	}
	for (int i = 0, j = n - 1, r = 0; i < m; i++) {
		for (int k = j + 1; k < n; k++) {
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

// Afisare triunghi isoscel din matrice in functie de indice.

void afisareTriunghiIsoscelIndice(int x[100][100], int m, int n, int indice) {
	cout << "Triunghiul este cel din ";
	if (indice == 1) {
		cout << "nord." << endl;
		afisareTriunghiNordFaraDiag(x, m, n);
	}
	if (indice == 2) {
		cout << "vest." << endl;
		afisareTriunghiVestFaraDiag(x, m, n);
	}
	if (indice == 3) {
		cout << "sud." << endl;
		afisareTriunghiSudFaraDiag(x, m, n);
	}
	if (indice == 4) {
		cout << "est." << endl;
		afisareTriunghiEstFaraDiag(x, m, n);
	}
}

// Transpunerea matricei X in matricea Y.

void transpunere(int x[100][100], int y[100][100], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			y[i][j] = x[j][i];
		}
	}
}

