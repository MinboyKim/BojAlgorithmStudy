#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> myints;
int N, M;
bool visit[10];
std::vector<int> x;
void dfs() {
	if (x.size() == M) {
		for (auto& i : x) {
			std::cout << i << " ";
		}
		std::cout<<"\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			x.push_back(myints[i]);
			visit[i] = true;
			dfs();
			x.pop_back();
			visit[i] = false;
		}
	}

	return;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N>> M;
	myints.push_back(0);   //myints[0] == dummy 
	for (int i = 1; i <= N; i++) {
		myints.push_back(i);
	}

	
	dfs();

	

	return 0;
}
