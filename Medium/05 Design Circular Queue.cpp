class MyCircularQueue {
public:
        int capacity;
        vector<int>arr;
        int rear;
        int front;
        int size;
    MyCircularQueue(int k) {
        capacity = k;   
        rear = -1;
        front = 0;
        size = 0;
        arr.resize(k);
    }
    
    bool enQueue(int value) {

        if(size == capacity){
            return false;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;

        return true;
    }
    
    bool deQueue() {
        if(size == 0){
            return false;
        }

        front = (front + 1) % capacity;
        size--;

        return true;
    }
    
    int Front() {
        if (size == 0) {
            return -1;
        }
        return arr[front];
    }
    
    int Rear() {
        if (size == 0) {
            return -1;
        }
        return arr[rear];
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
