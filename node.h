#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int color);
  const void SetNode(Node* left, Node* right, Node* top, Node* bottom) const;
  const void SetColor(int color) const;
  const int GetColor() const;
 private:
  Node* left_; 
  Node* right_;
  Node* top_;
  Node* bottom_;
  int color_;
};

#endif  // NODE_H