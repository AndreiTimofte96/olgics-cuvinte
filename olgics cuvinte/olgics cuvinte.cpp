// olgics cuvinte.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#pragma warning (disable : 4996)
#define DMAX 50

using namespace std;

ifstream fin("cuvinte.txt");
ifstream fin1("test.txt");

char str[DMAX];
char *p, x;
int i, j, k, t, nr;
int n, sol[DMAX], uz[DMAX], dimm;
char sir[DMAX], sir1[DMAX], solfin[DMAX], M[100000][10];


void CitireCuvinte() {

	int i = 0;
	char cuvinte[DMAX];
	while (fin.getline(cuvinte, DMAX)) {
		strcpy(M[i++], cuvinte);
	}
	fin >> nr;
	cout << nr;
	dimm = i - 1;
}

void Cautare(int n) {

	int i;
	strcpy(solfin, "\0");
	for (i = 0; i < n; i++) {
		x = sir[sol[i]];
		sir1[0] = x;
		strcat(solfin, sir1);
	}
	for (i = 0; i < dimm; i++)
		if (strcmp(M[i], solfin) == 0)
		{
			cout << solfin << '\n';
			break;
		}
}

void Bkt(int k, int n){

	int i;
	if (k >= n) {
		Cautare(n);
		return;
	}

	for (i = 0; i < n; i++)
		if (uz[i] == 0) {
			sol[k] = i;
			uz[i] = 1;
			Bkt(k + 1, n);
			uz[i] = 0;
		}
}

void ExtragereCuvinte(){

	while (fin1 >> str[i++]);

	int length = i - 1;
	for (k = 1; k < length; k++)
		for (i = 0; i < length; i++) {
			for (j = i + k; j < length; j++) {
				strcpy(sir, "\0");
				for (t = i; t < i + k; t++) {
					x = str[t];
					sir1[0] = x;
					strcat(sir, sir1);
				}
				x = str[j];
				sir1[0] = x;
				strcat(sir, sir1);
				//cout << sir<<" ";
				Bkt(0, k + 1);
			}
		}
}





int main()
{
	CitireCuvinte();
	ExtragereCuvinte();

	/*while (fin.getline(str, DMAX)) {

		p = strtok(str, " ");
		if (strlen(p) < 8)
			fout << p<<'\n';
	}*/
    return 0;
}

