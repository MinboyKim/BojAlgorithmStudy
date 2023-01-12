#include <bits/stdc++.h>

using namespace std;

int Row, Col, M;
typedef tuple<int, int, int> tp;
pair<tp, bool> sea[101][101];
pair<tp, bool> newSea[101][101];
int sum;

pair<int,int> sharkMove(int direction, int cur,int speed) {
	speed %= 2 * (Col - 1);
	int dt = 1;
	int nextDirection=direction;
	switch (direction) {
	case 1:                 //up
		while (speed--) {
			if (dt == 1 && cur == 1 || dt == -1 && cur == Row) {
				dt *= -1;
			}
			cur -= dt;
		}
		if (dt==-1) nextDirection = 2;

		break;
	case 2:					//down
		dt *= -1;
		while (speed--) {
			if (dt == 1 && cur == 1 || dt == -1 && cur == Row) {
				dt *= -1;
			}
			cur -= dt;
		}
		if (dt==1) nextDirection = 1;
		break;
	case 3:					//right
		while (speed--) {
			if (dt == 1 && cur == Col || dt == -1 && cur == 1) {
				dt *= -1;
			}
			cur += dt;
		}
		if (dt==-1) nextDirection = 4;
		break;
	case 4:					//left
		dt *= -1;
		while (speed--) {
			if (dt == 1 && cur == Col || dt == -1 && cur == 1) {
				dt *= -1;
			}
			cur += dt;
		}
		if (dt==1) nextDirection = 3;
		break;
	default:
		break;
	}

	return { cur,nextDirection };
}

 void solve(){
	 int kingLoc = 0;
	 while (kingLoc < Col) {
		 kingLoc++;
		 for (int i = 1; i <= Row; i++) {
			 if (sea[i][kingLoc].second) {
				 sum += get<2>(sea[i][kingLoc].first);
				 sea[i][kingLoc].second = false;
				 break;
			 }
		 }
		 int direction,speed,newi,newj;
		 pair<int, int> move;
		 for (int i = 1; i <= Row; i++) {
			 for (int j = 1; j <= Col; j++) {
				 if (sea[i][j].second) {
					 sea[i][j].second = false;
					 direction = get<1>(sea[i][j].first);
					 speed = get<0>(sea[i][j].first);
					 if (direction == 1 || direction == 2) {
						 move = sharkMove(direction,i,speed);
						 newi = move.first;
						 newj = j;
						 get<1>(sea[i][j].first) = move.second;
					 }
					 else {
						 move = sharkMove(direction, j, speed);
						 newj = move.first;
						 newi = i;
 						 get<1>(sea[i][j].first) = move.second;
					 }
					 if (newSea[newi][newj].second) {
						 newSea[newi][newj].first = (get<2>(sea[i][j].first) > get<2>(newSea[newi][newj].first)) ? sea[i][j].first : newSea[newi][newj].first; //bigger one occupy loc
					 }
					 else {
						 newSea[newi][newj].first= sea[i][j].first;
						 newSea[newi][newj].second = true;
					 }
				 }
			 }
		 }

		 for (int i = 1; i <= Row; i++) {
			 for (int j = 1; j <= Col; j++) {
				 if (newSea[i][j].second) {
					 newSea[i][j].second = false;
					 sea[i][j].first = newSea[i][j].first;
					 sea[i][j].second = true;
				 }
			 }
		 }
	 }
	 cout << sum;
	return;
 }
 

void init() {
	int r, c, s, d, z;
	tp shark;
	cin >> Row >> Col >> M;
	while (M--) {
		cin >> r >> c >> s >> d >> z;
		shark = { s,d,z };
		sea[r][c] = { shark,true };
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