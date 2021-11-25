#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int color);
  Node();
  const void SetNode(Node* left, Node* right, Node* top, Node* bottom) ;
  const void SetColor(int color) ;
  const int GetColor() const;
  const Node* GetLeft() const;
  const Node* GetRight() const;
  const Node* GetTop() const;
  const Node* GetBottom() const;
 private:
  const Node* left_ = nullptr; 
  const Node* right_ = nullptr;
  const Node* top_ = nullptr;
  const Node* bottom_ = nullptr;
  int color_ = -1;  // -1:space, 0:filled dot, 1:empty dot
};

#endif  // NODE_H
