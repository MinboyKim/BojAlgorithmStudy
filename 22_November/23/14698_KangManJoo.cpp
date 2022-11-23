#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;




long long calcElectric() {
	int slimenum;

	priority_queue<long long,vector<long long>,greater<long long>> slimeEnergy;
	long long electricEnergy[60]={0};
	long long result=1;

	cin >> slimenum;
	for (int i = 0; i < slimenum; i++) {
		long long SE;
		cin >> SE;
		slimeEnergy.push(SE);
	}

	int idx = 0;
	int count = 0;
	
	if (slimeEnergy.size() <= 1) return result;
	else {
		while (count!=slimenum-1) {
			long long first = slimeEnergy.top();
			//cout << first << endl;
			slimeEnergy.pop();
			long long second = slimeEnergy.top();
			//cout << second << endl;
			slimeEnergy.pop();
			electricEnergy[count] = first*second;
			slimeEnergy.push(first*second);
			count++;
		}
	}

	for (auto& i : electricEnergy) {
		result=result % 1000000007;
		long long newi = (i % 1000000007);
		if(i!=0) result = result * newi;
	}
	


	return result;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int TC;
	cin >> TC;

	while (TC--) {
		cout << calcElectric() << '\n';
	}

	return 0;
}