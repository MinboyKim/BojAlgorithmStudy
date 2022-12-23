#include <bits/stdc++.h>

using namespace std;

string str;
int loc;

 void solve(){
	 string oldstr = str;
	 int cur = 0;
	 do {
		 cur++;
		 if (cur == loc) break;
	 } while (next_permutation(str.begin(), str.end()));

	 cout << oldstr << " " << loc << " = ";
	 if (cur < loc) cout << "No permutation"<<'\n';
	 else cout << str<<'\n';
	 return;
 }
 
void init() {
	while (cin >> str>> loc){
		solve();
	}
	 return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}