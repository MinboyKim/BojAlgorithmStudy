#include <bits/stdc++.h>

using namespace std;

int n;
int board[1025][1025];
int rectan[4];
 void solve(){
	 while (n > 0) {
		 n = n / 2;
		 for (int i = 0; i < n; i++) {
			 for (int j = 0; j < n; j++) {
				 int col = i * 2;
				 int low = j * 2;
				 rectan[0] = board[col][low];
				 rectan[1] = board[col][low + 1];
				 rectan[2] = board[col+1][low];
				 rectan[3] = board[col+1][low +1];
				 sort(rectan, rectan + 4);
				 board[i][j] = rectan[2];
			 }
		 }
	 }
	 cout << board[0][0];
	return;
 }
 

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
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