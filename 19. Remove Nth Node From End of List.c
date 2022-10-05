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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans;
        ListNode* fast=head;
        ListNode* slow=head; 
        
        for(int i=0; i<n; i++) fast=fast->next; //Key point 는 fast와 slow 차이를 n 으로 만들고, 계속 fast를 끝까지 밀면 slow가 포인팅 하는것이 끝에서 N
       
        if(fast==nullptr){
            ans=head->next;
            delete head;
            return ans;
        }
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=temp->next;
        delete temp;
        return head;
        
    }
};





//very bad 풀이
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int lenList=0;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* temp=head;
        while(temp){
            lenList++;
            temp=temp->next;
        }
        temp=dummy;
        if(lenList-n==0) {
            dummy->next=dummy->next->next;
            return dummy->next;}
        for(int i=0; i<lenList-n; i++){
            temp=temp->next;
        }
        if(temp->next)
        temp->next=temp->next->next;
        return dummy->next;
    }
};
