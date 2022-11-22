#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int deck[22]={0};

int N;
unordered_set<int> subset;



void dfs(int cur,int i) {

	if (cur != 0) {
		subset.insert(cur);
	}

	i++;
	if (i > N)
		return;
	int conclude=cur+deck[i];
	

	dfs(conclude, i);
	dfs(cur, i);

	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cardNum,sum=0;
	cin >> N;
	for (int i = 1; i <= N;i++) {
		cin >> cardNum;
		deck[i] = cardNum;
		sum += cardNum;
	}
	dfs(0,0);

	cout << sum - subset.size();
}