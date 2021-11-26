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
int Node::GetColor() const {	
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
Node* Node::Clone() const {
  return new Node(*this);
}

void Node::BFS() const {
  std::cout<< "~~~~in~~~~" << std::endl;

  if(this->GetLeft() != nullptr) {
    if(this->GetColor() != this->GetLeft()->GetColor() && this->GetLeft()->GetColor() != -1) {
      const Node* index = this->Clone()->GetLeft();
      while (index->GetColor() != -1) {
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
    if(this->GetColor() != this->GetRight()->GetColor() && this->GetRight()->GetColor() != -1) {
      const Node* index = this->Clone()->GetRight();
      while (index->GetColor() != -1) {
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
    if(this->GetColor() != this->GetTop()->GetColor() && this->GetTop()->GetColor() != -1) {
      const Node* index = this->Clone()->GetTop();
      while (index->GetColor() != -1) {
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
    if(this->GetColor() != this->GetBottom()->GetColor() && this->GetBottom()->GetColor() != -1) {
      const Node* index = this->Clone()->GetBottom();
      while (index->GetColor() != -1) {
        if(index != this && index->GetColor() == this->GetColor()) {
            this->GetBottom()->SetColor(this->GetColor());
            this->GetBottom()->BFS();
            break;
        }
        index = index->GetBottom();
        if(index->GetBottom() == nullptr) break;
      }
    }
  } //index할당 해제 해줘야함,,
}