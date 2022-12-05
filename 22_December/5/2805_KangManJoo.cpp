#include <bits/stdc++.h>

using namespace std;

int arr[1'000'000];

void binary_search(long long left, long long right,int n,long long need) {
	long long mid;
	long long sum = 0;
	long long max=0;
	while (left <= right) {
		mid = (right + left) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid < arr[i])
				sum += arr[i] - mid;
		}
		if (sum == need) {
			max = mid;
			break;
		}
		else if (sum > need) {
			left = mid+1;
			if (mid > max) {
				max = mid;
			}
		}
		else right = mid-1;
	}

	cout << max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long need;
	int n,i=0;
	cin >> n >> need;
	while (n--) {
		cin >> arr[i];
		i++;
	}
	sort(arr,arr+i);
	long long max = arr[i - 1];

	binary_search(0, max,i,need);
	return 0;
}