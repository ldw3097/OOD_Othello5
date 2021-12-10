#include "board.h"
#include "gtest/gtest.h"
#include "node.h"

TEST(board, board88) {
  Board brd(8, 8);
  EXPECT_EQ(brd[3][4]->GetColor(), 1);
}

TEST(board, board99_99) {
  Board brd(99, 99);
  EXPECT_EQ(brd[48][49]->GetColor(), 1);
}

TEST(board, board33) {
  Board brd(3, 3);
  EXPECT_EQ(brd[0][0]->GetColor(), 0);
}

TEST(board, sorttable) {
  Board brd(8, 8);
  EXPECT_EQ(brd[2][3]->GetBottomRight()->GetColor(), 1);
}

TEST(board, sorttable2) {
  Board brd(6, 6);
  EXPECT_EQ(brd[4][3]->GetTop()->GetColor(), 0);
}

TEST(board, invalidInput) {
  Board brd(8, 8);
  EXPECT_FALSE(brd.IsValidInput(3, 3, 0));
}

TEST(board, invalidInput2) {
  Board brd(8, 8);
  EXPECT_FALSE(brd.IsValidInput(2, 3, 0));
}

TEST(board, invalidInput3) {
  Board brd(8, 8);
  EXPECT_FALSE(brd.IsValidInput(9, 0, 0));
}

TEST(board, placestone) {
  Board brd(4, 4);
  brd.PlaceStone(0, 1, 1);
  brd.PlaceStone(0, 2, 0);
  brd.PlaceStone(1, 3, 1);
  EXPECT_EQ(brd[1][2]->GetColor(), 1);
}

TEST(board, ispass) {
  Board brd(3, 3);
  brd.PlaceStone(1, 2, 1);
  brd.PlaceStone(0, 2, 0);
  EXPECT_EQ(brd.IsPass(0), 2);
  brd.PlaceStone(2, 2, 0);
  brd.PlaceStone(2, 0, 0);
  EXPECT_EQ(brd.IsPass(0), 1);
}
