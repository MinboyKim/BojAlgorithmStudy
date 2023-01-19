#include <bits/stdc++.h>

using namespace std;

int n, m, k;
long long arr[1'010'101];
long long segTree[4'040'404];

 long long makeSeg(int start,int end,int node) {
	 long long mid = (start + end) / 2;
	 if (start == end) {
		 return segTree[node] = arr[start];
	 }
	 else {
		 segTree[node]= makeSeg(start, mid, node * 2) + makeSeg(mid + 1, end, node * 2 + 1);
		 return segTree[node];
	 }
 }

 long long findSum(int a, int b,int left, int right, int node) {
	 long long mid=(left+right)/2;
	 if (left > b || right < a) return 0;
	 else if (a <= left && right <= b) return segTree[node];
	 else return findSum(a,b,left,mid,node*2) + findSum(a,b,mid+1,right,node*2+1);
 }

 void fix(int a, int b) {
	 int left=1, right=n,node=1;
	 int mid;
	 long long diff = b-arr[a];
	 arr[a] = b;
	 segTree[node] += diff;
	 while (left < right) {
		 mid = (left + right) / 2;
		 if (a <= mid) {
			 right = mid;
			 node = node * 2;
		 }
		 else {
			 left = mid + 1;
			 node = node * 2+1;
		 }
		 segTree[node] += diff;
	 }
 }

void init() {
	long long a, b, c;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	makeSeg(1, n, 1);
	

	int printOut = m + k;
	while (printOut--) {
		cin >> a >> b >> c;
		if (a == 2) {
			cout<<findSum(b, c,1,n,1)<<endl;
		}
		else {
			fix(b, c);
		}
	}
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}