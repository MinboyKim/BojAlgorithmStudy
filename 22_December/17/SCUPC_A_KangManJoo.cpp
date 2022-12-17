#include <bits/stdc++.h>

using namespace std;

int n;
string ans;
int bcount, scount;

void solve() {
	const char* c = ans.c_str();
	const char* big = strstr(c, "bigdata");
	const char* se = strstr(c, "security");
	while (big != NULL) 
	{
		big = strstr(big + 1, "bigdata"); 
		bcount++;
	}
	while (se != NULL)
	{
		se = strstr(se + 1, "security");
		scount++;
	}
	if (scount > bcount) cout << "security!";
	else if (scount < bcount) cout << "bigdata?";
	else cout << "bigdata? security!";
}
void init() {
	cin >> n;
	cin >> ans;
	solve();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}