#include <bits/stdc++.h>

using namespace std;

string s;
int cnt;
void init() {
	cin >> s;
	for (auto i : s) {
		if (s[0] != i) break;
		cnt++;
	}
	cout << cnt;
	 return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}