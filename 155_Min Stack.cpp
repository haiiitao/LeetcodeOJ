/**
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 */
class MinStack {
private:
    stack<int> Stack;
    stack<int> StackMin;
    
public:
    void push( int x ) {
        Stack.push( x );
        if ( StackMin.empty() || StackMin.top() >= x )
            StackMin.push( x );
    }

    void pop() {
        if ( Stack.empty() )
            return;
        
        if ( StackMin.top() == Stack.top() )
            StackMin.pop();
            
        Stack.pop();
    }

    int top() {
        if ( Stack.empty() )
            return INT_MIN;
            
        return Stack.top();
    }

    int getMin() {
        if ( StackMin.empty() )
            return INT_MIN;
            
        return StackMin.top();
    }
};