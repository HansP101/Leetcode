/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> matchingMap; //k:original node v: new node
        Node* temp;
        temp=head;
        while(temp){
            matchingMap[temp]=new Node(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp){
            matchingMap[temp]->next=matchingMap[temp->next];
            matchingMap[temp]->random=matchingMap[temp->random];
            temp=temp->next;
        }
        return matchingMap[head];
    }
};
