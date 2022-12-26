#include <bits/stdc++.h>

using namespace std;

string n;
string reverseN;
typedef long long ll;
vector<ll> prime;

void isPrime() {
	if (n == "1") {
		cout << "no";
		return;
	}
	ll origin = stoll(n);
	ll reverse = stoll(reverseN);
	for (int i = 2; i <= sqrt(origin); i++) {
		if (origin % i == 0) {
			cout << "no";
			return;
		}
	}
	for (int i = 2; i <= sqrt(reverse); i++) {
		if (reverse % i == 0) {
			cout << "no";
			return;
		}
	}
	cout << "yes";
	return;
}

/*void eratos() {
	if (n == "1") {
		cout << "no";
		return;
	}
	for (int i = 2; i*i <= 100'000'000; i++) {
		if (a[i] == 1) continue;
		else {
			prime.push_back(i);
			for (ll j = i * i; j <= 100'000'000; j += i) {
				a[j] = 1;
			}
		}
	}
	isPrime();
}*/

 void solve(){
	 for (int i = n.size() - 1; i >= 0; i--) {
		 if (n[i] == '3' || n[i] == '4' || n[i] == '7') {
			 cout << "no";
			 return;
		 }
		 else if (n[i] == '0' || n[i] == '2' || n[i] == '5' || n[i] == '8' || n[i] == '1') reverseN += n[i];
		 else if (n[i] == '6') reverseN += '9';
		 else if (n[i] == '9') reverseN += '6';
	}
	//eratos();
	isPrime();
	return;
 }
 
void init() {
	cin >> n;
	solve();
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}