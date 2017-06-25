/**
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
 */
class NumArray {
public:
    NumArray( vector<int> &nums ) {
        m_TempNums = nums;
        for ( size_t i = 1, len = nums.size(); i < len; i++ ) 
            m_TempNums[i] += m_TempNums[i - 1];
    }

    int sumRange( int i, int j ) {
        return m_TempNums[j] - ((i == 0) ? 0 : m_TempNums[i - 1]);
    }

private:
    vector<int> m_TempNums;
};



// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);