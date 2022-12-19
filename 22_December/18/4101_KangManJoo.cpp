#include <bits/stdc++.h>

using namespace std;

void init() {
	int a, b;
	while (true) {
		cin >>a>>b;
		if (a == 0 && b == 0)break;
		if (a > b)cout << "Yes";
		else cout << "No";
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}