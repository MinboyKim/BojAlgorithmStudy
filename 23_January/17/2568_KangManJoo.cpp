#include <bits/stdc++.h>

using namespace std;

int n;
typedef pair<int, int> pr;
pr line[101010];
int lis[101010];
int len;
pr pos[101010];

int binary_search(int x) {
	int left = 0,mid;
	int right = len-1;
	while (left < right) {
		mid = (left + right) / 2;
		if (lis[mid] < x) {
			left = mid+1;
		}
		else {
			right = mid;
		}
	}
	return left;
}

void solve() {
	lis[0]=line[0].second;
	len++;
	pos[0] = { line[0].first, 1 };
	int p = 1;

	for (int i = 1; i < n; i++) {
		if (line[i].second > lis[len-1]){
			lis[len] = line[i].second;
			len++;               //len= real lis len
			pos[p].second=len;
			pos[p].first = line[i].first;
		}
		else {
			int idx=binary_search(line[i].second);
			lis[idx] = line[i].second;
			pos[p].second = idx+1;
			pos[p].first = line[i].first;
		}
		p++;
	}
	cout << n-len<<endl;
	for (int i = n-1; i >=0; i--) {
		if (pos[i].second == len) {
			pos[i].first = 0;
			len--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (pos[i].first) cout << pos[i].first<<'\n';
	}

	return;
 }
 

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> line[i].first>>line[i].second;
	}
	sort(line, line + n);
	
	solve();
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}