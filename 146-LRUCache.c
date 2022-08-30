class LRUCache {
public:
    /* Will make the head to tail double linked list */
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(): key(-1), value(-1), prev(nullptr), next(nullptr){}
        Node(int k, int v): key(k), value(v) ,prev(nullptr), next(nullptr){}
    };
    
    int cap;
    /*HashMap structure
    K:key
    V: Node to have the prev, next pointer to access O(1) time and link back. 
    */
    
    unordered_map<int, Node*> keyNodeMap;
    
    Node* head=new Node();
    Node* tail=new Node();
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        auto it=keyNodeMap.find(key);
            if(it!=keyNodeMap.end()){//key exisit update the value and take off and put into head
                remove(it->second);
                putitHead(it->second);
             return it->second->value;   
            }
            else return -1; }
    
    void putitHead(Node* node){
        Node* temp= head->next;
        head->next=node;
        node->next=temp;
        temp->prev=node;
        node->prev=head;
    }
    void remove(Node* &node){
        Node* temp=node;
        //free(node);
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    void put(int key, int value) {
        auto it=keyNodeMap.find(key);
        if(it!=keyNodeMap.end()){
            it->second->value=value;
                remove(it->second);
              putitHead(it->second);
        } //key exisit update the value and take off and put into head
        else{
            Node* newNode=new Node(key, value);
            keyNodeMap[key]=newNode;
            putitHead(newNode);
            if(keyNodeMap.size()>cap)
            {
                Node* preTail=tail->prev;
                keyNodeMap.erase(preTail->key); 
                remove(preTail);
            }
            
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
