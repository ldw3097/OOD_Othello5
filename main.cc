#include <unistd.h>

#include <iostream>
#include <string>
#include <utility>

#include "Board.h"
#include "node.h"
#include "node_print.h"

int inputValidx() {
  int x;
  std::cin >> x;
  while (1) {
    if (x >= 4 && x <= 99 && std::cin.good()) {
      break;
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
    std::cin >> x;
  }
  return x;
}

std::pair<int, int> inputValidyx() {
  int x, y;
  std::cin >> x >> y;
  while (1) {
    if (x >= 0 && x <= 128 && y >= 0 && y <= 128 && std::cin.good()) break;

    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "잘못된 입력입니다. 다시 입력해주세요." << std::endl;
    std::cin >> x >> y;
  }
  std::pair<int, int> ret = {y, x};
  return ret;
}

// 게임 실행
bool OneGame() {
  using std::cin;
  using std::cout;
  using std::endl;
  cout << "사용할 보드의 한변의 길이를 입력해주세요. " << endl;
  cout << "최소 크기는 4 * 4 이며 최대 크기는 99 * 99 입니다." << endl;
  int x = inputValidx();

  Board board(x, x);
  Node_Print_table* NT = Node_Print_table::GetInstance();

  std::pair<int, int> inp;
  int color = 1;  // 흑돌
  while (1) {     // TODO: 게임 끝 검사를 조건문으로 하기
    NT->Print(board);
    if (color) {
      cout << "흑돌(\u25cb)의 차례입니다. 돌을 놓을 위치를 x y 로 "
              "입력해주세요"
           << endl;
    } else
      cout << "백돌(\u25cf)의 차례입니다. 돌을 놓을 위치를 x y 로 "
              "입력해주세요"
           << endl;
    inp = inputValidyx();
    while (!board.IsValidInput(inp.first, inp.second, color)) {
      cout << "해당 위치에는 놓을 수 없습니다. 다시 입력하세요" << endl;
      inp = inputValidyx();
    }
    board.PlaceStone(inp.first, inp.second, color);
    // if 안에서 부르게 되면 호출 순서가 꼬여서 밖에서 호출
    int ispass_ = board.IsPass(color);
    if (ispass_ == 1) {  // 모두 놓을 곳 없는 상태
      break;
    } else if (ispass_ == 2) {  // 한 턴만 넘어갈 때
      continue;
    } else {  // 모두 가능할 때
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
