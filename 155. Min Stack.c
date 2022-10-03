class MinStack {
    
struct ListNode {
 int val;
 ListNode *next;
  };

    ListNode* Stack;    
    
public:
    MinStack() {
        Stack=nullptr;
    }
    
    void push(int val) {
        ListNode* head= Stack;
        ListNode* temp = new ListNode();
         temp->val=val;
        temp->next=nullptr;
        if(!Stack){           
            Stack=temp;
        }
        else{
            while(head->next){
                head=head->next;
            }
            head->next=temp;
        }           
    }
    
    void pop() {
        ListNode* temp=Stack;
        while(temp->next->next){
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=nullptr;      
    }
    
    int top() {
     ListNode* temp=Stack;
        while(temp->next){
            temp=temp->next;
        }
       return temp->val;
    }
    
    
    int getMin() {
            int Min = INT_MAX;
           ListNode* temp=Stack;
        while(temp){
            if(temp->val < Min)
                Min=temp->val;
            temp=temp->next;
        }
       return Min;
    }
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
