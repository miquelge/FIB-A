#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//vector<int> optim;
vector < vector<int> > M;

int dif (char x, char y) {
	return abs((int)x - (int)y);
}

int PD (int m, int n, string a, string b) {
	vector < vector<int> > M (m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) M[i][0] = i*10;
	for (int j = 0; j < n; j++) M[0][j] = j*10;
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			M[i][j] = min(dif(a[i], b[j]) + M[i-1][j-1],
						min (10 + M[i-1][j], 10 + M[i][j-1]));
		}
	}
	/*
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return M[m-1][n-1];
}

int backtracking (string a, string b, int puntuacio, int i, int j) {
	//cout << a << " " << b << " " << puntuacio << " " << i << " " << j << endl;
	int r;
	if (i == a.size()) r = puntuacio + 10*(b.size()-j);
	else if (j == b.size()) r = puntuacio + 10*(a.size()-i);
	else if (a[i] == b[j]) r = backtracking(a, b, puntuacio, i+1, j+1);
	else {
		//ens petem lletra de la paraula a
		r = backtracking(a, b, puntuacio + 10, i+1, j);
		//ens petem lletra de la paraula b
		int aux = backtracking(a, b, puntuacio + 10, i, j+1);
		if (r > aux) r = aux;
		//calculem diferencia de lletre
		aux = backtracking(a, b, puntuacio + dif(a[i], b[j]), i+1, j+1);
		if (r > aux) r = aux;
	}
	//cout << r << endl;
	return r;
}

int main () {
	string a, b;
	while(cin >> a >> b) {
		//int x = PD(a.length(), b.length(), a, b);
		int x = backtracking(a, b, 0, 0, 0);
		cout << x << endl;
	}
}

