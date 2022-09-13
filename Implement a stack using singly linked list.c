#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
  public:
  int data;
  Node* prev;
  Node(int d){
    data=d;
    prev=nullptr;
  }
};

struct Stack{
 int stackSize;
 int len;
  Node* top;
  Stack(int s){
    stackSize=s;
    len=0;
    top=nullptr;
  }
  void push(int data){
    if(stackSize==len){
      printf("stack is full");
      return;
    }
    Node* newNode=new Node(data);
    newNode->prev=top;
    top=newNode;
    len++;
  }
  bool isEmpty(){
    return top==nullptr;
  }
  int peak(){
    if(!isEmpty()) return top->data;
    else return -1;
  }
  void pop(){
    if(top==nullptr){
      printf("\n Stack Underflow");
      exit(1);
    }else{
     // Node* temp1=top;
      top=top->prev;
     // free(temp1);
      len--;
    }
  }
  void display(){
    Node* temp;
    if(top==nullptr){
      printf("stack underflow");
      exit(1);
    }
    else{
      temp=top;
      while(temp!=nullptr){
        printf("%d-->", temp->data);
        temp=temp->prev;
      }
    }
  }
};

int main(){
  Stack s(3);
  s.push(11);
  s.push(22);
  s.push(33);
  s.push(44);
  s.display();
  printf("the top value is %d", s.peak());
  s.pop();
  s.pop();
  s.display();
  return 0;
}
