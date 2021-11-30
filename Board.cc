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
  if ((x < 0)||(y < 0)) {   //입력 좌표가 음수인 경우
    return false;
  }
  if ((this->x_ > x)&&(this->y_ > y)) {   //보드판 내의 좌표인 경우
    if (board_[y][x]->GetColor() != -1)  // 이미 돌이 존재하는 곳
      return false;
// 게임 규칙에 따른 위치 조건
    if (board_[y][x]->Condition(color) == 0)
      return true;
    else
      return false;
  }
  else {  //보드판 밖의 좌표인 경우
    return false;
  }
}

void Board::PlaceStone(int y, int x, int color){
  board_[y][x]->SetColor(color);
  board_[y][x]->SetDot();
}

int Board::IsPass(int color) {
  // 보드 전체를 돌며 종료/패스 조건 체크
  // 현재 인자로 들어온 색은 이미 놓였으니
  // 다음 색을 놓을 수 있는지 체크
  for (int i = 0; i < this->x_; i++){
    for (int j = 0; j < this->y_; j++){
      if (board_[j][i]->GetColor() == -1){
        if (board_[j][i]->Condition(!color) == 0){
          return 0;
        }
      }
    }
  }
  if (!color == 1)
    std::cout << "흑돌을 놓을 수 있는 곳이 없습니다. 턴을 넘깁니다" << std::endl;
  else
    std::cout << "백돌을 놓을 수 있는 곳이 없습니다. 턴을 넘깁니다" << std::endl;
  // 인자로 들어온 색의 돌을 놓고, 그 다음 색이 놓을 수 없을 때
  // 턴을 넘긴 후에 자신도 놓을 수 있는지 체크
  for (int i = 0; i < this->x_; i++){
    for (int j = 0; j < this->y_; j++){
      if (board_[j][i]->GetColor() == -1){
        if (board_[j][i]->Condition(color) == 0){
          return 2;
        }
      }
    }
  }
  std::cout << "두 플레이어 모두 놓을 수 있는 곳이 없습니다." << std::endl;
  std::cout << "게임을 종료합니다." << std::endl;
  return 1;
}

std::string Board::Winner() {
  int ED_count_ = 0; // 흑돌 수
  int FD_count_ = 0; // 백돌 수
  for (int i = 0; i < this->x_; i++){
    for (int j = 0; j < this->y_; j++){
      if (board_[j][i]->GetColor() == 1)
        ED_count_++;
      else
        FD_count_++;
    }
  }
  if (ED_count_ == FD_count_)
    return "무승부";
  else
    return (ED_count_ > FD_count_) ? "흑돌 승" : "백돌 승";
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