#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[100001];
int sum[100001];
int num=1;
int len = 999999;
int lp, rp;
void solve(){
	int k = 0;
	while (lp<num&&rp<=num) {
		if (sum[rp] - sum[lp] >= s) {
			if (rp - lp < len) len = rp - lp;
			lp++;
		}
		else {
			rp++;
		}
	}

	cout << (len != 999999 ? len : 0);

	return;
 }
 
void init() {
	cin >> n >> s;
	while (n--) {
		cin >> arr[num];
		sum[num] = sum[num - 1]+arr[num];
		num++;
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