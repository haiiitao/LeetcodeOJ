/**
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.
 */
class Solution {
public:
    int maxArea( vector<int>& heights ) {
        int start = 0, end = heights.size() - 1, result = 0;
        int width, height;
        while ( start < end ) {
            width = end - start;
            if ( heights[start] <= heights[end] )
                height = heights[start++];
            else if ( heights[start] > heights[end] )
                height = heights[end--];
            
            result = max( result, width * height );
        }
        return result;
    }
};