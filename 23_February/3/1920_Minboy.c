#include <stdio.h>
#include <stdlib.h>

int N, M, temp;
int Arr[101010];

int compare(const void* a, const void* b) {
  if (*(int*)a > *(int*)b)
    return 1;
  else if (*(int*)a < *(int*)b)
    return -1;
  else
    return 0;
}

int bSearch(int num) {
  int l = 0;
  int r = N - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (Arr[mid] == num)
      return 1;
    else if (Arr[mid] > num)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return 0;
}

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &Arr[i]);

  qsort(Arr, N, sizeof(int), compare);

  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%d", &temp);
    if (bSearch(temp))
      printf("1\n");
    else
      printf("0\n");
  }

  return 0;
}