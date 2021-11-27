#include "node.h"
#include <iostream>
Node::Node(int color, int x, int y):
  color_(color), left_(nullptr), right_(nullptr), top_(nullptr), bottom_(nullptr), x_(x), y_(y) {}

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

int Node::GetX() const {
  return this->x_;
}
int Node::GetY() const {
  return this->y_;
}


void Node::BFS() const {
  std::cout << "~~~~" << this->x_ << ", " << this->y_ << "in~~~~" << std::endl;

  if(this->GetLeft() != nullptr) {
    if(this->GetColor() != this->GetLeft()->GetColor() && this->GetLeft()->GetColor() != -1) {
      Node* index1 = this->Clone()->GetLeft();
      while (index1->GetColor() != -1) {
        if(index1 != this && index1->GetColor() == this->GetColor()) {
            index1 = this->Clone();
	delete index1; 
	index1 = NULL;
  std::cout << "change: " << this->GetLeft()->x_ << ", " << this->GetLeft()->y_ << "" << std::endl;
            this->GetLeft()->SetColor(this->GetColor());
            this->GetLeft()->BFS();
            break;
        }
          if(index1->GetLeft() == nullptr) break;
          index1 = index1->GetLeft();
      }
      index1 = this->Clone();
      delete index1;
      index1 = NULL;
    }
  } 
  std::cout<< "exit L" << std::endl;

//RIGHT
  if(this->GetRight() != nullptr) {
    if(this->GetColor() != this->GetRight()->GetColor() && this->GetRight()->GetColor() != -1) {
      Node* index2 = this->Clone()->GetRight();
      while (index2->GetColor() != -1) {
        if(index2 != this && index2->GetColor() == this->GetColor()) {
            index2 = this->Clone();
	delete index2; 
	index2 = NULL;
  std::cout << "change: " << this->GetRight()->x_ << ", " << this->GetRight()->y_ << "" << std::endl;
            this->GetRight()->SetColor(this->GetColor());
            this->GetRight()->BFS();
            break;
        }
          if(index2->GetRight() == nullptr) break;
          index2 = index2->GetRight();
      }
            index2 = this->Clone();
      delete index2;
      index2 = NULL;
    }
  } 
  std::cout<< "exit R" << std::endl;

////   
////   반대편에 같은 색 돌의 위치가 가장자리라면 발동하지 않음.  
    
//TOP
  if(this->GetTop() != nullptr) {
    if(this->GetColor() != this->GetTop()->GetColor() && this->GetTop()->GetColor() != -1) {
      Node* index3 = this->Clone()->GetTop();
      while (index3->GetColor() != -1) {
        if(index3 != this && index3->GetColor() == this->GetColor()) {
            index3 = this->Clone();
	delete index3; 
	index3 = NULL;
  std::cout << "change: " << this->GetTop()->x_ << ", " << this->GetTop()->y_ << "" << std::endl;
            this->GetTop()->SetColor(this->GetColor());
            this->GetTop()->BFS();
            break;
        }
          if(index3->GetTop() == nullptr) break;
          index3 = index3->GetTop();
      }
            index3 = this->Clone();
      delete index3;
      index3 = NULL;
    }
  } 

  std::cout<< "exit T" << std::endl;
//BOTTOM
  if(this->GetBottom() != nullptr) {
    if(this->GetColor() != this->GetBottom()->GetColor() && this->GetBottom()->GetColor() != -1) {
      Node* index4 = this->Clone()->GetBottom();
      while (index4->GetColor() != -1) {
        if(index4 != this && index4->GetColor() == this->GetColor()) {
            index4 = this->Clone();
	delete index4; 
	index4 = NULL;
  std::cout << "change: " << this->GetBottom()->x_ << ", " << this->GetBottom()->y_ << "" << std::endl;
            this->GetBottom()->SetColor(this->GetColor());
            this->GetBottom()->BFS();
            break;
        }
  std::cout<< "12345" << std::endl;
          if(index4->GetBottom() == nullptr) break;
            index4 = index4->GetBottom();

      }
            index4 = this->Clone();
      delete index4;
      index4 = NULL;
    }
  } 
  std::cout<< "exit B" << std::endl;
  std::cout << "~~~~" << this->x_ << ", " << this->y_ << "out~~~~" << std::endl;
}
/*          Node* temp = index4->Clone();
          index4 = NULL;
          delete temp;
          temp = NULL;*/

/*
백업 21-11-26 21:44

  if(this->GetTop() != nullptr) {
    if(this->GetColor() != this->GetTop()->GetColor() && this->GetTop()->GetColor() != -1) {
std::cout<< "enter T" << std::endl;
      const Node* index3 = this->Clone()->GetTop();
      while (index3->GetColor() != -1) {
        if(index3 != this && index3->GetColor() == this->GetColor()) {
            delete index3;
            index3 = NULL;

  std::cout << "change: " << this->GetTop()->x_ << ", " << this->GetTop()->y_ << "" << std::endl;
            this->GetTop()->SetColor(this->GetColor());
            this->GetTop()->BFS();
            break;
        } else {
          if(index3->GetTop() == nullptr) break;
          index3 = index3->GetTop();
          if(index3->GetTop() == nullptr) break;
        }
      }
      delete index3;
      index3 = NULL;
    }
  }


백업 21-11-27 14:46
  if(this->GetLeft() != nullptr) {
    if(this->GetColor() != this->GetLeft()->GetColor() && this->GetLeft()->GetColor() != -1) {
      Node* index1 = this->Clone()->GetLeft();
      while (index1->GetColor() != -1) {
        if(index1 != this && index1->GetColor() == this->GetColor()) {
            index1 = this->Clone();
	delete index1; 
	index1 = NULL;
  std::cout << "change: " << this->GetLeft()->x_ << ", " << this->GetLeft()->y_ << "" << std::endl;
            this->GetLeft()->SetColor(this->GetColor());
            this->GetLeft()->BFS();
            break;
        }
          if(index1->GetLeft() == nullptr) break;
          index1 = index1->GetLeft();
          if(index1->GetLeft() == nullptr) break;
      }
      index1 = this->Clone();
      delete index1;
      index1 = NULL;
    }
  } 
*/