class Solution {
public:
    bool verifyPreorder( vector<int>& preorder ) {
        stack<int> stk;
        int lower_bound = INT_MIN;
        for ( auto i : preorder ) {
            if ( i < lower_bound )
                return false;
                
            while ( !stk.empty() && i > stk.top() ) {
                lower_bound = stk.top();
                stk.pop();
            }
            stk.push( i );
        }
        return true;
    }
};