#include "print.h"
#include <string>
#include <iostream>

#define LU "\u250c"	//Left Up
#define RU "\u2510"	//Right Up
#define MU "\u252c"	//Mid Up

#define LD "\u2514"	//Left Down
#define RD "\u2518"	//Right Down
#define MD "\u2534"	//Mid Down

#define VL "\u2502"	//Vertical Line
#define HL "\u2500"	//Horizon Line

#define CR "\u253c"	//CRoss

#define UE "\3000"	//Unicode Empty
#define SE " "		//Space Empty

#define BD "\u25cf"	//Black Dot
#define WD "\u25cb"	//White Dot



const void Print_table::Print() const {
  int x = this->x_;
  int y = this->y_;
  std::string line1_  = "";
  std::string line2_ =  "   ";

  //첫번째 초기출력 : 숫자들
  for(int i=0; i<x; i++) {
      line1_ += "   ";
      //그냥 i로 정수 박으니까 매크로 나옴 ㄷㄷ
      line1_ += std::to_string(i);
  }
  std::cout << line1_ << std::endl;
  //두번쨰 초기출력 : 테이블 최상단
  line2_ += LU;
  for(int i=0; i<x; i++) {
      line2_ += HL;
      line2_ += HL;
      line2_ += HL;
    if(i == x-1) {
      line2_ += RU;
    } else {
      line2_ += MU;
    }
  }
  std::cout << line2_ << std::endl;


  //내용 출력
  for(int i=0; i<y; i++){
    line1_ = " " + std::to_string(i) + " " + VL;
    for(int j=0; j<x; j++){
      line1_ += SE;
      if (this->table_[i][j] == -1) {
        line1_ += SE;
      } else if (this->table_[i][j] == 0) {
        line1_ += BD;
      } else if (this->table_[i][j] == 1) {
        line1_ += WD;
      }
      line1_ += SE;
      line1_ += VL;
    }
    std::cout << line1_ << std::endl;
    line2_ = "   ";
    if (i < y-1) {
      line2_ += VL;
      for(int i=0; i<x; i++) {
        line2_ += HL;
        line2_ += HL;
        line2_ += HL;
        line2_ += VL;
      }
    } else if (i == y-1) {
      line2_ += LD;
      for(int i=0; i<x; i++) {
        line2_ += HL;
        line2_ += HL;
        line2_ += HL;
        if(i < x-1) {
          line2_ +=MD;
        }
      }
      line2_ += RD;
    }
    std::cout << line2_ << std::endl;
  }
}



Print_table* Print_table::instance_ = NULL;

Print_table::Print_table(int** table, int x, int y)
  : table_(table), x_(x), y_(y) {}

Print_table* Print_table::GetInstance(int** table, int x, int y) {
  if (instance_ == NULL) {
    instance_ = new Print_table(table, x, y);
  }
  return instance_;
}