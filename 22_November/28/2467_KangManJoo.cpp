#include <iostream>

using namespace std;

int arr[2][100001];           //first index ==0 ->negative , index==1 ->positive
int p = 0;
int n = 0;
int liqA, liqB;
// 자신 그룹의 앞뒤와 반대 그룹에서의 binary search 후 앞뒤 총 4개를 비교한다.
int binary_search(int pos[], int x) {
	int left = 0;
	int right = p;
	int mid = 0;
	while (left < right) {
		mid = left + (right - left) / 2;
		if (pos[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int total;
	cin >> total;
	for (int i = 0; i < total; i++) {
		int a;
		cin >> a;
		if (a < 0) {
			arr[0][n] = a;
			n++;
		}
		else {
			arr[1][p] = a;
			p++;
		}
	}
	int min = 2000000000;
	for (int i = 0; i < n; i++) {
		int idx = binary_search(arr[1], arr[0][i] * (-1));
		if (idx != p) {
			if (min > abs(arr[1][idx] + arr[0][i])) {
				min = abs(arr[1][idx] + arr[0][i]);
				liqA = arr[0][i];
				liqB = arr[1][idx];
			}
		}
		if (idx != 0) {
			if (min > abs(arr[1][idx - 1] + arr[0][i])) {
				min = abs(arr[1][idx - 1] + arr[0][i]);
				liqA = arr[0][i];
				liqB = arr[1][idx - 1];
			}
		}

	}
	if (n >= 2) {
		if (min > abs(arr[0][n - 1] + arr[0][n - 2])) {
			min = abs(arr[0][n - 1] + arr[0][n - 2]);
			liqA = arr[0][n - 2];
			liqB = arr[0][n - 1];
		}
	}
	if (p >= 2) {
		if (min > arr[1][0] + arr[1][1]) {
			liqA = arr[1][0];
			liqB = arr[1][1];
		}
	}
	cout << liqA << " " << liqB;

	return 0;
}