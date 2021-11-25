#include "print.h"
#include "node.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  int x=8; //x랑 y를 다르게 하면 바로 오류뜨네요
  int y=8; //y가 작으면 돌아는 가는데 x가 작으면 터져버립니다,,, 수정 코맨트 환영
  int** temp_table;
  temp_table = (int**)malloc(sizeof(int*)*y);

  for(int i=0; i<x; i++) {
    temp_table[i] = (int*)malloc(sizeof(int) * x);
  }

  for (int i=0; i<x; i++) {
    for (int j=0; j<x; j++) {
      temp_table[i][j] = -1;
      std::cout << temp_table[i][j] + " ";
    }
  }  

  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      temp_table[y/2 + i - 1][x/2 + j -1] = i ^ j;
    }
  }

  Print_table* PT = Print_table::GetInstance(temp_table, x, y);
  PT->Print();


  for(int i=0; i<x; i++) {
    free(temp_table[i]);
  }
  free(temp_table);
  return 0;
}