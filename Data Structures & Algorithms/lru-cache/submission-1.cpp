class ListNode{
public:
    int key;
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int key1,int val1){
        key=key1;
        val=val1;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int , ListNode*> mpp;
    int size1=0;
    ListNode* head;
    ListNode* tail;
    LRUCache(int capacity) {
        size1=capacity;
        head=new ListNode(-1,-1);
        tail=new ListNode(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    void remove(ListNode* node){
        ListNode* prev_node=node->prev;
        ListNode* next_node=node->next;
        prev_node->next=next_node;
        next_node->prev=prev_node;
    }

    void insert(ListNode* node){
        ListNode* prev_node=tail->prev;
        prev_node->next=node;
        node->prev=prev_node;
        node->next=tail;
        tail->prev=node;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        ListNode* node=mpp[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            ListNode* node=mpp[key];
            remove(node);
            mpp.erase(key);
        }
        if(mpp.size()==size1){
            ListNode* lru=head->next;
            remove(lru);
            mpp.erase(lru->key);
        }
        ListNode* node1=new ListNode(key,value);
        insert(node1);
        mpp[key]=node1;
    }
};
