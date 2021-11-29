#ifndef BOARD_H
#define BOARD_H
#include "node.h"

class Board {
 public:
  Board(int y, int x);

  Node*** board();

  const int y() const;
  const int x() const;

  Node** operator[] (int index) const;
  void SortTable();
  bool IsValidInput(int y, int x, int color);
  void PlaceStone(int y, int x, int color);
  ~Board();
 private:
  Node*** board_;
  const int y_;
  const int x_;
};

#endif // BOARD_H