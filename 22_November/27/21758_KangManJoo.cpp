#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int sum[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		if (i == 0) sum[i] = a;
		else sum[i] += sum[i-1]+a;
	}
	
	/********************************left right case*************************************/
	int pos2 = 1;
	int leftMostHoney = 0;
	int rightMostHoney = 0;
	int leftsecondBee;
	int rightsecondBee;
	for (int i = 1; i < N-1; i++) {
		leftsecondBee = (sum[N - 1] - sum[pos2])*2;
		leftsecondBee += sum[pos2 - 1] - arr[0];
		rightsecondBee = (sum[pos2-1]) * 2;
		rightsecondBee += sum[N - 2] - sum[pos2];
		leftMostHoney= (leftMostHoney > leftsecondBee ? leftMostHoney : leftsecondBee);
		rightMostHoney= (rightMostHoney > rightsecondBee ? rightMostHoney : rightsecondBee);
		pos2++;
	}

	/***************************************************************************/

	/********************************middle case*************************************/
	int middleHoney = 0;
	int max = 0;
	for (int i = 1; i < N-1; i++) {
		middleHoney += arr[i];
		if (arr[i] > max) max=arr[i];
	}
	middleHoney += max;
	/*****************************************************************************/

	int MaxHoney = (leftMostHoney > rightMostHoney ? leftMostHoney : rightMostHoney);
	MaxHoney = (MaxHoney > middleHoney ? MaxHoney : middleHoney);




	cout << MaxHoney;

	return 0;
}