/**
There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.

Note:
n and k are non-negative integers.
 */
class Solution {
public:
    int numWays( int n, int k ) {
        if ( !n || !k )
            return 0;
            
        int same = 0, not_same = k;
        for ( int i = 2; i <= n; i++ ) {
            int temp = not_same;
            not_same = (k - 1)*(same + not_same);
            same = temp;
        }
        return same + not_same;
    }
};