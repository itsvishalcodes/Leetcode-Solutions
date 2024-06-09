class MyQueue {
public:
    stack<int> real, intermediate;
    MyQueue() {
      
    }
    
    void push(int x) {
      while(real.size()) {
        int top = real.top();
        intermediate.push(top);
        real.pop();
      }
      intermediate.push(x);
      while(intermediate.size()) {
        int top = intermediate.top();
        real.push(top);
        intermediate.pop();
      }
    }
    
    int pop() {
      int top = real.top();
      real.pop();
      return top;
    }
    
    int peek() {
      return real.top();
    }
    
    bool empty() {
      return !real.size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */