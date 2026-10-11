class LRUCache {
struct Node {
    int key;
    int val;
    Node* prev;
    Node* next;
};
int capacity_;
int size_;
Node* head;
Node* last;
unordered_map<int, Node*> cache_;

void removeNode(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
}

void addNode(Node* node) {
    last->prev->next = node;
    node->prev = last->prev;
    node->next = last;
    last->prev = node;
}

public:
    LRUCache(int capacity) : capacity_(capacity), size_(0) {
        head = new Node(-1, -1);
        last = new Node(-1, -1);
        head->next = last;
        last->prev = head;
    }
    
    int get(int key) {
        auto it = cache_.find(key);
        if (it == cache_.end()) return -1;

        removeNode(it->second);
        addNode(it->second);

        return it->second->val;
    }
    
    void put(int key, int value) {
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            it->second->val = value;
            removeNode(it->second);
            --size_;
        } else {
            if (size_ == capacity_) {
                auto tmp = head->next;
                removeNode(head->next);
                cache_.erase(tmp->key);
                --size_;
                delete tmp;
            }
            auto curr = new Node(key, value);
            cache_[key] = curr;
        }

        addNode(cache_[key]);
        ++size_;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */