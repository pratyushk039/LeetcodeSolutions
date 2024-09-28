class MyCircularDeque {
public:
    int max_size;
    deque<int> deq;
    MyCircularDeque(int k) {
        this->max_size = k;
    }
    
    bool insertFront(int value) {
        if(this->deq.size()<this->max_size){this->deq.push_front(value);return true;}
        return false;
    }
    
    bool insertLast(int value) {
        if(this->deq.size()<this->max_size){this->deq.push_back(value);return true;}
        return false; 
    }
    
    bool deleteFront() {
        if(!this->deq.empty()){this->deq.pop_front();return true;}
        return false;
    }
    
    bool deleteLast() {
        if(!this->deq.empty()){this->deq.pop_back();return true;}
        return false;
    }
    
    int getFront() {
        if(!this->deq.empty()){return this->deq.front();}
        return -1;
    }
    
    int getRear() {
        if(!this->deq.empty()){return this->deq.back();}
        return -1;
    }
    
    bool isEmpty() {
        return this->deq.empty();
    }
    
    bool isFull() {
        return this->deq.size()==this->max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */