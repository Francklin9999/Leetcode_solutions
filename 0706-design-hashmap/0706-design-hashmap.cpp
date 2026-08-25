class MyHashMap {
struct Node {
    int key;
    int val;
    Node* next;
    Node(int _key, int _val) : key(_key), val(_val), next(nullptr) { }
};

vector<Node*> table;
std::size_t capacity;
public:
    MyHashMap(std::size_t _capacity = 1000) : capacity(_capacity) {
        table.resize(capacity);

        for (auto& bucket : table) {
            bucket = new Node(-1, -1);
        }
    }
    
    void put(int key, int value) {
        auto n = new Node(key, value);
        auto curr = table[key % capacity];

        while (curr->next) {
            if (curr->next->key == key) {
                curr->next->val = value;
                return;
            }

            curr = curr->next;
        }

        curr->next = n;
        
    }
    
    int get(int key) {
        auto curr = table[key % capacity];
        while (curr->next && curr->next->key != key) {
            curr = curr->next;
        }

        if (curr->next) return curr->next->val;

        return -1;
    }
    
    void remove(int key) {
        auto curr = table[key % capacity];
        while (curr->next && curr->next->key != key) {
            curr = curr->next;
        }

        if (!curr->next) return;

        auto n = curr->next;
        curr->next = n->next;

        delete n;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */