#include "print.h"
#include "node.h"
#include "node_print.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  int x=8; 
  int y=8;
  int** temp_table;
  temp_table = new int*[y];
  for(int i=0; i<x; i++) {
    temp_table[i] = new int[x];
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
  Node* temp_top = new Node();
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
    for (int j=0; j<x; j++) {
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
  std::cout << "0 : Filled, 1 : Empty, Nothing : -1" << std::endl;
  std::cout << "3,4 color" << node_table[4][3]->GetColor() << std::endl;
  std::cout << "top color" << node_table[4][3]->GetTop()->GetColor() << std::endl;
  std::cout << "right color " << node_table[4][3]->GetRight()->GetColor() << std::endl;
  std::cout << "left color " << node_table[4][3]->GetLeft()->GetColor() << std::endl;
  std::cout << "bottom color " << node_table[4][3]->GetLeft()->GetColor() << std::endl;

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
