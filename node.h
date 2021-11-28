#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int color, int x, int y);
  Node();
  const void SetNode(Node* left, Node* right, Node* top, Node* bottom) ;

  const void SetNode(Node* left, Node* right, Node* top, Node* bottom, Node* top_left, Node* top_right, Node* bottom_left, Node* bottom_right);

  const void SetColor(int color) ;
  int GetColor() const;

  const void SetGuide(int guide);
  int GetGuide() const;

  Node* GetLeft() const ;
  Node* GetRight() const ;
  Node* GetTop() const ;
  Node* GetBottom() const ;

  Node* GetTopRight() const;
  Node* GetTopLeft() const;
  Node* GetBottomRight() const;
  Node* GetBottomLeft() const;

  Node* Clone() const;

  int GetX() const;
  int GetY() const;

  Node* GetNext(int dir) const;

  void SetDot() const;
  void DFS(int dir) const;
  int Condition(int origin_color) const;


  void BFS() const;

 private:
  Node* left_ = nullptr;
  Node* right_ = nullptr;
  Node* top_ = nullptr;
  Node* bottom_ = nullptr;

  Node* top_left_ = nullptr;
  Node* top_right_ = nullptr;
  Node* bottom_left_ = nullptr;
  Node* bottom_right_ = nullptr;

  int x_=-1;
  int y_=-1;

  int guide_ = -1;
  int color_ = -1; // -1:space, 0:filled, 1:empty
};

#endif  // NODE_H
