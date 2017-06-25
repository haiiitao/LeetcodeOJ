class Solution {
public:
    int largestRectangleArea( vector<int>& heights ) {
        stack<int> stk;
        int result = 0;
        heights.push_back( 0 );
        for ( int i = 0, len = heights.size(); i < len; ) {
            if ( stk.empty() || heights[i] >= heights[stk.top()] ) {
                stk.push( i++ );
            } else {
                int height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                result = max( result, height * width );
            }
        }
        return result;
    }
};