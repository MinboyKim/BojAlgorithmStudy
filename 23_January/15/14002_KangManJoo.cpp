#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1010];
int lis[1010];
int len;
int pos[1010];
int realLis[1010];
int binarySearch(int x) {
	int left = 0;
	int right = len;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (lis[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return right;
}
void solve() {
	int idx;
	lis[0] = arr[0];
	int p = 0;
	pos[p] = len;
	for (int i = 1; i < n; i++) {
		p++;
		if (arr[i] > lis[len]) {
			len++;
			lis[len] = arr[i];
			pos[p] = len;
		}
		else {
			idx = binarySearch(arr[i]);
			lis[idx + 1] = arr[i];
			pos[p] = idx+1;
		}
	}
	int l = len;
	while (p >= 0) {
		if (pos[p] == l) {
			realLis[l] = arr[p];
			l--;
		}
		p--;
	}

	cout << len + 1<<endl;
	for (int i = 0; i <= len; i++) {
		cout << realLis[i] << " ";
	}
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