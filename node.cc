#include "node.h"

Node::Node(int color):color_(color), left_(nullptr), right_(nullptr), top_(nullptr), bottom_(nullptr) {}

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
Node* Node::GetLeft() const  {
  return this->left_;
}
Node* Node::GetRight()const   {
  return this->right_;
}
Node* Node::GetTop() const  {
  return this->top_;
}
Node* Node::GetBottom() const {
  return this->bottom_;
}

void Node::BFS() const {
// LEFT
  if(this->GetLeft() == nullptr && this->GetColor() == this->GetLeft()->GetColor()) {
  } else{
    for(
        const Node* index=this->GetLeft();		
        index != nullptr || index->GetColor() == this->GetColor();
        index = index->GetLeft()
      ){
      if(index->GetColor() != this->GetLeft()->GetColor()) {
        this->GetLeft()->SetColor(this->GetColor());
        this->GetLeft()->BFS();
        break;
      }
    }
  }

//RIGHT
  if(this->GetRight() == nullptr && this->GetColor() == this->GetRight()->GetColor()) {
  } else{
    for(
        const Node* index=this->GetRight();		
        index != nullptr || index->GetColor() == this->GetColor();
        index = index->GetRight()
      ){
      if(index->GetColor() != index->GetRight()->GetColor()) {
        this->GetRight()->SetColor(this->GetColor());
        this->GetRight()->BFS();
        break;
      }
    }
  }

//TOP
  if(this->GetTop() == nullptr && this->GetColor() == this->GetTop()->GetColor()) {
  } else{
    for(
        const Node* index=this->GetTop();		
        index != nullptr || index->GetColor() == this->GetColor();
        index = index->GetTop()
      ){
      if(index->GetColor() != index->GetTop()->GetColor()) {
        this->GetTop()->SetColor(this->GetColor());
        this->GetTop()->BFS();
        break;
      }
    }
  }

//BOTTOM
  if(this->GetBottom() == nullptr && this->GetColor() == this->GetBottom()->GetColor()) {
  } else{
    for(
        const Node* index=this->GetBottom();		
        index != nullptr || index->GetColor() == this->GetColor();
        index = index->GetBottom()
      ){
      if(index->GetColor() != index->GetBottom()->GetColor()) {
        this->GetBottom()->SetColor(this->GetColor());
        this->GetBottom()->BFS();
        break;
      }
    }
  }



}