#include <bits/stdc++.h>

using namespace std;
int arr[2002];
int n;
int m;
int startN, endN;
int pal[2002][2002];

void solve1(int x, int i){
	if (x - i >= 1 && x + i <= n) {
		if (arr[x - i] == arr[x + i]) {
			pal[x - i][x + i] = 1;
			solve1(x, i+1);
		}
		else {
			solve1(x + 1, 0);      //범위를 벗어나기전에 팰린드롬이 실패했을 때
		}
	}
	else if(x<n) {
		solve1(x + 1, 0);            //만약 팰린드롬이 전부 성공하고 범위를 벗어났을때
	}

	return;
 }
void solve2(int x,int i) {
	if (x - i >= 1 && x + 1+i <= n) {
		if (arr[x - i] == arr[x +1+ i]) {
			pal[x - i][x + 1+i] = 1;
			solve2(x, i+1);
		}
		else {
			solve2(x + 1, 0);      //범위를 벗어나기전에 팰린드롬이 실패했을 때
		}
	}
	else if (x < n-1) {
		solve2(x + 1, 0);            //만약 팰린드롬이 전부 성공하고 범위를 벗어났을때
	}

	return;
}
 
void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}  
	solve1(1,0);
	solve2(1, 0);
	cin >> m;
	while (m--) {
		cin  >> startN  >> endN;
		cout << pal[startN][endN]<<'\n';
	}
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}