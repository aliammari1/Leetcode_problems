// https://leetcode.com/problems/min-stack

class MinStack {
    stack<int> s;
public:
    MinStack() {
        s = {};
    }
    
    void push(int val) {
        s.push(val);
    }
    
    void pop() {
        if(s.empty())
            return;
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        stack<int> t = s;
        int val = 0,min = t.top();
        while(!t.empty())
        {
            val = t.top();
            t.pop();
            if(val < min)
                min = val;
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */