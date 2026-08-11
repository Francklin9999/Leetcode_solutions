class LRUCache {
struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int _key, int _val) : key(_key), val(_val), next{nullptr}, prev(nullptr) { }
};

int capacity;
int size;

unordered_map<int, Node*> map;

Node* first;
Node* last;

void addNode(Node* node) {
    last->prev->next = node;
    node->prev = last->prev;
    node->next = last;
    last->prev = node;
}

void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        first = new Node(-1, -1);
        last = new Node(-1, -1);
        first->next = last;
        last->prev = first;
    }
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;

        removeNode(it->second);
        addNode(it->second);

        return it->second->val; 
    }
    
    void put(int key, int value) {
        auto it = map.find(key);

        if (it != map.end()) {
            it->second->val = value;
            removeNode(it->second);
            addNode(it->second);
        } else {
            size++;
            map[key] = new Node(key, value);
            addNode(map[key]);

            if (size > capacity) {
                auto toDelete = first->next;
                map.erase(toDelete->key);
                removeNode(toDelete);
                delete toDelete;
                size--;
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