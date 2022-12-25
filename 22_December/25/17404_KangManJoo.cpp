#include <bits/stdc++.h>

using namespace std;

//get<0>(tuples[0]);
int n;
int red, green, blue;
tuple<int,int,int> tuples[1001];
int homeCnt;
int minCosts[3];

int minCost(int x, int y, int z) {
	int tmp = x;
	if (x >= y && z >= y) tmp = y;
	else if (x >= z && y >= z) tmp = z;

	return tmp;

}

 void solve(){
	 tuple<int, int, int> copyTuples[1001];
		 for (int i = 0; i < homeCnt; i++) {
			 copyTuples[i] = tuples[i];
		 }
		 get<0>(copyTuples[1]) = 9999;
		 get<1>(copyTuples[1]) += get<0>(copyTuples[0]);
		 get<2>(copyTuples[1]) += get<0>(copyTuples[0]);
		 for (int i = 2; i < homeCnt; i++) {
			 get<0>(copyTuples[i]) += min(get<1>(copyTuples[i-1]),   get<2>(copyTuples[i-1]));
			 get<1>(copyTuples[i]) += min(get<0>(copyTuples[i - 1]), get<2>(copyTuples[i - 1]));
			 get<2>(copyTuples[i]) += min(get<0>(copyTuples[i - 1]), get<1>(copyTuples[i - 1]));
		 }
		 minCosts[0] = min(get<1>(copyTuples[homeCnt - 1]), get<2>(copyTuples[homeCnt - 1]));

		 for (int i = 0; i < homeCnt; i++) {
			 copyTuples[i] = tuples[i];
		 }
		 get<1>(copyTuples[1]) = 9999;
		 get<0>(copyTuples[1]) += get<1>(copyTuples[0]);
		 get<2>(copyTuples[1]) += get<1>(copyTuples[0]);
		 for (int i = 2; i < homeCnt; i++) {
			 get<0>(copyTuples[i]) += min(get<1>(copyTuples[i - 1]), get<2>(copyTuples[i - 1]));
			 get<1>(copyTuples[i]) += min(get<0>(copyTuples[i - 1]), get<2>(copyTuples[i - 1]));
			 get<2>(copyTuples[i]) += min(get<0>(copyTuples[i - 1]), get<1>(copyTuples[i - 1]));
		 }
		 minCosts[1] = min(get<0>(copyTuples[homeCnt - 1]), get<2>(copyTuples[homeCnt - 1]));

		 for (int i = 0; i < homeCnt; i++) {
			 copyTuples[i] = tuples[i];
		 }
		 get<2>(copyTuples[1]) = 9999;
		 get<0>(copyTuples[1]) += get<2>(copyTuples[0]);
		 get<1>(copyTuples[1]) += get<2>(copyTuples[0]);
		 for (int i = 2; i < homeCnt; i++) {
			 get<0>(copyTuples[i]) += min(get<1>(copyTuples[i - 1]), get<2>(copyTuples[i - 1]));
			 get<1>(copyTuples[i]) += min(get<0>(copyTuples[i - 1]), get<2>(copyTuples[i - 1]));
			 get<2>(copyTuples[i]) += min(get<0>(copyTuples[i - 1]), get<1>(copyTuples[i - 1]));
		 }
		 minCosts[2] = min(get<0>(copyTuples[homeCnt - 1]), get<1>(copyTuples[homeCnt - 1]));

		 cout << minCost(minCosts[0], minCosts[1], minCosts[2]);
	 
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