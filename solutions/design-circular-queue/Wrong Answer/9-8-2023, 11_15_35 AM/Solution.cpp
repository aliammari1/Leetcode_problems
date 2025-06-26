// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
    int tail,head;
    vector<int> v;
public:
    MyCircularQueue(int k) {
        tail = -1;
        head = -1;
        v.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        if(head == -1)
            head = 0;
        tail++;
        if(tail == v.size())
            tail = 0;
        v[tail]=value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        head++;
        if(head == v.size())
            head = 0;
        if(head == tail)
        {
            head = -1;
            tail = -1;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) 
            return -1;
        return v[head];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return v[tail];
    }
    
    bool isEmpty() {
        return head == -1 && tail == -1;
    }
    
    bool isFull() {
        cout << head  << " " << tail << endl;
        return head + tail + 1 == v.size();
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