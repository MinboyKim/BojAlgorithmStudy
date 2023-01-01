#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int col[1001][1001];
int colNum,rowNum;
int maxLen;
pair<int, int> maxLoc;
string reverselcString,lcString;

void findLcString() {
	int firstLoc = maxLoc.first;
	int secondLoc = maxLoc.second;

	while (col[firstLoc][secondLoc]) {
		if (col[firstLoc][secondLoc] == col[firstLoc - 1][secondLoc]) {
			firstLoc--;
		}
		else if (col[firstLoc][secondLoc] == col[firstLoc][secondLoc - 1]) {
			secondLoc--;
		}
		else {
			reverselcString += s1[secondLoc - 1];
			firstLoc--;
			secondLoc--;
			
		}
	}
	for (int i = reverselcString.size() - 1; i >= 0; i--) {
		lcString += reverselcString[i];
	}
}

void lcs() {
	for (int i = 1; i <= s2.size(); i++) {
		for (int j = 1; j <= s1.size(); j++) {
			if (s1[j-1] == s2[i-1]) {           //fill 0 when col==0 or row==0 because of reccurrence relation's normalization
				col[i][j] = col[i - 1][j -1]+1;
				if (col[i][j] > maxLen) {
					maxLen = col[i][j];
					maxLoc =make_pair(i,j);
				}
			}
			else {
				col[i][j] = max({col[i][j - 1], col[i - 1][j] });
			}
		}
	}

	findLcString();
	cout << maxLen << '\n'<<lcString;

}

int main() {
	cin >> s1>> s2;
	lcs();
}