#ifndef NODE_PRINT_H
#define NODE_PRINT_H
#include "node.h"
#include "Board.h"

class Node_Print_table {
 public:
  Node_Print_table();
  static Node_Print_table* GetInstance();
  const void Print( Board &board) ;
 private:
  static Node_Print_table* instance_;
};

#endif  // NODE_PRINT_H