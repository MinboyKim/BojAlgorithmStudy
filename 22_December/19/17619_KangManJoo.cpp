#include <bits/stdc++.h>

using namespace std;

int n, q,trash;
int loggroup[100001];
int num;
vector<pair<int,int>> group;
vector<pair<int, int>> LOGS;
typedef pair<int, int> p;

void solve() {
	int cur = 0;
	for (auto log: LOGS) {
		cur++;
		int curgrp = 0;
		for (auto& grp : group) {
			if (grp.first <= log.second && grp.second >= log.first) {
				loggroup[cur] = curgrp;
				break;
			}
			curgrp++;
		}
	}
	while (q--) {
		int q1, q2;
		cin >> q1 >> q2;
		if (loggroup[q1] == loggroup[q2]) cout << 1;
		else cout << 0;
		cout << '\n';
	}
}

void init() {
	cin >> n >> q;
	group.push_back({ 0,0 });
	while (n--) {
		int plag = 0; //pair belong to group?
		p pair;
		num++;
		cin >> pair.first >> pair.second>>trash;
		LOGS.push_back(pair);
		int cur = 0;
		for (auto &grp : group) { 
			if (grp.first <= pair.second && grp.second >= pair.first) {
				if (loggroup[num] == 0) {
					loggroup[num] = cur;
					plag = 1;
					grp.first = grp.first < pair.first ? grp.first : pair.first;
					grp.second = grp.second > pair.second ? grp.second : pair.second;
				}
				else {
					group[loggroup[num]].first = (group[loggroup[num]].first < grp.first ? group[loggroup[num]].first : grp.first);
					group[loggroup[num]].second= (group[loggroup[num]].second > grp.second ? group[loggroup[num]].second : grp.second);
					group[cur] = { -1,-1 };  //grp reset
				}
			}
			cur++;
		}
		if (!plag) group.push_back(pair);
	}
	solve();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	return 0;
}