#include <bits/stdc++.h>

using namespace std;

int n;
int dpArray[1'000'001];
int backTracking[1'000'001];
int min(int a, int b, int c) {
	int tmp = (a < b) ? a : b;
	return (tmp < c) ? tmp : c;
}

int findNext(int x) {
	if (dpArray[x] == dpArray[x - 1]+1) return x - 1;
	else if (dpArray[x] == dpArray[x/2]+1 &&x%2==0) return x/2;
	else if (dpArray[x] == dpArray[x/3]+1) return x/3;
}

 void dp(int x){
	 for (int i = 2; i <= n; i++) {
		 if (i % 2 == 0) {
			 if (i % 3 == 0) {
				 dpArray[i] = min(dpArray[i - 1], dpArray[i / 2], dpArray[i / 3]) + 1;
			 }
			 else  dpArray[i] = min(dpArray[i - 1], dpArray[i / 2]) + 1;
		 }
		 else if (i % 3 == 0) dpArray[i] = min(dpArray[i - 1], dpArray[i / 3]) + 1;
		 else dpArray[i] = dpArray[i - 1] + 1;

		 backTracking[i] = findNext(i);
	 }
	 cout << dpArray[n] << endl<<n<<" ";
	 while(n>1){
		 cout << backTracking[n]<<" ";
		 n = backTracking[n];
	 }

 }
 

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 cin >> n;
	 dp(n);
	 return 0;
}