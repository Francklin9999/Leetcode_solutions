class LRUCache {
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

int capacity;
int size;

Node* head;
Node* last;
unordered_map<int, Node*> cache;

void insert(int key, int value) {
    auto node = new Node(key, value);

    cache[key] = node;

    last->prev->next = node;
    node->prev = last->prev;
    node->next = last;
    last->prev = node;
}

void update(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->prev = last->prev;
    last->prev->next = node;
    node->next = last;
    last->prev = node;
}

void remove() {
    auto t = head->next;

    t->prev->next = t->next;
    t->next->prev = t->prev;

    cache.erase(t->key);

    delete t;
}

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node(-1, -1);
        last = new Node(-1, -1);

        head->next = last;
        last->prev = head;
    }
    
    int get(int key) {
        auto it = cache.find(key);

        if (it == cache.end()) return -1;

        update(it->second);

        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            it->second->value = value;
            update(it->second);
            return;
        }

        if (size == capacity) {
            remove();
            --size;
        }

        insert(key, value);
        ++size;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */