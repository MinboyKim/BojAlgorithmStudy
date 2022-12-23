#include <bits/stdc++.h>

using namespace std;

pair<int, string> player[301];
pair<int, string> room[301];
int check[301];
int n, maxp;
int lv;
int number_of_player;

void makeroom(int bangjang);

bool compare(pair<int,string> &a, pair<int,string> &b) {
	return a.second < b.second;   //ascending order
}

 void solve(){
	 for (int num = 0; num < number_of_player;num++) {
		 if (check[num]) continue;
		 else {
			 check[num] = 1;
			 makeroom(num);
		 }
	 }

	 return;
 }

 void makeroom(int bangjang) {
	 room[1] = player[bangjang];
	 int lvLimit = player[bangjang].first;
	 int roomPlayer = 1;
	 for (int num = bangjang; num < number_of_player; num++) {
		 if (check[num] == 0) {
			 if (abs(player[num].first - lvLimit) <= 10) {            // LV +- 10
				 if (roomPlayer < maxp) {
					 check[num] = 1;
					 roomPlayer++;
					 room[roomPlayer]=player[num];
				 }
			 }
		 }
	 }
	 if (roomPlayer == maxp) cout << "Started!" << endl;
	 else cout << "Waiting!" << endl;

	 sort(room+1, room + roomPlayer+1,compare);

	 for (int p=1; p <= roomPlayer; p++) {
		 cout << room[p].first << " " << room[p].second<<'\n';
	 }
	 
	 return;
 }
 
void init() {
	cin >> n>>maxp;
	while (n--) {
		cin >> player[number_of_player].first >> player[number_of_player].second;
		number_of_player++;
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