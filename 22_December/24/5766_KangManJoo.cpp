#include <bits/stdc++.h>

using namespace std;

int n, m;
int player[10001];
int maxX;
int maxp;
int secondP;
int secondList[10001];
 void solve(){
	 maxX = 0;
	 for (int i = 0; i < 10001; i++) {
		 if (player[i] > maxX) {
			 maxX = player[i];
			 maxp = i;
		 }
	 }
	 player[maxp] = 0;
	 maxX = 0;
	 for (int i = 0; i < 10001; i++) {
		 if (player[i] > maxX) {
			 secondP = 1;
			 maxX = player[i];
			 maxp = i;
			 secondList[secondP] = i;
			 continue;
		 }
		 if (player[i] == maxX) {
			 secondP++;
			 secondList[secondP] = i;
		 }
	 }
	 for (int i = 1; i <= secondP; i++) {
		 cout << secondList[i] << " ";
	 }
	 cout << endl;
	 return;
 }
 
void init() {
	int goodplayer;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		while (n--) {
			for (int i = 0; i < m; i++) {
				cin >> goodplayer;
				player[goodplayer]++;
			}
		}
		solve();
		for (auto& i : player) i = 0;  //reset list
	}
	
	 return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}