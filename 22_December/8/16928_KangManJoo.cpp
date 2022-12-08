#include <bits/stdc++.h>

using namespace std;

int N, M;
int UpDn[101];
bool visited[110] = { false };
typedef pair<int, int> p;
queue<p> que;

void init() {
	cin >> N>>M;
	int s,e;
	while (N--) {
		cin >> s>>e;
		UpDn[s] = e;
	}
	while (M--) {
		cin >> s>> e;
		UpDn[s] = e;
	}
	return;
}

void play(int loc,int cnt) {
	if (loc == 100) {
		cout << cnt;
		return;
	}

	if (loc > 100) {
		p next = que.front();
		que.pop();
		play(next.first, next.second);
		return;
	}                                  //over 100, stop check
	if (UpDn[loc]) {
		if (visited[UpDn[loc]]) {
			p next = que.front();
			que.pop();
			play(next.first, next.second);
			return;
		}													
		else {
			visited[UpDn[loc]] = true;
			loc = UpDn[loc];
		}
	}
	visited[loc] = true;
	int dice = 6;
	while (dice) {
		if (visited[loc+dice]==false) {                     //if it has inserted in queue at the past, it has shortest path to visited[loc+dice]
			que.push(make_pair(loc + dice, cnt + 1));
		}
		dice--;
	}
	p next=que.front();
	que.pop();
	play(next.first, next.second);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	play(1,0);
	return 0;
}