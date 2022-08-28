/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head==nullptr){
            head=new Node(insertVal);
            head->next=head;
            return head;
        }
        
        Node* cur=head;
        while(cur->next!=head){
            int CurVal= cur->val;
            int NextVal=cur->next->val;
            if(CurVal<=insertVal and insertVal<=NextVal) break;//normal forward situation and insertval is between
            if(CurVal>NextVal and (CurVal<=insertVal or insertVal<=NextVal)) break; //insert val is in between max and min
            cur=cur->next;
        }
        Node* newNode= new Node(insertVal, cur->next);
        cur->next=newNode;
        return head;
        
    }
};
