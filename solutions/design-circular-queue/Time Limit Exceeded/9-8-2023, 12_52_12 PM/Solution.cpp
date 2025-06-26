// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
    int tail,head;
    vector<int> v;
public:
    MyCircularQueue(int k) {
        tail = -1;
        head = -1;
        v.resize(k,-1);
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
        cout << "enqueue: ";
        showQueue();
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        v[head] = -1;
        head++;
        if(head == v.size())
            head = 0;
        cout << "dequeue: ";
        showQueue();
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
        cout << "empty: " << head << " " << tail << endl;
        for(int i = 0;i < v.size();i++)
            if(v[i] != -1)
                return false;
        return true;
    }
    
    bool isFull() {
        cout << "full: " << head  << " " << tail << endl;        
        bool test = true;
        for(int i = 0;i < v.size();i++)
            if(v[i] == -1)
            {
                test = false;
                break;
            }
        return test;
    }
    
    void showQueue()
    {
        cout << "showQueue: ";
        for(int i = 0;i < v.size();i++)
            cout << v[i] << " ";
        cout << endl;
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