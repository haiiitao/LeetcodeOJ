/**
 * Description: Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 */
class Stack {
public:
    Stack() {
        pQ1 = new queue<int>();
        pQ2 = new queue<int>();
    }
    
    ~Stack() {
        delete pQ1;
        delete pQ2;
    }
    
    // Push element x onto stack.
    void push( int x ) {
        pQ2->push( x );
        while ( !pQ1->empty() ) {
            pQ2->push( pQ1->front() );
            pQ1->pop();
        }
        swap( pQ1, pQ2 );
    }

    // Removes the element on top of the stack.
    void pop() {
        if ( !pQ1->empty() )
            pQ1->pop();
    }

    // Get the top element.
    int top() {
        return pQ1->front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return pQ1->empty();
    }
    
private:
    queue<int> *pQ1, *pQ2;
};