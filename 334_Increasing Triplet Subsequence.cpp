/**
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false
 */
class Solution {
public:
    bool increasingTriplet( vector<int>& nums ) {
        int first = INT_MAX, second = INT_MAX;
        for ( auto num : nums ) {
            if ( num <= first )
                first = num;           
            else if ( num <= second ) 
                second = num;        
            else           
                return true;       
        }
        return false;
    }
};

class Solution {
public:
    bool increasingTriplet( vector<int>& nums ) {
        vector<int> tails;
        for ( auto num : nums ) {
            auto iter = lower_bound( tails.begin(), tails.end(), num );
            if ( iter == tails.end() ) {
                if ( tails.size() == 2 )
                    return true;
                    
                tails.push_back( num );
            }
            else if ( num < *iter )
                *iter = num;
        }
        return false;
    }
};