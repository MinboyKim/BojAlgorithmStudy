#include <bits/stdc++.h>

using namespace std;

int n;
double arrX[10001];
double arrY[10001];

 void solve(){
	 double sumA=0, sumB=0;
	 for (int i = 0; i < n-1; i++) {
		 sumA += arrX[i] * arrY[i + 1];
		 sumB += arrY[i] * arrX[i + 1];
	 }
	 sumA += arrX[n - 1]*arrY[0];
	 sumB += arrY[n - 1] * arrX[0];

	
	 cout << (abs(sumA - sumB) / 2);
	return;
 }
 

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arrX[i] >> arrY[i];
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