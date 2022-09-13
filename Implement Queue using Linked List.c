#include <algorithm>
#include <cstddef>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
  public:
  int data;
  Node* next;
  Node(int d){
    data=d;
    next=nullptr;
  }
  Node(){
    data=-1;
    next=nullptr;
  }
};

struct Queue{
 int queueSize;
 int len;
  Node* head;
  Node* cur;
  Node* temp;
  Queue(int s){
    queueSize=s;
    len=0;
    head=new Node();
    cur=head;
  }
  void enQueue(int data){
    if(queueSize==len){
      printf("\nQueue is full\n");
      return;
    }
    Node* newNode=new Node(data);
    cur->next=newNode;
    cur=newNode;
    len++;
  }
  bool isEmpty(){
    return head->next==nullptr;
  }
  int peak(){
    if(!isEmpty()) return head->next->data;
    else return -1;
  }
  void deQueue(){
    if(head==nullptr){
      printf("\n Queue is Underflow\n");
      exit(1);
    }else{
     temp=head;
     head=head->next;
     delete(temp);
      len--;
    }
  }
  void display(){
    Node* temp;
    if(head->next==nullptr){
      printf("\n Q is underflow\n");
      exit(1);
    }
    else{
      temp=head->next;
      while(temp!=nullptr){
        printf("%d-->", temp->data);
        temp=temp->next;
      }
    }
  }
};

int main(){
  Queue q(3);
  q.enQueue(11);
  q.enQueue(22);
  q.enQueue(33);
  q.enQueue(44);
  q.display();
  printf("the front value is %d\n", q.peak());
  q.deQueue();
  q.deQueue();
  q.display();
  return 0;
}
