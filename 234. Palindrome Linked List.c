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
    bool isPalindrome(ListNode* head) {
        return checkBackTracking(&head, head);
    }
    bool checkBackTracking(ListNode** headPtr, ListNode* p){
        if(p==nullptr)return true;
        bool isPal=checkBackTracking(headPtr, p->next);
        if((*headPtr)->val!=p->val) isPal=false;
        *headPtr=(*headPtr)->next;
        return isPal;
    }
};
