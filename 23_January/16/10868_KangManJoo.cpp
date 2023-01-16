#include <bits/stdc++.h>
#define max 1'000'000'001
using namespace std;

int n,m;
pair<int,int> arr[101010];
int segTree[404040];
int checked[101010];
int result;
pair<int, int> pr;
int i;

pair<int,int> findMin() {
	i++;
	int min = max;
	return arr[i];
}

 void makeTree(){
	 pr = findMin();
	 int minNum = pr.second;
	 int min = pr.first;
	 int left=1,right=n;
	 int vertex = 1;
	 int mid;
	 if (segTree[vertex] == 0) segTree[vertex] = min;  //when Top node is blank

	 while (left<right) {
		 mid = (left + right) / 2;
		 if (minNum <= mid) {
			 right = mid;
			 vertex = vertex*2;
		 }
		 else {
			 left = mid + 1;
			 vertex = vertex * 2+1;
		 }
		 if (segTree[vertex] == 0) segTree[vertex] = min;
	 }

	 return;
 }
 
 void solve(int start, int end, int node, int a, int b) {
	 if (a>end || b<start) return;
	 else if (a <= start && b >= end) {
		 if (segTree[node] < result) result = segTree[node];
	 }
	 else {
		 int mid = (start + end) / 2;
		 solve(start, mid, node * 2, a, b);
		 solve(mid+1,end, node * 2+1, a, b);
	 }
	 return;
 }

void init() {
	int a, b;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> pr.first;
		pr.second = i;
		arr[i] = pr;
	}
	sort(arr, arr + n+1);

	for (int i = 1; i <= n; i++) {
		makeTree();
	}
	while (m--) {
		result = max;
		cin >> a >> b;
		solve(1,n,1,a, b);
		cout << result<<'\n';
	}

	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}