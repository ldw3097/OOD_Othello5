#include "print.h"
#include "node.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  int x=8; //x�� y�� �ٸ��� �ϸ� �ٷ� �����߳׿�
  int y=8; //y�� ������ ���ƴ� ���µ� x�� ������ ���������ϴ�,,, ���� �ڸ�Ʈ ȯ��
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