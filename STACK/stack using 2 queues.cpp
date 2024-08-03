class MyStack {
public:
        queue<int>q,q1;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        while(!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
        }


        q.swap(q1);
        
    }
    
    int pop() {
        int ans=0;
    
             ans=q1.front();
            q1.pop();
            
        
        return ans;
        
    }
    
    int top() {
        int ans=q1.front();
        return ans;
        
    }
    
    bool empty() {

        return (q1.empty())?1:0;
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
