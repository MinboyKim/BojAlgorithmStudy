#include <bits/stdc++.h>

using namespace std;

int x, y, n;
int arr[102][102];
int trashX, trashY;
int check[101][101];
int Max=0;

 int solve(int x, int y,int size){
	 check[x][y] = 1;
	 if (arr[x][y] == 1) {
		 size++;
		 if (arr[x - 1][y] == 1 && check[x - 1][y] == 0) {
			 size=solve(x - 1, y, size);
		 }
		 if (arr[x][y + 1] == 1 && check[x][y + 1] == 0) {
			 size = solve(x, y +1, size);
		 }
		 if (arr[x + 1][y] == 1 && check[x + 1][y] == 0) {
			 size = solve(x + 1, y, size);
		 }
		 if (arr[x][y - 1] == 1 && check[x][y - 1] == 0) {
			 size = solve(x, y - 1, size);
		 }
	 }

	 if (Max < size) Max = size;
	 return size;
 }
 
void init() {
	cin >> x >> y >> n;
	while (n--) {
		cin >> trashX >> trashY;
		arr[trashX][trashY] = 1;
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if(!check[i][j]) solve(i, j, 0);
		}
	}
	
	cout << Max;

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}