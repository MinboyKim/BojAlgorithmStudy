#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int cur = 1;
	int path = 1;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	while (true) {
		cur += 6*path;
		path++;
		if (N <= cur) break;
		
	}
	cout << path;
	return 0;

}