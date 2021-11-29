#include <iostream>
#include <string>
#include <unistd.h>

#include "node.h"
#include "node_print.h"
#include "Board.h"


// 게임 실행
bool OneGame() {
  using std::cin;
  using std::cout;
  using std::endl;
  cout << "사용할 보드의 크기를 y x 양식으로 입력해주세요" << endl;
  int y, x;
  cin >> y >> x;
  Board board(y, x);
  Node_Print_table* NT = Node_Print_table::GetInstance();

  int color = 1;  // 흑돌
  int ip_x_, ip_y_;
  while (1) {  // TODO: 게임 끝 검사를 조건문으로 하기
    
    NT->Print(board);
    NT->Print(board); 
    if (color) {
      cout << "흑돌(\u25cb)의 차례입니다. 돌을놓을 위치를 y x 양식으로 입력해주세요" << endl;
    } else
      cout << "백돌(\u25cf)의 차례입니다. 돌을놓을 위치를 y x 양식으로 입력해주세요" << endl;
    do{cin >> ip_y_ >> ip_x_;}
    while(!board.IsValidInput(ip_y_, ip_x_, color));
    board.PlaceStone(ip_y_, ip_x_, color);

    color =  !color;
  }

  cout << "다시 하시겠습니까? (1 : 다시하기, 0 : 그만하기)" << endl;
  bool re;
  cin >> re;
  return re;
}


int main(int argc, char** argv) {
  using std::cout;
  using std::endl;

  cout << "오셀로 게임에 오신것을 환영합니다.\n";

  bool doGame = 1;
  while (doGame) {
    doGame = OneGame();
  }
  cout << "오셀로 게임을 종료합니다." <<endl;
  sleep(2000);

  return 0;
}
