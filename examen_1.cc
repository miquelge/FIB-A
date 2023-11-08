#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main () {
	queue<string> Q;
	vector<queue<string> > cues(26);
	string aux;
	while (cin >> aux) Q.push(aux);
	if (not Q.empty()) {
		int longitud = Q.front().size();
		int pos = 1;
		int index;
		while (pos <= longitud) {
			while (not Q.empty()) {
				aux = Q.front();
				Q.pop();
				index = ((int)(aux[aux.size() - pos]))-97;
				cues[index].push(aux);
			}
			for (int i = 0; i<26; i++) {
				while (not cues[i].empty()) {
					aux = cues[i].front();
					cues[i].pop();
					Q.push(aux);
				}
			}
			pos++;
		}
		cout << Q.front();
		Q.pop();
		while (not Q.empty()) {
			cout << " " << Q.front();
			Q.pop();
		}
	}
	cout << endl;
}
