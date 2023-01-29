#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100100];
int maxX;
 void solve(){
	 sort(arr, arr + n,greater<>());
	 for (int i = 0; i < n; i++) {
		 if(maxX<arr[i]+i+2)maxX=arr[i]+i+2;

	 }
	 cout << maxX;
	return;
 }
 

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
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