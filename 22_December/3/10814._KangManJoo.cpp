#include <iostream>
#include <vector>

using namespace std;
vector<string> s;
vector<vector<string>> v(100000,s);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int i=0;
	cin >> n;
	while (n--) {
		int age;
		string name;
		cin >> age >> name;
		v[age].push_back(name);
	}
	int temp;
	
	
	
	for (int i = 0; i < 100000; i++) {
		for (auto j : v[i]) {
			cout << i << " " <<j<< "\n";
		}
	}
	
}