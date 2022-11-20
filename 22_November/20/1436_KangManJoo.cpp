#include <iostream>
#include <string>

using namespace std;

int main() {
	int num;
	int cnt = 0;
	int i = 0;
	cin >> num;
	
	
	while (1) {
		i++;
		string s = to_string(i);
		if (s.find("666")!=string::npos) {
			cnt++;
		};
		if (cnt == num) {
			break;
		}
	}

	cout<<i;
	return 0;

}