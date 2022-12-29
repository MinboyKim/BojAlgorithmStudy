#include <bits/stdc++.h>

using namespace std;

int n;      
long long sum;

int factorial(int num)
{
	int result = 1;
	for (int i = 1; i <= num; ++i)
	{
		result = result * i;
	}
	return result;
}

long long numberOfCase(int numer,int denom,int useColorN) {
	return factorial(numer) / pow(factorial(denom),useColorN);  //calculate number of cases
}

void solve(int n,long long caseN,int a,int b, int c){       //current layer, has to multiple cases, number of balls that remain
	if (n == 0) {      //done ?
		sum += caseN;
		return;
	}
	//use three color of balls
	if (n >= 3 && n % 3 == 0) {
		int useBall = n/3;
		if (a >= useBall && b >= useBall && c >= useBall) {    //if have enough ball, go to next layer
			solve(n - 1, caseN*numberOfCase(n, useBall,3), a - useBall, b - useBall, c - useBall);
		}
	}
	//use two color of balls
	if (n >= 2 && n % 2 == 0) {
		int useBall = n / 2;
		if (a >= useBall && b >= useBall) {
			solve(n - 1, caseN * numberOfCase(n, useBall, 2), a - useBall, b - useBall, c);
		}
		if (a >= useBall && c >= useBall) {
			solve(n - 1, caseN * numberOfCase(n, useBall, 2), a - useBall, b, c - useBall);
		}
		if (c >= useBall && b >= useBall) {
			solve(n - 1, caseN * numberOfCase(n, useBall, 2), a, b - useBall, c - useBall);
		}
	}
	// just one
	if (a >= n) {
		solve(n - 1, caseN, a-n, b, c);
	}
	if (b >= n) {
		solve(n - 1, caseN, a, b-n, c);
	}
	if (c >= n) {
		solve(n - 1, caseN, a, b, c-n);
	}
	return;
}
 
void init() {
	int a, b, c; //a,b,c is a color of ball
	cin >> n>>a>>b>>c;
	solve(n,1,a,b,c);
	cout << sum;
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}