#include <bits/stdc++.h>

using namespace std;
int n, m,i;
string address[100001];
string password[100001];
map <string, string> account;

void solve() {
	string findadd;
	while (m--) {
		cin >> findadd;
		cout << account[findadd]<<'\n';
	}
	return;
}

void init() {
	cin >> n >> m;
	string add, pass;
	while (n--) {
		cin >> add>>pass;
		account[add]=pass;
	}
	solve();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	return 0;
}