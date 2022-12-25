#include <bits/stdc++.h>

using namespace std;

//get<0>(tuples[0]);

int n;
int homeCnt;
int red, green, blue;
tuple<int,int,int> tuples[1001];
int firstSmall;
int secondSmall;
int best;

int minCost(int x, int y, int z) {
	int tmp=x;
	if (x >= y&&z>=y) tmp = y;
	else if (x >= z && y >= z) tmp = z;
	
	return tmp;

}

 void solve() {
	 for (int i = 0; i < homeCnt; i++) {
		 get<0>(tuples[i]) = min(get<1>(tuples[i - 1]) + get<0>(tuples[i]), get<2>(tuples[i - 1]) + get<0>(tuples[i]));
		 get<1>(tuples[i]) = min(get<0>(tuples[i - 1]) + get<1>(tuples[i]), get<2>(tuples[i - 1]) + get<1>(tuples[i]));
		 get<2>(tuples[i]) = min(get<1>(tuples[i - 1]) + get<2>(tuples[i]), get<0>(tuples[i - 1]) + get<2>(tuples[i]));
	 }
	 int mincost= minCost(get<0>(tuples[homeCnt - 1]), get<1>(tuples[homeCnt - 1]), get<2>(tuples[homeCnt - 1]));
	 cout << mincost;
	 return;
 }
 
void init() {
	cin >> n;

	while (n--) {
		cin >> red >> green >> blue;
		tuples[homeCnt]=make_tuple(red, green, blue);
		homeCnt++;
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