#include <stdio.h>

int N, flag;
char files[55][55];
char ans[55];

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%s", &files[i]);

  for (int i = 0; i < 55; i++) {
    flag = 0;
    for (int j = 1; j < N; j++) {
      if (files[j][i] != files[0][i]) {
        flag = 1;
      }
    }
    if (!flag)
      ans[i] = files[0][i];
    else
      ans[i] = '?';
  }

  printf("%s\n", ans);

  return 0;
}