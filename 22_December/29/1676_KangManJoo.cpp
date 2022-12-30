#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll fact[501];
int sum;

ll factorial(int num)
{
	ll result = 1;
	for (int i = 1; i <= num; ++i)
	{
		result = result * i;
		while(!(result % 10)) {        //if 1seat == 0 , sum++ and delete that
			result = result / 10;
			sum++;
		}
		result %= 1000;				 //eliminate unneed seat
		
	}
	return result;
}

int main() {
	cin >> n;
	ll result = factorial(n);
	
	
	cout << sum;
	return 0;
}