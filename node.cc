#include "node.h"

Node::Node(int color):color_(color), left_(nullptr), right_(nullptr), top_(nullptr), bottom_(nullptr) {}

const void Node::SetNode(Node* left, Node* right, Node* top, Node* bottom) const {
  this->left_ = left;
  this->right_ = right;
  this->top_ = top;
  this->bottom_ = bottom;
}

const void Node::SetColor(int color) const {
  this->color_ = color;
}
const int Node::GetColor() const {
  return this->color_;
}