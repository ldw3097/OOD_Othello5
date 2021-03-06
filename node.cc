#include "node.h"

#include <iostream>
Node::Node(int color, int x, int y) : color_(color), x_(x), y_(y) {}

Node::Node() {}

const void Node::SetNode(Node* left, Node* right, Node* top, Node* bottom) {
  this->left_ = left;
  this->right_ = right;
  this->top_ = top;
  this->bottom_ = bottom;
}
const void Node::SetNode(Node* left, Node* right, Node* top, Node* bottom,
                         Node* top_left, Node* top_right, Node* bottom_left,
                         Node* bottom_right) {
  this->left_ = left;
  this->right_ = right;
  this->top_ = top;
  this->bottom_ = bottom;
  this->top_left_ = top_left;
  this->top_right_ = top_right;
  this->bottom_left_ = bottom_left;
  this->bottom_right_ = bottom_right;
}

const void Node::SetColor(int color) { this->color_ = color; }
int Node::GetColor() const { return this->color_; }

const void Node::SetGuide(int color) { this->guide_ = color; }
int Node::GetGuide() const { return this->guide_; }

Node* Node::GetLeft() const { return this->left_; }
Node* Node::GetRight() const { return this->right_; }
Node* Node::GetTop() const { return this->top_; }
Node* Node::GetBottom() const { return this->bottom_; }

Node* Node::GetTopLeft() const { return this->top_left_; }
Node* Node::GetTopRight() const { return this->top_right_; }
Node* Node::GetBottomLeft() const { return this->bottom_left_; }
Node* Node::GetBottomRight() const { return this->bottom_right_; }

Node* Node::Clone() const { return new Node(*this); }

int Node::GetX() const { return this->x_; }
int Node::GetY() const { return this->y_; }

// 0:left, 1:right, 2:top, 3:bottom, 4:to
Node* Node::GetNext(int dir) const {
  if (dir == 0) {
    return this->left_;
  } else if (dir == 1) {
    return this->right_;
  } else if (dir == 2) {
    return this->top_;
  } else if (dir == 3) {
    return this->bottom_;
  } else if (dir == 4) {
    return this->top_left_;
  } else if (dir == 5) {
    return this->top_right_;
  } else if (dir == 6) {
    return this->bottom_left_;
  } else if (dir == 7) {
    return this->bottom_right_;
  }
  return NULL;
}
void Node::SetDot() const {
  this->DFS(0);
  this->DFS(1);
  this->DFS(2);
  this->DFS(3);
  this->DFS(4);
  this->DFS(5);
  this->DFS(6);
  this->DFS(7);
}

// 0:left, 1:right, 2:top, 3:bottom, 4:to
void Node::DFS(int dir) const {
  if (this->GetNext(dir) != nullptr) {
    if (this->GetColor() != this->GetNext(dir)->GetColor() &&
        this->GetNext(dir)->GetColor() != -1) {
      Node* index = this->Clone()->GetNext(dir);
      while (index->GetColor() != -1) {
        if (index != this && index->GetColor() == this->GetColor()) {
          index = this->Clone();
          delete index;
          index = NULL;
          this->GetNext(dir)->SetColor(this->GetColor());
          this->GetNext(dir)->DFS(dir);  // 진행 방향으로 반복
          break;
        }
        if (index->GetNext(dir) == nullptr) break;
        index = index->GetNext(dir);
      }
      index = this->Clone();
      delete index;
      index = NULL;
    }
  }
}
// 돌을 놓을 수 있는 조건 체크, 가능하면 0, 불가능이면 1 리턴
int Node::Condition(int origin_color) const {
  int flag = 0;  // 탐색 과정에서 사이에 상대 돌이 있었는지
  Node* index = this->Clone();
  Node* origin_node = index;
  // 한 방향부터 순서대로 탐색
  // 해당 방향의 다음 노드가 존재하는 경우 반복
  for (int i = 0; i < 8; i++) {
    index = origin_node->GetNext(i);
    flag = 0;  // 이전 방향에서의 플래그는 초기화
    while ((index != nullptr)) {
      if ((index->GetColor() == -1)) break;
      if (origin_color != index->GetColor()) {
        // 다른 색, 즉 상대방 돌이 존재할 경우 플래그 세팅
        flag = 1;
        index = index->GetNext(i);
        continue;
      }
      if (origin_color == index->GetColor()) {
        // 자신 돌을 만나면 반복 종료
        break;
      }
      index = index->GetNext(i);
    }

    if ((index) == nullptr) continue;
    // 연속으로 자신의 돌을 만나지 않고
    // 놓을 돌과 자신 돌 사이가 상대 돌로만 이루어졌다면
    // 가능한 자리이므로 0 리턴
    if ((flag == 1) && (index->GetColor() != -1) && (index != nullptr))
      return 0;
  }
  return 1;
}
