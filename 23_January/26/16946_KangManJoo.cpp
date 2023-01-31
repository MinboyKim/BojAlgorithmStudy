#include <bits/stdc++.h>

using namespace std;

int n, m;
string col;
int board[1001][1001];
int canGo[1001001];
int checked[1001][1001];
int parent[1001001];
int see[1001001];

void dfs(int x, int y, int flag) {
	parent[x*m+y] = flag;
	canGo[flag]++;
	checked[x][y] = 1;
	if (x&&!board[x - 1][y] && checked[x - 1][y]!=1) {
		dfs(x - 1, y, flag);
	}
	if (y && !board[x][y-1] && checked[x][y - 1] != 1) {
		dfs(x, y-1, flag);
	}
	if (y!=m-1 && !board[x][y +1] && checked[x][y +1] != 1) {
		dfs(x, y +1, flag);
	}
	if (x!=n-1 && !board[x+1][y] && checked[x+1][y] != 1) {
		dfs(x+1, y, flag);
	}
	return;
}


int findNum(int x, int y) {
	int sum = 0;
	if (x && !board[x - 1][y] && !see[parent[(x - 1) * m + y]]) {
		sum += canGo[parent[(x - 1) * m + y]];
		see[parent[(x - 1) * m + y]] = 1;
	}
	if (y && !board[x][y - 1] && !see[parent[x * m + y - 1]]) {
		sum += canGo[parent[x * m + y - 1]];
		see[parent[x * m + y-1]] = 1;
	}
	if (y != m - 1 && !board[x][y + 1] && !see[parent[x  * m + y+1]]) {
		sum += canGo[parent[x * m + y + 1]];
		see[parent[x * m + y + 1]] = 1;
	}
	if (x != n - 1 && !board[x + 1][y] && !see[parent[(x + 1) * m + y]]) {
		sum += canGo[parent[(x + 1) * m + y]];
	}
	see[parent[(x - 1) * m + y]] = 0;
	see[parent[x * m + y-1]] = 0;
	see[parent[x * m + y+1]] = 0;

	return sum;
}

 void solve(){
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < m; j++) {
			 if (board[i][j]) continue;
			 if(!checked[i][j])
				dfs(i, j, m * i + j+1);
		 }
	 }

	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < m; j++) {
			 if (board[i][j] == 0) {
				 cout << "0";
			 }
			 else {
				 cout << (findNum(i,j)+1) % 10;
			 }
		 }
		 cout << endl;
	 }
	 
	return;
 }
 

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int j = 0;
		cin >> col;
		for (auto& s : col) {
			board[i][j] = s-'0';
			j++;
		}
	}
	
	solve();
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}