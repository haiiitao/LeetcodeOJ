/**
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
public:
    string getPermutation( int n, int k ) {
        int f = 1;
        string str_Result;
        str_Result.append( n, '0' );
        for ( int i = 1; i <= n; i++ ) {
            f *= i;
            str_Result[i - 1] += i; 
        }
        
        stringstream ss;
        k--;
        for ( int i = n; i >= 1; i-- ) {
            f /= i;
            int idx = k / f;
            ss << str_Result[idx];
            str_Result.erase( str_Result.begin() + idx );
            k %= f;
        }
        return ss.str();
    }
};