#include <iostream>
#include <stack>
using namespace std;
int a[100000];
stack<int> s;


int main() {
	int k;
	cin >> k;
	while (k--) {
		int n;
		cin >> n;
		if (n == 0) {
			s.pop();
		}
		else s.push(n);
	}
	int sum = 0;
	int size = s.size();
	while(size--) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
	return 0;
}