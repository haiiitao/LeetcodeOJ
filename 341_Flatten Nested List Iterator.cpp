class NestedIterator {
public:
    NestedIterator( vector<NestedInteger>& nestedList ) {
        for ( auto rit = nestedList.rbegin(); rit != nestedList.rend(); rit++ ) 
            stk.push( *rit );
    }

    int next() {
        int res = stk.top().getInteger();
        stk.pop();
        return res;        
    }

    bool hasNext() {
        while( !stk.empty() && !stk.top().isInteger() ) {
            auto t = stk.top().getList();
            stk.pop();
            for ( auto rit = t.rbegin(); rit != t.rend(); rit++ ) 
                stk.push( *rit );
        }
        return !stk.empty();
    }
    stack<NestedInteger> stk;
};