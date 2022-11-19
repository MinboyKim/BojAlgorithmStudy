#include <iostream>

using namespace std;

/************************stack implement***************************/
class stack {
	int n;
	char st[10000];
public:
	stack();
	int pop();
	void push(char x);
	bool isEmpty();
	int barNum();
};

stack::stack() {
	n = 0;
	//char st[10000] = { '0' };
}

int stack::pop() {
	if (n != 0) {
		n--;
		return st[n];
	}
	else {
		return -1;
	}
}

void stack::push(char x) {
	n++;
	st[n] = x;
}

int stack::barNum() {
	return n;
}
bool stack::isEmpty() {
	if (n == 0) {
		return true;
	}
	return false;
}
/************************stack implement***************************/

int piece = 0;

int laser(string d) {
	stack s;
	char before;

	for (auto i : d) {
		if (i == '(') {
			s.push(i);

		}
		else if (i==')') {
			if(s.isEmpty()) return 0;
			s.pop();
			if (before == '(') {
				piece+=s.barNum();   //now irradiated bar's num
			}
			else {
				piece += 1;
			}
		}
		before = i;
	}
	return piece;
}

int main() {
	string deployment;
	cin >> deployment;

	cout << laser(deployment);

	return 0;
}