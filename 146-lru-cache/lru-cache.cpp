class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k,int v)
        {
            key=k;
            val=v;
        }
    };
    int cap;
    Node*  head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;

    }

    void insertFront(Node* node)
    {
        Node* temp=head->next;
        head->next=node;
        temp->prev=node;
        node->next=temp;
        node->prev=head;
    }

    void deleteLast(Node* node)
    {
        Node* prevNode=node->prev;
        Node* nextNode=node->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            deleteLast(node);
            insertFront(node);
             return node->val;

        }
        return -1;
       
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            node->val=value;
            deleteLast(node);
            insertFront(node);
        }
        else{
            if(mp.size()==cap)
            {
                Node* lru=tail->prev;
                deleteLast(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node=new Node(key,value);
            insertFront(node);
            mp[key]=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */