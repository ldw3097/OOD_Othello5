#include "node_print.h"

#include <iostream>
#include <string>

#define LU "\u250c"  	// Left Up
#define RU "\u2510"  	// Right Up
#define MU "\u252c"  	// Mid Up

#define LD "\u2514"  	// Left Down
#define RD "\u2518"  	// Right Down
#define MD "\u2534"  	// Mid Down

#define VL "\u2502"  	// Vertical Line
#define HL "\u2500"  	// Horizon Line

#define CR "\u253c" 	// CRoss

#define SE " "  		// Space Empty

#define FD "\u25cf" 	// Filled Dot(white)
#define ED "\u25cb"  	// Empty Dot(black)

#define GF "\u2299"  	//Guide Filled dot
#define GE "\u25CE"  	//Guide Empty dot

const void Node_Print_table::Print(Board &board) {
  const int x = board.x();
  const int y = board.y();
  std::string line1_ = "  ";
  std::string line2_ = "   ";

  for (int i = 0; i < x; i++) {
    line1_ += "   ";
    line1_ += std::to_string(i);
  }
  std::cout << line1_ << std::endl;
  line2_ += LU;
  for (int i = 0; i < x; i++) {
    line2_ += HL;
    line2_ += HL;
    line2_ += HL;
    if (i == x - 1) {
      line2_ += RU;
    } else {
      line2_ += MU;
    }
  }
  std::cout << line2_ << std::endl;
  for (int i = 0; i < y; i++) {
    line1_ = " " + std::to_string(i) + " " + VL;
    for (int j = 0; j < x; j++) {
      line1_ += SE;
      //공백 사이에 들어갈 문자 선택
      if (board[i][j]->GetColor() == -1) {
       //색이 지정되지 않고 가이드가 없으면공백
       
       if(board[i][j]->GetGuide() == -1){
         line1_ += SE;
         line1_ += SE; 
       } else {
         //색이 지정되지 않고 가이드가 있으면 해당 가이드 출력
         if(board[i][j]->GetGuide() == 0) {
           line1_ += GF;
         } else if(board[i][j]->GetGuide() == 1) {
           line1_ += GE;
         }
       }
       
//wsl이 아니라면 FD, ED다음에 SE를 추가시키면 됩니다.
      } else if (board[i][j]->GetColor() == 0) {  // 백돌
        line1_ += FD;
        line1_ += SE;
      } else if (board[i][j]->GetColor() == 1) {  // 흑돌
        line1_ += ED;
        line1_ += SE;
      }
      line1_ += VL;
    }
    std::cout << line1_ << std::endl;
    
    line2_ = "   ";
    if (i < y - 1) {
      line2_ += VL;
      for (int i = 0; i < x; i++) {
        line2_ += HL;
        line2_ += HL;
        line2_ += HL;
        if (i < x - 1) {
          line2_ += CR;
        } else
          line2_ += VL;
      }
    } else if (i == y - 1) {
      line2_ += LD;
      for (int i = 0; i < x; i++) {
        line2_ += HL;
        line2_ += HL;
        line2_ += HL;
        if (i < x - 1) {
          line2_ += MD;
        }
      }
      line2_ += RD;
    }
    std::cout << line2_ << std::endl;
  }
}

Node_Print_table* Node_Print_table::instance_ = NULL;

Node_Print_table::Node_Print_table(){}

Node_Print_table* Node_Print_table::GetInstance() {
  if (instance_ == NULL) {
    instance_ = new Node_Print_table();
  }
  return instance_;
}
