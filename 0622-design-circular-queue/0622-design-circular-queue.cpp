class MyCircularQueue {
struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int _val = -1) : val(_val), next(nullptr), prev(nullptr) { }
};

size_t capacity;
size_t size;
Node* first;
Node* last;
public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        first = new Node(-1);
        last = new Node(-1);
        first->next = last;
        first->prev = last;
        last->next = first;
        last->prev = first;
    }
    
    bool enQueue(int value) {
        if (size == capacity) return false;
        auto n = new Node(value);

        last->prev->next = n;
        n->prev = last->prev;
        n->next = last;
        last->prev = n;
        ++size;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        auto curr = first->next;
        first->next = curr->next;
        curr->next->prev = first;
        --size;

        return true;
    }
    
    int Front() {
        if (size == 0) return -1;

        return first->next->val;
    }
    
    int Rear() {
        if (size == 0) return -1;

        return last->prev->val; 
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */