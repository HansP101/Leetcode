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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode* prev=dummyNode;
        ListNode* cur=dummyNode;
        while(cur){
            if(cur->val==val){
                ListNode* temp=cur;
                prev->next=cur->next; //editing is here by skipping the node
                cur=cur->next;
               delete temp;
            }else{
               prev=cur; //prev is following up.
                cur=cur->next; 
            }      
        }
        return dummyNode->next;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        if (head==nullptr)return nullptr;
        ListNode* temp=dummy;
        while(temp->next){
            if(temp->next->val==val)
                temp->next=temp->next->next;
            else
                temp=temp->next;
        }
        return dummy->next;
    }
};
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode** cur=&head;
        while(*cur){
            if((*cur)->val==val){
                *cur=(*cur)->next; //replacing "itself" to the nextone!
            }else{
                cur=&((*cur)->next); //keep traverse to next one!
            }
        }
        return head;
    }
};
