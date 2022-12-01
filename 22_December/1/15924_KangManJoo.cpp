#include <iostream>

using namespace std;
char map[3001][3001];
long long intmap[3001][3001]={0};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N>>M;
	int i,j;
	for (i = 0; i < N;i++) {
		string loc;
		cin >> loc;
		int t=0;
		for (auto row : loc) {
			map[i][t] = row;
			t++;
		}

	}

	long long path = 0;

	for (i = 0; i < N; i++) {
		intmap[i][M-1] = 1;
	}
	for (i = 0; i < M; i++) {
		intmap[N-1][i] = 1;
	}

	for (i = N - 2; i >= 0; i--) {
		for (j= M - 2; j >= 0; j--) {
			if (map[i][j] == 'B') {
				intmap[i][j] = intmap[i + 1][j] + intmap[i][j + 1];
				intmap[i][j]=intmap[i][j] % 1000000009;
			}
			else if(map[i][j]=='S')intmap[i][j] = intmap[i+1][j];
			else if (map[i][j] == 'E')intmap[i][j] = intmap[i][j+1];

		}
	}

	for (i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			path+= intmap[i][j];
			path= path % 1000000009;
		}
	}
	cout << path%1000000009;
	return 0;
}