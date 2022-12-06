#include <iostream>

using namespace std;

class Deque {
public:
	int n=0;
	int arr[10000];
	void push_front(int x);
	void push_back(int x);
	void pop_front();
	void pop_back();
	void size();
	bool empty();
	void front();
	void back();
};

void Deque::push_front(int x) {
	for (int i = n; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = x;
	n++;
}

void Deque::push_back(int x) {
	arr[n] = x;
	n++;
};

void Deque::pop_back() {
	if (n == 0) cout << -1 << '\n';
	else {
		cout << arr[n - 1] << '\n';
		n--;
	}
}

void Deque::pop_front() {
	if (n == 0) cout << -1 << '\n';
	else {
		cout << arr[0] << '\n';
		for (int i = 0; i < n - 1; i++) {
			arr[i] = arr[i + 1];
		}
		n--;
	}
}

void Deque::size() {
	cout << n << '\n';
}

bool Deque::empty() {
	if (n == 0) {
		cout << 1 << '\n';
		return true;
	}
	else cout << 0 << '\n';
	return false;
}

void Deque::front() {
	if (n==0) cout << -1 << '\n';
	else cout << arr[0] << '\n';
	
}

void Deque::back() {
	if (n==0) cout << -1 << '\n';
	else cout << arr[n-1] << '\n';
}
int main() {
	int N;
	int x;
	Deque deque;
	cin >> N;
	string cmd;
	while (N--) {
		cin >> cmd;
		
		if (cmd == "push_front") {
			cin >> x;
			deque.push_front(x);
		}
		else if (cmd == "push_back") {
			cin >> x;
			deque.push_back(x);
		}
		else if (cmd == "pop_front") {
			deque.pop_front();
		}
		else if (cmd == "pop_back") {
			deque.pop_back();
		}
		else if (cmd == "size") {
			deque.size();
		}
		else if (cmd == "empty") {
			deque.empty();
		}
		else if (cmd == "front") {
			deque.front();
		}
		else if (cmd == "back") {
			deque.back();
		}
	}
}