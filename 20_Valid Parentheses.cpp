/**
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
class Solution {
public:
    bool isValid( string s ) {
        stack<char> stk;
        for ( size_t i = 0, len = s.size(); i < len; i++ ) {
            if ( s[i] == '(' || s[i] == '[' || s[i] == '{' )
                stk.push( s[i] );
            else if ( !stk.empty() && 
                     ((stk.top() == '(' && s[i] == ')') ||
                      (stk.top() == '[' && s[i] == ']') ||
                      (stk.top() == '{' && s[i] == '}')) )
                stk.pop();
            else 
                return false;
        }
        return stk.empty();
    }
};