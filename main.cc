#include <unistd.h>

#include <iostream>
#include <string>

#include "Board.h"
#include "node.h"
#include "node_print.h"


// 게임 실행
bool OneGame() {
  using std::cin;
  using std::cout;
  using std::endl;
  cout << "사용할 보드의 크기를 x * x 양식으로 입력해주세요" << endl;
  cout << "보드의 최소 크기는 3 * 3 입니다." << endl;
  int y, x;
  cin >> x >> y;
  while((x!=y)||(x < 3)||(y <3)){
    cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
    cin >> x >> y;
  }
  Board board(y, x);
  Node_Print_table* NT = Node_Print_table::GetInstance();

  int color = 1;  // 흑돌
  int ip_x_, ip_y_;
  while (1) {  // TODO: 게임 끝 검사를 조건문으로 하기
    NT->Print(board);
    if (color) {
      cout << "흑돌(\u25cb)의 차례입니다. 돌을 놓을 위치를 x y 양식으로 "
              "입력해주세요"
           << endl;
    } else
      cout << "백돌(\u25cf)의 차례입니다. 돌을 놓을 위치를 x y 양식으로 "
              "입력해주세요"
           << endl;
      cin >> ip_x_ >> ip_y_;
    while (!board.IsValidInput(ip_y_, ip_x_, color)) {
      cout << "해당 위치에는 놓을 수 없습니다. 다시 입력하세요" << endl;
      cin >> ip_x_ >> ip_y_;
    }
    board.PlaceStone(ip_y_, ip_x_, color);
    // if 안에서 부르게 되면 호출 순서가 꼬여서 밖에서 호출
    int ispass_ = board.IsPass(color);
    if (ispass_ == 1) { // 모두 놓을 곳 없는 상태
      break;
    }
    else if (ispass_ == 2){   // 한 턴만 넘어갈 때
      continue;
    }
    else {  // 모두 가능할 때
      color = !color;
    }
  }
  // 돌 수 세기
  board.Winner();

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
  cout << "오셀로 게임을 종료합니다." << endl;
  sleep(2000);

  return 0;
}
