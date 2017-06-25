/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
 */
class Solution {
public:
    vector<string> generateParenthesis( int n ) {
        vector<string> result;
        dfs( result, "", n, n, 2 * n );
        
        return result;
    }
private:
    void dfs( vector<string>& result, string str, int L, int R, int len ) {
        if ( !L && !R ) {
            result.push_back( str );
            return;
        }

        if ( L )
            dfs( result, str + "(", L - 1, R, len );

        if ( R > L )
            dfs( result, str + ")", L, R - 1, len );
    }
};