#include <iostream>
#include <string>

#include "node.h"
#include "node_print.h"
#include "print.h"

#define x 8
#define y 8

void SortTable(Node*** node) {
  Node* temp_top = nullptr;
  Node* temp_bottom = nullptr;
  Node* temp_left = nullptr;
  Node* temp_right = nullptr;
  Node* temp_top_left = nullptr;
  Node* temp_top_right = nullptr;
  Node* temp_bottom_left = nullptr;
  Node* temp_bottom_right = nullptr;

  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      if (i == 0) {
        temp_top = nullptr;
      } else
        temp_top = node[i - 1][j];

      if (i == y - 1) {
        temp_bottom = nullptr;
      } else
        temp_bottom = node[i + 1][j];

      if (j == 0) {
        temp_left = nullptr;
      } else
        temp_left = node[i][j - 1];

      if (j == x - 1) {
        temp_right = nullptr;
      } else
        temp_right = node[i][j + 1];


      if (i == 0 || j == 0) {
        temp_top_left = nullptr;
      } else
        temp_top_left = node[i - 1][j - 1];

      if (i == 0 || j == x - 1) {
        temp_top_right = nullptr;
      } else
        temp_top_right = node[i - 1][j + 1];

      if (i == y - 1 || j == 0) {
        temp_bottom_left = nullptr;
      } else
        temp_bottom_left = node[i + 1][j - 1];

      if (i == y - 1 || j == x- 1) {
        temp_bottom_right = nullptr;
      } else
        temp_bottom_right = node[i + 1][j + 1];



      node[i][j]->SetNode(temp_left, temp_right, temp_top, temp_bottom, temp_top_left, temp_top_right, temp_bottom_left, temp_bottom_right);
      //포인터 청소
      temp_top = nullptr;
      temp_bottom = nullptr;
      temp_left = nullptr;
      temp_right = nullptr;
      temp_top_left = nullptr;
      temp_top_right = nullptr;
      temp_bottom_left = nullptr;
      temp_bottom_right = nullptr;
    }
  }
  delete (temp_top);
  delete (temp_bottom);
  delete (temp_left);
  delete (temp_right);
  delete (temp_top_left);
  delete (temp_top_right);
  delete (temp_bottom_left);
  delete (temp_bottom_right);
}



Node*** InitNewTable() {
  Node*** node;
  Node* temp_top = nullptr;
  Node* temp_bottom = nullptr;
  Node* temp_left = nullptr;
  Node* temp_right = nullptr;

  node = new Node**[y];

  for (int i = 0; i < x; i++) {
    node[i] = new Node*[x];
  }
  for (int i = 0; i < y; i++) {  // new node
    for (int j = 0; j < x; j++) {
      node[i][j] = new Node(-1, j, i);
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      node[4 + i - 1][4 + j - 1]->SetColor(i ^ j);
    }
  }
  return node;
}

int main(int argc, char** argv) {
  /*
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
  */

  // node table init
  Node*** node_table = InitNewTable();
  SortTable(node_table);

  Node_Print_table* NT = Node_Print_table::GetInstance(node_table, x, y);
  NT->Print();

  std::cout << "0 : Filled, 1 : Empty, Nothing : -1" << std::endl;
  std::cout << "3,4 color" << node_table[4][3]->GetColor() << std::endl;
  std::cout << "top color" << node_table[4][3]->GetTop()->GetColor()
            << std::endl;
  std::cout << "right color " << node_table[4][3]->GetRight()->GetColor()
            << std::endl;
  std::cout << "left color " << node_table[4][3]->GetLeft()->GetColor()
            << std::endl;
  std::cout << "bottom color " << node_table[4][3]->GetLeft()->GetColor()
            << std::endl;


  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  // 임시 유저 인터페이스
  // 입력할때마다 돌 색이 바뀌며 돌이 있는곳에 두면 취소하고 다음 입력받음
  // 지금은 버그있어서 연결된 모든 돌의 색이 변함 21-11-26
  int ip_x_, ip_y_;
  int color = 0;
  while (ip_x_ != 99) {
    std::cin >> ip_x_ >> ip_y_;
    if(ip_x_ ==-1 && ip_y_==-1){
      int cccc=-1;
      std::cout << "change color" << std::endl;
      std::cin >> ip_x_ >> ip_y_;
      std::cout << "Change: " << node_table[ip_y_][ip_x_]->GetX() << ", " << node_table[ip_y_][ip_x_]->GetY() << "" << std::endl;
      std::cin >>cccc;
      node_table[ip_y_][ip_x_]->SetColor(cccc);
      NT->Print();
      continue;
    }
    
    std::cout << "현재 차례 : ";
    if (color == 0)
      std::cout << "선공" << std::endl;
    else
      std::cout << "후공" << std::endl;
    
    if (node_table[ip_y_][ip_x_]->GetColor() != -1) continue;
    if (node_table[ip_y_][ip_x_]->Condition(color) == 1) {
// 조건 체크(놓으려는 돌과 자신 돌 사이에 상대 돌이 있어야 함)
      std::cout << "유효하지 않은 위치입니다." << std::endl;
      continue;
    }
    NT->Print();
    node_table[ip_y_][ip_x_]->SetColor(color);
    node_table[ip_y_][ip_x_]->SetDot();
//    SortTable(node_table);

    NT->Print();
// 조건에 맞지 않으면 차례가 바뀌어서는 안되므로 아래로 내림
    color = !color;
    color = 0x1&color;
  }

  
  //destruction
  for (int i = 0; i < x; i++) {
    delete[] node_table[i];
  }
  delete[] node_table;

  return 0;
}
