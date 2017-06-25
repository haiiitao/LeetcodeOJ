class Solution {
public:
    int depthSum( vector<NestedInteger>& nestedList ) {
        return dfs( nestedList, 1 );
    }
    int dfs ( vector<NestedInteger>& nestedList, int depth ) {
        int sum = 0;
        for ( auto& i : nestedList ) {
            if ( i.isInteger() )
                sum += i.getInteger() * depth;
            else
                sum += dfs( i.getList(), depth + 1 );
        }
        return sum;
    }
};