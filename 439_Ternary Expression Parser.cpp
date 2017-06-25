class Solution {
public:
    string parseTernary( string expression ) {
        stack<char> stk;
        for ( int i = expression.size() - 1; i >= 0; i-- ) {
            char token = expression[i];
            if ( !stk.empty() && stk.top() == '?' ) {
                stk.pop();
                char x = stk.top();
                stk.pop();
                stk.pop();
                char y = stk.top();
                stk.pop();
                token = token == 'T' ? x : y;
            }
            stk.push( token );
        }
        return string(1, stk.top());
    }
};