#include <iostream>
#include <vector>

using namespace std;


int main () {
	int vertexs, arestes, aux1, aux2, size;
	while(cin >> vertexs >> arestes) {
		vector <vector<int> > graf(vertexs);
		vector<int> graus(vertexs, 0);
		for (int i =0; i<arestes; i++) {
			cin>> aux1 >> aux2;
			graf[aux1].push_back(aux2);
			graf[aux2].push_back(aux1);
			graus[aux1]++;
			graus[aux2]++;
		}
		int sol = graus[0];
		for (int i=0; i<vertexs; i++) if (graus[i]<sol) sol = graus[i];
		cin >> size;
		int index;
		for (int i=0; i<vertexs-size; i++) {
			index = 0;
			for (int j=0; j<vertexs; j++) {
				if (graus[index] == -1) index = j;
				else if (graus[j]<graus[index] and graus[j] != -1) index=j;
			}
			graus[index] = -1;
			for (int j=0; j<graf[index].size(); j++) {
				if (graus[graf[index][j]] != -1) graus[graf[index][j]]--;
			}
			int min = graus[0];
			for (int i=0; i<vertexs; i++) {
				if (min == -1) min = graus[i];
				else if (graus[i]<min and graus[i] != -1) min = graus[i];
			}
			if (min > sol) sol = min;
		}
		cout << sol << endl;
	}	
}



