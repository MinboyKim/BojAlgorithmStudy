#include <bits/stdc++.h>

using namespace std;

string s;
int arr[1010100];
vector<int> v;
 void solve(){
	 int len=s.size();
	 int j = 0;
	 int MAX = 0;
	 int flag=0,flag2=0;

		 for (int i = len-1; i >=0; i--) {
			 v.push_back(arr[i]);
			 if (MAX <= arr[i]) {
				 MAX = arr[i];
				 if (i == 0) {
					 cout << 0;
					 exit(0);
				 }
			 }
			 else {
				 flag = i;
				 break;
			 }

		 }
		 sort(v.begin(), v.end());
		 for (int i=0; i<v.size(); i++){
			 if (v[i] > arr[flag]) {
				 arr[flag] = v[i];
				 flag2=i;
				 break;
			 }
		 }
		 for (int i = 0; i <= flag; i++) {
			 cout << arr[i];
		 }
		 for (int i = 0; i < v.size(); i++) {
			 if (i == flag2) continue;
			 cout << v[i];
		 }

	 
	return;
 }
 

void init() {
	cin >> s;
	int k = 0;
	for (auto& i : s) {
		arr[k] = i-48;
		k++;
	}
	solve();
	return;
}

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);

	 init();
	 return 0;
}