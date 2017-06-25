/**
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */
class Solution {
public:
    int numTrees(int n) {
        int f[n + 1] = { 0 };
        f[0] = 1;
        for ( int i = 1; i <= n; i++ ) {
            for ( int j = 0; j < i; j++ ) {
                f[i] += f[j] * f[i - j - 1];
            }
        }
        return f[n];
    }
};