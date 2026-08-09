class LRUCache {
struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node (int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {}
};
int capacity;
int size;
unordered_map<int, Node*> map;
Node* head{};
Node* last{};
public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        auto curr = new Node(-1, -1);
        map[-1] = curr;
        head = curr;
        last = curr;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it != map.end()) {
            put(key, map[key]->val);
            return map[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if (it != map.end()) {
            map[key]->val = value;
        } else {
            map[key] = new Node(key, value);
            size++;
        }
        if (map[key] == last) return;
        if (map[key]->prev) {
            map[key]->prev->next = map[key]->next;
        }
        if (map[key]->next) {
            map[key]->next->prev = map[key]->prev;
        }
        map[key]->prev = last;
        last->next = map[key];
        map[key]->next = nullptr;
        if (size > capacity) {
            auto n = head->next;
            head->next = n->next;
            if (n->next)
                n->next->prev = head;
            map.erase(n->key);
            delete n;
            size = capacity;
        }
        
        last = map[key];
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */