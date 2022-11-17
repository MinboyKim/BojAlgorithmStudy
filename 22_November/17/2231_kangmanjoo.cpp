#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N;
	
	vector<int> k;
	cin >> N;
	int i = 0;
	while (i<=N) {
		ios::sync_with_stdio(false);
		cin.tie(NULL);
		i++;
		int temp = 0;
		string str=std::to_string(i);
		for (int i = 0; i < str.length(); i++) {
			temp+=(int)(str[i]-48);
		}
		if (N == temp + i)
			break;
	}
	if (i > N) {
		cout << 0;
	}
	else {
		cout << i;
	}
}