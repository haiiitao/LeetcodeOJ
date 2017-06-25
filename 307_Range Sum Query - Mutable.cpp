/**
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
 */
class NumArray {
    vector<int> bit;
    vector<int> m_nums;
public:
    NumArray( vector<int>& nums ) : m_nums( nums ) {
        const int len = nums.size();
        bit.resize( len + 1 );
        for ( int i = 0; i < len; i++ ) 
            modify( i, nums[i] );
    }

    void update( int i, int val ) {
        if ( val != m_nums[i] ) {
            modify( i, val - m_nums[i] );
            m_nums[i] = val;
        }
    }

    int sumRange( int i, int j ) {
        return sum( j ) - sum( i - 1 );
    }
    
private:
    inline int last_bit( int i ) {
        return i & -i;
    }

    void modify( int i, int diff ) {
        i++;
        const int len = bit.size();
        while ( i < len ) {
            bit[i] += diff;
            i += last_bit( i );
        }
    }

    int sum( int i ) {
        i++;
        int sum = 0;
        while ( i > 0 ) {
            sum += bit[i];
            i -= last_bit( i );
        }
        return sum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);