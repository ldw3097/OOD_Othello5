#include "Board.h"
#include <iostream>

Board::Board(int y, int x) : y_(y), x_(x) {
  board_ = new Node**[y];
  for (int i = 0; i < y; i++) {
    board_[i] = new Node*[x];
  }
  for (int i = 0; i < y; i++) {  
    for (int j = 0; j < x; j++) {
      board_[i][j] = new Node(-1, j, i);
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      board_[4 + i - 1][4 + j - 1]->SetColor(i ^ j);
    }
  }
  SortTable();
}

Node*** Board::board() { return board_; }

const int Board::y() const  { return y_; }

const int Board::x() const { return x_; }

Node** Board::operator[](int index) const { return board_[index]; }

void Board::SortTable() {
  Node* temp_top = nullptr;
  Node* temp_bottom = nullptr;
  Node* temp_left = nullptr;
  Node* temp_right = nullptr;
  Node* temp_top_left = nullptr;
  Node* temp_top_right = nullptr;
  Node* temp_bottom_left = nullptr;
  Node* temp_bottom_right = nullptr;

  for (int i = 0; i < y_; i++) {
    for (int j = 0; j < x_; j++) {
      if (i == 0) {
        temp_top = nullptr;
      } else
        temp_top = board_[i - 1][j];

      if (i == y_ - 1) {
        temp_bottom = nullptr;
      } else
        temp_bottom = board_[i + 1][j];

      if (j == 0) {
        temp_left = nullptr;
      } else
        temp_left = board_[i][j - 1];

      if (j == x_ - 1) {
        temp_right = nullptr;
      } else
        temp_right = board_[i][j + 1];

      if (i == 0 || j == 0) {
        temp_top_left = nullptr;
      } else
        temp_top_left = board_[i - 1][j - 1];

      if (i == 0 || j == x_ - 1) {
        temp_top_right = nullptr;
      } else
        temp_top_right = board_[i - 1][j + 1];

      if (i == y_ - 1 || j == 0) {
        temp_bottom_left = nullptr;
      } else
        temp_bottom_left = board_[i + 1][j - 1];

      if (i == y_ - 1 || j == x_ - 1) {
        temp_bottom_right = nullptr;
      } else
        temp_bottom_right = board_[i + 1][j + 1];

      board_[i][j]->SetNode(temp_left, temp_right, temp_top, temp_bottom,
                            temp_top_left, temp_top_right, temp_bottom_left,
                            temp_bottom_right);
    }
  }
}

bool Board::IsValidInput(int y, int x, int color){  // 올바른 위치인지 검사
  
  
  
  return 1;
}

void Board::PlaceStone(int y, int x, int color){
  board_[y][x]->SetColor(color);
  //std::cout << y<<" " << x << " " << color <<std::endl;
  //board_[y][x]->SetDot();
}

Board::~Board(){
  for (int i = 0; i < y_; i++) {
    for(int j = 0; j < x_; j++){
      delete board_[i][j];
    }
    delete[] board_[i];
  }
  delete[] board_;
}