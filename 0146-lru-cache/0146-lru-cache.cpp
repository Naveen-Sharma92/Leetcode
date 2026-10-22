class LRUCache {
public:
    struct Node{
        int val,key;
        Node* prev;
        Node* next;

        Node(int k,int v){
            val=v;
            key=k;
            prev=NULL;
            next=NULL;

        }
    };

    int cap;
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    void removeNode(Node* node){
        Node* p= node->prev;
        Node* n=node->next;
        p->next=n;
        n->prev=p;
    }
    void addNode(Node* node){
        Node * nn= head->next;
        head->next=node;
        node->prev=head;
        node->next=nn;
        nn->prev=node;
    }

    LRUCache(int capacity) {
        cap=capacity;
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        removeNode(mpp[key]);
        addNode(mpp[key]);
        return mpp[key]->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            mpp[key]->val=value;
            removeNode(mpp[key]);
            addNode(mpp[key]);
            return;
        }
        if(mpp.size()==cap){
            Node* node=tail->prev;
            removeNode(node);
            mpp.erase(node->key);
            delete node;
        }
        Node * node=new Node(key,value);
        addNode(node);
        mpp[key]=node;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */