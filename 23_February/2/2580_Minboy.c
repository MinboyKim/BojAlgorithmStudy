#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int row[10][10];
int col[10][10];
int box[10][10];
int map[10][10];

void dfs(int d) {
  if (d == 81) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        printf("%d ", map[i][j]);
      }
      printf("\n");
    }
    exit(0);
  }
  int x = d / 9;
  int y = d % 9;
  if (!map[x][y]) {
    for (int i = 1; i <= 9; i++) {
      if (!row[x][i] && !col[y][i] && !box[(x / 3) * 3 + (y / 3)][i]) {
        row[x][i] = 1;
        col[y][i] = 1;
        box[(x / 3) * 3 + (y / 3)][i] = 1;
        map[x][y] = i;
        dfs(d + 1);
        row[x][i] = 0;
        col[y][i] = 0;
        box[(x / 3) * 3 + (y / 3)][i] = 0;
        map[x][y] = 0;
      }
    }
  } else
    dfs(d + 1);
}

int main(void) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &map[i][j]);
      if (map[i][j]) {
        row[i][map[i][j]] = 1;
        col[j][map[i][j]] = 1;
        box[(i / 3) * 3 + (j / 3)][map[i][j]] = 1;
      }
    }
  }

  dfs(0);

  return 0;
}