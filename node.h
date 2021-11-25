#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int color);
  const void SetNode(Node* left, Node* right, Node* top, Node* bottom) ;
  const void SetColor(int color) ;
  const int GetColor() const;
  const Node* GetLeft() const;
  const Node* GetRight() const;
  const Node* GetTop() const;
  const Node* GetBottom() const;
 private:
  const Node* left_; 
  const Node* right_;
  const Node* top_;
  const Node* bottom_;
  int color_;
};

#endif  // NODE_H
