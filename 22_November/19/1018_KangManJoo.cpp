//https://www.acmicpc.net/problem/1018

#include<iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;
vector<char> block;
int main() {
	int b_row=0, b_col=0;
	cin >> b_col>> b_row;
	
	for (int i = 0; i < b_col; i++) {
		for (int j = 0; j < b_row; j++) {
			char color;
			cin >> color;
			block.push_back(color);
		}
		board.push_back(block);
		block.clear();
	}

	int Min = 9999999;
	char pre;
	char cur;
	char up=' ';
	int cnt = 0;
	for (int col = 0; col <= b_col - 8; col++) {
		for (int row = 0; row <= b_row - 8; row++) {
			if (board[col][row] == 'W') pre = 'W';
			else pre = 'B';
			for (int i = 0; i < 8; i++) {
				if (i != 0) {
					pre = up;
				}
				for (int j = 0; j < 8; j++) {
					if (i == 0 && j == 0) {
						up = pre;
						continue;
					}
					cur = board[col + i][row + j];
					if (pre == cur) {
						if (pre == 'W') {
							pre = 'B';
						}
						else pre = 'W';
						cnt++;
					}
					else pre = cur;
					if (j == 0) {
						up = pre;
					}
				}
			}
			if (Min > cnt) Min = cnt;

			cnt = 0;
		}
	}
	for (int col = 0; col <= b_col - 8; col++) {
		for (int row = 0; row <= b_row - 8; row++) {
			
				if (board[col][row] == 'W') pre = 'B';
				else pre = 'W';
				cnt++;
				for (int i = 0; i < 8; i++) {
					if (i != 0) {
						pre = up;
					}
					for (int j = 0; j < 8; j++) {
						if (i == 0 && j == 0) {
							up = pre;
							continue;
						}
						cur = board[col + i][row + j];
						if (pre == cur) {
							if (pre == 'W') {
								pre = 'B';
							}
							else pre = 'W';
							cnt++;
						}
						else pre = cur;
						if (j == 0) {
							up = pre;
						}
					}
				}
				if (Min > cnt) Min = cnt;

				cnt = 0;
		}
	}
	cout << Min;
}

