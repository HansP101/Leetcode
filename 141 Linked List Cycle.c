/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast;
        ListNode* slow;
        if (head==nullptr) return false;
        fast=head->next;
        slow=head;
        while(fast!=slow and fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(!fast or !fast->next) return false;
        return true;
    }
};
