#include <iostream>
#include <vector>
using namespace std;

vector<int> Node[10000];
int CutVertex[10000]={0};
int highest[10000];
int Lv = 0;
int dfn[10000];                //depth first node , idx= node's Lv
vector<int> cut;


int dfs(int cur, int p) {
	dfn[cur] = ++Lv;
	int minimum = dfn[cur];
	int cnt=0;
	int min_l;
	for (auto& nxt : Node[cur]) {
		if (dfn[nxt] == 0) {
			if (p == 0) {
				cnt++;
				if(cnt>1) CutVertex[cur] = 1;
			}
			min_l=dfs(nxt, cur);
			if (p != 0 && min_l >= dfn[cur]) {
					CutVertex[cur] = 1;
			}
			minimum = min(minimum, min_l);
		}
		else if(dfn[nxt] != 0) {         //if connect node has minimal dfn then cur
			if(nxt!=p)
				minimum = min(minimum, dfn[nxt]);
		}

	}


	return minimum;

}

int main(){
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int Pnode, Nnode;
		cin >> Pnode >> Nnode;
		Node[Pnode].push_back(Nnode);
		Node[Nnode].push_back(Pnode);
	}

	for (int i = 1; i <= N; i++) {
		if(!dfn[i])
			dfs(i, 0);
		}
	
	int cnt=0;
	for (int i = 1; i < N+1; i++) {
		if (CutVertex[i] == 1) {
			cut.push_back(i);
			cnt++;
		}
	}
	cout << cnt << endl;
	for (auto& i : cut) cout << i<<" ";
	return 0;
}