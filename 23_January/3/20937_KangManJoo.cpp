#include <bits/stdc++.h>

using namespace std;

int n,cnt;
int arr[50005];
int plate;
int maxN;
 
 
 void init() {
	 cin >> n;
	 for (int i = 0; i < n; i++) {
		 cin >> plate;
		 arr[plate]++;
		 if (arr[plate] > maxN) maxN = arr[plate];
	 }
	 cout << maxN;

	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}