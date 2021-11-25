#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int color);
  const void SetNode(Node* left, Node* right, Node* top, Node* bottom);
  const void SetColor(int color) ;
  const int GetColor() const;

//const Node*는 Getter Setter설정할때 오류가 발생함.
  Node* GetLeft() const ;
  Node* GetRight() const ;
  Node* GetTop() const ;
  Node* GetBottom() const ;
  void BFS() const;
 private:
  Node* left_; 
  Node* right_;
  Node* top_;
  Node* bottom_;
  int color_ ;
};

#endif  // NODE_H
