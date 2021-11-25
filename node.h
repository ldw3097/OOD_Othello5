#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int color);
  Node();
  const void SetNode(Node* left, Node* right, Node* top, Node* bottom) ;
  const void SetColor(int color) ;
  const int GetColor() const;

//const Node*?äî Getter Setter?Ñ§?†ï?ï†?ïå ?ò§Î•òÍ?? Î∞úÏÉù?ï®.
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
