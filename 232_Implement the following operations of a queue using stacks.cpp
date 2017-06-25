class MyQueue {
public:
    stack<int> stk1, stk2;
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push( int x ) {
        stk1.push( x );
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int t = peek();
        stk2.pop();
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        if ( stk2.empty() ) {
            while ( !stk1.empty() ) {
                stk2.push( stk1.top() );
                stk1.pop();
            }
        }
        return stk2.top();        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};