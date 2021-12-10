#ifndef NODE_PRINT_H_
#define NODE_PRINT_H_
#include "node.h"
#include "board.h"

class Node_Print_table {
 public:
  Node_Print_table();
  static Node_Print_table* GetInstance();
  void Print(const Board &board);
 private:
  static Node_Print_table* instance_;
};

#endif  // NODE_PRINT_H_
