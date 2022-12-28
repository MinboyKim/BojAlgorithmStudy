#include <bits/stdc++.h>

using namespace std;

int arr1[202];
int arr2[202];
string gear;
int len1,len2;
int minLen1,minLen2;
 void solve(){
	 int correct;
	
	 for (int j = 0; j <= len1; j++) {
		 correct = 1;
		 for (int i = 0; i < len2; i++) {
			 if (arr1[i + j] == 2 && arr1[i + j] == arr2[i]) {
				 correct = 0;
				 break;
			 }
		 }
		 if (correct) {
			 minLen1 = ((len2 + j > len1) ? len2 + j : len1);
			 break;
		 }
	 }
	 
	 for (int j = 0; j <= len2; j++) {
		 correct = 1;
		 for (int i = 0; i < len1; i++) {
			 if (arr2[i + j] == 2 && arr2[i + j] == arr1[i]) {
				 correct = 0;
				 break;
			 }
		 }
		 if (correct) {
			 minLen2=((len1 + j > len2) ? len1 + j : len2);
			 break;
		 }
	 }
	 cout << ((minLen1 > minLen2) ? minLen2 : minLen1);
	 
 
	return;
 }
 
 void init() {
	 cin >> gear;
	 for (auto& i : gear) {
		 arr1[len1] = i-'0';
		 len1++;
	 }
	 cin >> gear;
	 for (auto& i : gear) {
		 arr2[len2] = i-'0';
		 len2++;
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