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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode();
        ListNode* head=ans;
        int carry=0;
        while(l1 or l2 or carry){
            int temp;
            if(l1 and l2) temp=l1->val+l2->val+carry;
            else if (l1) temp=l1->val+carry;
            else if(l2) temp=l2->val+carry;
            else temp=carry;
            if (temp>=10){
                carry=temp/10;
                temp=temp%10;
            }
            else carry=0;
            ListNode* tempNode=new ListNode(temp);
            ans->next=tempNode;
            ans=ans->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return head->next;
    }
};
