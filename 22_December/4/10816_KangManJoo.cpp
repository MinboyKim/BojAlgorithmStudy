#include <bits/stdc++.h>

using namespace std;
int a[10000001][2];
int main() {
	int m,n,card;
	cin >> m;
	while (m--) {
		cin >> card;
		a[abs(card)][card > 0]++;
	}
	cin >> n;
	while (n--) {
		cin >> card;
		cout << a[abs(card)][card > 0]<<" ";
	}
}