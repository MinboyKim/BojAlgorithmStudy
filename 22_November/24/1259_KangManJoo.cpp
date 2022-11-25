#include <iostream>

using namespace std;

int main() {
	string input;
	string check;
	while (1) {
		cin >> input;
		if (input == "0") break;
		check = "yes";
		for (int i = 0; i < input.size(); i++) {
			if(input[i] != input[input.size()-1- i]) check = "no";
		}
		cout << check<<'\n';		
	}

}