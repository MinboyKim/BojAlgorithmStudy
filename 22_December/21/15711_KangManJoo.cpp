#include <bits/stdc++.h>

using namespace std;

int t;
int i;
long long tc[505];
int prime[2'000'002];  //prime=0, not prime=1;
int realPrime[2'000'002];   //only have prime
int r;
 void solve(){
	 long long odd;
	 int is_prime;
	 for (int j = 0; j < i; j++) {
		 if (tc[j] <=3) {
			 cout << "NO";
			 continue;
		 }
		 is_prime = 0;
		 if (tc[j] % 2l == 0)  cout << "YES";	 
		 else {
			 odd = tc[j] - 2;
			 for (int k = 0; k<r; k++) {
				 if (realPrime[k] > sqrt(odd)) break;
				 if (odd % (long long)realPrime[k] == 0) {
					 is_prime = 1;
					 break;
				 }
			 }
			 if (is_prime) cout << "NO";
			 else cout << "YES";
		 }
		 cout << '\n';
	}
	return;
 }
 void is_prime() {
	 for (int i = 2; i <= 2'000'001; i++) {
		 if (prime[i] == 1) continue;
		 else {
			 realPrime[r] = i;
			 r++;
			 for (int j = i*2; j <= 2'000'001; j+=i) {
				 if (j%i == 0) prime[j] = 1;
			 }
		 }
	 }
 }
 
void init() {
	long long a, b;
	cin >> t;

	while (t--) {
		cin >> a >> b;
		tc[i] = a + b;
		i++;
	}
	is_prime();
	solve();
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}