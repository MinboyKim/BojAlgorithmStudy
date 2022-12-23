#include <stdio.h>

#include <iostream>

int main(void) {
  int student[31] = {0};
  int presentNum;

  for (int i = 0; i < 28; i++) {       //출석한 28명의
    scanf("%d", &presentNum);          //출석 번호를 입력받아
    student[presentNum] = presentNum;  //해당 인덱스에 저장
  }
  for (int i = 1; i < 31; i++) {  //모든 학생을 조회
    if (student[i] == 0)          //초기값이 변경되지 않았다면
      printf("%d\n", i);
  }

  return 0;
}
