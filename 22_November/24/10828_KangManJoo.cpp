#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class stack {
	int n;
	int stk[10001];
public:
	stack();
	void push(int x);
	int top();
	int pop();
	int size();
	bool is_empty();
};

stack::stack() {
	n = 0;
}
void stack::push(int x) {
	n++;
	stk[n] = x;
}

int stack::pop() {
	if (n == 0) return -1;
	int rtn = stk[n];
	n--;
	return rtn;
}
int stack::top() {
	if (n == 0) return -1;
	return stk[n];
}

int stack::size() {
	return n;
}
bool stack::is_empty() {
	if (n == 0) return 1;
	else return 0;
}


int main() {
	int N;
	string cmd;
	stack stack1;
	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			stack1.push(x);
		}
		else if (cmd == "pop")
			cout<<stack1.pop()<<'\n';
		else if (cmd == "top")
			cout << stack1.top() << '\n';
		else if (cmd == "size")
			cout << stack1.size() << '\n';
		else if (cmd == "empty")
			cout << stack1.is_empty() << '\n';

	}
}