#include "node.h"

Node::Node(int color):color_(color), left_(nullptr), right_(nullptr), top_(nullptr), bottom_(nullptr) {}

Node::Node(){};

const void Node::SetNode(Node* left, Node* right, Node* top, Node* bottom) {
  this->left_ = left;
  this->right_ = right;
  this->top_ = top;
  this->bottom_ = bottom;
}

const void Node::SetColor(int color) {
  this->color_ = color;
}
const int Node::GetColor() const {
  return this->color_;
}
const Node* Node::GetLeft() const {
  return this->left_;
}
const Node* Node::GetRight() const {
  return this->right_;
}
const Node* Node::GetTop() const {
  return this->top_;
}
const Node* Node::GetBottom() const {
  return this->bottom_;
}
