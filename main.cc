#include "print.h"
#include "node.h"
#include "node_print.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  int x=8; //x랑 y를 다르게 하면 바로 오류뜨네요
  int y=8; //y가 작으면 돌아는 가는데 x가 작으면 터져버립니다,,, 수정 코맨트 환영

  // int table
  int** temp_table;
  temp_table = (int**)malloc(sizeof(int*)*y);
  for(int i=0; i<x; i++) {
    temp_table[i] = (int*)malloc(sizeof(int) * x);
  }
  for (int i=0; i<y; i++) {
    for (int j=0; j<x; j++) {
      temp_table[i][j] = -1;
    }
  }
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      temp_table[y/2 + i - 1][x/2 + j -1] = i ^ j;
    }
  }
  //int table end

  //node table
  Node*** node_table;
  Node* temp_top = (Node*)malloc(sizeof(Node*));
  Node* temp_bottom = (Node*)malloc(sizeof(Node*));
  Node* temp_left = (Node*)malloc(sizeof(Node*));
  Node* temp_right = (Node*)malloc(sizeof(Node*));

  node_table = (Node***)malloc(sizeof(Node**)*y);
  for(int i=0; i<x; i++) {
    node_table[i] = (Node**)malloc(sizeof(Node*) * x);
  }
  for (int i=0; i<y; i++) {	//new node
    for (int j=0; j<x; j++) {
      node_table[i][j] = new Node(-1);
    }
  }
  for (int i=0; i<y; i++) {
    for (int j=0; j<x; j++) {	//노드 엮기
      if (i == 0) {	
        temp_top = nullptr; 
      }else temp_top = node_table[i-1][j];
      if (i == y-1) {	
        temp_bottom = nullptr; 
      }else temp_bottom = node_table[i+1][j];
      if (j == 0) {
        temp_left = nullptr; 
      }else temp_left = node_table[i][j-1];
      if (j == x-1) {
        temp_right = nullptr; 
      }else temp_right = node_table[i][j+1];

      node_table[i][j]->SetNode(temp_left, temp_right, temp_top, temp_bottom);
    }
  }
  for (int i=0; i<2; i++) {
    for (int j=0; j<2; j++) {
      node_table[y/2 + i - 1][x/2 + j -1]->SetColor(i ^ j);
    }
  }
  free(temp_top);
  free(temp_bottom);
  free(temp_left);
  free(temp_right);
  //node table end



  Print_table* PT = Print_table::GetInstance(temp_table, x, y);
  PT->Print();
  
  std::cout << " nodenode" << std::endl;  

  Node_Print_table* NT = Node_Print_table::GetInstance(node_table, x, y);
  NT->Print();

  for(int i=0; i<x; i++) {
    free(temp_table[i]);
  }
  free(temp_table);

  for(int i=0; i<x; i++) {
    free(node_table[i]);
  }
  free(node_table);

  return 0;
}