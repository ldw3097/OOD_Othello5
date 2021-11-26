#include "node.h"
#include <iostream>
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
  const Node* index=this;
  if(this->GetLeft() != nullptr) {
    if(this->GetColor() != this->GetLeft()->GetColor() && this->GetColor() != -1) {
      index=this;
      while (index->GetLeft()->GetColor() != -1) {
          if(index != this && index->GetColor() == this->GetColor()) {
              this->GetLeft()->SetColor(this->GetColor());
              this->GetLeft()->BFS();
              break;
          }
        
        index = index->GetLeft();
        if(index->GetLeft() == nullptr) break;
      }
    }
  }
  std::cout<< "exit L" << std::endl;
//RIGHT
  if(this->GetRight() != nullptr) {
    if(this->GetColor() != this->GetRight()->GetColor() && this->GetColor() != -1) {
      index=this;
      while (index->GetRight()->GetColor() != -1) {
          if(index != this && index->GetColor() == this->GetColor()) {
              this->GetRight()->SetColor(this->GetColor());
              this->GetRight()->BFS();
              break;
          }
        
        index = index->GetRight();
        if(index->GetRight() == nullptr) break;
      }
    }
  }
  std::cout<< "exit R" << std::endl;

    
//TOP
  if(this->GetTop() != nullptr) {
    if(this->GetColor() != this->GetTop()->GetColor() && this->GetColor() != -1) {
      index=this;
      while (index->GetTop()->GetColor() != -1) {
          if(index != this && index->GetColor() == this->GetColor()) {
              this->GetTop()->SetColor(this->GetColor());
              this->GetTop()->BFS();
              break;
          }
        
        index = index->GetTop();
        if(index->GetTop() == nullptr) break;
      }
    }
  }

  std::cout<< "exit T" << std::endl;
//BOTTOM
  if(this->GetBottom() != nullptr) {
    if(this->GetColor() != this->GetBottom()->GetColor() && this->GetColor() != -1) {
      index=this;
      while (index->GetBottom()->GetColor() != -1) {
          if(index != this && index->GetColor() == this->GetColor()) {
              this->GetBottom()->SetColor(this->GetColor());
              this->GetBottom()->BFS();
              break;
          }
        
        index = index->GetBottom();
        if(index->GetBottom() == nullptr) break;
      }
    }
  }
  std::cout<< "exit B" << std::endl;
  delete index;

  //참조 : https://tmdgus.tistory.com/163
  index = NULL;
}