92. Reverse Linked List II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode **pre = &head;
    int steps = m;
    while (--steps) { pre = &(*pre)->next;}
    ListNode *cur = *pre;
    for (int i = m; i < n; i++) {
        ListNode *next_n = cur->next;
        cur->next = next_n->next;
        next_n->next = *pre;
        *pre = next_n;
    }
    return head; 
  }
};
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        ListNode* prev=dummy;
        dummy->next=head;//dummy is for the case when iteration (ie left=1 case), dummy will take the "prev" node role. 
       
        for(int i=0; i<left-1; i++) prev=prev->next;
          ListNode* cur=prev->next; //current (just next one) will keep drifiting forward to the end
        for(int i=0; i<right-left; i++){
        ListNode* temp=prev->next;
        prev->next=cur->next; //cur->next (far end) one will be next to prev.
        cur->next=cur->next->next; //for following one will come to next to prev later. 
        prev->next->next=temp;} //prev->next got updated with the one far end, now this one has to link to exisiting temp one.
    
         return dummy->next;
    }
};

Reverse Double Linked List

#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* C++ program using namespace std;

/* Node of the doubly linked list */
class Node {
public:
  int data;
  Node* next;
  Node* prev;
};

/* Function to reverse a Doubly Linked List */
void reverse(Node** head_ref)
{
  Node* temp = NULL;
  Node* current = *head_ref;

  /* swap next and prev for all nodes of
  doubly linked list */
  while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  /* Before changing the head, check for the cases like
  empty list and list with only one node */
  if (temp != NULL)
    *head_ref = temp->prev;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the
beginning of the Doubly Linked List */
void push(Node** head_ref, int new_data)
{
  /* allocate node */
  Node* new_node = new Node();

  /* put in the data */
  new_node->data = new_data;

  /* since we are adding at the beginning,
  prev is always NULL */
  new_node->prev = NULL;

  /* link the old list off the new node */
  new_node->next = (*head_ref);

  /* change prev of head node to new node */
  if ((*head_ref) != NULL)
    (*head_ref)->prev = new_node;

  /* move the head to point to the new node */
  (*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list
This function is same as printList() of singly linked list
*/
void printList(Node* node)
{
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
}

// Driver's code
int main()
{
  /* Start with the empty list */
  Node* head = NULL;

  /* Let us create a sorted linked list to test the
  functions Created linked list will be 10->8->4->2 */
  push(&head, 2);
  push(&head, 4);
  push(&head, 8);
  push(&head, 10);

  cout << "Original Linked list" << endl;
  printList(head);

  // Function call
  reverse(&head);

  cout << "\nReversed Linked list" << endl;
  printList(head);

  return 0;
}

// This code is contributed by rathbhupendra
