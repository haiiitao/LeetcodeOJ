/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse( vector<NestedInteger>& nestedList ) {
        vector<int> result;
        dfs( nestedList, 0, result );

        int sum = 0;
        for ( int i = 0, len = result.size(); i < len; i++ )
            sum += result[i] * (len - i);
        
        return sum;
    }
    
private:
    void dfs( vector<NestedInteger>& nestedList, int depth, vector<int>& result ) {
        if ( result.size() == depth ) 
            result.push_back( 0 );
        
        for ( auto& i : nestedList ) {
            if ( i.isInteger() ) 
                result[depth] += i.getInteger();
            else 
                dfs( i.getList(), depth + 1, result );
        }
    }
};