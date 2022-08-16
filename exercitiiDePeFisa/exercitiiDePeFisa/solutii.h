#include "functii.h"

// 1. Se citeste o matrice patratica de maxim 100
// de elemente numere intregi.
// a) Sa se calculeze suma elementelor 
// de pe diagonala secundara.
// b) Realizati suma elementelor situate deasupra
// diagonalei principale.
// c) Afisati descrescator (dupa ce au fost sortate)
// elementele depe diagonala principala.
// d) Cate elemente superprime situate sub
// diagonala secundara avem?
// e) Care este suma elementelor situate
// deasupra diagonalei secundare?
// f) Afisati media aritmetica a elementelor din
// regiunea de nord a matricei.
// g) Cate elemente negative sunt in regiunea
// de sud a matricei?
// h) Cate elemente pare sunt in regiunea
// de est a matricei?
// i) Care este cel mai mare element din vestul
// matricei?

// 1-a
// Sa se calculeze suma elementelor 
// de pe diagonala secundara.

void solutiepb1a() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Suma elementelor de pe diagonala secundara este : " << sumaElementeDiagSec(x, m, n) << "." << endl;
}

// 1-b
// Realizati suma elementelor situate deasupra
// diagonalei principale.

void solutiepb1b() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Suma elementelor de deasupra diagonalei principale este : " << sumaElementeDeasupraDiagPrin(x, m, n) << "." << endl;
}

// 1-c
// Afisati descrescator (dupa ce au fost sortate)
// elementele depe diagonala principala.

void solutiepb1c() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Elementele diagonalei principale in ordine descrescatoare sunt : ";
	vectorElementeDiagPrin(x, m, n);
}

// 1-d
// Cate elemente superprime situate sub
// diagonala secundara avem?

void solutiepb1d() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Sub diagonala secundara exista " << countElemSuperPrimeSubDiagSec(x, m, n) << " elemente superprime." << endl;
}

// 1-e
// Care este suma elementelor situate
// deasupra diagonalei secundare?

void solutiepb1e() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Suma elementelor situate deasupra diagonalei secundare este : " << sumaElementeDeasupraDiagSec(x, m, n) << "." << endl;
}

// 1-f
// Afisati media aritmetica a elementelor din
// regiunea de nord a matricei.

void solutiepb1f() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Media aritmetica a elementelor din regiunea de nord a matricei este : " << mediaAritElementeNord(x, m, n) << "." << endl;
}

// 1-g
// Cate elemente negative sunt in regiunea
// de sud a matricei?

void solutiepb1g() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "In regiunea de sud exista " << countNegativeRegiuneSud(x, m, n) << " elemente negative." << endl;
}

// 1-h
// Cate elemente pare sunt in regiunea
// de est a matricei?

void solutiepb1h() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "In regiunea de est exista " << countPareRegiuneEst(x, m, n) << " elemente pare." << endl;
}

// 1-i
// Care este cel mai mare element din vestul
// matricei?

void solutiepb1i() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Cel mai mare element din vestul matricei este : " << celMaiMareRegiuneVest(x, m, n) << "." << endl;
}

// 2. Sa se citeasca o matrice patratica de maxim
// 1000x1000 de elemente numere intregi.
// a) Care este cmmdc-ul tuturor elementelor de pe diagonala
// principala?
// b) Sa se verifice daca matricea este simetrica fata de
// diagonala I.
// c) Afisati triunghiul isoscel cu maximul de numere
// ce au prima cifra egala cu ultima cifra.
// d) Sa se inlocuiasca toate aparitiile lui k din triunghiul
// dreptunghic inferior diagonalei secundare cu cifra de 
// control. (k citit de la tastatura)
// e) Care este numarul cu cele mai multe cifre distincte
// de pe diagonala secundara?
// f) Sa se verifice daca pe fiecare linie si pe fiecare
// coloana sunt elementele {1, ..., 9} o singura data
// (Tip Sudoku)
// g) Sa se realizeze un vector cu toate elementele
// ce au cifra de control un numar par.
// h) Sortati vectorul de la punctul g. crescator pana la
// mijloc si descrescator dupa (metodele cu care se 
// va sorta acest vector trebuie sa fie diferite pentru
// cele doua sortari)
// i) Interschimbati toate elementele din triunghiul
// superior diagonalei principale cu elementele
// din triunghiul inferior diagonalei secundare.
// j) Interschimbati toate elementele de minim din N
// cu toate elementele de maxim din S.
// k) Sortati descrescator diagonala secundara in functie
// de suma cifrelor din elemente.
// l) Care este triunghiul isoscel ce are cea mai mare
// frecventa a cifrei k? (k citit de la tastatura)
// m) Matricea B este transpusa matricei A. B = ?
// n) Afisati mesajul DA daca elementele de pe diagonala
// principala sunt multiplii celor de pe diagonala
// secundara. Metoda de comparare este urmatoarea
// a[0][0] cu a[0][n-1], a[1][1] cu a[1][n-2], etc.

// 2-a
// Care este cmmdc-ul tuturor elementelor de pe diagonala
// principala?

void solutiepb2a() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Cel mai mare divizor comun al elementelor de pe diagonala principala este : " << cmmdcDiagPrincipala(x, m, n) << "." << endl;
}

// 2-b
// Sa se verifice daca matricea este simetrica fata de
// diagonala I.

void solutiepb2b() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Matricea";
	if (simetricaFataDeDiagPrin(x, m, n)) {
		cout << " este ";
	}
	else {
		cout << " nu este ";
	}
	cout << "simetrica fata de diagonala principala." << endl;
}

// 2-c
// Afisati triunghiul isoscel cu maximul de numere
// ce au prima cifra egala cu ultima cifra.

void solutiepb2c() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	int indice = careTriunghiMaxNrPrimaUltima(x, m, n);
	cout << endl;
	cout << "Triunghiul cu maximul de numere ce au prima cifra egala cu ultima este cel din ";
	if (indice == 1) {
		cout << "nord." << endl << endl;
		afisareTriunghiNord(x, m, n);
	}
	if (indice == 2) {
		cout << "vest." << endl << endl;
		afisareTriunghiVest(x, m, n);
	}
	if (indice == 3) {
		cout << "sud." << endl << endl;
		afisareTriunghiSud(x, m, n);
	}
	if (indice == 4) {
		cout << "est." << endl << endl;
		afisareTriunghiEst(x, m, n);
	}
}

// 2-d
// Sa se inlocuiasca toate aparitiile lui k din triunghiul
// dreptunghic inferior diagonalei secundare cu cifra de 
// control. (k citit de la tastatura)

void solutiepb2d() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << endl;
	int k;
	cout << "Introduceti numarul k : ";
	cin >> k;
	cout << endl;
	inlocuireKDreptunghiSubDiagSec(x, m, n, k);
	cout << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}

// 2-e
// Care este numarul cu cele mai multe cifre distincte
// de pe diagonala secundara?

void solutiepb2e() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Numarul cu cele mai multe cifre distincte de pe diagonala principala este : " << elementMaxCifreDistincte(x, m, n) << "." << endl;
}

// 2-f
// Sa se verifice daca pe fiecare linie si pe fiecare
// coloana sunt elementele {1, ..., 9} o singura data
// (Tip Sudoku)

void solutiepb2f() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << endl;
	cout << "Matricea";
	if (tipSudoku(x, m, n)) {
		cout << " este ";
	}
	else {
		cout << " nu este ";
	}
	cout << "de tip sudoku." << endl;
}

// 2-g
// Sa se realizeze un vector cu toate elementele
// ce au cifra de control un numar par.

void solutiepb2g() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << endl << "Vectorul format din elementele cu cifra de control numar par este : " << endl << endl;
	afisareVectorElementeCifraControlPara(x, m, n);
}

// 2-h
// Sortati vectorul de la punctul g. crescator pana la
// mijloc si descrescator dupa (metodele cu care se 
// va sorta acest vector trebuie sa fie diferite pentru
// cele doua sortari)

void solutiepb2h() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << endl << "Vectorul dupa ce a fost sortat crescator folosind metoda Bubble Sort pana la mijlocul vectorului, iar dupa descrescator folosind metoda Merge Sort este :" << endl << endl;
	sortareVectorElemCCParaProb2h(x, m, n);
}

// 2-i
// Interschimbati toate elementele din triunghiul
// superior diagonalei principale cu elementele
// din triunghiul inferior diagonalei secundare.

void solutiepb2i() {
	int m = 0, n = 0;
	int x[100][100];
	citireFisier(x, m, n);
	afisareMatrice(x, m, n);
	cout << "Matricea dupa aceasta modificare este : " << endl << endl;
	afisareMatrice(x, m, n);
}