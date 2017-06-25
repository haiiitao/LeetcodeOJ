/**
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
class Solution {
public:
    int longestValidParentheses( string s ) {
        stack<int> stk;
        stk.push( -1 );
        int result = 0;
        for ( int i = 0, len = s.size(); i < len; i++ ) {
            if ( s[i] == ')' && stk.top() != -1 && s[stk.top()] == '(' ) {
                stk.pop();
                result = max( result, i - stk.top() );
            } else
                stk.push( i );
        }
        return result;
    }
};

class Solution {
public:
    int longestValidParentheses( string s ) {
        int len = s.length();
        int longest = 0, last = -1;
        stack<int> st;
        for ( int i = 0; i < len; i++ ) {
            if ( s[i] == '(' ) 
                st.push( i );
            else {
                if ( !st.empty() ) {
                    st.pop();
                    if ( st.empty() )
                        longest = max( longest, i - last );
                    else
                        longest = max( longest, i - st.top() );
                } else
                    last = i;
            }
        }
        return longest;
    }
};