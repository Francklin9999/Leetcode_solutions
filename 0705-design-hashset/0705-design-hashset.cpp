class MyHashSet {
struct Node {
    int val;
    Node* next;
    Node() : val(-1), next(nullptr) { }
    Node(int _val) : val(_val), next(nullptr) { }
};

vector<Node*> table;
std::size_t capacity;
public:
    MyHashSet(std::size_t n = 1000) : capacity(n) {
        table.resize(capacity);

        for (auto& bucket : table) {
            bucket = new Node(-1);
        }
    }
    
    void add(int key) {
        auto n = new Node(key);
        int idx = key % capacity;
        auto i = table[idx];

        while (i->next) {
            if (i->next->val == key) return;
            
            i = i->next;
        }

        i->next = n;
    }
    
    void remove(int key) {
        int idx = key % capacity;
        auto i = table[idx];

        while (i->next && i->next->val != key) i = i->next;

        if (!i->next || i->next->val != key) return;

        auto curr = i->next;
        i->next = curr->next;
        delete curr;
    }
    
    bool contains(int key) {
        int idx = key % capacity;
        auto i = table[idx];

        while (i && i->val != key) i = i->next;

        return i != nullptr;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */