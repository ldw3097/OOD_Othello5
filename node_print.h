#ifndef NODE_PRINT_H
#define NODE_PRINT_H
#include "node.h"

class Node_Print_table {
 public:
  Node_Print_table(Node*** table, int x, int y);
  static Node_Print_table* GetInstance(Node*** table, int x, int y);
  const void Print() const;
 private:
  Node*** table_;
  int x_;
  int y_;
  static Node_Print_table* instance_;
};

#endif  // NODE_PRINT_H