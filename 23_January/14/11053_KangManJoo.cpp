#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1010];
int lis[1010];
int len;
int binarySearch(int x) {
	int left = 0;
	int right = len;
	int mid;
	while (left<=right) {
		mid = (left + right) / 2;
		if (lis[mid] < x) {
			left = mid+1;
		}
		else {
			right = mid - 1;
		}
	}
	return right;
}
 void solve(){
	 int idx;
	 lis[0] = arr[0];
	 for (int i = 1; i < n; i++) {
		 if (arr[i] > lis[len]) {
			 len++;
			 lis[len] = arr[i];
		 }
		 else {
			 idx = binarySearch(arr[i]);
			 lis[idx+1] = arr[i];
		 }
	 }

	 cout << len+1;
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