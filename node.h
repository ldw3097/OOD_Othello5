#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int color, int x, int y);
  Node();
  const void SetNode(Node* left, Node* right, Node* top, Node* bottom) ;
  const void SetColor(int color) ;
  int GetColor() const;

  Node* GetLeft() const ;
  Node* GetRight() const ;
  Node* GetTop() const ;
  Node* GetBottom() const ;
  void BFS() const;
  Node* Clone() const;

  int GetX() const;
  int GetY() const;

 private:
  Node* left_ = nullptr;
  Node* right_ = nullptr;
  Node* top_ = nullptr;
  Node* bottom_ = nullptr;
  int x_=-1;
  int y_=-1;
  int color_ = -1; // -1:space, 0:filled, 1:empty
};

#endif  // NODE_H
