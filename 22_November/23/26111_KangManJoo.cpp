#include <iostream>
#include <stack>

using namespace std;

stack<int> s;


long long tree_height(string tree) {
	long long sum= 0;
	char last;

	for (auto& i : tree) {
		if (i == '(') {
			s.push('(');
			last = '(';
		}
		else if (i == ')') {
			s.pop();
			if (last == '(')
				sum += s.size();
			last = ')';
		}
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string tree;
	cin >> tree;

	cout << tree_height(tree);	
	return 0;
}